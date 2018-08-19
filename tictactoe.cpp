#include<bits/stdc++.h>
using namespace std;
#define player1 1
#define player2 2
#define side 3
#define PLAYERMOVE1 '0'
#define PLAYERMOVE2 'x'
void showboard(int board[][side])
{
    printf("\n\n");
    printf("\t\t\t  %c | %c | %c \n", board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t-------------\n");
    printf("\t\t\t  %c | %c | %c \n", board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t-------------\n");
    printf("\t\t\t  %c | %c | %c \n", board[2][0],board[2][1],board[2][2]);
    printf("\n\n");
}
void initialize(int board[][side])
{
    for(int i=0;i<side;i++)
    {
        for(int j=0;j<side;j++)
        {
            board[i][j]=' ';
        }
    }
 
}
bool rowcrossed(int board[][side])
{
    for(int i=0 ; i<side ; i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
            return true;
    }
    return false;
}
bool columncrossed(int board[][side])
{
    for(int i=0 ; i<side ; i++)
    {
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!=' ')
            return true;
    }
    return false;
}
bool diagonalcrossed(int board[][side])
{
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ')
        return true;
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' ')
        return true;
    return false;
}
bool gameover(int board[][side])
{
   return (rowcrossed(board) || columncrossed(board) || diagonalcrossed(board) );
}
void declarewinner(int whoseturn )
{
    if(whoseturn==player1)
        printf("Congratulations!! Player1 has won the game.\n");
    else if(whoseturn==player2)
        printf("Congratulations!! Player2 has won the game.\n");
}

void playtictactoe(int whoseturn)
{
    int board[side][side];
//    int moves[side*side];
    int x,y, moveindex = 0;
    initialize(board);
    showboard(board);
    while(gameover(board) == false && moveindex!=9 )
    {
        if(whoseturn==player1)
        {
            printf("It's player1 turn!\nEnter the value of row x: ");
            scanf("%d",&x);
            printf("Enter the value of column y: ");
            scanf("%d",&y);
            if(board[x][y]==' ')
            {
                board[x][y]=PLAYERMOVE1;
                whoseturn=player2;
                showboard(board);
                moveindex++;
            }
            else
            {
                printf("The chosen tictactoe's cell is already filled. Change your choice Player1!");
                showboard(board);
                whoseturn=player1;
            }
        }
        else if(whoseturn==player2)
        {
            printf("It's player2 turn!\n Enter the value of row x: ");
            scanf("%d",&x);
            printf("Enter the value of column y: ");
            scanf("%d",&y);
            if(board[x][y]==' ')
            {
                board[x][y]=PLAYERMOVE2;
                whoseturn=player1;
                showboard(board);
                moveindex++;
            }
            else
            {
                printf("The chosen tictactoe's cell is already filled. Change your choice Player2 !");
                showboard(board);
                whoseturn=player2;
            }
        }
    }
    if(gameover(board)==false && moveindex==9)
        printf("It's a draw.\nWell played !\n");
    else
    {
        if(whoseturn==player1)
            whoseturn=player2;
        else if(whoseturn==player2)
            whoseturn=player1;
          declarewinner(whoseturn);
    }
}

int main()
{
    int turn;
    printf("!! Please tell who should start the game !!\n");
    printf("--------------------------------------------\nENTER 1 FOR Player1 ELSE TYPE 2 FOR Player2\n\n");
    scanf("%d",&turn);
    playtictactoe(turn);
    return 0;
}
