// In the process of refactoring, we will do without the debug UI (console) for now.

#include "pch.h"

namespace Debug
{
	DspDebug::DspDebug(std::string title, size_t width, size_t height):
		Cui(title, width, height)
	{
	}

	void DspDebug::OnKeyPress(char Ascii, int Vkey, bool shift, bool ctrl)
	{
	}
}

void DBOpen()
{

}

void DBClose()
{

}