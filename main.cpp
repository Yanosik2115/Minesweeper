#include <iostream>

struct Field
{

  bool Mina;
  bool Flaga;
  bool odkrytePole;

};

class Plansza
{

  Field board [100][100];
  int szerokosc;
  int wysokosc;
  // void ....();
  
public:
  

  Plansza(int szer, int wys);
  Plansza();
  
  void debug_display() const;
};

Plansza::Plansza()
{

}

Plansza::Plansza(int szer, int wys)
{
    szerokosc = szer;
    wysokosc = wys;

    for(int i = 0; i<wysokosc; i++)
    {
      for(int j = 0; i<szerokosc; i++)
      {
        board[i][j].Mina = false;
      }
    }

}

void debug_display()
{

}


int main() {
  std::cout << "Łukasz Waszczak, 259625";
}