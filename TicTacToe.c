#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

char board[3][3] = {{' ',' ',' '}, 
                    {' ',' ',' '},
                    {' ',' ',' '}};

typedef struct{
    char name[MAX];
    char symbol;
} User;

void setName(User *p, char name[]){
    name[strcspn(name, "\n")] = '\0';
    strcpy(p->name, name);
}

void setSymbol(User *p, char symbol){
    p->symbol = symbol;
}

void printBoard(){
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWin(User *p){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == p->symbol && board[i][1] == p->symbol && board[i][2] == p->symbol){
            return 1;
        }

        if(board[0][i] == p->symbol && board[1][i] == p->symbol && board[2][i] == p->symbol){
            return 1;
        }
    }
    if(board[0][0] == p->symbol && board[1][1] == p->symbol && board[2][2] == p->symbol){
        return 1;
    }
    return 0;
}

int main(){

    User Player_1;
    User Player_2;

    char player_1_name[MAX],player_2_name[MAX];

    printf("Enter player 1 name : ");
    fgets(player_1_name, MAX, stdin);
    printf("Enter player 2 name : ");
    fgets(player_2_name, MAX, stdin);

    setName(&Player_1, player_1_name);
    setName(&Player_2, player_2_name);
    setSymbol(&Player_1, 'X');
    setSymbol(&Player_2, 'O');

    int row;
    int column;
    int rounds = 0;

    User *currentPlayer = &Player_1;

    printBoard();
    while(rounds < 9){
        printf("%s's turn! [%c]\n", currentPlayer->name, currentPlayer->symbol);
        printf("Enter row : ");
        scanf("%d", &row);
        printf("Enter column : ");
        scanf("%d", &column);

        if (row < 0 || row > 2 || column < 0 || column > 2 || board[row][column] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][column] = currentPlayer->symbol;
        rounds++;
        printBoard();

        if(checkWin(currentPlayer)){
            printf("Congratulations %s! You win!\n", currentPlayer->name);
            break;
        }

        currentPlayer = (currentPlayer == &Player_1) ? &Player_2 : &Player_1;
    }

    if(rounds == 9 && !checkWin(currentPlayer)){
        printf("Draw!");
    }

    return 0;
}