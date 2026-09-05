#include <iostream>
using namespace std;

char board[3][3];

// Initialize board
void initializeBoard()
{
    char value = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value++;
        }
    }
}

// Display board
void displayBoard()
{
    cout << "\n\n";
    cout << "     TIC TAC TOE\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "     |     |     \n";
        cout << "  " << board[i][0]
             << "  |  " << board[i][1]
             << "  |  " << board[i][2] << "\n";

        if (i < 2)
            cout << "_____|_____|_____\n";
    }

    cout << "     |     |     \n";
}

// Check winner
bool checkWinner(char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

// Make player move
void makeMove(char player)
{
    int position;

    while (true)
    {
        cout << "\nPlayer " << player
             << ", enter position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9)
        {
            cout << "Invalid position! Choose 1 to 9.\n";
            continue;
        }

        int row = (position - 1) / 3;
        int column = (position - 1) % 3;

        if (board[row][column] == 'X' ||
            board[row][column] == 'O')
        {
            cout << "Position already taken! Try again.\n";
            continue;
        }

        board[row][column] = player;
        break;
    }
}

// Play game
void playGame()
{
    initializeBoard();

    char player = 'X';

    while (true)
    {
        displayBoard();

        makeMove(player);

        if (checkWinner(player))
        {
            displayBoard();

            cout << "\nPlayer " << player
                 << " wins!\n";

            break;
        }

        if (checkDraw())
        {
            displayBoard();

            cout << "\nThe game is a draw!\n";

            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

// Main
int main()
{
    char replay;

    cout << "====================================\n";
    cout << "       TIC TAC TOE GAME\n";
    cout << "====================================\n";

    do
    {
        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}
