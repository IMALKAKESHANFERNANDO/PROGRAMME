#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameOver;
const int width =20;
const int height =15;

int x,y;
int fruitX ,fruitY;
int score;

int tailx[100],tailY[100];
int nTail;

enum Direction {STOP = 0,LEFT,RIGHT, UP, DOWN };
Direction dir;

void setup()
{
    gameOver =false;
    dir = STOP;

    x = width /2;
    y = height / 2;

    srand((unsigned)time(0));

    fruitX = rand() % width;
    fruitY = rand() % height;

    score = 0;
    nTail = 0;

}

void Draw()
{
  system("cls");

  for(int i = 0; i < width + 2; i++)
    cout << "#";
   cout << endl;
   
   for(int i = 0; i < height ; i++)
   {
     for(int j = 0; j < width; i++)
     {
        if (j == 0)
           cout << "#";

        if (i == y && j == x )

            cout << "0";

        else if (i == fruitY && j == fruitX)
        
             cout << "*";
           
        else
           { 
            bool printTail = false;
            
             for(int k = 0; k < nTail; k++)
             {
                 if (tailx[k] == j && tailY[k] == i)
                 {
                    cout << "0";
                    printTail = true;
                    break;
                 }  
             
             }    
        
             if(!printTail)
             cout << "" ;
           }

          if (j == width -1)
            cout << "#";

         
     }    
       
      
     cout << endl;


    }


    for (int i = 0; i < width + 2; i++)
        cout << "#";

    cout << "\nScore: " << score << endl;
    cout << "controls: W A S C D | X = Quit \n ";

} 

 void Input ()
 {
  if(_kbhit())
  {
    
    switch (_getch())
    {
    case 'a':
    case 'A':
      if (dir != RIGHT)
          dir = LEFT;

       break;

     case 'd':
     case 'D':
     
       if (dir != RIGHT)
          dir = RIGHT;
       break;

     case 'w':
     case 'W':
      if (dir != DOWN)
          dir = UP;
       break;

     case 's':
     case 'S':
       if (dir != DOWN)
          dir = UP;
       break;
        
    case 'x':
     case 'X':
       gameOver = true;
        
       break;


 
    }
  }

}

void Logic()
{
    int prevX = tailx [0];
    int prevY = tailY [0];

    int prev2X, prev2Y;

    tailx[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailx[i];
        prev2Y = tailY[i];

        tailx[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    if (x < 0 || x >= width ||
        y < 0 || y >= height)
    {
        gameOver = true;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailx[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;

        if (nTail < 100)
            nTail++;

        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }

    cout << "\nGAME OVER!\n";
    cout << "Final Score: " << score << endl;

    system("pause");
    return 0;
}