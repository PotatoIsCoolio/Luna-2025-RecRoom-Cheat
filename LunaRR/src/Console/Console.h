/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <iostream>
#include <Windows.h>
#include "colored_cout.h"

class Console {
private: 
	const std::string m_title{};
	static Console* ptr;
private:
	void Initialize();
	[[maybe_unused]] void Destroy();
public:
	static void Create(const std::string& title);
	static Console Get();
	inline bool IsValid() const;
	void Log(clr color, const char* format, ...);
public:
	Console(const std::string& title) noexcept : m_title(title) {}
};