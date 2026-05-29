#include "./Homework2.h"

void	Homework02_Run(void)
{
	FGamer		Player;
	FGamer		Dealer(false);
	FCardDeck	Deck();
}

void	PrintInit(void)
{
	printf("Black Jack=====================================\n\n");
	printf("목표\n");
	printf("	21점에 가까운 사람이 승리합니다.\n");
	printf("	21점을 초과하면 자동으로 패배합니다(버스트).\n");
	printf("카드의 점수\n");
	printf("	2~10은 카드 숫자가 점수입니다.\n");
	printf("	J, Q, K는 10점입니다.\n");
	printf("	A는 1점 또는 11점입니다.\n");
	printf("		21점 이하 중 가장 높은 점수가 자동선택됩니다.\n");
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
	std::getchar();
}

void	InitGame(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{
	std::system("cls");
	printf("카드를 섞는 중...\n");
	Sleep(200);
	CardDeck.Shuffle();
	Sleep(200);
	printf("카드를 분배하는 중...\n");
	Player.AddCard(CardDeck.Draw());
	Dealer.AddCard(CardDeck.Draw());
	Player.AddCard(CardDeck.Draw());
	Dealer.AddCard(CardDeck.Draw());
	printf("분배가 완료됐습니다!\n");
	printf("준비가 완료돼셨다면 엔터를 눌러주세요.\n");
	std::getchar();
}

void	GameLoop(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck)
{}

void	PrintPlayerDealerState(FGamer& Player, FGamer& Dealer)
{
	Player.Print();
	Dealer.Print();
}
