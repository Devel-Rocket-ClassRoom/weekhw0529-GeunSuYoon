#include "./Homework1.h"

//extern const const char*	kDate[kTotalDate];

void	Homework01_Run(void)
{
	FYearMonthDay	MyYMD;
	int				TotalDaySum = 0;

	GetInput(MyYMD);
	TotalDaySum += GetTotalDayUntilYear(MyYMD.Year);
	TotalDaySum += GetTotalDayUntilMonth(MyYMD);
	TotalDaySum += MyYMD.Day - 1;
	MyYMD.print();
	printf("은 %s입니다.\n", kDate[TotalDaySum % kTotalDate]);
}

void	GetInput(FYearMonthDay& InYMD)
{
	std::string	InputStr;

	printf("요일을 확인할 날짜를 입력해주세요.\n");
	while (true)
	{
		printf("입력 예시는 \"2026 5 29\"입니다: ");
		std::getline(std::cin, InputStr);
		size_t	YMDivider = InputStr.find(' ');
		if (!(YMDivider == std::string::npos))
		{
			size_t	MDDivider = InputStr.find(' ', YMDivider + 1);
			if (!(MDDivider == std::string::npos))
			{
				InYMD.Year = atoi(InputStr.substr(0, YMDivider).c_str());
				InYMD.Month = atoi(InputStr.substr(YMDivider, MDDivider).c_str());
				InYMD.Day = atoi(InputStr.substr(MDDivider).c_str());
				if (IsCorrectYMDChecker(InYMD))
					return ;
			}
		}
		printf("잘못 입럭하셨습니다\n");
	}
}

// 입력한 년월일이 유효한지 확인
bool	IsCorrectYMDChecker(const FYearMonthDay& InYMD)
{
	if (InYMD.Year > 0 // 년도 확인
		&& InYMD.Month > 0 && InYMD.Month < 13  // 월 확인
		&& InYMD.Day > 0 && InYMD.Day < 32) // 일 확인
	{
		//	2월 아니면 그냥 확인
		if (InYMD.Month != 2)
		{
			if (InYMD.Day <= kMonthDay[InYMD.Month - 1])
				return (true);
			return (false);
		}
		//	윤년 아니면 그냥 확인
		else if (!IsLeapYearChecker(InYMD.Year))
		{
			if (InYMD.Day <= kMonthDay[InYMD.Month - 1])
				return (true);
			return (false);
		}
		//	윤년이면 1 더해서 확인
		else
		{
			if (InYMD.Day <= kMonthDay[InYMD.Month - 1] + 1)
				return (true);
			return (false);
		}
	}
	return (false);
}

// 입력한 년도 전년까지 모든 날짜 더하기
int	GetTotalDayUntilYear(int InYear)
{
	int	ResultDay = 0;

	for (int YearCount = 1; YearCount < InYear; YearCount++)
	{
		if (!IsLeapYearChecker(YearCount))
		{
			ResultDay += kTotalDay;
		}
		else
		{
			ResultDay += kTotalDayLeap;
		}
	}
	return (ResultDay);
}

// 윤년 판별기
bool	IsLeapYearChecker(int InYear)
{
	const int	DivFour = 4;
	const int	DivHund = 100;
	const int	DivFourHund = 400;

	return (!(InYear % DivFour) // 4로 나눠떨어짐
		&& ((InYear % DivHund)	// 100으로 나눠떨어짐
			|| (!(InYear % DivHund)
				&& !(InYear % DivFourHund))	// 400으로 나눠떨어짐
			));
}

// 입력한 달 전까지 모든 달의 날짜 더하기
int	GetTotalDayUntilMonth(const FYearMonthDay& InYMD)
{
	int	ResultDay = 0;

	for (int MonthCount = 0; MonthCount < InYMD.Month - 1; MonthCount++)
	{
		ResultDay += kMonthDay[MonthCount];
	}
	return (ResultDay);
}
