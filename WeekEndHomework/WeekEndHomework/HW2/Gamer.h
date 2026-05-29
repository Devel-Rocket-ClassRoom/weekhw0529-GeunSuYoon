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
	// 딜러로 세팅할 때 사용
	FGamer(bool InIsPlayer)
		: IsPlayer(InIsPlayer)
	{ }
	// 내부 요소들 초기화
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
	// 점수와 카드 내용 출력하는 함수
	void	Print(bool InIsGameEnd)
	{
		if (this->CardDeckSize)
		{
			if (IsPlayer)
			{
				printf("플레이어 현재 점수: [%d]\n", this->Score);
				printf("[%s] ", kCardDeck[CardDeck[0]]);
			}
			else
			{
				if (InIsGameEnd)
				{
					printf("딜러 현재 점수: [%d]\n", this->Score);
					printf("[%s] ", kCardDeck[CardDeck[0]]);
				}
				else
				{
					printf("딜러 현재 점수: [%d]\n", this->Score - kCardPoint[CardDeck[0]]);
					printf("[??] ");
				}
			}
			for (int CardCount = 1; CardCount < CardDeckSize; CardCount++)
			{
				printf("[%s] ", kCardDeck[CardDeck[CardCount]]);
			}
			printf("\n");
		}
	}
	// 카드 추가하는 함수
	void	AddCard(int InCard)
	{
		this->CardDeck[CardDeckSize++] = InCard;
		this->Score += kCardPoint[InCard];
		// 뽑은 카드가 에이스면 에이스 추가됐다고 말하기
		if (!(InCard % kShapeCardSize))
		{
			this->ASize++;
		}
		// 에이스 카드로 추가점수 얻었으면 추가점수 다 빼주기
		if (this->AScore)
		{
			this->Score -= this->AScore * kAScore;
			this->AScore = 0;
		}
		// 21점이 넘지 않는 선에서 에이스 추가점수 더하기
		while (this->AScore < this->ASize)
		{
			if (this->Score + kAScore > kBurstScore)
				break ;
			this->AScore++;
			this->Score += kAScore;
		}
		// 버스트 스코어 이하일 때
		if (this->Score <= kBurstScore)
		{
			// 블랙잭인 경우
			if (this->CardDeckSize == 2 && this->Score + kAScore == kBurstScore)
			{
				IsBlacJack = true;
			}
		}
		// 버스트일 때
		else
		{
			this->IsBurst = true;
		}
	}
	void	SetIsStand(bool InVal)
	{
		this->IsStand = InVal;
	}
	bool	GetIsBurst(void) const
	{
		return (this->IsBurst);
	}
	bool	GetIsStand(void) const
	{
		return (this->IsStand);
	}
	bool	GetIsBlacJack(void) const
	{
		return (this->IsBlacJack);
	}
	int	GetScore(void) const
	{
		return (this->Score);
	}
};
