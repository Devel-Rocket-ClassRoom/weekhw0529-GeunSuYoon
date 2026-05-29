#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include "./ConstDefine.h"
#include "./CardDeck.h"
#include "./Gamer.h"
#include "./CoordUtil.h"

void	Homework02_Run(void);
void	PrintInit(void);
void	InitGame(FGamer& Player, FGamer &Dealer, FCardDeck& CardDeck);
void	GameLoop(FGamer& Player, FGamer &Dealer, FCardDeck& CardDeck);
void	PrintPlayerDealerState(FGamer& Player, FGamer& Dealer);
void	PrintPlayerDealerStateEnd(FGamer& Player, FGamer& Dealer);
void	PlayerTurn(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck);
void	DealerTurn(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck);
void	GameEnd(FGamer& Player, FGamer& Dealer, FCardDeck& CardDeck);
bool	GetIsPlayerContinue(void);
