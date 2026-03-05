#include <iostream>

using namespace std;

int r, c;
int sx, sy;
char m[50][50];
bool been[50][50];
bool yes = false;
int goal[50][50];

inline void can_goal()
{
}

inline void yes_s()
{
}

inline void no_t()
{
}

inline void move(int x, int y)
{
    switch (m[y][x])
    {
    case 'S':
    {
        if (been[y + 1][x] == false)
        {
            been[y + 1][x] = true;
            move(x, y + 1);
            been[y + 1][x] = false;
        }
        else if (been[y - 1][x] == false)
        {
            been[y - 1][x] = true;
            move(x, y - 1);
            been[y - 1][x] = false;
        }
        else if (been[y][x + 1] == false)
        {
            been[y][x + 1] = true;
            move(x + 1, y);
            been[y][x + 1] = false;
        }
        else if (been[y][x - 1] == false)
        {
            been[y][x - 1] = true;
            move(x - 1, y);
            been[y][x - 1] = false;
        }
        else
        {
            return;
        }
    }
    case '+':
    {
        if (been[y + 1][x] == false)
        {
            been[y + 1][x] = true;
            move(x, y + 1);
            been[y + 1][x] = false;
        }
        else if (been[y - 1][x] == false)
        {
            been[y - 1][x] = true;
            move(x, y - 1);
            been[y - 1][x] = false;
        }
        else if (been[y][x + 1] == false)
        {
            been[y][x + 1] = true;
            move(x + 1, y);
            been[y][x + 1] = false;
        }
        else if (been[y][x - 1] == false)
        {
            been[y][x - 1] = true;
            move(x - 1, y);
            been[y][x - 1] = false;
        }
        else
        {
            return;
        }
    }
    case 'T':
    {
        yes = true;
        if (been[y + 1][x] == false)
        {
            been[y + 1][x] = true;
            move(x, y + 1);
            been[y + 1][x] = false;
        }
        else if (been[y - 1][x] == false)
        {
            been[y - 1][x] = true;
            move(x, y - 1);
            been[y - 1][x] = false;
        }
        else if (been[y][x + 1] == false)
        {
            been[y][x + 1] = true;
            move(x + 1, y);
            been[y][x + 1] = false;
        }
        else if (been[y][x - 1] == false)
        {
            been[y][x - 1] = true;
            move(x - 1, y);
            been[y][x - 1] = false;
        }
        else
        {
            return;
        }
    }
    case '-':
    {
        if (been[y][x + 1] == false)
        {
            been[y][x + 1] = true;
            move(x + 1, y);
            been[y][x + 1] = false;
        }
        else if (been[y][x - 1] == false)
        {
            been[y][x - 1] = true;
            move(x - 1, y);
            been[y][x - 1] = false;
        }
        else
        {
            return;
        }
    }
    case '|':
    {
        if (been[y + 1][x] == false)
        {
            been[y + 1][x] = true;
            move(x, y + 1);
            been[y + 1][x] = false;
        }
        else if (been[y - 1][x] == false)
        {
            been[y - 1][x] = true;
            move(x, y - 1);
            been[y - 1][x] = false;
        }
        else
        {
            return;
        }
    }
    case '.':
    {
        if (been[y - 1][x] == false)
        {
            been[y - 1][x] = true;
            move(x, y - 1);
            been[y - 1][x] = false;
        }
        else
        {
            return;
        }
    }
    case '#':
    {
        return;
    }
    }
}

int main()
{
    cin >> r;
    cin >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            been[i][j] = false;

            cin >> m[i][j];
            if (m[i][j] == 'S')
            {
                sx = j;
                sy = i;
            }
            else if (m[i][j] == '#')
            {
                been[i][j] = true;
            }
        }
    }
    move(sx, sy);
    if (yes)
    {
        ;
    }
    else
    {
        cout << "I'm stuck!";
    }
}