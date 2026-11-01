
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameOver;

const int width = 20;
const int height = 15;

int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100];
int nTail;

enum eDirection
{
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

eDirection dir;

void setup()
{
    gameOver = false;
    dir = STOP;

    x = width / 2;
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

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool printTail = false;

                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        printTail = true;
                        break;
                    }
                }

                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }

        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";

    cout << "\nScore: " << score << endl;
    cout << "Controls: W A S D | X = Quit\n";
}

void input()
{
    if (_kbhit())
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
            if (dir != LEFT)
                dir = RIGHT;
            break;

        case 'w':
        case 'W':
            if (dir != DOWN)
                dir = UP;
            break;

        case 's':
        case 'S':
            if (dir != UP)
                dir = DOWN;
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
    if (nTail > 0)
    {
        for (int i = nTail - 1; i > 0; i--)
        {
            tailX[i] = tailX[i - 1];
            tailY[i] = tailY[i - 1];
        }

        tailX[0] = x;
        tailY[0] = y;
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

    // Wall collision
    if (x < 0 || x >= width ||
        y < 0 || y >= height)
    {
        gameOver = true;
        return;
    }

    // Tail collision
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            return;
        }
    }

    // Eat fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;

        if (nTail < 100)
        {
            tailX[nTail] = x;
            tailY[nTail] = y;
            nTail++;
        }

        // Place fruit away from the snake
        bool occupied;

        do
        {
            occupied = false;

            fruitX = rand() % width;
            fruitY = rand() % height;

            if (fruitX == x && fruitY == y)
                occupied = true;

            for (int i = 0; i < nTail; i++)
            {
                if (tailX[i] == fruitX &&
                    tailY[i] == fruitY)
                {
                    occupied = true;
                    break;
                }
            }

        } while (occupied);
    }
}

int main()
{
    setup();

    while (!gameOver)
    {
        Draw();
        input();
        Logic();
        Sleep(100);
    }

    cout << "\nGAME OVER!\n";
    cout << "Final Score: " << score << endl;

    system("pause");

    return 0;
}
