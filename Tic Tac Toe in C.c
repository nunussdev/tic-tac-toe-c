#include <stdio.h>

#define MAX 100
#define EMPTY '-'
    
void initializeBoard(char board[MAX][MAX], int n);
void printBoard(char board[MAX][MAX], int n);
int isValidMove(char board[MAX][MAX], int n, int row, int col);
int checkWin(char board[MAX][MAX], int n, char player);
int checkLine(char board[MAX][MAX], int n, char player, int r1, int c1, int r2, int c2, int r3, int c3);
    
int main()
{
    char board[MAX][MAX];
    int n;
    int row, col;
    int xMoves = 0, oMoves = 0;
    int gameOver = 0;
    
    printf("Enter board size (5-100):\n");
    scanf("%d", &n);
    
    while (n < 5 || n > 100)
    {
        printf("Invalid board size. Enter board size (5-100):\n");
        scanf("%d", &n);
    }
    
    initializeBoard(board, n);
    
    printf("\nInitial Board:\n");
    printBoard(board, n);
    
    while (!gameOver && (xMoves < 10 || oMoves < 10))
    {
        if (xMoves < 10)
        {
            do
            {
                printf("\nPlayer X, enter coordinates (row col):\n");
                scanf("%d %d", &row, &col);

                if (!isValidMove(board, n, row, col))
                {
                    printf("Invalid move. Cell already occupied or out of range. Try again.\n");
                }

            } while (!isValidMove(board, n, row, col));

            board[row - 1][col - 1] = 'X';
            xMoves++;

            printBoard(board, n);

            if (checkWin(board, n, 'X'))
            {
                printf("\nPlayer X wins!\n");
                gameOver = 1;
                break;
            }
        }

        if (oMoves < 10)
        {
            do
            {
                printf("\nPlayer O, enter coordinates (row col):\n");
                scanf("%d %d", &row, &col);

                if (!isValidMove(board, n, row, col))
                {
                    printf("Invalid move. Cell already occupied or out of range. Try again.\n");
                }

            } while (!isValidMove(board, n, row, col));

            board[row - 1][col - 1] = 'O';
            oMoves++;

            printBoard(board, n);

            if (checkWin(board, n, 'O'))
            {
                printf("\nPlayer O wins!\n");
                gameOver = 1;
                break;
            }
        }
    }

    if (!gameOver)
    {
        printf("\nNo player wins. Game ended in a draw.\n");
    }

    return 0;
}

void initializeBoard(char board[MAX][MAX], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[MAX][MAX], int n)
{
    int i, j;

    printf("\n   ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d  ", i + 1);

        for (j = 0; j < n; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

int isValidMove(char board[MAX][MAX], int n, int row, int col)
{
    if (row < 1 || row > n || col < 1 || col > n)
    {
        return 0;
    }

    if (board[row - 1][col - 1] != EMPTY)
    {
        return 0;
    }

    return 1;
}

int checkWin(char board[MAX][MAX], int n, char player)
{
    int i, j, k;
    
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == player)
            {
                for (k = j + 1; k < n; k++)
                {
                    if (board[i][k] != EMPTY && board[i][k] != player)
                    {
                        break;
                    }

                    if (board[i][k] == player)
                    {
                        int m;

                        for (m = k + 1; m < n; m++)
                        {
                            if (board[i][m] != EMPTY && board[i][m] != player)
                            {
                                break;
                            }

                            if (board[i][m] == player)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (board[i][j] == player)
            {
                for (k = i + 1; k < n; k++)
                {
                    if (board[k][j] != EMPTY && board[k][j] != player)
                    {
                        break;
                    }

                    if (board[k][j] == player)
                    {
                        int m;

                        for (m = k + 1; m < n; m++)
                        {
                            if (board[m][j] != EMPTY && board[m][j] != player)
                            {
                                break;
                            }

                            if (board[m][j] == player)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == player)
            {
                int step;
                
                
                for (step = 1; i + step < n && j + step < n; step++)
                {
                    if (board[i + step][j + step] != EMPTY &&
                        board[i + step][j + step] != player)
                    {
                        break;
                    }

                    if (board[i + step][j + step] == player)
                    {
                        int step2;

                        for (step2 = step + 1; i + step2 < n && j + step2 < n; step2++)
                        {
                            if (board[i + step2][j + step2] != EMPTY &&
                                board[i + step2][j + step2] != player)
                            {
                                break;
                            }

                            if (board[i + step2][j + step2] == player)
                            {
                                return 1;
                            }
                        }
                    }
                }
                
                
                for (step = 1; i + step < n && j - step >= 0; step++)
                {
                    if (board[i + step][j - step] != EMPTY &&
                        board[i + step][j - step] != player)
                    {
                        break;
                    }

                    if (board[i + step][j - step] == player)
                    {
                        int step2;

                        for (step2 = step + 1; i + step2 < n && j - step2 >= 0; step2++)
                        {
                            if (board[i + step2][j - step2] != EMPTY &&
                                board[i + step2][j - step2] != player)
                            {
                                break;
                            }

                            if (board[i + step2][j - step2] == player)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}