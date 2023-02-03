/*
Author:- Hardik Verma
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int inst1();
int dis_pos(int[3][3]);
int mgame(int[3][3],char[3][3],char[3][3]);
int gameactive();
int eateregg();
int bye();

int main(){
   char active;
   playagain:
   gameactive();
   yn:
   printf("\nDo You Want To Play Again Press y/n  \n");
   scanf(" %c",&active);
   if(active=='y'){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    goto playagain;}
   else if(active=='n'){
      printf("\nThanks For playing\n\n\n");
      bye();
      sleep(5);
      return 0;}
   else
      goto yn;
   }

int gameactive() {
    int data[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    char TTTE[3][3] ={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    char TTTV[3][3] ={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    printf("x-----------------------x\n       TIC-TAC-TOE\n");
    printf("x----By Hardik Verma----x\nx-----------------------x\n");
    inst1();
    //dis_pos(data);
    mgame(data,TTTE,TTTV);

    return 0;
}
int dis_pos(int l[3][3]){
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
         if((j+1)%3==0)
            printf("%d\n",l[i][j]);
        else
            printf("%d|" ,l[i][j]);
    } }
}
int dis_TTT(char l[3][3]){
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
         if((j+1)%3==0)
            printf("%c\n",l[i][j]);
        else
            printf("%c|" ,l[i][j]);
    } }
}
int inst1(){
    printf("       INSTRUCTION      \nPlayer 1:X\nPlayer 2:O\n");
    printf("Player had to press a no\nTo add X or O\n");
}
int mgame(int data[3][3],char TTTE[3][3],char TTTV[3][3]){
    int n=0,player,choice,i,j,win=0;
    int endgame=0;
    while(1){
      printf("x-----------------------x\n");
      dis_TTT(TTTV);
      printf("x-----------------------x\n");
      printf("-----Avalable Places-----\n");
      dis_pos(data);
      player=n%2+1; //to iterate threw players (1-2-1-2-1-1)
      endgame++;
      error://Error Handling
      printf("Enter Player%d:",player);
      scanf("%d",&choice);
      if (choice==24)
        easteregg();
      if (endgame==10){//IF no one win
         printf("x----------TIE----------x\n");
         break;}
      if (choice==0){//if user enter zero
         printf("x-POSITION CANT BE ZERO-x\n");
         goto error;}
      if (choice>=10 || choice<0){//not valid no
         printf("x-------NOT VALID-------x\n");
         goto error;}
      if(choice>=1 && choice<=3)
        i=0;
      else if(choice>=4 && choice<=6)
        i=1;
      else if(choice>=7 && choice<=9)
        i=2;
      if(choice==1 || choice==4 || choice==7)
        j=0;
      else if(choice==2 || choice==5 || choice==8)
        j=1;
      else if(choice==3 || choice==6 || choice==9)
        j=2;
      if(data[i][j]==0){//if user enter in a prefilled place
        printf("x-POSITION NOT AVALABLE-x\n");
        goto error;
      }
      if(player==1){
         TTTE[i][j]='X';
         TTTV[i][j]='X';}
      if(player==2){
         TTTE[i][j]='O';
         TTTV[i][j]='O';}
      data[i][j]=0;
      for(i=0;i<=2;i++){
       if(TTTE[i][0]==TTTE[i][1] && TTTE[i][1]==TTTE[i][2]){//row
           if(TTTE[i][0]=='X')
             printf("x-----PLAYER 1 WINS-----x");
           else
             printf("x-----PLAYER 2 WINS-----x");
           win=1;
       }
       if(TTTE[0][i]==TTTE[1][i] && TTTE[1][i]==TTTE[2][i]){//column
           if(TTTE[0][i]=='X')
             printf("x-----PLAYER 1 WINS-----x");
           else
             printf("x-----PLAYER 2 WINS-----x");
           win=1;
       }
      }
      if(TTTE[0][0]==TTTE[1][1] && TTTE[1][1]==TTTE[2][2]){
        if(TTTE[0][0]=='X')
             printf("x-----PLAYER 1 WINS-----x");
        else
             printf("x-----PLAYER 2 WINS-----x");
        win=1;
      }
      else if(TTTE[2][0]==TTTE[1][1] && TTTE[1][1]==TTTE[0][2]){
        if(TTTE[2][0]=='X')
             printf("x-----PLAYER 1 WINS-----x");
        else
             printf("x-----PLAYER 2 WINS-----x");
        win=1;
      }
      if(win==1){
        printf("\n");
        dis_TTT(TTTV);
        break;}
      n++;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
int easteregg(){
    printf("DEVELOPER\n");
    printf("  _   _               _ _ _     __     __                        \n");
    printf(" | | | | __ _ _ __ __| (_) | __ \\ \\   / /__ _ __ _ __ ___   __ _ \n");
    printf(" | |_| |/ _` | '__/ _` | | |/ /  \\ \\ / / _ \\ '__| '_ ` _ \\ / _` |\n");
    printf(" |  _  | (_| | | | (_| | |   <    \\ V /  __/ |  | | | | | | (_| |\n");
    printf(" |_| |_|\\__,_|_|  \\__,_|_|_|\\_\\    \\_/ \\___|_|  |_| |_| |_|\\__,_|\n");}

int bye(){
    printf("★─▄█▀▀║░▄█▀▄║▄█▀▄║██▀▄║─★\n");
    printf("★─██║▀█║██║█║██║█║██║█║─★\n");
    printf("★─▀███▀║▀██▀║▀██▀║███▀║─★\n");
    printf("★───────────────────────★\n");
    printf("★───▐█▀▄─ ▀▄─▄▀ █▀▀──█───★\n");
    printf("★───▐█▀▀▄ ──█── █▀▀──▀───★\n");
    printf("★───▐█▄▄▀ ──▀── ▀▀▀──▄───★\n");
}
