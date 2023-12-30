#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
enum tracking
{
    Valid,
    Invalid
} process = Valid;
enum game_status
{
    Yes,
    No,
} over = No;
enum play_mode
{
    Single,
    CO_OP,
    Unselected
} mode = Unselected;

// Function zone
void start_menu();               // EVALUATED
void game_rule();                // EVALUATED
void mode_select();              // EVALUATED
void show_board();               // EVALUATED
void reset_board();              // EVALUATED
void player_move(int, int, int); // EVALUATED
void show_invalid(int, int);     // EVALUATED
void ai_move();                  // EVALUATED
// void win_check(char[], int);     // EVALUATED
void win_check();                // EVALUATED
void tie_check();                // EVALUATED
void over_check();               // EVALUATED
void start_game();               // CHECKING
void end_credit();               // EVALUATED

// Structs zone
typedef char Sentence[50];
typedef struct
{
    Sentence Name;
    int Score, Row, Col;
    enum sign Sign;
} Player;
// Player main_player = {"", 0, 0, 0, None};
// Player secondary_player = {"", 0, 0, 0, None};
// Player bot_player = {"", 0, 0, 0, None};
Player main_player = {"", None};
Player secondary_player = {"", None};
Player bot_player = {"", None};

// Main zone
int main()
{

    start_menu();
    mode_select();
    game_rule();
    start_game();
    // Playing 
    // while (over == No)
    // {
    //     if (mode == Single)
    //     {
    //         show_board();
    //         printf("Enter the new Row: ");
    //         scanf("%d", &main_player.Row);
    //         printf("\n");
    //         printf("Enter the new Column: ");
    //         scanf("%d", &main_player.Col);
    //         printf("\n");
    //         player_move(main_player.Row, main_player.Col, main_player.Sign);
    //         over_check();
    //         if (over == No)
    //         {
    //             ai_move();
    //             over_check();
    //         }
    //         else if (over == Yes)
    //         {
    //             break;
    //         }
    //     }
    //     else if (mode == CO_OP)
    //     {
    //         show_board();
    //         printf("Enter the new Row: ");
    //         scanf("%d", &main_player.Row);
    //         printf("\n");
    //         printf("Enter the new Column: ");
    //         scanf("%d", &main_player.Col);
    //         printf("\n");
    //         player_move(main_player.Row, main_player.Col, main_player.Sign);
    //         over_check();
    //         if (over == No)
    //         {
    //             show_board();
    //             printf("Enter the new Row: ");
    //             scanf("%d", &secondary_player.Row);
    //             printf("\n");
    //             printf("Enter the new Column: ");
    //             scanf("%d", &secondary_player.Col);
    //             printf("\n");
    //             player_move(secondary_player.Row, secondary_player.Col, secondary_player.Sign);
    //             over_check();
    //         }
    //         else if (over == Yes)
    //         {
    //             break;
    //         }
    //     }
        
        
    // }
    
    
    
    // show_board();
    // // tie_check();
    // // printf("\n");
    // // printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
    // // printf("\n");
    
    // player_move(1, 1, main_player.Sign);
    // player_move(3, 1, secondary_player.Sign);

    // show_board();
    // // tie_check();
    // // printf("\n");
    // // printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
    // // printf("\n");

    // player_move(2, 2, secondary_player.Sign);
    // player_move(3, 3, main_player.Sign);
    
    // show_board();
    // // tie_check();
    // // printf("\n");
    // // printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
    // // printf("\n");

    // player_move(3, 2, main_player.Sign);
    // player_move(1, 3, secondary_player.Sign);

    // show_board();
    // // tie_check();
    // // printf("\n");
    // // printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
    // // printf("\n");

    // player_move(2, 3, main_player.Sign);
    // player_move(1, 2, secondary_player.Sign);

    // show_board();
    // // tie_check();
    // // printf("\n");
    // // printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
    // // printf("\n");

    // player_move(2, 1, secondary_player.Sign);
    
    // show_board();
    // // tie_check();
    // // printf("\n");
    // // printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
    // // printf("\n");

    // printf("over: %u, mode: %u,sign: %u, process: %u\n", over, mode, player_sign, process);

    // // player_move(1, 1, main_player.Sign);
    // // player_move(1, 1, secondary_player.Sign);
    // // show_board();

    // // player_move(1, 1, main_player.Sign);
    // // player_move(1, 1, secondary_player.Sign);
    // // show_board();
    
    // // player_move(1, 1, main_player.Sign);
    // // player_move(1, 1, secondary_player.Sign);
    // // show_board();

    // // player_move(1, 1, main_player.Sign);
    // // player_move(1, 1, secondary_player.Sign);
    // // show_board();
    // // player_move(2, 2, main_player.Sign);
    // // ai_move(main_player.Sign);
    // // show_board();
    // // player_move(3, 3, main_player.Sign);
    // // ai_move(main_player.Sign);
    // // show_board();
    // over_check();
    // printf("over: %u, mode: %u,sign: %u, process: %u\n", over, mode, player_sign, process);
    end_credit();

    return 0;
}

void start_menu()
{
    char enter;

    printf("\n");
    printf("****************** Welcome to Tic Tac Toe Game! ******************\n");
    printf("\n");
    printf("------------------ (Press <Enter> to continue) -------------------\n");
    printf("\n");
    scanf("%c", &enter);
}

void game_rule()
{
    char response;

    if (mode == Single)
    {
        printf("\n");
        printf("******************************************************************\n");
        printf("RULE OF THIS GAME.\n");
        printf("******************************************************************\n");
        printf("\n");
        printf("Hello %s!, Welcome to Tic Tac Toe Game! I believe that most of you\n", main_player.Name);
        printf("used to play it once a time but if not I will briefly explain you.\n");
        printf("\n");
        printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
        printf("\n");
        printf("2. You are X, your friend (or the computer) is O.\n");
        printf("   Players take turns putting their marks in empty squares.\n");
        printf("\n");
        printf("3. The first player to get 3 of her marks in a row (up, down, across,\n");
        printf("   or diagonally) is the winner.\n");
        printf("\n");
        printf("4. When all 9 squares are full, the game is over. If no player has 3\n");
        printf("   marks in a row, the game ends in a tie.\n");
        printf("\n");
        printf("Example:\n");
        printf("\n");
        printf(" %c | %c | %c\t %c | %c | %c\t %c | %c | %c\t %c | %c | %c\n", 88, 88, 88, 88, 32, 32, 88, 32, 32, 88, 79, 88);
        printf("---|---|---\t---|---|---\t---|---|---\t---|---|---\n");
        printf(" %c | %c | %c\t %c | %c | %c\t %c | %c | %c\t %c | %c | %c\n", 32, 32, 32, 88, 32, 32, 32, 88, 32, 79, 88, 88);
        printf("---|---|---\t---|---|---\t---|---|---\t---|---|---\n");
        printf(" %c | %c | %c\t %c | %c | %c\t %c | %c | %c\t %c | %c | %c\n", 32, 32, 32, 88, 32, 32, 32, 32, 88, 79, 88, 79);
        printf("\n");
        printf("    Win\t\t    Win\t\t    Win\t\t    Tie\n");
        printf("\n");
        printf("------------------ (Press <Enter> to stat game) ------------------\n");
        printf("\n");
        while ((response = getchar()) != '\n' && response != EOF);
        scanf("%c", &response);
    }
    else if (mode == CO_OP)
    {
        printf("\n");
        printf("******************************************************************\n");
        printf("RULE OF THIS GAME.\n");
        printf("******************************************************************\n");
        printf("\n");
        printf("Hello %s and %s!, Welcome to Tic Tac Toe Game! I believe\n", main_player.Name, secondary_player.Name);
        printf("that most of you used to play it once a time but if not\n");
        printf("I will briefly explain you.\n");
        printf("\n");
        printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
        printf("\n");
        printf("2. You are X, your friend (or the computer) is O.\n");
        printf("   Players take turns putting their marks in empty squares.\n");
        printf("\n");
        printf("3. The first player to get 3 of her marks in a row (up, down, across,\n");
        printf("   or diagonally) is the winner.\n");
        printf("\n");
        printf("4. When all 9 squares are full, the game is over. If no player has 3\n");
        printf("   marks in a row, the game ends in a tie.\n");
        printf("\n");
        printf("Example:\n");
        printf("\n");
        printf(" %c | %c | %c\t %c | %c | %c\t %c | %c | %c\t %c | %c | %c\n", 88, 88, 88, 88, 32, 32, 88, 32, 32, 88, 79, 88);
        printf("---|---|---\t---|---|---\t---|---|---\t---|---|---\n");
        printf(" %c | %c | %c\t %c | %c | %c\t %c | %c | %c\t %c | %c | %c\n", 32, 32, 32, 88, 32, 32, 32, 88, 32, 79, 88, 88);
        printf("---|---|---\t---|---|---\t---|---|---\t---|---|---\n");
        printf(" %c | %c | %c\t %c | %c | %c\t %c | %c | %c\t %c | %c | %c\n", 32, 32, 32, 88, 32, 32, 32, 32, 88, 79, 88, 79);
        printf("\n");
        printf("    Win\t\t    Win\t\t    Win\t\t    Tie\n");
        printf("\n");
        printf("------------------ (Press <Enter> to stat game) ------------------\n");
        printf("\n");
        while ((response = getchar()) != '\n' && response != EOF);
        scanf("%c", &response);
    }
    else
    {
        printf("\n");
        printf("******************************************************************\n");
        printf("ERROR : void game_rule()\n");
        printf("******************************************************************\n");
        printf("\n");
    }
    
    
}

void mode_select()
{
    char response;

    while (mode == Unselected)
    {
        printf("******************************************************************\n");
        printf("Do you want to play alone or play with your friend?\n");
        printf("[ A ] -> Play alone (vs Bot)\n");
        printf("[ B ] -> Play with friend\n");
        printf("******************************************************************\n");
        printf("Your response: ");
        scanf(" %c", &response);
        printf("\n");

        if (toupper(response) == 'A')
        {
            char main_player_sign;

            mode = Single;
            do
            {
                printf("\n");
                printf("******************************************************************\n");
                printf("Please fill in the player information.\n");
                printf("******************************************************************\n");
                printf("Player name: ");
                scanf("%s", main_player.Name);
                printf("What side do you need to play (X or O): ");
                scanf(" %c", &main_player_sign);
                printf("\n");
                if (toupper(main_player_sign) == 'X')
                {
                    main_player.Sign = X;
                    bot_player.Sign = O;
                }
                else if (toupper(main_player_sign) == 'O')
                {
                    main_player.Sign = O;
                    bot_player.Sign = X;
                }
                else
                {
                    printf("\n");
                    printf("******************************************************************\n");
                    printf("Please fill in the valid value\n");
                    printf("******************************************************************\n");
                    printf("\n");
                }
            } while (main_player.Sign == None);
            break;
        }
        else if (toupper(response) == 'B')
        {
            char main_player_sign;

            mode = CO_OP;
            do
            {
                printf("\n");
                printf("******************************************************************\n");
                printf("Please fill in the player information.\n");
                printf("******************************************************************\n");
                printf("Main player name: ");
                scanf("%s", main_player.Name);
                printf("Secondary player name: ");
                scanf("%s", secondary_player.Name);
                printf("\n");
                printf("Fill in the first player side (the secondary will get the opposite one).\n");
                printf("What side do you need to play (X or O): ");
                scanf(" %c", &main_player_sign);
                printf("\n");
                if (toupper(main_player_sign) == 'X')
                {
                    main_player.Sign = X;
                    secondary_player.Sign = O;
                }
                else if (toupper(main_player_sign) == 'O')
                {
                    main_player.Sign = O;
                    secondary_player.Sign = X;
                }
                else
                {
                    printf("\n");
                    printf("******************************************************************\n");
                    printf("Please fill in the valid value\n");
                    printf("******************************************************************\n");
                    printf("\n");
                }
            } while (main_player.Sign == None);
            break;
        }
        else
        {
            printf("\n");
            printf("******************************************************************\n");
            printf("Please fill in the valid value\n");
            printf("******************************************************************\n");
        }
    }
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
    if (over == No)
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
    else
    {
        win_check();
    }
}

void ai_move()
{
    if (over == No)
    {
        int row, col;

        do
        {
            srand(time(0));
            row = rand() % 3; // Random Row
            col = rand() % 3; // Random Column
        } while (board[row][col] != 32 || (row >= 3 || col >= 3));

        if (main_player.Sign == X)
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
        else if (main_player.Sign == O)
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
}

// void win_check(Sentence player_name, int sign)
// {
//     if (mode == Single)
//     {
//         int num_board_row, num_board_col, i, j;

//         num_board_row = sizeof(board) / sizeof(board[0]);
//         num_board_col = sizeof(board[0]) / sizeof(board[0][0]);
//         i = 0;

//         // Diagonal win
//         if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != 32))
//         {
//             over = Yes;
//             if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
//             {
//                 printf("*** %s has won! ***\n", player_name);
//                 printf("\n");
//             }
//             else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
//             {
//                 printf("*** AI has won! ***\n");
//                 printf("\n");
//             }
//         }
//         else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != 32))
//         {
//             over = Yes;
//             if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
//             {
//                 printf("*** %s has won! ***\n", player_name);
//                 printf("\n");
//             }
//             else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
//             {
//                 printf("*** AI has won! ***\n");
//                 printf("\n");
//             }
//         }
//         else if (over == No)
//         {
//             while (over == No && i < num_board_row)
//             {
//                 j = 0;

//                 while (j < num_board_col)
//                 {
//                     // Column win
//                     if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && (board[i][0] != 32))
//                     {
//                         over = Yes;
//                         if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
//                         {
//                             printf("*** %s has won! ***\n", player_name);
//                             printf("\n");
//                             break;
//                         }
//                         else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
//                         {
//                             printf("*** AI has won! ***\n");
//                             printf("\n");
//                             break;
//                         }
//                     }

//                     // Row win
//                     if ((board[0][j] == board[1][j] && board[1][j] == board[2][j]) && (board[0][j] != 32))
//                     {
//                         over = Yes;
//                         if ((sign == X && board[0][j] == 88) || (sign == O && board[0][j] == 79))
//                         {
//                             printf("*** %s has won! ***\n", player_name);
//                             printf("\n");
//                             break;
//                         }
//                         else if ((sign == X && board[0][j] == 79) || (sign == O && board[0][j] == 88))
//                         {
//                             printf("*** AI has won! ***\n");
//                             printf("\n");
//                             break;
//                         }
//                     }

//                     j++;
//                 }
//                 i++;
//             }
//             if (over == No)
//             {
//                 over = Yes;
//                 printf("*** The game is Tie! ***\n");
//                 printf("\n");
//             }
//         }
//         else
//         {
//             printf("\n");
//             printf("******************************************************************\n");
//             printf("ERROR : win_check(int sign)\n");
//             printf("******************************************************************\n");
//             printf("\n");
//         }
//     }
//     else if (mode == CO_OP)
//     {
//         int num_board_row, num_board_col, i, j;

//         num_board_row = sizeof(board) / sizeof(board[0]);
//         num_board_col = sizeof(board[0]) / sizeof(board[0][0]);
//         i = 0;

//         // Diagonal win
//         if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != 32))
//         {
//             over = Yes;
//             if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
//             {
//                 printf("*** %s has won! ***\n", player_name);
//                 printf("\n");
//             }
//             else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
//             {
//                 printf("*** AI has won! ***\n");
//                 printf("\n");
//             }
//         }
//         else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != 32))
//         {
//             over = Yes;
//             if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
//             {
//                 printf("*** %s has won! ***\n", player_name);
//                 printf("\n");
//             }
//             else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
//             {
//                 printf("*** AI has won! ***\n");
//                 printf("\n");
//             }
//         }
//         else if (over == No)
//         {
//             while (over == No && i < num_board_row)
//             {
//                 j = 0;

//                 while (j < num_board_col)
//                 {
//                     // Column win
//                     if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && (board[i][0] != 32))
//                     {
//                         over = Yes;
//                         if ((sign == X && board[i][0] == 88) || (sign == O && board[i][0] == 79))
//                         {
//                             printf("*** %s has won! ***\n", player_name);
//                             printf("\n");
//                             break;
//                         }
//                         else if ((sign == X && board[i][0] == 79) || (sign == O && board[i][0] == 88))
//                         {
//                             printf("*** AI has won! ***\n");
//                             printf("\n");
//                             break;
//                         }
//                     }

//                     // Row win
//                     if ((board[0][j] == board[1][j] && board[1][j] == board[2][j]) && (board[0][j] != 32))
//                     {
//                         over = Yes;
//                         if ((sign == X && board[0][j] == 88) || (sign == O && board[0][j] == 79))
//                         {
//                             printf("*** %s has won! ***\n", player_name);
//                             printf("\n");
//                             break;
//                         }
//                         else if ((sign == X && board[0][j] == 79) || (sign == O && board[0][j] == 88))
//                         {
//                             printf("*** AI has won! ***\n");
//                             printf("\n");
//                             break;
//                         }
//                     }

//                     j++;
//                 }
//                 i++;
//             }
//             if (over == No)
//             {
//                 over = Yes;
//                 printf("*** The game is Tie! ***\n");
//                 printf("\n");
//             }
//         }
//         else
//         {
//             printf("\n");
//             printf("******************************************************************\n");
//             printf("ERROR : win_check(int sign)\n");
//             printf("******************************************************************\n");
//             printf("\n");
//         }
//     }
    
// }

void win_check()
{
    if (mode == Single)
    {
        int num_board_row, num_board_col, i, j;

        num_board_row = sizeof(board) / sizeof(board[0]);
        num_board_col = sizeof(board[0]) / sizeof(board[0][0]);
        i = 0;

        // Diagonal win
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != 32))
        {
            over = Yes;
            show_board();
            if ((main_player.Sign == X && board[0][0] == 88) || (main_player.Sign == O && board[0][0] == 79))
            {
                printf("*** %s has won! ***\n", main_player.Name);
                printf("\n");
            }
            else if ((main_player.Sign == X && board[0][0] == 79) || (main_player.Sign == O && board[0][0] == 88))
            {
                printf("*** AI has won! ***\n");
                printf("\n");
            }
        }
        else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != 32))
        {
            over = Yes;
            show_board();
            if ((main_player.Sign == X && board[0][2] == 88) || (main_player.Sign == O && board[0][2] == 79))
            {
                printf("*** %s has won! ***\n", main_player.Name);
                printf("\n");
            }
            else if ((main_player.Sign == X && board[0][2] == 79) || (main_player.Sign == O && board[0][2] == 88))
            {
                printf("*** AI has won! ***\n");
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
                        show_board();
                        if ((main_player.Sign == X && board[i][0] == 88) || (main_player.Sign == O && board[i][0] == 79))
                        {
                            printf("*** %s has won! ***\n", main_player.Name);
                            printf("\n");
                            break;
                        }
                        else if ((main_player.Sign == X && board[i][0] == 79) || (main_player.Sign == O && board[i][0] == 88))
                        {
                            printf("*** AI has won! ***\n");
                            printf("\n");
                            break;
                        }
                    }

                    // Row win
                    if ((board[0][j] == board[1][j] && board[1][j] == board[2][j]) && (board[0][j] != 32))
                    {
                        over = Yes;
                        show_board();
                        if ((main_player.Sign == X && board[0][j] == 88) || (main_player.Sign == O && board[0][j] == 79))
                        {
                            printf("*** %s has won! ***\n", main_player.Name);
                            printf("\n");
                            break;
                        }
                        else if ((main_player.Sign == X && board[0][j] == 79) || (main_player.Sign == O && board[0][j] == 88))
                        {
                            printf("*** AI has won! ***\n");
                            printf("\n");
                            break;
                        }
                    }
                    j++;
                }
                i++;
            }
            // if (over == No && i == 2)
            // {
            //     over = Yes;
            //     show_board();
            //     printf("*** The game is Tie! ***\n");
            //     printf("\n");
            // }
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
    else if (mode == CO_OP)
    {
        int num_board_row, num_board_col, i, j;

        num_board_row = sizeof(board) / sizeof(board[0]);
        num_board_col = sizeof(board[0]) / sizeof(board[0][0]);
        i = 0;

        // Diagonal win
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != 32))
        {
            over = Yes;
            show_board();
            if ((main_player.Sign == X && board[0][0] == 88) || (main_player.Sign == O && board[0][0] == 79))
            {
                printf("*** %s has won! ***\n", main_player.Name);
                printf("\n");
            }
            else if ((main_player.Sign == X && board[0][0] == 79) || (main_player.Sign == O && board[0][0] == 88))
            {
                printf("*** %s has won! ***\n", secondary_player.Name);
                printf("\n");
            }
        }
        else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != 32))
        {
            over = Yes;
            show_board();
            if ((main_player.Sign == X && board[0][2] == 88) || (main_player.Sign == O && board[0][2] == 79))
            {
                printf("*** %s has won! ***\n", main_player.Name);
                printf("\n");
            }
            else if ((main_player.Sign == X && board[0][2] == 79) || (main_player.Sign == O && board[0][2] == 88))
            {
                printf("*** %s has won! ***\n", secondary_player.Name);
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
                        show_board();
                        if ((main_player.Sign == X && board[i][0] == 88) || (main_player.Sign == O && board[i][0] == 79))
                        {
                            printf("*** %s has won! ***\n", main_player.Name);
                            printf("\n");
                            break;
                        }
                        else if ((main_player.Sign == X && board[i][0] == 79) || (main_player.Sign == O && board[i][0] == 88))
                        {
                            printf("*** %s has won! ***\n", secondary_player.Name);
                            printf("\n");
                            break;
                        }
                    }

                    // Row win
                    if ((board[0][j] == board[1][j] && board[1][j] == board[2][j]) && (board[0][j] != 32))
                    {
                        over = Yes;
                        show_board();
                        if ((main_player.Sign == X && board[0][j] == 88) || (main_player.Sign == O && board[0][j] == 79))
                        {
                            printf("*** %s has won! ***\n", main_player.Name);
                            printf("\n");
                            break;
                        }
                        else if ((main_player.Sign == X && board[0][j] == 79) || (main_player.Sign == O && board[0][j] == 88))
                        {
                            printf("*** %s has won! ***\n", secondary_player.Name);
                            printf("\n");
                            break;
                        }
                    }

                    j++;
                }
                i++;
            }
            // if (over == No && i == 2)
            // {
            //     over = Yes;
            //     show_board();
            //     printf("*** The game is Tie! ***\n");
            //     printf("\n");
            // }
        }
        // else if (over == No && i == 2)
        // {
        //     over = Yes;
        //     show_board();
        //     printf("*** The game is Tie! ***\n");
        //     printf("\n");
        // }
        else
        {
            printf("\n");
            printf("******************************************************************\n");
            printf("ERROR : win_check(int sign)\n");
            printf("******************************************************************\n");
            printf("\n");
        }
    }
    
}

void tie_check()
{
    if (over == No)
    {
        bool first_row_full = (board[0][0] != 32 && board[0][1] != 32 && board[0][2] != 32);
        bool second_row_full = (board[1][0] != 32) && (board[1][1] != 32) && (board[1][2] != 32);
        bool third_row_full = (board[2][0] != 32) && (board[2][1] != 32) && (board[2][2] != 32);
        
        if (first_row_full && second_row_full && third_row_full)
        {
            over = Yes;
            show_board();
            printf("*** The game is Tie! ***\n");
            printf("\n");
        }
    }
}

void over_check()
{
    win_check();
    tie_check();
}

void start_game()
{
    while (over == No)
    {
        if (mode == Single)
        {
            show_board();
            printf("Enter the new Row: ");
            scanf("%d", &main_player.Row);
            printf("\n");
            printf("Enter the new Column: ");
            scanf("%d", &main_player.Col);
            printf("\n");
            player_move(main_player.Row, main_player.Col, main_player.Sign);
            over_check();
            if (over == No)
            {
                ai_move();
                over_check();
            }
            else if (over == Yes)
            {
                break;
            }
        }
        else if (mode == CO_OP)
        {
            show_board();
            printf("Enter the new Row: ");
            scanf("%d", &main_player.Row);
            printf("\n");
            printf("Enter the new Column: ");
            scanf("%d", &main_player.Col);
            printf("\n");
            player_move(main_player.Row, main_player.Col, main_player.Sign);
            over_check();
            if (over == No)
            {
                show_board();
                printf("Enter the new Row: ");
                scanf("%d", &secondary_player.Row);
                printf("\n");
                printf("Enter the new Column: ");
                scanf("%d", &secondary_player.Col);
                printf("\n");
                player_move(secondary_player.Row, secondary_player.Col, secondary_player.Sign);
                over_check();
            }
            else if (over == Yes)
            {
                break;
            }
        }
    }
}

void end_credit()
{
    printf("\n");
    printf("---------------------- Thanks for playing! -----------------------\n");
    printf("--------------------- Hope you enjoy my game ---------------------\n");
    printf("\n");
}