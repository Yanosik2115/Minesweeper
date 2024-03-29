#include "minesClass.h"
#include "MSBoardTextView.h"

MinesweeperBoard::MinesweeperBoard(const int &_width, const int &_height, GameMode mode)
{
  height = _height;
  width = _width;

  for (int column = 0; column < height; column++)
  {
    for (int row = 0; row < width; row++)
    {
      board[column][row].hasFlag = false;
      board[column][row].isRevealed = false;
      board[column][row].hasMine = false;
    }
  }

  setMinesOnBoard(mode);

  state = RUNNING;
}

MinesweeperBoard::MinesweeperBoard()
{
}

void MinesweeperBoard::setMinesOnBoard(GameMode mode)
{
  mines_on_field = 0;

  if (mode == EASY)
  {
    mines_on_field = width * height * 0.1;
  }
  else if (mode == NORMAL)
  {
    mines_on_field = width * height * 0.2;
  }
  else if (mode == HARD)
  {
    mines_on_field = width * height * 0.3;
  }

  for (int i = mines_on_field; i > 0; i--)
  {
    int _col = rand() % height + 1;
    int _row = rand() % width + 1;

    board[_col][_row].hasMine = 1;
  }

  if (mode == DEBUG)

  {
    mines_on_field = width * height * 0.5;

    for (int i = mines_on_field; i >= 0; i--)
    {
      int _col = rand() % height + 1;
      int _row = rand() % width + 1;

      board[_col][_row].hasMine = 1;
    }
  }
}

int MinesweeperBoard::getBoardWidth() const
{
  return width;
}
int MinesweeperBoard::getBoardHeight() const
{
  return height;
}
int MinesweeperBoard::getMineCount()
{
  mines_on_field = 0;

  for (int column = 0; column < height; column++)
  {
    for (int row = 0; row < width; row++)
    {
      if (board[column][row].hasMine == 1)
      {
        mines_on_field++;
      }
    }
  }

  return mines_on_field;
}

int MinesweeperBoard::countMines(int row, int col) const
{
  int num = 0;

  if (board[row - 1][col].hasMine == 1)
    num++;
  else if (board[row + 1][col].hasMine == 1)
    num++;
  else if (board[row][col + 1].hasMine == 1)
    num++;
  else if (board[row][col - 1].hasMine == 1)
    num++;
  else if (board[row + 1][col + 1].hasMine == 1)
    num++;
  else if (board[row + 1][col - 1].hasMine == 1)
    num++;
  else if (board[row - 1][col + 1].hasMine == 1)
    num++;
  else if (board[row - 1][col - 1].hasMine == 1)
    num++;

  return num;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
  if (board[col][row].hasFlag == 1)
  {
    return 1;
  }
  else
    return 0;
}
void MinesweeperBoard::toggleFlag(int row, int col)
{

  if (board[col][row].isRevealed == 0 && getGameState() == RUNNING)
  {
    board[col][row].hasFlag = 1;
  }
}

void MinesweeperBoard::revealField(int row, int col)
{
  if (board[col][row].hasFlag != 1 && getGameState() == RUNNING && board[col][row].isRevealed != 1 && board[row][col].hasMine == 0)
  {
    board[row][col].isRevealed = 1;
  }
  else if (board[col][row].hasFlag != 1 && getGameState() == RUNNING && board[col][row].isRevealed != 1 && board[row][col].hasMine == 1)
  {
    state = FINISHED_LOST;
  }
}

GameState MinesweeperBoard::getGameState() const
{

  return state;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
  if (board[row][col].hasFlag == 1 && board[row][col].isRevealed == 0)
  {
    return 'F';
  }
  else if (board[row][col].isRevealed == 0 && board[row][col].hasFlag == 0)
  {
    return '_';
  }
  else if (board[row][col].isRevealed == 1 && board[row][col].hasMine == 1)
  {
    return 'x';
  }
  else if (board[row][col].isRevealed == 1 && countMines(row, col) == '0')
  {
    return ' ';
  }
  else if (board[row][col].isRevealed == 1 && countMines(row, col) != '0')
  {
    return countMines(row, col);
  }
  else
    return 0;
}

void MinesweeperBoard::endGame() const //do dokonczenia
{
  
  if(state == FINISHED_LOST)
  {
    std::cout<<"You Lost :<"<<std::endl;
  }
  else if(state == FINISHED_WIN)
  {
    std::cout<<"You Won :>"<<std::endl;
  }
}

void MinesweeperBoard::debug_display() const
{

  for (int column = 0; column < height; column++)
  {
    for (int row = 0; row < width; row++)
    {
      std::cout << "[";
      if (board[column][row].hasMine)
        std::cout << "M";
      else
        std::cout << ".";
      if (board[column][row].isRevealed)
        std::cout << "o";
      else
        std::cout << ".";
      if (board[column][row].hasFlag)
        std::cout << "f";
      else
        std::cout << ".";
      std::cout << "]";
    }
    std::cout << std::endl;
  }
}
