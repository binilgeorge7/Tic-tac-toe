#include <stdio.h>

// Function to print the tic tac toe board with emojis
void print_table(char (*mat)[3])
{
    printf("-------------------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] == 'X')
                printf("  ❌   |");
            else if (mat[i][j] == 'O')
                printf("  ⭕   |");
            else
                printf("       |");
        }
        printf("\n-------------------------\n");
    }
}

// Function to check if there's a winner
int match_check(char (*mat)[3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
        if (mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] != ' ')
            return (mat[i][0] == 'X') ? 1 : 2;

    // Check columns
    for (int j = 0; j < 3; j++)
        if (mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j] && mat[0][j] != ' ')
            return (mat[0][j] == 'X') ? 1 : 2;

    // Check diagonals
    if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != ' ')
        return (mat[0][0] == 'X') ? 1 : 2;

    if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != ' ')
        return (mat[0][2] == 'X') ? 1 : 2;

    return 0; // No winner yet
}

// Function to display the rules
void display_rules()
{
    printf("\n================ Rules ================\n");
    printf("1. The game is played on a 3x3 grid.\n");
    printf("2. Player 1 uses ❌ and Player 2 uses ⭕.\n");
    printf("3. Players take turns to place their symbol in an empty cell.\n");
    printf("4. The first player to get 3 symbols in a row, column, or diagonal wins.\n");
    printf("5. If all cells are filled and no player wins, the game is a tie.\n");
    printf("======================================\n\n");
}

int main()
{
    char player1[30], player2[30];
    int choice;

    printf("Enter player 1 Name: ");
    scanf("%[^\n]", player1);
    getchar();
    printf("Enter player 2 Name: ");
    scanf("%[^\n]", player2);

    int play = 1;

    while (play)
    {
        printf("\n===== TIC TAC TOE MENU =====\n");
        printf("1. Play Game\n");
        printf("2. Rules\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char mat[3][3];
            int count = 0;
            // Initialize board
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    mat[i][j] = ' ';

            print_table(mat);

            while (1)
            {
                int i, j;

                // Player 1 turn
                printf("%s's chance, Select position (row col): ", player1);
                while (1)
                {
                    scanf("%d %d", &i, &j);
                    if (i >= 0 && i < 3 && j >= 0 && j < 3 && mat[i][j] == ' ')
                    {
                        mat[i][j] = 'X';
                        break;
                    }
                    else
                        printf("Position not available or invalid. Enter Again: ");
                }
                print_table(mat);
                if (match_check(mat) == 1)
                {
                    printf("Congratulations %s Won!\n", player1);
                    break;
                }
                count++;
                if (count == 9)
                {
                    printf("Game TIED\n");
                    break;
                }

                // Player 2 turn
                printf("%s's chance, Select position (row col): ", player2);
                while (1)
                {
                    scanf("%d %d", &i, &j);
                    if (i >= 0 && i < 3 && j >= 0 && j < 3 && mat[i][j] == ' ')
                    {
                        mat[i][j] = 'O';
                        break;
                    }
                    else
                        printf("Position not available or invalid. Enter Again: ");
                }
                print_table(mat);
                if (match_check(mat) == 2)
                {
                    printf("Congratulations %s Won!\n", player2);
                    break;
                }
                count++;
            }
            break;
        }

        case 2:
            display_rules();
            break;

        case 3:
            printf("Exiting... Goodbye!\n");
            play = 0;
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}


		
