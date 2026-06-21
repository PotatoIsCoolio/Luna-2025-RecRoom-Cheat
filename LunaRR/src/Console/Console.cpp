/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Console.h"

Console* Console::ptr = nullptr;

void Console::Initialize() {
	if (!AllocConsole())
		return;

	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	SetConsoleTitle(m_title.c_str());
}

void Console::Destroy() {
	if (!IsValid()) {
		Log(clr::red, "[Console][Destroy] Please do not run console function with invalid object!");
	}
	try {
		FreeConsole();
		Sleep(1000);
		delete ptr;
	}
	catch (const std::exception& e) {
		Log(clr::red, "[Console][Destroy] Failed, %s\n", e.what());
	}
}


void Console::Create(const std::string& title) {
	ptr = new Console(title);
	ptr->Initialize();
}

Console Console::Get() { return *ptr; }
bool Console::IsValid() const { return ptr != nullptr; }

void Console::Log(clr color, const char* format, ...) {
	if (!IsValid()) {
		Log(clr::red, "[Console][Log] Please do not run console function with invalid object!");
		return;
	}

	va_list va{};
	char buffer[256];

	va_start(va, buffer);
	vsnprintf(buffer, sizeof(buffer), format, va);
	va_end(va);

	std::cout << color << buffer << clr::reset << std::endl;
}