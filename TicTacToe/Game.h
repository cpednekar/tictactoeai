#pragma once

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Constants.h"
#include "header.h"
#include "CFG.h"


class IGameState;

 
class Game
{
private:
	IGameState* m_gameState;
	Player* m_currentPlayer;
	GameTypes m_gameType;		//PvP or PvC
	
	int m_board[3][3];

	bool BoardFull();
	bool hasWon(Symbols symbol);
	bool MarkPosition(EventTypes* eventType);
	bool MarkPositionAI(Player* player);
	void GenerateMoves(std::list<Pos> &availableMoves);
	int EvaluatePosition();
	int MinMove(Pos& bestMove);
	int MaxMove(Pos& bestMove);
	Pos MiniMax(Player* player);

public:
	Game();
	~Game();
	
	void HandleInput(EventTypes* eventType);		//Not from IGameState interface
	void Update();									//Not from IGameState interface
	void Draw(SDL_Renderer* renderer);				//Not from IGameState interface

	void SetState(IGameState* state);
	void SetCurrentPlayer(Player* currPlayer);
	bool IsCurrentPlayer(Player* player);
	void SetGameType(GameTypes gameType);
	GameTypes* GetGameType();

	void ClearBoard();
	bool GameOver();
	bool TakeTurn(EventTypes* eventType);
	bool PositionEmpty(int row, int col);
	bool PositionMarkedX(int row, int col);
	bool PositionMarkedO(int row, int col);
	std::string GetGameOverMessage();

};


#endif