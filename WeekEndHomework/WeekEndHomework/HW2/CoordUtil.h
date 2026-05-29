#pragma once

#include <windows.h>

// 출력시 콘솔 커서 컨트롤용 유틸
COORD	GetCurrentCursorPosition(void);
void	SetCursorPosition(int PosX, int PosY);
