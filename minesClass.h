#include <iostream>

#ifndef MINESBOARD_H__
#define MINESBOARD_H__

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
  int mines_on_field;

public:

  MinesweeperBoard(const int &_width, const  int &_height, GameMode mode);
  GameState getGameState(GameState state) const;

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  int countMines(int row, int col) const;
  
  bool hasFlag(int row, int col) const;

  void toggleFlag(int row, int col);
 
  void getMines();

  void revealField(int row, int col, GameState state);

  char getFieldInfo(int row, int col) const;

  void debug_display() const;
};

#endif
