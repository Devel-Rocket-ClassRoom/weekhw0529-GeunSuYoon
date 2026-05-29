#include "./CoordUtil.h"

// 지금 커서 위치를 저장한다.
COORD	GetCurrentCursorPosition(void)
{
	HANDLE						NowConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO	NowCsbi;

	GetConsoleScreenBufferInfo(NowConsole, &NowCsbi);
	return (NowCsbi.dwCursorPosition);
}

// 입력한 위치로 커서를 이동한다.
void	SetCursorPosition(int PosX, int PosY)
{
	HANDLE	NowConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD	Pos;

	Pos.X = PosX;
	Pos.Y = PosY;
	SetConsoleCursorPosition(NowConsole, Pos);
}
