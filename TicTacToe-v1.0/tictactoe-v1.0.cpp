/**
 Kent State University
 CS 33901 Software Engineering
 Fall 2017
 Project #1
 Simple Tic Tac Toe
 tictactoe-v0.9.cpp
 Source: http://paste4btc.com/enVArEWu
 Author #1: NVitanovic, https://www.youtube.com/user/NVitanovic
 Author #2: Adeeb
*/


#include <iostream>
#include <time.h>
#include "tictactoe-v1.0.hpp"

using namespace std;


    
void Board::resetBoard(){
    int BoardNumbers = 1;
    for ( int i = 0; i < 3; i++ ){
	for (int j = 0; j < 3; j++ ){
	    board[i][j] = '0' + BoardNumbers++;

	  }
    }
}
    
void Board::PrintBoard(){
    cout << string( 100, '\n' );
    cout << "TicTacToe v1.0" << endl;
   
    for (int i = 0; i < 3; i++){
	for (int j = 0; j < 3; j++){
	    cout << board[i][j] << " ";
	  }
	cout << endl;
      }
      
      cout << "Player X: " <<  xwinsCounter << "      Ties: " << ties << "      Player O: " << owinsCounter <<endl;
  }
    
    
void Player::PlayerVsPlayerMove(char player, char playerMove){
    char playerTurn;
    bool playerMoveExisted = false;
    
    if(player == 'X'){
	playerTurn = 'X';
      }else{
	playerTurn = 'O';
      }
 
    while(playerMoveExisted == false && moveCounter != 9){
	for (int i = 0; i < 3; i++){
	    for (int j = 0; j < 3; j++){
                if(playerMove == board[i][j]){
                    board[i][j] = player;
                    
                    playerMoveExisted = true;
                   moveCounter++;
		  }
	      }
	  }
          if (playerMove == 'q'){
              cout << "Exit \n";
              exit(1);
          }
	if(playerMoveExisted == false){
	    std::cout << "Invalid. Choose another number \n" << std::endl;
	    std::cout << "Player " << playerTurn << " turn \n" << std::endl;
	    cin >> playerMove;
	  }
      }
  }

    
    
void Player::PlayerVsMachineMove(char player, char playerMove){
        char playerTurn;
        bool playerMoveExisted = false;
    
    
        if(player == 'X'){
            playerTurn = 'X';
        }
        else{
            playerTurn = 'O';
        }
        
        
        
        while(playerMoveExisted == false && moveCounter != 9){
            std::cout << "Player " << playerTurn << " turn \n" << std::endl;
            if (playerTurn == 'O'){
                playerMove = RandomPick();
                
            }if (playerTurn == 'X') {
                cin >> playerMove;
            }
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if(playerMove == board[i][j]){
                        board[i][j] = player;
                        
                        playerMoveExisted = true;
                        moveCounter++;
                    }
                }
            }
            
            if (playerMove == 'q'){
                cout << "Exit \n";
                exit(1);
                
            }
            if(playerMoveExisted == false){
                std::cout << "Invalid. Choose another number \n" << std::endl;
                if (playerTurn == 'O'){
                    playerMove = RandomPick();
                    cout << playerMove;
                    
                }
            }
        }
    }
    
    
char Player::RandomPick() {
        
    return Random[rand() % 9];
  }
    

void Board::MarkBoard(char num, char player){
    if (num == 1)
      board[0][0] = player;
    else if (num == 2)
      board[0][1] = player;
    else if (num == 3)
      board[0][2] = player;
    else if (num == 4)
      board[1][0] = player;
    else if (num == 5)
      board[1][1] = player;
    else if (num == 6)
      board[1][2] = player;
    else if (num == 7)
      board[2][0] = player;
    else if (num == 8)
      board[2][1] = player;
    else if (num == 9)
      board[2][2] = player;
        
        
  }
    
bool GameResult::CheckResult(bool gameOver){
    
    if (GameScore() == 'X'){
	++xwinsCounter;
	cout << "X wins!" << endl;
          cout << "Player X: " <<  xwinsCounter << "      Ties: " << ties << "      Player O: " << owinsCounter <<endl;
	gameOver = true;
	if (xwinsCounter == 3){
	  cout << "Player X you win $300K cash! \n";
	}
	if (xwinsCounter == 6){
	  cout << "Player X you win $600K cash! \n";
	}
	if (xwinsCounter == 9){
	  cout << "Player X you win $900K cash! \n";
	}
	if (xwinsCounter == 10){
	  cout << "Player X you win $1M cash! \n";
	  exit(1);
	}
	moveCounter = 0;
	owinsCounter = 0;
	ties = 0;
      }
    else if (GameScore() == 'O')
      {
	++owinsCounter;
	cout << "O wins!" << endl;
          cout << "Player X: " <<  xwinsCounter << "      Ties: " << ties << "      Player O: " << owinsCounter <<endl;
	gameOver = true;
	moveCounter = 0;
	if (owinsCounter == 3){
	  cout << "Player O you win $300K cash! \n";
	}
	if (owinsCounter == 6){
	  cout << "Player O you win $600K cash! \n";
	}
	if (owinsCounter == 9){
	  cout << "Player O you win $900K cash! \n";
	}
	if (owinsCounter == 10){
	  cout << "Player O you win $1M cash! \n";
	  exit(1);
	}
	xwinsCounter = 0;
	ties = 0;
      }
    else if (moveCounter == 9 ){
      cout << "No one wins!" << endl;
      gameOver = true;
      moveCounter = 0;
      ++ties;
      xwinsCounter = 0;
      owinsCounter = 0;
    }
        
    return gameOver;
  }
    
    
bool GameMenu::Menu(int num, bool gameOver){
    
    Board number;
    
    cout << "Choose a number \n" ;
    cout << "[1] Continue \n" ;
    cout << "[2] Play Again \n" ;
    cout << "[3] Quit \n";
    cin >> num;
    if(num == 1){
      number.resetBoard();
      //break;
      gameOver = false;
    }
    if (num == 2){
      gameOver = false;
      xwinsCounter = 0;
      owinsCounter = 0;
    }
    if (num == 3){
      cout << "Exit the game \n";
      gameOver = true;
    }
    else{
      cout << "Invalid \n";
    }
        
    return gameOver;
  }

char GameResult::GameScore() {
    //first player
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
      return 'X';
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
      return 'X';
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
      return 'X';
        
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
      return 'X';
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
      return 'X';
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
      return 'X';
        
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
      return 'X';
    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
      return 'X';
        
    //second player
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
      return 'O';
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
      return 'O';
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
      return 'O';
        
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
      return 'O';
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
      return 'O';
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
      return 'O';
        
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
      return 'O';
    if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
      return 'O';
        
    return '/';
  }
    
    
    
void GameMenu::MainMenu(){
    char num = '0';
    Board call;
    Player call1;
    GameResult call2;
    bool win = false;
    bool gameOver = false;
    char player = 'X';
      
  again:
    cout << "[1] P vs P \n";
    cout << "[2] P vs M \n";
    cin >> num;


        
    switch (num) {
    case '1':
                
      while (1) {
                    
	call.PrintBoard();
	call.MarkBoard(num, player);
	std::cout << "Player " << player << " turn \n" << std::endl;
	cin >> num;
	call1.PlayerVsPlayerMove(player, num);
	call2.GameScore();
	call.PrintBoard();
                    
	win = call2.CheckResult(win);
	if (win == true)
	  {
	    win = false;
	    call.resetBoard();
	    if (xwinsCounter == 3 || owinsCounter == 3 || xwinsCounter == 6 || owinsCounter == 6 || xwinsCounter == 9 || owinsCounter == 9 || xwinsCounter == 10 || owinsCounter == 10){
	      gameOver = Menu(num, win);
	      if (gameOver == true){
		break;
	      }
	    }
	  }
                    
	if (player == 'X'){
	  player = 'O';
	} else{
	  player = 'X';
	}
      }
      break;
    case '2':
      while (1) {
                   
	call.PrintBoard();
	call.MarkBoard(num, player);
	call1.PlayerVsMachineMove(player, num);
	call2.GameScore();
	call.PrintBoard();
                    
	win = call2.CheckResult(win);
          if (win == true){
              win = false;
              call.resetBoard();
             if (xwinsCounter == 3 || owinsCounter == 3 || xwinsCounter == 6 || owinsCounter == 6 || xwinsCounter == 9 || owinsCounter == 9 || xwinsCounter == 10 || owinsCounter == 10){
                  gameOver = Menu(num, win);
                  if (gameOver == true){
                      break;
                  }
              }
          }
          
          if (player == 'X'){
              player = 'O';
          } else{
              player = 'X';
          }
      }
      break;
    case 'q':
    cout << "Exit the game \n";
    exit(1);
    break;
            
    default:
            cout << "Try again \n";
    goto again;
    }
  }



char Player::playerTurn(char player){
   
    if (player == 'X'){
        player = 'O';
    } else{
        player = 'X';
    }
    return player;
}


int main(){
    
cout << "Press Q to Quit \n";
  GameMenu game;
  game.MainMenu();
    

  return 0;
}
