#pragma once

#include "./ConstDefine.h"

struct FGamer
{
	int		CardDeck[kTotalCardDeckSize] = {0, };
	int		CardDeckSize = 0;
	bool	IsPlayer = true;
	bool	IsBurst = false;
	bool	IsStand = false;
	bool	IsBlacJack = false;
	int		ASize = 0;
	int		AScore = 0;
	int		Score = 0;

	FGamer()
	{ }
	FGamer(bool InIsPlayer)
		: IsPlayer(InIsPlayer)
	{ }
	void	Reset(void)
	{
		for (int CardCount = 0; CardCount < CardDeckSize; CardCount++)
		{
			CardDeck[CardCount] = 0;
		}
		CardDeckSize = 0;
		IsBurst = false;
		IsStand = false;
		IsBlacJack = false;
		ASize = 0;
		AScore = 0;
		Score = 0;
	}
	void	Print(void)
	{
		if (this->CardDeckSize)
		{
			if (IsPlayer)
			{
				printf("플레이어 현재 점수: [%d]\n", this->Score);
				printf("%s ", kCardDeck[CardDeck[0]]);
			}
			else
			{
				printf("딜러 현재 점수: [%d]\n", this->Score - kCardPoint[0]);
				printf("?? ");
			}
			for (int CardCount = 1; CardCount < CardDeckSize; CardCount++)
			{
				printf("%s ", kCardDeck[CardDeck[CardCount]]);
			}
			printf("\n");
		}
	}
	void	AddCard(int InCard)
	{
		this->CardDeck[CardDeckSize++] = InCard;
		this->Score += kCardPoint[InCard];
		if (!(InCard % kShapeCardSize))
		{
			this->ASize++;
		}
		this->Score -= this->AScore * kAScore;
		this->AScore = 0;
		while (this->ASize != this->AScore)
		{
			if (this->Score + kAScore > kBurstScore)
				break ;
			this->AScore++;
			this->Score += kAScore;
		}
		if (this->Score + kAScore <= kBurstScore)
		{
			this->IsBurst = false;
			if (this->CardDeckSize == 2)
			{
				IsBlacJack = true;
			}
		}
		else
		{
			this->IsBurst = true;
		}
	}
	void	SetIsStand(bool InVal)
	{
		this->IsStand = InVal;
	}
};
