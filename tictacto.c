#include<stdio.h>

// Function to print the tic tac toe board with emojis
void print_table(char (*mat)[3])
{
    printf("-------------------------\n");
    for(int i = 0; i < 3; i++)
    {
        printf("|");
        for(int j = 0; j < 3; j++)
        {
            if(mat[i][j] == 'X')
                printf("  ❌   |");
            else if(mat[i][j] == 'O')
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
    for(int i = 0; i < 3; i++)
    {
        if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] != ' ')
            return (mat[i][0] == 'X') ? 1 : 2;
    }

    // Check columns
    for(int j = 0; j < 3; j++)
    {
        if(mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j] && mat[0][j] != ' ')
            return (mat[0][j] == 'X') ? 1 : 2;
    }

    // Check diagonals
    if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != ' ')
        return (mat[0][0] == 'X') ? 1 : 2;

    if(mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != ' ')
        return (mat[0][2] == 'X') ? 1 : 2;

    // No winner yet
    return 0;
}

int main()
{
    char player1[30], player2[30];
    printf("Enter player 1 Name :");
    scanf("%[^\n]", player1);
    getchar();
    printf("Enter player 2 Name :");
    scanf("%[^\n]", player2);

    char mat[3][3];
    int play = 1, count = 0;

    while(play)
    {
        int i, j;
        if(count == 0)
        {
            // Initialize board with empty spaces
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    mat[i][j] = ' ';
            print_table(mat);
        }

        // Player 1 turn
        printf("%s's chance, Select position (row col): ", player1);
        j = 1;
        while(j)
        {
            scanf("%d %d", &i, &j);
            if(mat[i][j] == ' ')
            {
                mat[i][j] = 'X';
                j = 0;
            }
            else
                printf("Position not available\nEnter Again: ");
        }
        print_table(mat);

        // Check for winner or tie
        if(match_check(mat) == 1)
        {
            printf("Congratulations %s Won\n", player1);
            printf("Play again? (1-Yes / 0-No): ");
            scanf("%d", &play);
            count = 0;
            continue;
        }
        else if(match_check(mat) == 2)
        {
            printf("Congratulations %s Won\n", player2);
            printf("Play again? (1-Yes / 0-No): ");
            scanf("%d", &play);
            count = 0;
            continue;
        }

        count++;
        if(count == 9)
        {
            printf("Game TIED\n");
            printf("Play again? (1-Yes / 0-No): ");
            scanf("%d", &play);
            count = 0;
            continue;
        }

        // Player 2 turn
        printf("%s's chance, Select position (row col): ", player2);
        j = 1;
        while(j)
        {
            scanf("%d %d", &i, &j);
            if(mat[i][j] == ' ')
            {
                mat[i][j] = 'O';
                j = 0;
            }
            else
                printf("Position not available\nEnter Again: ");
        }
        print_table(mat);

        // Check again for winner or tie
        if(match_check(mat) == 1)
        {
            printf("Congratulations %s Won\n", player1);
            printf("Play again? (1-Yes / 0-No): ");
            scanf("%d", &play);
            count = 0;
            continue;
        }
        else if(match_check(mat) == 2)
        {
            printf("Congratulations %s Won\n", player2);
            printf("Play again? (1-Yes / 0-No): ");
            scanf("%d", &play);
            count = 0;
            continue;
        }

        count++;
    }
}

		
