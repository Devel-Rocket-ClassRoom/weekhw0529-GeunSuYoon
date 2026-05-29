#pragma once

#include <iostream>
#include <time.h>
#include <windows.h>
#include "./ConstDefine.h"
#include "./CardDeck.h"
#include "./Gamer.h"

void	Homework02_Run(void);
void	PrintInit(void);
void	InitGame(FGamer& Player, FGamer &Dealer, FCardDeck& CardDeck);
void	GameLoop(FGamer& Player, FGamer &Dealer, FCardDeck& CardDeck);
void	PrintPlayerDealerState(FGamer& Player, FGamer& Dealer);