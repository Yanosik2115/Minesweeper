#include <iostream>

#ifndef MINESBOARDMS_H__
#define MINESBOARDMS_H__

enum GameMode
{
  DEBUG,
  EASY,
  NORMAL,
  HARD
};

enum GameState
{
  RUNNING,
  FINISHED_WIN,
  FINISHED_LOST
};

struct Field
{
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard
{

  Field board[100][100];
  int width;
  int height;

public:
  
  MinesweeperBoard(const int &_width, const  int &_height, GameMode mode);
  MinesweeperBoard();
  GameState getGameState() const;

  void getMines(GameMode mode);

  int mines_on_field;

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount();

  int countMines(int row, int col) const;
  
  bool hasFlag(int row, int col) const;

  void toggleFlag(int row, int col);
 
  void revealField(int row, int col);

  char getFieldInfo(int row, int col) const;

  void debug_display() const;
};

#endif
