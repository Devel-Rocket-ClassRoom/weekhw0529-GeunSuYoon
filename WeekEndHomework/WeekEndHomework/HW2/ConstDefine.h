#pragma once

// 총 카드 덱 사이즈
const int	kTotalCardDeckSize = 52;
// 색깔별 카드 개수
const int	kShapeCardSize = 13;
// 버스트 점수
const int	kBurstScore = 21;
// A일 때 더하고 뺄 점수
const int	kAScore = 10;

// 접두사로 S(스페이드) C(클로버) D(다이아몬드) H(하트)를 나눴다.
// 실제 카드는 숫자로 저장하고, 이 배열에서 해당 숫자를 넣어 출력할 예정이다.
const char* const	kCardDeck[kTotalCardDeckSize]
{
	"SA", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK",
	"CA", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK",
	"DA", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK",
	"HA", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK",
};
const int	kCardPoint[kTotalCardDeckSize] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
};
