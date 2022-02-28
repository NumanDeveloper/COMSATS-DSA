#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// global variables
char board[3][3]; // empty board
const char PLAYER = 'X';
const char COMPUTER = 'O';

// functions prototypes
void reset_board();
void print_board();
int check_empty_spaces();
void player_move();
void computer_move();
char check_winner();
void print_winner(char winner);

int main()
{
    char winner = ' ';
    char response = ' ';
    do
    {
        int winner = ' ';
        reset_board();
        while (winner == ' ' && check_empty_spaces() != 0)
        {
            print_board();
            player_move();
            winner = check_winner();
            if (winner != ' ' || check_empty_spaces() == 0)
                break;
            computer_move();
            winner = check_winner();
            if (winner != ' ' || check_empty_spaces() == 0)
                break;
        }
        print_board();
        print_winner(winner);
        printf("\n\nWould you like to play again(Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');
    printf("Thanks for playing!");
    return 0;
}

void reset_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void print_board()
{
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
}
int check_empty_spaces()
{
    int spaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
                spaces--;
        }
    }
    return spaces;
}
void player_move()
{
    int x, y;
    do
    {
        printf("\nEnter row #(1-3): ");
        scanf("%d", &x);
        x--; // decrement to match index
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--; // decrement to match index
        // check if position is available
        if (board[x][y] != ' ')
            printf("Invalid Position");
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] == ' ');
}
void computer_move()
{
    if (check_empty_spaces != 0)
    {
        int x, y;
        do
        {
            // generate a seed value
            srand(time(0));
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
        print_winner(' ');
}
char check_winner()
{
    // check rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    // check columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[i][0];
    // check principal diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    // check principal diagonal
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];
    return ' ';
}
void print_winner(char winner)
{
    if (winner == PLAYER)
        printf("\nYOU WON!😍");
    else if (winner == COMPUTER)
        printf("\nYOU LOSE!😥");
    else
        printf("\nIT'S A TIE!🙄");
}
