#ifndef TICCLASS_H
#define TICCLASS_H

#include <string>

char board[3][3] = { {'1', '2','3'},{ '4','5', '6'}, {'7', '8', '9'}}; //two-dimensional arrays
int xwinsCounter = 0;
int owinsCounter = 0;
int ties = 0;
int moveCounter = 0;


class Board{
    
    
public:
    
    Board() {}
    
    void resetBoard();
    
    void PrintBoard();
    
    void MarkBoard(char num, char player);
    
private:
    
};


class Player{
public:
    
    Player() {};
    
    char playerTurn(char player);
    
    void PlayerVsPlayerMove(char player,  char playerMove);
    
    void PlayerVsMachineMove(char player, char playerMove);
    
    char RandomPick() ;
    
    
    
private:
    
    char Random [9] = {  '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
};


class GameMenu{
public:
    GameMenu(){};
    
    bool Menu(int num, bool gameOver);
    
    void MainMenu();

    
};



class GameResult{
    
public:
    
    bool CheckResult(bool gameOver);
    
    
    char GameScore();
    
    
};




#endif