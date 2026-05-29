#pragma once

#include <iostream>
#include <string>

const int	kTotalMonth = 12;
const int	kTotalDate = 7;
const int	kTotalDay = 365;
const int	kTotalDayLeap = 366;
// 각 월에 며칠이 있는지 저장하는 배열. 윤년일 땐 2월에 1일을 더해야 한다.
const int	kMonthDay[kTotalMonth]
{
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};
// 출력할 날짜 적어둔 배열
const char*	const kDate[kTotalDate]
{
	"월요일",
	"화요일",
	"수요일",
	"목요일",
	"금요일",
	"토요일",
	"일요일",
};
// 입력받은 년월일 저장하는 구조체
struct FYearMonthDay
{
	int	Year	= 0;
	int	Month	= 0;
	int	Day		= 0;
	void	print(void)
	{
		printf("%d년 %d월 %d일",
			this->Year,
			this->Month,
			this->Day);
	}
};

void	Homework01_Run(void);
// 년월일 입력받기
void	GetInput(FYearMonthDay& InYMD);
// 입력받은 년월일이 유효한지 확인하기
bool	IsCorrectYMDChecker(const FYearMonthDay& InYMD);
// 윤년 계산기
bool	IsLeapYearChecker(int InYear);
// 1년부터 입력받은 년도 전까지 총 날짜 계산
int		GetTotalDayUntilYear(int InYear);
// 1월부터 입력받은 월까지 총 날짜 계산
int		GetTotalDayUntilMonth(const FYearMonthDay& InYMD);
