#include "Game.h"
#include "MainMenuState.h"
#include "IGameState.h"

Game::Game()
{
	//set initial state
	m_gameState = CFG::stateMainMenu;
}

Game::~Game()
{
	delete m_gameState;
	delete m_currentPlayer;

	m_gameState = NULL;
	m_currentPlayer = NULL;
}

void Game::HandleInput(EventTypes* eventType)
{
	m_gameState->HandleInput(this, eventType);
}

void Game::Update()
{}

void Game::Draw(SDL_Renderer* renderer)
{
	m_gameState->Draw(renderer);
}

void Game::SetState(IGameState* state_)
{
	m_gameState = state_;
	m_gameState->Enter(this);
}

void Game::SetCurrentPlayer(Player* currPlayer)
{
	m_currentPlayer = currPlayer;
}

bool Game::IsCurrentPlayer(Player* player)
{
	return (m_currentPlayer == player);
}

void Game::SetGameType(GameTypes gameType)
{
	m_gameType = gameType;
}

GameTypes* Game::GetGameType()
{
	return &m_gameType;
}

void Game::ClearBoard()
{
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			m_board[i][j] = Symbol_EmptySpace;
		}
	}
}

bool Game::GameOver()
{
	return ( BoardFull() || hasWon(Symbol_X) || hasWon(Symbol_O) );
}

bool Game::BoardFull()
{
	bool boardFull = true;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(m_board[i][j] == Symbol_EmptySpace){
				boardFull = false;
				break;
			}
		}
	}

	return boardFull;
}

bool Game::hasWon(Symbols symbol)
{
	//bool won = false;

	//Check for rows
	for(int i = 0; i < 3; i++){
		if( (m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2]) && (m_board[i][0] == symbol) ){
			return true;
			//won = true;
			//break;
		}
	}

	//Check for columns
	for(int i = 0; i < 3; i++){
		if( (m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i]) && (m_board[0][i] == symbol) ){
			return true;
			//won = true;
			//break;
		}
	}

	//Check for diagonals
	if( (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]) && (m_board[0][0] == symbol) ){
		return true;
		//won = true;
	}
	if( (m_board[2][0] == m_board[1][1] && m_board[1][1] == m_board[0][2]) && (m_board[2][0] == symbol) ){
		return true;
		//won = true;
	}

	return false;
	//return won;
}



bool Game::TakeTurn(EventTypes* eventType)
{
	bool turnTaken = false;

	switch(m_gameType)
	{
		case GameType_PlayerVsPlayer:
			turnTaken = MarkPosition(eventType);
			break;
		case GameType_PlayerVsComputer:
			if(m_currentPlayer == CFG::playerOne){
				turnTaken = MarkPosition(eventType);
			}
			else{
				turnTaken = MarkPositionAI(CFG::playerTwo);
			}
			break;
	}

	return turnTaken;
}


bool Game::MarkPosition(EventTypes* eventType)
{
	bool marked = false;
	Symbols currPlayerSymbol = *(m_currentPlayer->GetSymbol());
	
	switch(*eventType)
	{
		case EventType_KeyPad_1:
			if( PositionEmpty(2, 0) ){
				m_board[2][0] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_2:
			if( PositionEmpty(2, 1) ){
				m_board[2][1] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_3:
			if( PositionEmpty(2, 2) ){
				m_board[2][2] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_4:
			if( PositionEmpty(1, 0) ){
				m_board[1][0] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_5:
			if( PositionEmpty(1, 1) ){
				m_board[1][1] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_6:
			if( PositionEmpty(1, 2) ){
				m_board[1][2] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_7:
			if( PositionEmpty(0, 0) ){
				m_board[0][0] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_8:
			if( PositionEmpty(0, 1) ){
				m_board[0][1] = currPlayerSymbol;
				marked = true;
			}
			break;
		case EventType_KeyPad_9:
			if( PositionEmpty(0, 2) ){
				m_board[0][2] = currPlayerSymbol;
				marked = true;
			}
			break;
		default:
			break;
	}

	return marked;
}


int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

bool Game::MarkPositionAI(Player *player)
{
	bool marked = false;
	Pos bestPos = MiniMax(player);
	if(!(bestPos.x == -1 && bestPos.y == -1))
	{
		m_board[bestPos.x][bestPos.y] = *(player->GetSymbol());
		marked = true;
	}
	return marked;
}


void Game::GenerateMoves(std::list<Pos> &availableMoves)
{
	Pos move;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if( PositionEmpty(i, j) ){
				move.x = i;
				move.y = j;
				availableMoves.push_back(move);
			}
		}
	}
}

int Game::EvaluatePosition()
{	
	if(GameOver())
	{
		Symbols symPlayerOne = *(CFG::playerOne->GetSymbol());
		Symbols symPlayerTwo = *(CFG::playerTwo->GetSymbol());

		if( hasWon( symPlayerOne ) ){	return +CFG::infinity;	}				//Player 1 Won
		else if( hasWon( symPlayerTwo ) ){	return -CFG::infinity;	}			//Player 1 Lost
		else {		return 0;	}												//Draw
	}

	return -1;
}

int Game::MinMove(Pos& bestMove)
{
	int pos_val = EvaluatePosition();
	if(pos_val != -1){
		return pos_val;
	}

	int bestScore = +CFG::infinity;
	std::list<Pos> movesList;
	GenerateMoves(movesList);

	int i = 0, j = 0;
	while(!movesList.empty())
	{
		i = movesList.front().x;
		j = movesList.front().y;
		m_board[i][j] = *(CFG::playerTwo->GetSymbol());			//playerTwo is Minimizing Player
		Pos opponentsBestMove;
		int score = MaxMove(opponentsBestMove);
		if(score < bestScore)
		{
			bestScore = score;
			bestMove = movesList.front();
		}
		m_board[i][j] = Symbol_EmptySpace;
		movesList.pop_front();
	}

	return bestScore;
}

int Game::MaxMove(Pos& bestMove)
{
	int pos_val = EvaluatePosition();
	if(pos_val != -1){
		return pos_val;
	}

	int bestScore = -CFG::infinity;
	std::list<Pos> movesList;
	GenerateMoves(movesList);

	int i = 0, j = 0;
	while(!movesList.empty())
	{
		i = movesList.front().x;
		j = movesList.front().y;
		m_board[i][j] = *(CFG::playerOne->GetSymbol());			//playerOne is Maximizing Player
		Pos opponentsBestMove;
		int score = MinMove(opponentsBestMove);
		if(score > bestScore)
		{
			bestScore = score;
			bestMove = movesList.front();
		}
		m_board[i][j] = Symbol_EmptySpace;
		movesList.pop_front();
	}

	return bestScore;
}

Pos Game::MiniMax(Player* player)
{
	Pos bestMove;
	bestMove.x = -1;
	bestMove.y = -1;

	int i = 0;
	if(player == CFG::playerOne)
	{
		i = MaxMove(bestMove);				//playerOne is Maximizing Player
	}
	else if(player == CFG::playerTwo)
	{
		i = MinMove(bestMove);				//playerTwo is Minimizing Player
	}

	return bestMove;
}



bool Game::PositionEmpty(int row, int col)
{
	return (m_board[row][col] == Symbol_EmptySpace);
}

bool Game::PositionMarkedX(int row, int col)
{
	return (m_board[row][col] == Symbol_X);
}

bool Game::PositionMarkedO(int row, int col)
{
	return (m_board[row][col] == Symbol_O);
}

std::string Game::GetGameOverMessage()
{
	std::string sMessage = "";

	bool bPlayerOneWon = hasWon(*(CFG::playerOne->GetSymbol()));
	bool bPlayerTwoWon = hasWon(*(CFG::playerTwo->GetSymbol()));

	std::string sWinningSymbol = ( hasWon(Symbol_X) ? "X" : ((hasWon(Symbol_O)) ? "O" : "") );
	std::string sWinningPlayer = ( (bPlayerOneWon) ? "PLAYER ONE" : ((bPlayerTwoWon) ? "PLAYER TWO" : "") );

	if(sWinningPlayer == "" && sWinningSymbol == "")
	{
		sMessage = "GAME DRAWN!";
	}
	else
	{
		sMessage = sWinningPlayer + " " + "<" + sWinningSymbol + ">" + " " + "WINS";
	}

	return sMessage;
}