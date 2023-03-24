
#include <iostream>
#include <cstdlib>
#include <ctime>

bool compWin = false;

bool checkWin(char board[][3], bool& compWin)
{
    bool win = false;
    for (int i = 0; i <= 2; i++)
    {

        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            win = true;
            compWin = false;
        }
        else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            win = true;
            compWin = true;
        }
        else if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            win = true;
            compWin = false;
        }
        else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            win = true;
            compWin = true;
        }
    }

    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')  win = true;

    else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        win = true;
        compWin = false;
    }

    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')  win = true;
    else
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        {
            win = true;
            compWin = true;
        }
    return win;
}
void printBoard(char board[][3])       //This function prints the board.
{
    std::cout << std::endl;
    for (int row = 0; row <= 2; row++)
    {
        for (int col = 0; col <= 2; col++)
        {
            std::cout << board[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool checkTie(char board[][3])       //This function checks tie.
{

    int count = 0;
    for (int row = 0; row <= 2; row++)
    {
        for (int col = 0; col <= 2; col++)
        {
            if ((board[row][col] == 'O') || (board[row][col] == 'X'))  count++;
        }
    }
    if (count == 9) return true; else
        return false;
}

// Helper function to check if a row, column, or diagonal is a winning move
bool isWinningMove(char a, char b, char c, char player) {
    return (a == player && b == player && c == '-') ||
        (a == player && b == '-' && c == player) ||
        (a == '-' && b == player && c == player);
}

void nextMove(char board[][3], int& row, int& col)
{
    row = -1;
    col = -1;

        // Check if the computer can win in the next move

        for (int i = 0; i < 3; i++) {
            if (isWinningMove(board[i][0], board[i][1], board[i][2], 'X')) {
                row = i;
                col = (board[i][0] == '-') ? 0 : ((board[i][1] == '-') ? 1 : 2);
                return;
            }
            if (isWinningMove(board[0][i], board[1][i], board[2][i], 'X')) {
                row = (board[0][i] == '-') ? 0 : ((board[1][i] == '-') ? 1 : 2);
                col = i;
                return;
            }
        }
        if (isWinningMove(board[0][0], board[1][1], board[2][2], 'X')) {
            row = (board[0][0] == '-') ? 0 : ((board[1][1] == '-') ? 1 : 2);
            col = (board[0][0] == '-') ? 0 : ((board[1][1] == '-') ? 1 : 2);
            return;
        }
        if (isWinningMove(board[0][2], board[1][1], board[2][0], 'X')) {
            row = (board[0][2] == '-') ? 0 : ((board[1][1] == '-') ? 1 : 2);
            col = (board[0][2] == '-') ? 2 : ((board[1][1] == '-') ? 1 : 0);
            return;
        }

        // Check if the player can win in the next move

        for (int i = 0; i < 3; i++) {
            if (isWinningMove(board[i][0], board[i][1], board[i][2], 'O')) {
                row = i;
                col = (board[i][0] == '-') ? 0 : ((board[i][1] == '-') ? 1 : 2);
                return;
            }
            if (isWinningMove(board[0][i], board[1][i], board[2][i], 'O')) {
                row = (board[0][i] == '-') ? 0 : ((board[1][i] == '-') ? 1 : 2);
                col = i;
                return;
            }
        }
        if (isWinningMove(board[0][0], board[1][1], board[2][2], 'O')) {
            row = (board[0][0] == '-') ? 0 : ((board[1][1] == '-') ? 1 : 2);
            col = (board[0][0] == '-') ? 0 : ((board[1][1] == '-') ? 1 : 2);
            return;
        }
        if (isWinningMove(board[0][2], board[1][1], board[2][0], 'O')) {
            row = (board[0][2] == '-') ? 0 : ((board[1][1] == '-') ? 1 : 2);
            col = (board[0][2] == '-') ? 2 : ((board[1][1] == '-') ? 1 : 0);
            return;
        }

        if (row == -1 && col == -1)
        {
            int repeat = 1;     //inputs random spot if none of the above are found
            while (repeat == 1)
            {
                row = rand() % 3;
                col = rand() % 3;
                if (board[row][col] = '-' && board[row][col] != 'O')
                {
                    repeat = 0;
                }
            }
            return;
        }

        board[row][col] = 'X';
        return;
}

int main()
{
    srand((unsigned int)time(NULL));
    char keepPlaying;

    do              //The do while loop continues until the player does not want to play anymore.
    {
        char board[3][3] = { {'O','-','-'},{'-','-','-'},{'-','-','-'} };

        while (true)      //This while loop continues until the player or computer wins.
        {
            int rowO, colO, repeat; //Computer play


            printBoard(board);  //This calls the printBoard function using call by value.

            if (checkWin(board, compWin)) //The if statement checks if the computer won and breaks out
            {
                std::cout << "computer wins \n ";
                break;
            };
            if (checkTie(board))
            {
                std::cout << "There is a tie \n";
                break;
            };

            //This section prompts the user to input a row and column to place and O.
            {
                repeat = 1;
                while (repeat == 1) //check legal inputs
                {
                    std::cout << "What row (0, 1, or 2) would you like to place your X in?" << std::endl;
                    std::cin >> rowO;
                    std::cout << "What column (0, 1, or 2) would you like to place your X in?" << std::endl;
                    std::cin >> colO;
                    if (board[rowO][colO] == 'X')
                    {
                        repeat = 1;
                        std::cout << "That spot is already taken. Please choose another row and column."
                            << std::endl;
                    }
                    else if (board[rowO][colO] == 'O')
                    {
                        repeat = 1;
                        std::cout << "That spot is already taken. Please choose another row and column."
                            << std::endl;
                    }
                    else if (rowO > 2 || colO > 2 || rowO < 0 || colO < 0)
                    {
                        repeat = 1;
                        std::cout << "You must choose either 0, 1, or 2. Please enter another row and column." << std::endl;

                    }
                    else
                        repeat = 0;
                } //end of lgal input check

                board[rowO][colO] = 'X';    //This places an O in the correct stop.
                int airow = 0;
                int aicol = 0;
                printBoard(board);
                nextMove(board, airow, aicol);
                board[airow][aicol] = 'O';

                if (checkWin(board, compWin)) {
                    printBoard(board);
                    if (!compWin)
                    {
                        std::cout << "You win " << std::endl;          //This checks if the player has won.
                        break;
                    }
                    else
                    {
                        std::cout << "You lost " << std::endl;          //This checks if the computer has won.
                        break;
                    }
                }
                if (checkTie(board)) {
                    std::cout << "There is a tie " << std::endl;
                    break;
                }
            } //end of user play
        } //end of while(true)

        std::cout << "Do you want to play again? (Y/N)?" << std::endl;;
        std::cin >> keepPlaying;

    } while (keepPlaying == 'Y');

    return 0;
}