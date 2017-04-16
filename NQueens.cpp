
#include<iostream>

using namespace std;

int board[8][8];
int counter = 0;

void setInitialBoard(int);
void nQueen(int, int, int);
bool checkPosition(int, int, int);
bool checkPosition(int, int);
bool checkLeft(int, int, int);
bool checkRight(int, int, int);
void clearRow(int, int);
void printBoard(int);

int main()
{
    int n;
    cout<<"Enter the board size (MIN 4|MAX 8) :";
    cin>>n;
    setInitialBoard(n);
    nQueen(0, 0, n);
    printBoard(n);
    return 0;
}

void setInitialBoard(int n)
{
    for(int i=0; i<n; i++)
        clearRow(i, n);
}

void nQueen(int row, int column, int n)
{

    if(row == n)
    {
        counter = 1;
        return;
    }
    if(column == n)
    {
        clearRow(row, column);
        return;
    }
    if(checkPosition(row, column, n) && checkPosition(row, column))
    {
        printBoard(n);
        clearRow(row, column);
        board[row][column] = 1;
        nQueen(row+1, 0, n);
    }
    if(counter == 1)
        return;

    nQueen(row, column+1, n);
}

bool checkPosition(int row, int column, int n)
{
    if(row<0 || column<0 || column>=n)
    {
        return true;
    }

    if(!board[row][column] && (checkLeft(row, column, n) && checkRight(row, column, n)))
    {
        return true;
    }

    return false;
}

bool checkLeft(int row, int column, int n)
{
    if(row<0 || column<0 || column>=n)
    {
        return true;
    }
    if(!board[row][column] && checkLeft(row-1, column-1, n))
        return true;
    return false;
}

bool checkRight(int row, int column, int n)
{
    if(row<0 || column<0 || column>=n)
    {
        return true;
    }
    if(!board[row][column] && checkRight(row-1, column+1, n))
        return true;
    return false;
}

bool checkPosition(int row, int column)
{
    for(int i=0; i<row; i++)
    {
        if(board[i][column])
            return false;
    }
    return true;
}

void clearRow(int row, int column)
{
    for(int i=0; i<column; i++)
        board[row][i] = 0;
}

void printBoard(int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
