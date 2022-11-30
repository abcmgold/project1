#include <bits/stdc++.h>
using namespace std;
#define N 8
int number_solved = 0;
void print(char arr[N][N])
{
    cout<<" _______________________________________________\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[0][0]<<"  |  "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  |  "<<arr[0][3]<<"  |  "<<arr[0][4]<<"  |  "<<arr[0][5]<<"  |  "<<arr[0][6]<<"  |  "<<arr[0][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[1][0]<<"  |  "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  |  "<<arr[1][3]<<"  |  "<<arr[1][4]<<"  |  "<<arr[1][5]<<"  |  "<<arr[1][6]<<"  |  "<<arr[1][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[2][0]<<"  |  "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  |  "<<arr[2][3]<<"  |  "<<arr[2][4]<<"  |  "<<arr[2][5]<<"  |  "<<arr[2][6]<<"  |  "<<arr[2][7]<<"  |\n";    
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[3][0]<<"  |  "<<arr[3][1]<<"  |  "<<arr[3][2]<<"  |  "<<arr[3][3]<<"  |  "<<arr[3][4]<<"  |  "<<arr[3][5]<<"  |  "<<arr[3][6]<<"  |  "<<arr[3][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[4][0]<<"  |  "<<arr[4][1]<<"  |  "<<arr[4][2]<<"  |  "<<arr[4][3]<<"  |  "<<arr[4][4]<<"  |  "<<arr[4][5]<<"  |  "<<arr[4][6]<<"  |  "<<arr[4][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[5][0]<<"  |  "<<arr[5][1]<<"  |  "<<arr[5][2]<<"  |  "<<arr[5][3]<<"  |  "<<arr[5][4]<<"  |  "<<arr[5][5]<<"  |  "<<arr[5][6]<<"  |  "<<arr[5][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[6][0]<<"  |  "<<arr[6][1]<<"  |  "<<arr[6][2]<<"  |  "<<arr[6][3]<<"  |  "<<arr[6][4]<<"  |  "<<arr[6][5]<<"  |  "<<arr[6][6]<<"  |  "<<arr[6][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout<<"|     |     |     |     |     |     |     |     |\n";
    cout<<"|  "<<arr[7][0]<<"  |  "<<arr[7][1]<<"  |  "<<arr[7][2]<<"  |  "<<arr[7][3]<<"  |  "<<arr[7][4]<<"  |  "<<arr[7][5]<<"  |  "<<arr[7][6]<<"  |  "<<arr[7][7]<<"  |\n";
    cout<<"|_____|_____|_____|_____|_____|_____|_____|_____|\n\n";
}

bool check_safe(char arr[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N)
    {
        for (int k = -N; k <= N; k++)
        {
            if (y + k >= 0 && y + k < N && arr[x][y + k] == 'Q')
            {
                return false;
            }

            if (y + k >= 0 && y + k < N && x + k >= 0 && x + k < N && arr[x + k][y + k] == 'Q')
            {
                return false;
            }

            if (y + k >= 0 && y + k < N && x - k >= 0 && x - k < N && arr[x - k][y + k] == 'Q')
            {
                return false;
            }

            if (y - k >= 0 && y - k < N && x + k >= 0 && x + k < N && arr[x + k][y - k] == 'Q')
            {
                return false;
            }

            if (y - k >= 0 && y - k < N && x - k >= 0 && x - k < N && arr[x - k][y - k] == 'Q')
            {
                return false;
            }
        }
    }   
    else
    {
        return false;
    }
    return true;
}

void solve(char arr[N][N], int col)
{
    if (col == N) {
        number_solved++;
        print(arr);
    }
    
    for (int i = 0; i < N; i++)
    {
        if (check_safe(arr, i, col))
        {
            arr[i][col] = 'Q';
            solve(arr, col + 1);
            arr[i][col] = ' ';
        }
    }
}

int main()
{
    char arr[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = ' ';
        }
    }
    solve(arr, 0);

    cout << number_solved;
}