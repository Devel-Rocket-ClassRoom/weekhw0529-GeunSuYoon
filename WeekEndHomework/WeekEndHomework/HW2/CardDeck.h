#pragma once

#include <iostream>
#include "./ConstDefine.h"

struct FCardDeck
{
	// 카드 덱
	int	Cards[kTotalCardDeckSize];
	// 드로우할 때 어떤 카드 줄지 선택하는 피봇
	int	CardPoint = 0;
	FCardDeck()
	{
		for (int CardCount = 0; CardCount < kTotalCardDeckSize; CardCount++)
		{
			this->Cards[CardCount] = CardCount;
		}
	}
	// 피셔-예이츠 셔플
	void	Shuffle(void)
	{
		for (int CardCount = 1; CardCount < kTotalCardDeckSize; CardCount++)
		{
			int	RandomIdx = rand() % (kTotalCardDeckSize - CardCount);
			int	TmpVal = this->Cards[kTotalCardDeckSize - CardCount];

			this->Cards[kTotalCardDeckSize - CardCount] = this->Cards[RandomIdx];
			this->Cards[RandomIdx] = TmpVal;
		}
		// 셔플할 때는 게임 시작할 때 밖에 없으므로 피봇 초기화
		CardPoint = 0;
	}
	// 카드 주기
	int	Draw(void)
	{
		return (Cards[CardPoint++]);
	}
};
