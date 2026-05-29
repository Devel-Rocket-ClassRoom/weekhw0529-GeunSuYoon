#include "./Homework2.h"

void	Homework02_Run(void)
{
	FGamer		Player;
	FGamer		Dealer(false);
	FCardDeck	CardDeck;
	bool		IsContinue = true;

	PrintInit();
	while (IsContinue)
	{
		GameLoop(Player, Dealer, CardDeck);
		IsContinue = GetIsPlayerContinue();
	}
	printf("블랙잭 종료\n");
	return ;
}

void	PrintInit(void)
{
	std::string	InputString;
	printf("Black Jack=====================================\n\n");
	printf("목표\n");
	printf("	21점에 가까운 사람이 승리합니다.\n");
	printf("	21점을 초과하면 자동으로 패배합니다(버스트).\n");
	printf("카드의 점수\n");
	printf("	2~10은 카드 숫자가 점수입니다.\n");
	printf("	J, Q, K는 10점입니다.\n");
	printf("	A는 1점 또는 11점입니다.\n");
	printf("		21점 이하 중 가장 높은 점수가 자동선택됩니다.\n");
	printf("	딜러의 점수는 홀 카드를 제외한 점수입니다.\n");
	printf("게임 진행\n");
	printf("1. 게임 시작\n");
	printf("	플레이어와 딜러가 두 장의 카드를 각각 받습니다.\n");
	printf("	플레이어는 모든 카드를 공개합니다.\n");
	printf("	딜러는 한 장의 홀 카드를 제외한 모든 카드를 공개합니다.\n");
	printf("	플레이어가 먼저 진행합니다.\n");
	printf("2. 플레이어 턴\n");
	printf("	플레이어는 두 선택을 할 수 있습니다.\n");
	printf("	a. 히트\n");
	printf("		카드 한 장을 추가로 받습니다.\n");
	printf("	b. 스탠드\n");
	printf("		카드를 그만 받고 턴을 넘깁니다.\n");
	printf("	만일 버스트(21점 초과)가 되면 즉시 패배합니다.\n");
	printf("3. 딜러 턴\n");
	printf("	딜러는 점수가 17점 미만이면 계속 카드를 뽑습니다.\n");
	printf("	점수가 17점 이상이면 드로우를 멈춥니다.\n");
	printf("	만일 버스트(21점 초과)가 되면 즉시 패배합니다.\n\n");
	printf("잘 읽고 이해하셨으면 엔터를 눌러주세요.==============\n");
	std::getline(std::cin, InputString);
}

void	GameLoop(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{
	InitGame(Player, Dealer, CardDeck);
	PlayerTurn(Player, Dealer, CardDeck);
	if (!Player.GetIsBurst() && !Player.GetIsBlacJack())
	{
		DealerTurn(Player, Dealer, CardDeck);
	}
	GameEnd(Player, Dealer, CardDeck);
}

void	InitGame(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{
	std::string	InputString;
	std::system("cls");
	Player.Reset();
	Dealer.Reset();
	printf("카드를 섞는 중...\n");
	Sleep(200);
	CardDeck.Shuffle();
	//Sleep(200);
	printf("카드를 분배하는 중...\n");
	Player.AddCard(CardDeck.Draw());
	Dealer.AddCard(CardDeck.Draw());
	Player.AddCard(CardDeck.Draw());
	Dealer.AddCard(CardDeck.Draw());
	Sleep(200);
	printf("분배가 완료됐습니다!\n");
	printf("준비가 완료돼셨다면 엔터를 눌러주세요.\n");
	std::getline(std::cin, InputString);
}

void	PrintPlayerDealerState(FGamer& Player, FGamer& Dealer)
{
	std::system("cls");
	printf("======================================\n");
	Player.Print(false);
	printf("======================================\n");
	Dealer.Print(false);
	printf("======================================\n");
}

void	PrintPlayerDealerStateEnd(FGamer& Player, FGamer& Dealer)
{
	std::system("cls");
	printf("======================================\n");
	Player.Print(true);
	printf("======================================\n");
	Dealer.Print(true);
	printf("======================================\n");
}

void	PlayerTurn(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{
	while (!Player.GetIsStand() // 플레이어가 스탠드가 아님
		&& !Player.GetIsBurst() // 플레이어가 버스트가 아님
		&& Player.GetScore() < kBurstScore // 플레이어 점수가 21점 미만임
		&& !Player.GetIsBlacJack()) // 플레이어가 블랙잭이 아님
	{
		std::string	InputString;
		int			InputChecker = 0;
		PrintPlayerDealerState(Player, Dealer);
		COORD		NowCursorCoord = GetCurrentCursorPosition();
		printf("아래 번호에 맞춰 히트와 스탠드 중 하나를 골라주세요.\n");
		printf("1. 히트(카드 뽑기)\n");
		printf("2. 스탠드(카드 그만 뽑고 턴 넘기기)\n");
		std::getline(std::cin, InputString);
		InputChecker = atoi(InputString.c_str());
		while (InputChecker != 1 && InputChecker != 2)
		{
			SetCursorPosition(NowCursorCoord.X, NowCursorCoord.Y);
			printf("잘못 입력하셨습니다.                                \n");
			printf("아래 번호에 맞춰 히트와 스탠드 중 하나를 골라주세요.    \n");
			printf("1. 히트(카드 뽑기)                                 \n");
			printf("2. 스탠드(카드 그만 뽑고 턴 넘기기)                  \n");
			COORD		TempCursorCoord = GetCurrentCursorPosition();
			printf("                                                 \n");
			SetCursorPosition(TempCursorCoord.X, TempCursorCoord.Y);
			std::getline(std::cin, InputString);
			InputChecker = atoi(InputString.c_str());
		}
		if (InputChecker == 1)
		{
			printf("히트를 선택하셨습니다.\n");
			printf("카드를 한 장 뽑습니다.\n");
			Player.AddCard(CardDeck.Draw());
		}
		else
		{
			printf("스탠드를 선택하셨습니다.\n");
			printf("턴을 마칩니다.\n");
			Player.SetIsStand(true);
		}
	}
}

void	DealerTurn(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{
	while (Dealer.GetScore() < kDealerEndScore // 딜러가 17점 미만
		&& !Dealer.GetIsBurst() // 딜러가 버스트가 아님
		&& !Dealer.GetIsBlacJack()) // 딜러가 블랙잭이 아님
	{
		PrintPlayerDealerState(Player, Dealer);
		printf("딜러가 카드를 뽑습니다\n");
		Dealer.AddCard(CardDeck.Draw());
		Sleep(500);
	}
}

void	GameEnd(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{
	bool	IsPlayerWin = false;
	bool	IsDraw = false;
	PrintPlayerDealerStateEnd(Player, Dealer);
	if (Player.GetIsBlacJack())
	{
		if (Dealer.GetIsBlacJack())
		{
			IsDraw = true;
		}
		else
		{
			IsPlayerWin = true;
		}
	}
	else if (Player.GetIsBurst())
	{
		printf("플레이어가 버스트했습니다.\n");
		IsPlayerWin = false;
	}
	else if (Dealer.GetIsBurst())
	{
		printf("딜러가 버스트했습니다.\n");
		IsPlayerWin = true;
	}
	else if (Player.GetScore() > Dealer.GetScore())
	{
		IsPlayerWin = true;
	}
	else if (Player.GetScore() == Dealer.GetScore())
	{
		IsDraw = true;
	}
	if (IsDraw)
	{
		printf("비겼습니다.\n\n");
	}
	else if (IsPlayerWin)
	{
		printf("승리하셨습니다!\n\n");
	}
	else
	{
		printf("패배하셨습니다...\n\n");
	}
}

bool	GetIsPlayerContinue(void)
{
	std::string	InputString;
	COORD		NowCursorCoord = GetCurrentCursorPosition();

	printf("게임을 계속 하시겠습니까?\n");
	printf("계속 하시려면 Y를 입력해주세요.\n");
	printf("그만 하시려면 N을 입력해주세요.\n");
	std::getline(std::cin, InputString);
	while (InputString != "Y" && InputString != "y"
		&& InputString != "N" && InputString != "n")
	{
		SetCursorPosition(NowCursorCoord.X, NowCursorCoord.Y);
		printf("잘못 입력하셨습니다.                                \n");
		printf("게임을 계속 하시겠습니까?                            \n");
		printf("계속 하시려면 Y를 입력해주세요.                      \n");
		printf("그만 하시려면 N을 입력해주세요.                      \n");
		COORD		TempCursorCoord = GetCurrentCursorPosition();
		printf("                                                  \n");
		SetCursorPosition(TempCursorCoord.X, TempCursorCoord.Y);
		std::getline(std::cin, InputString);
	}
	if (InputString == "Y" || InputString == "y")
		return (true);
	return (false);
}
