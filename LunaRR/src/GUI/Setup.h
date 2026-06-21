/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <kiero.h>
#include "Render.h"

namespace GUI {
	class Setup : Render {
	private:
		static Render* m_instance;
	public:
		bool m_init{};
	public:
		Setup(const std::string& title) : Render(title) {}
	public:
		static void __stdcall Run(LPVOID lpReserved, const std::string& title);
	};
}