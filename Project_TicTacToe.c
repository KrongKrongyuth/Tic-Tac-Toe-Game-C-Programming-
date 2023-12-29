#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Declare variables (Global Variables)
int board[3][3] = {{32, 32, 32},
                   {32, 32, 32},
                   {32, 32, 32}};
// IMPORTANT NOTE : In this game, I'm using ASCII CODE to build the board.
//                  Because I need to create the board by using 2D Arrays.
//                  I've used ASCII CODE as the following:
// ASCII CODE
// X(Capital) = 88
// O(Capital) = 79
// Space = 32
enum sign
{
    X,
    O,
    None
} player_sign = None;
enum status
{
    Valid,
    Invalid
} process = Valid;
enum game_status
{
    Yes,
    No
} over = No;

// Function zone
void start_menu();
void game_rule(char[]);
void show_board();               // EVALUATED
void reset_board();              // EVALUATED
void player_move(int, int, int); // EVALUATED
void show_invalid(int, int);     // EVALUATED
void ai_move(int);               // EVALUATED
void win_check(int);             // EVALUATED // Add player_name
void end_game();

// Structs zone
typedef char Sentence[50];
typedef struct
{
    Sentence Name;
    int Score, Row, Col, Status;
    enum sign Sign;
} Player;

// Main zone
int main()
{
    Player main_palayer;

    main_palayer.Sign = O;

    // TEST
    player_move(1, 2, main_palayer.Sign);
    ai_move(main_palayer.Sign);
    show_board();
    player_move(2, 2, main_palayer.Sign);
    ai_move(main_palayer.Sign);
    show_board();
    player_move(0, 0, main_palayer.Sign);
    ai_move(main_palayer.Sign);
    show_board();
    win_check(main_palayer.Sign);

    return 0;
}

void show_board()
{
    printf("\n");
    printf("******************************************************************\n");
    printf("Current Board\n");
    printf("******************************************************************\n");
    printf(" %c | %c | %c\n", (char)board[0][0], (char)board[0][1], (char)board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", (char)board[1][0], (char)board[1][1], (char)board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", (char)board[2][0], (char)board[2][1], (char)board[2][2]);
    printf("******************************************************************\n");
    printf("\n");
}

void reset_board()
{

    int num_board_row, num_board_col;

    num_board_row = sizeof(board) / sizeof(board[0]);
    num_board_col = sizeof(board[0]) / sizeof(board[0][0]);

    for (int i = 0; i < num_board_row; i++)
    {
        for (int j = 0; j < num_board_col; j++)
        {
            board[i][j] = 32;
        }
    }
}

void show_invalid(int row, int col)
{

    int current_board = board[row][col];

    process = Invalid;

    switch (process)
    {
    case Invalid:
        if ((current_board != 32) || (row >= 3 || col >= 3) || (row < 0 || col < 0))
        {
            printf("\n");
            printf("******************************************************************\n");
            printf("You can't place it in this location.\n");
            printf("Please fill in the valid value.\n");
            printf("******************************************************************\n");
            printf("\n");
        }
        break;

    default:
        printf("\n");
        printf("******************************************************************\n");
        printf("ERROR : void check_duplicate(int row, int col, int sign, int status)\n");
        printf("******************************************************************\n");
        printf("\n");
        break;
    }
}

void player_move(int row, int col, int sign)
{
    row--, col--;

    if ((row >= 3 || col >= 3) || (row < 0 || col < 0))
    {
        show_invalid(row, col);
    }

    if (process == Valid)
    {
        if (sign == X)
        {
            switch (board[row][col])
            {
            case 32:
                board[row][col] = 88;
                break;
            default:
                show_invalid(row, col);
                player_move(row, col, sign); // Recursive to check the value again
                break;
            }
        }
        else if (sign == O)
        {
            switch (board[row][col])
            {
            case 32:
                board[row][col] = 79;
                break;
            default:
                show_invalid(row, col);
                player_move(row, col, sign); // Recursive to check the value again
                break;
            }
        }
        else
        {
            printf("\n");
            printf("******************************************************************\n");
            printf("ERROR : void player_move(int row, int col, int sign)_2\n");
            printf("******************************************************************\n");
            printf("\n");
        }
    }
    else if (process == Invalid)
    {

        process = Valid;

        int new_row, new_col;

        printf("Enter the new Row: ");
        scanf("%d", &new_row);
        printf("\n");
        printf("Enter the new Column: ");
        scanf("%d", &new_col);
        printf("\n");

        player_move(new_row, new_col, sign); // Recursive to check the value again
    }
    else
    {
        printf("\n");
        printf("******************************************************************\n");
        printf("ERROR : void player_move(int row, int col, int sign)_1\n");
        printf("******************************************************************\n");
        printf("\n");
    }
}

void ai_move(int sign)
{

    int row, col;

    do
    {
        srand(time(0));
        row = rand() % 3; // Random Row
        col = rand() % 3; // Random Column
    } while (board[row][col] != 32 || (row >= 3 || col >= 3));

    if (sign == X)
    {
        switch (board[row][col])
        {
        case 32:
            board[row][col] = 79;
            break;
        default:
            printf("\n");
            printf("******************************************************************\n");
            printf("ERROR : void ai_move(int sign)_3\n");
            printf("******************************************************************\n");
            printf("\n");
            break;
        }
    }
    else if (sign == O)
    {
        switch (board[row][col])
        {
        case 32:
            board[row][col] = 88;
            break;
        default:
            printf("\n");
            printf("******************************************************************\n");
            printf("ERROR : void ai_move(int sign)_2\n");
            printf("******************************************************************\n");
            printf("\n");
            break;
        }
    }
    else
    {
        printf("\n");
        printf("******************************************************************\n");
        printf("ERROR : void ai_move(int sign)_1\n");
        printf("******************************************************************\n");
        printf("\n");
    }
}

void win_check(int sign)
{
    int num_board_row, num_board_col, i, j;

    num_board_row = sizeof(board) / sizeof(board[0]);
    num_board_col = sizeof(board[0]) / sizeof(board[0][0]);
    i = 0;

    // Diagonal win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != 32))
    {
        over = Yes;
        if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
        {
            printf("* Player has win!\n");
            printf("\n");
        }
        else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
        {
            printf("* AI has win!\n");
            printf("\n");
        }
    }
    else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != 32))
    {
        over = Yes;
        if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
        {
            printf("* Player has win!\n");
            printf("\n");
        }
        else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
        {
            printf("* AI has win!\n");
            printf("\n");
        }
    }
    else if (over == No)
    {
        while (over == No && i < num_board_row)
        {
            j = 0;

            while (j < num_board_col)
            {
                // Column win
                if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && (board[i][0] != 32))
                {
                    over = Yes;
                    if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
                    {
                        printf("* Player has win!\n");
                        printf("\n");
                        break;
                    }
                    else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
                    {
                        printf("* AI has win!\n");
                        printf("\n");
                        break;
                    }
                }

                // Row win
                if ((board[0][j] == board[1][j] && board[1][j] == board[2][j]) && (board[0][j] != 32))
                {
                    over = Yes;
                    if ((sign == X && board[0][j] == 88) || (sign == O && board[0][j] == 79))
                    {
                        printf("* Player has win!\n");
                        printf("\n");
                        break;
                    }
                    else if ((sign == X && board[0][j] == 79) || (sign == O && board[0][j] == 88))
                    {
                        printf("* AI has win!\n");
                        printf("\n");
                        break;
                    }
                }

                j++;
            }
            i++;
        }
        if (over == No)
        {
            over = Yes;
            printf("* Nobody has win!\n");
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("******************************************************************\n");
        printf("ERROR : win_check(int sign)\n");
        printf("******************************************************************\n");
        printf("\n");
    }
}