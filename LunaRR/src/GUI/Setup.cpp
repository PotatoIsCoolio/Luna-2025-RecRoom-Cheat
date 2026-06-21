/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Setup.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HRESULT(__stdcall* oPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
LRESULT(__stdcall* oWndProc)(HWND, UINT, WPARAM, LPARAM);

GUI::Render* GUI::Setup::m_instance = nullptr;

LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
	if (GUI::gui->IsActive()) ClipCursor(NULL);
	return GUI::gui->IsActive() ? true : CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

ID3D11Device* device;
ID3D11DeviceContext* context;
ID3D11RenderTargetView* renderTargetView;
bool m_initialize{};

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags) {

	if (!m_initialize) {
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&device))) {
			device->GetImmediateContext(&context);
			
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			HWND window = sd.OutputWindow;
			
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			device->CreateRenderTargetView(pBackBuffer, NULL, &renderTargetView);
			pBackBuffer->Release();
			
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			GUI::gui->InitImGui(window, device, context);
			m_initialize = true;
		}
		else return oPresent(pSwapChain, syncInterval, flags);
	}

	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX11_NewFrame();
	ImGui::NewFrame();

	GUI::gui->KeyManager();
	GUI::gui->Run();
	GUI::gui->RunExtra();
	GUI::gui->ModRunner();

	ImGui::Render();
	context->OMSetRenderTargets(1, &renderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, syncInterval, flags);
}

void __stdcall GUI::Setup::Run(LPVOID lpReserved, const std::string& title) {
	GUI::Render::Create(title);

	if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
	{
		kiero::bind(8, (void**)&oPresent, hkPresent);
	}
}