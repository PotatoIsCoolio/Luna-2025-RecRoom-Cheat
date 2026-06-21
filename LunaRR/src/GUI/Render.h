/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <iostream>
#include <Windows.h>
#include <d3d11.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_stdlib.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <Modules/Movement.h>
#include <Modules/Visuals.h>
#include <Modules/Aimbot.h>
#include <Modules/Exclusive.h>
#include <Cheat/Lists.h>

namespace GUI {
	class Render {
	private:
		const std::string m_title{};
		bool m_active{};
	public:
		Render(const std::string& title) noexcept : m_title(title) {}
	public:
		static void Create(const std::string& title);
		bool IsActive();
		void InitImGui(HWND window, ID3D11Device* device, ID3D11DeviceContext* context);
		void KeyManager();
		void Run() const;
		void RunExtra() const;
		void ModRunner() const;
	};
	extern Render* gui;
}