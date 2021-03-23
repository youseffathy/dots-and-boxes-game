#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "player_rank.h"
#include "save_load.h"
#include "computer.h"
#include "type_erase_letters.h"
#include "check_for_closed_box_different_lines.h"
#include "grid_display.h"

timeee time2 ;

timeee calculateCurrentTime(double a) ;

void checkForPlaceInScoreArray();

void saveHighScoreArray();

void loadHighScoreArray();

void save(int file_no,int menu1,int twoplayer_computer,int i, int count3,int turn,int temp_undo_array[12],int count_no_redo,int count_no_undo,int different_lines_array[12],char array[11][11],int color_array[11][11],int different_lines_no_for_undo[12],player playerA,player playerB,char array2[23][23],int color_array2[23][23],int temp_undo_array2[60],int different_lines_array2[60],int different_lines_number_for_undo2[60]);

void Load(int file_no,int *menu1,int *twoplayer_computer,int *i, int *count3,int *turn,int temp_undo_array[12],int *count_no_redo,int *count_no_undo,int different_lines_array[12],char array[11][11],int color_array[11][11],int different_lines_no_for_undo[12],char playerAname[50],int *playerAnum_of_moves,int *playerAscore,char playerBname[50],int *playerBnum_of_moves,int *playerBscore,char array2[23][23],int color_array2[23][23],int temp_undo_array2[60],int different_lines_array2[60],int different_lines_number_for_undo2[60]);

void gotoxy(int x,int y);

void grid_display( int row, int column, char array[row][column],int color_array[row][column],int no_of_moves1,int no_of_moves2,int score1,int score2,int remainig_lines,char playerA_name[],char playerB_name[],double hours,double minuts,double seconds );

int different_lines(int n,int line_number,int array[]);

int CheckForClosedSquare(int n,int r1, int c1, int r2, int c2, int array[]);

void TypeLettersInTheBox(int length, int n,int r1, int c1, int r2, int c2, char array[length][length], int diffLineArr [n], int turn, int difference,int color_array[length][length] );

void erase_LettersInTheBox(int length, int n,int r1, int c1, int r2, int c2, char array[length][length], int diffLineArr [n], int turn, int difference,int color_array[length][length] );

int check_3_lines(int n,int array[],int a,int b, int c );

int Computer(int n, int diffLinesArray[]);


int menu1;
int twoplayers_or_computer;
char BackToMenu11[2000];



int main()
{


    char array[11][11];
    int different_lines_number[12];
    int i = 0 ;
    int j ;
    char c=178;
    int row1,row2,column1,column2;
    int line_number, temp ;
    int flag = 0 ;
    int turnIndicator = -1 ;
    int score1 = 0 ;
    int score2 = 0 ;
    int r1, c1, r2, c2 ;
    int NumbOfMov1=0;
    int NumbOfMov2=0;
    int color_array[11][11];
    char rows_column[2000];
    int count=0,count1=0,count2=11;
    int input_array[4];
    int undo_indicator=0;
    int temp_undo_array[12];
    int count3;
    int count4;
    int count_number_of_undo=0;
    int count_number_of_redo=0;
    int count_number_of_redo2;
    int file_no;
    char file_no11[2000];
    timeee time1;
    clock_t start, end;
    double cpu_time_used;
    double totalTime ;
    double seconds, minuts, hours ;
    time2.hours=0;
    time2.minuts=0;
    time2.seconds=0;
    char array2[23][23];
    int different_lines_number2[60];
    int color_array2[23][23];
    int temp_undo_array2[60];
    char menue11[2000];
    char twoplayers_or_computer11[2000];
    int different_lines_number2_for_undo[60];
    int different_lines_number_for_undo[12];
    int compooo ;
    int u ;
    player playerA;
    player playerB;
    int new_load_game;
    char new_load_game11[2000];
    char menuOrExit[2000];
    char BackToMenu[2000];

    HANDLE hconsole;
    hconsole=GetStdHandle(STD_OUTPUT_HANDLE);


TheBegin :
    menu1=0;
    turnIndicator = -1 ;
    score1 = 0 ;
    score2 = 0 ;
    NumbOfMov1=0;
    NumbOfMov2=0;
    count=0;
    count1=0;
    undo_indicator=0;
    count_number_of_undo=0;
    count_number_of_redo=0;
    count_number_of_redo2=0;
    time2.hours=0;
    time2.minuts=0;
    time2.seconds=0;
    row1=0;
    row2=0;
    column1=0;
    column2=0;


    for(i=0;i<12;i++)
    {
        rows_column[0]='\0';
        strcpy(high[i].name,"");
        high[i].score=0;

    }
    loadHighScoreArray();
    checkForPlaceInScoreArray();



    // pattern of 2x2

    for(i=0; i<12; i++)
    {
        temp_undo_array[i]=0;
        different_lines_number[i]=0;
        different_lines_number_for_undo[i]=0;
    }
    for(i=0; i<11; i++)
    {
        for(j=0; j<11; j++)
        {
            color_array[i][j]=15;
            array[i][j] = '\0';
        }
    }

    array[10][0]='1';
    array[10][4]='2';
    array[10][8]='3';
    array[0][10]='1';
    array[4][10]='2';
    array[8][10]='3';

    for(i=0; i<11; (i=i+4))
    {
        for(j=0; j<11; (j=j+4))
        {
            array[i][j]='O';
        }
    }

    // pattern of 5x5

    for(i=0; i<60; i++)
    {
        temp_undo_array2[i]=0;
        different_lines_number2[i]=0;
        different_lines_number2_for_undo[i]=0;
    }
    for(i=0; i<23; i++)
    {
        for(j=0; j<23; j++)
        {
            color_array2[i][j]=15;
            array2[i][j] = '\0';
        }
    }
    for(i=0; i<23; (i=i+4))
    {
        for(j=0; j<23; (j=j+4))
        {
            array2[i][j]='O';
        }
    }
    array2[22][0]='1';
    array2[22][4]='2';
    array2[22][8]='3';
    array2[22][12]='4';
    array2[22][16]='5';
    array2[22][20]='6';
    array2[0][22]='1';
    array2[4][22]='2';
    array2[8][22]='3';
    array2[12][22]='4';
    array2[16][22]='5';
    array2[20][22]='6';

    while(2>1)
    {

        system("cls");
        gotoxy(85,17);
        printf("Start game enter 1");
        gotoxy(85,19);
        printf("Load a game enter 2");
        gotoxy(85,21);
        printf("Top 10 players enter 3");
        gotoxy(85,23);
        printf("Exit enter e");
        gotoxy(85,25);
        gets(new_load_game11);
        if((new_load_game11[0]-'0')==1||(new_load_game11[0]-'0')==2)
        {
            new_load_game=new_load_game11[0]-'0';
            system("cls");
            break;
        }
        if((new_load_game11[0]-'0')==3)
        {
            while(2>1)
            {
                system("cls");
                gotoxy(85,17);
                printf("Top 10 players :");
                for(i=11; i>=2; i--)
                {
                    gotoxy(85,31-i);
                    printf("%s %d",high[i].name,high[i].score);
                }
                gotoxy(85,32-i);
                printf("back enter m");
                gotoxy(85,33-i);
                gets(BackToMenu);


                if(BackToMenu[0]=='m'||BackToMenu[0]=='M')
                {
                    goto TheBegin ;
                }
            }
        }
        if(new_load_game11[0]=='e'||new_load_game11[0]=='E')
        {
            exit(1);
        }
    }
    if(new_load_game==2)                //load game
    {
        while(2>1)
        {
savee :
            system("cls");
            gotoxy(85,17);
            printf("Enter the load file number ( 1 or 2 or 3 )");
            gotoxy(85,19);
            printf("back enter m");
            gotoxy(85,21);
            gets(file_no11);
            if((file_no11[0]-'0')==1||(file_no11[0]-'0')==2||(file_no11[0]-'0')==3)
            {

                file_no=file_no11[0]-'0';
                system("cls");
                break;
            }
            if(file_no11[0]=='m'||file_no11[0]=='M')
            {
                goto TheBegin ;
            }
        }

        Load(file_no,&menu1,&twoplayers_or_computer,&i,&count3,&turnIndicator,temp_undo_array,&count_number_of_redo,&count_number_of_undo,different_lines_number,array,color_array,different_lines_number_for_undo,playerA.name,&NumbOfMov1,&score1,playerB.name,&NumbOfMov2,&score2,array2,color_array2,temp_undo_array2,different_lines_number2,different_lines_number2_for_undo);
        if(menu1==0)
        {
            goto savee ;
        }
        if(menu1==2)
        {
            if (twoplayers_or_computer==1)
            {
                goto game_2x2_multi;
            }
            else if (twoplayers_or_computer==2)
            {
                goto game_2x2_single;
            }
        }
        else if(menu1==5)
        {
            if (twoplayers_or_computer==1)
            {
                goto game_5x5_multi;
            }
            else if (twoplayers_or_computer==2)
            {
                goto game_5x5_single;
            }
        }
    }
    else if(new_load_game==1)           //new game
    {

beg22 :
        while(2>1)
        {
            system("cls");
            gotoxy(85,17);
            printf("Beginner (2x2) enter 2");
            gotoxy(85,19);
            printf("Expert (5x5) enter 5");
            gotoxy(85,21);
            printf("Back enter m");
            gotoxy(85,23);
            gets(menue11);
            if((menue11[0]-'0')==2||(menue11[0]-'0')==5)
            {
                menu1=menue11[0]-'0';
                system("cls");
                break;
            }
            if(menue11[0]=='m'||menue11[0]=='M')
            {
                goto TheBegin ;
            }
        }
        if(menu1==2)
        {
            while(2>1)
            {
                system("cls");
                gotoxy(85,17);
                printf("Player vs player mode enter 1");
                gotoxy(85,19);
                printf("Player vs computer mode enter 2");
                gotoxy(85,21);
                printf("Back enter m");
                gotoxy(85,23);
                gets(twoplayers_or_computer11);
                if((twoplayers_or_computer11[0]-'0')==1||(twoplayers_or_computer11[0]-'0')==2)
                {
                    twoplayers_or_computer=twoplayers_or_computer11[0]-'0';
                    system("cls");
                    break;
                }
                if(twoplayers_or_computer11[0]=='m'||twoplayers_or_computer11[0]=='M')
                {
                    goto beg22 ;
                }
            }
            if(twoplayers_or_computer==1)
            {
                gotoxy(85,17);
                puts("Enter player A name:");
                gotoxy(85,19);
                scanf("%s",playerA.name);
                gotoxy(85,21);
                puts("Enter player B name:");
                gotoxy(85,23);
                scanf("%s",playerB.name);
                system("cls");
                grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,12,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);

                for(i=0,count3=12; i<12; i++,count3--)
                {
                    playerA.num_of_moves=NumbOfMov1;
                    playerB.num_of_moves=NumbOfMov2;
                    playerA.score=score1;
                    playerB.score=score2;
game_2x2_multi:
                    if(new_load_game==2)
                    {
                        grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);
                        new_load_game=0;
                    }
                    start = clock();
                    printf("\n\n");

                    if(turnIndicator==-1)
                    {
                        gotoxy(17,33);
                        SetConsoleTextAttribute(hconsole,14);
                        printf("%s's turn",playerA.name);
                        SetConsoleTextAttribute(hconsole,15);
                    }
                    else if(turnIndicator==1)
                    {
                        SetConsoleTextAttribute(hconsole,12);
                        gotoxy(137,33);
                        printf("%s's turn",playerB.name);
                        SetConsoleTextAttribute(hconsole,15);
                    }
                    printf("\n\n");
                    gets(rows_column);
                    count1=0;
                    if(rows_column[0]=='s'||rows_column[0]=='S')
                    {
                        printf("Enter the save file number\n");
                        scanf("%d",&file_no);
                        //save function
                        save(file_no,menu1,twoplayers_or_computer,i,count3,turnIndicator,temp_undo_array,count_number_of_redo,count_number_of_undo,different_lines_number,array,color_array,different_lines_number_for_undo,playerA,playerB,array2,color_array2,temp_undo_array2,different_lines_number2,different_lines_number2_for_undo);
                        input_array[0]=999;
                        input_array[1]=999;
                        input_array[2]=999;
                        input_array[3]=999;

                    }
                    else if (rows_column[0]=='m'||rows_column[0]=='M')
                    {
                        goto TheBegin ;
                    }
                    else if (rows_column[0]=='e'||rows_column[0]=='E')
                    {
                        exit(1);
                    }
                    for(count=0; count<200; count++)
                    {
                        if(isdigit(rows_column[count]))
                        {
                            input_array[count1]=rows_column[count]-'0';
                            count1++;
                            if(count1>3)
                            {
                                break;
                            }
                        }
                    }
                    row1=input_array[0];
                    column1=input_array[1];
                    row2=input_array[2];
                    column2=input_array[3];
                    if (row1==1&&row2==1&&column1==1&&column2==1&&(count_number_of_redo<count_number_of_undo)) //redo function
                    {
                        for(count2=0; count2<12; count2++)
                        {
                            if(temp_undo_array[count2]!=0)
                            {
                                count_number_of_redo++;
                                int line_no =temp_undo_array[count2];
                                temp_undo_array[count2]=0;
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                goto here1;
                            }
                        }
                    }
                    else if (row1==0&&row2==0&&column1==0&&column2==0&&i>0)           //undo function
                    {
                        for(count2=11; count2>=0; count2--)
                        {
                            if(different_lines_number[count2]!=0)
                            {
                                count_number_of_undo++;
                                temp_undo_array[count2]=different_lines_number[count2];
                                int line_no =different_lines_number[count2];
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                int score_modifier=CheckForClosedSquare(12,row1,column1,row2,column2,different_lines_number);
                                if (score_modifier!=0)
                                {
                                    if(turnIndicator==-1)
                                    {
                                        erase_LettersInTheBox(11,12,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array,different_lines_number,turnIndicator,score_modifier,color_array);
                                        score1=score1-score_modifier;
                                        turnIndicator=turnIndicator*-1;
                                    }
                                    else if (turnIndicator==1)
                                    {
                                        erase_LettersInTheBox(11,12,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array,different_lines_number,turnIndicator,score_modifier,color_array);
                                        score2=score2-score_modifier;
                                        turnIndicator=turnIndicator*-1;
                                    }
                                }
                                if(turnIndicator==-1)
                                {
                                    turnIndicator=(turnIndicator*-1);
                                    NumbOfMov2--;
                                }
                                else if(turnIndicator==1)
                                {
                                    turnIndicator=(turnIndicator*-1);
                                    NumbOfMov1--;
                                }
                                different_lines_number[count2]=0;
                                if(row1==row2&&(column1==column2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array[row1][column1+1]='\0';
                                    array[row1][column1+2]='\0';
                                    array[row1][column1+3]='\0';
                                }
                                else if(column1==column2&&(row1==row2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array[row1+1][column1]='\0';
                                    array[row1+2][column1]='\0';
                                    array[row1+3][column1]='\0';
                                }
                                system("cls");
                                end = clock();
                                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                                time1=calculateCurrentTime(cpu_time_used);
                                time2.hours+=time1.hours;
                                time2.minuts+=time1.minuts;
                                time2.seconds+=time1.seconds;
                                totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                                time2=calculateCurrentTime(totalTime);
                                i--;
                                count3++;
                                grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);
                                undo_indicator=1;
                                i--;
                                count3++;

                                break;
                            }
                        }
                    }
                    else if (row1>0&&row1<4&&row2>0&&row2<4&&column1>0&&column1<4&&column2>0&&column2<4)
                    {
                        count_number_of_redo=0;
                        count_number_of_undo=0;
                        undo_indicator=0;
                        for(count4; count4<12; count4++)
                        {
                            temp_undo_array[count4]=0;
                        }
                        // test cases checking the order of the dots
here1:
                        if (column1>column2)
                        {
                            temp=column1;
                            column1=column2;
                            column2=temp;
                        }
                        if (row1>row2)
                        {
                            temp=row1;
                            row1=row2;
                            row2=temp;
                        }
                        r1=row1;
                        c1=column1;
                        r2=row2;
                        c2=column2;
                        line_number=row1*1000+column1*100+row2*10+column2;

                        if (different_lines(12,line_number,different_lines_number))
                        {
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);
                            i--;
                            count3++;
                            printf("invalid input enter another one in the same line\n");
                            continue;
                        }

                        different_lines_number[i]=line_number;
                        if(row1==row2&&(column1==column2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array[row1][column1+1]='-';
                            array[row1][column1+2]='-';
                            array[row1][column1+3]='-';
                            if (turnIndicator==-1)
                            {
                                color_array[row1][column1+1]=14;
                                color_array[row1][column1+2]=14;
                                color_array[row1][column1+3]=14;
                            }
                            else
                            {
                                color_array[row1][column1+1]=12;
                                color_array[row1][column1+2]=12;
                                color_array[row1][column1+3]=12;
                            }
                        }
                        else if(column1==column2&&(row1==row2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array[row1+1][column1]='|';
                            array[row1+2][column1]='|';
                            array[row1+3][column1]='|';
                            if (turnIndicator==-1)
                            {
                                color_array[row1+1][column1]=14;
                                color_array[row1+2][column1]=14;
                                color_array[row1+3][column1]=14;
                            }
                            else
                            {
                                color_array[row1+1][column1]=12;
                                color_array[row1+2][column1]=12;
                                color_array[row1+3][column1]=12;
                            }
                        }
                        else
                        {
                            different_lines_number[i]=0;
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);
                            i--;
                            count3++;
                            printf("play again and enter valid input \n");
                            continue;
                        }
                        if(turnIndicator==-1)
                        {
                            NumbOfMov1+=1;
                        }
                        else if(turnIndicator==1)
                        {
                            NumbOfMov2+=1;
                        }
                        if (turnIndicator == (-1))
                        {
                            flag=score1;
                            score1=score1+CheckForClosedSquare(12,r1,c1,r2,c2,different_lines_number);
                        }
                        if(turnIndicator==1)
                        {
                            flag=score2;
                            score2=score2+CheckForClosedSquare(12,r1,c1,r2,c2,different_lines_number);
                        }
                        //type letter in the box closed
                        r1=4*r1-4;
                        c1=4*c1-4;
                        r2=4*r2-4;
                        c2=4*c2-4;

                        if(turnIndicator == (-1))
                        {
                            TypeLettersInTheBox(11,12,r1,c1,r2,c2,array, different_lines_number, turnIndicator,(score1-flag),color_array);
                        }
                        else if (turnIndicator==(1))
                        {
                            TypeLettersInTheBox(11,12,r1,c1,r2,c2,array, different_lines_number, turnIndicator,(score2-flag),color_array);
                        }
                        if (turnIndicator==-1)
                        {

                            if(flag==score1)
                            {
                                turnIndicator=turnIndicator*(-1);
                            }
                        }
                        else if (turnIndicator==1)
                        {
                            if(flag==score2)
                            {
                                turnIndicator=turnIndicator*(-1);
                            }
                        }
                        system("cls");
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,(count3-1),playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);

                    }
                    else
                    {
                        system("cls");

                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);

                        i--;
                        count3++;

                        printf("play again and enter  valid numbers in the same line\n");
                    }

                }
            }
            else if (twoplayers_or_computer==2)
            {
                gotoxy(85,17);
                puts("Enter player A name:");
                gotoxy(85,19);
                scanf("%s",playerA.name);
                system("cls");
                grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,12,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);

                for(i=0,count3=12; i<12; i++,count3--)
                {
                    playerA.num_of_moves=NumbOfMov1;
                    playerB.num_of_moves=NumbOfMov2;
                    playerA.score=score1;
                    playerB.score=score2;
                    strcpy(playerB.name,"computer");
                    printf("\n\n");
game_2x2_single:
                    if(new_load_game==2)
                    {
                        grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                        new_load_game=0;
                    }
                    start = clock();

                    if(turnIndicator==-1)
                    {
                        gotoxy(17,33);
                        SetConsoleTextAttribute(hconsole,14);
                        printf("%s 's turn\n\n",playerA.name);
                        SetConsoleTextAttribute(hconsole,15);
                        gets(rows_column);
                        count1=0;
                        if(rows_column[0]=='s'||rows_column[0]=='S')
                        {
                            printf("enter the save file number\n");
                            scanf("%d",&file_no);
                            //save function
                            save(file_no,menu1,twoplayers_or_computer,i,count3,turnIndicator,temp_undo_array,count_number_of_redo,count_number_of_undo,different_lines_number,array,color_array,different_lines_number_for_undo,playerA,playerB,array2,color_array2,temp_undo_array2,different_lines_number2,different_lines_number2_for_undo);
                        input_array[0]=999;
                        input_array[1]=999;
                        input_array[2]=999;
                        input_array[3]=999;
                        }
                        else if (rows_column[0]=='m'||rows_column[0]=='M')
                        {
                            goto TheBegin ;
                        }
                        else if (rows_column[0]=='e'||rows_column[0]=='E')
                        {
                            exit(1);
                        }
                        for(count=0; count<200; count++)
                        {
                            if(isdigit(rows_column[count]))
                            {
                                input_array[count1]=rows_column[count]-'0';
                                count1++;
                                if(count1>3)
                                {
                                    break;
                                }
                            }

                        }
                        row1=input_array[0];
                        column1=input_array[1];
                        row2=input_array[2];
                        column2=input_array[3];
                    }
                    else if(turnIndicator==1)
                    {
                        SetConsoleTextAttribute(hconsole,12);
                        printf("computer  turn");
                        SetConsoleTextAttribute(hconsole,15);

                        compooo=Computer(12,different_lines_number);
                        column2=compooo%10;
                        compooo=compooo/10;
                        row2=compooo%10;
                        compooo=compooo/10;
                        column1=compooo%10;
                        compooo=compooo/10;
                        row1=compooo;

                    }
                    printf("\n\n");
                    if (row1==1&&row2==1&&column1==1&&column2==1&&(count_number_of_redo<count_number_of_undo)) //redo function
                    {
there1:
                        count_number_of_redo2=0;
                        for(count2=0; count2<12; count2++)
                        {
                            if(temp_undo_array[count2]!=0)
                            {
                                count_number_of_redo2++;
                                count_number_of_redo++;
                                int line_no =abs(temp_undo_array[count2]);
                                temp_undo_array[count2]=0;
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                count2++;
                                goto here1111;

                            }
                        }
                    }
                    else if (row1==0&&row2==0&&column1==0&&column2==0&&i>0)           //undo function
                    {

                        for(count2=11; count2>=0; count2--)
                        {

                            if(different_lines_number_for_undo[count2]!=0)
                            {
                                while(different_lines_number_for_undo[count2]>0)
                                {
                                    count_number_of_undo++;
                                    temp_undo_array[count2]=different_lines_number_for_undo[count2];
                                    int line_no =abs(different_lines_number_for_undo[count2]);
                                    row1=line_no/1000;
                                    line_no=line_no%1000;
                                    column1=line_no/100;
                                    line_no=line_no%100;
                                    row2=line_no/10;
                                    line_no=line_no%10;
                                    column2=line_no;
                                    int score_modifier=CheckForClosedSquare(12,row1,column1,row2,column2,different_lines_number);
                                    if (score_modifier!=0)
                                    {
                                        erase_LettersInTheBox(11,12,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array,different_lines_number,turnIndicator,score_modifier,color_array);
                                        score2=score2-score_modifier;
                                        NumbOfMov2--;
                                    }
                                    else
                                    {
                                        NumbOfMov2--;
                                    }
                                    different_lines_number[count2]=0;
                                    different_lines_number_for_undo[count2]=0;
                                    if(row1==row2&&(column1==column2-1))
                                    {
                                        row1=4*row1-4;
                                        column1=4*column1-4;
                                        array[row1][column1+1]='\0';
                                        array[row1][column1+2]='\0';
                                        array[row1][column1+3]='\0';

                                    }
                                    else if(column1==column2&&(row1==row2-1))
                                    {
                                        row1=4*row1-4;
                                        column1=4*column1-4;
                                        array[row1+1][column1]='\0';
                                        array[row1+2][column1]='\0';
                                        array[row1+3][column1]='\0';

                                    }
                                    count2--;
                                    i--;
                                    count3++;
                                }
                                count_number_of_undo++;
                                temp_undo_array[count2]=different_lines_number_for_undo[count2];
                                int line_no =abs(different_lines_number_for_undo[count2]);
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                int score_modifier=CheckForClosedSquare(12,row1,column1,row2,column2,different_lines_number);
                                if (score_modifier!=0)
                                {
                                    erase_LettersInTheBox(11,12,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array,different_lines_number,turnIndicator,score_modifier,color_array);
                                    score1=score1-score_modifier;
                                    NumbOfMov1--;

                                }

                                else
                                {
                                    NumbOfMov1--;
                                }

                                different_lines_number[count2]=0;
                                different_lines_number_for_undo[count2]=0;
                                if(row1==row2&&(column1==column2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array[row1][column1+1]='\0';
                                    array[row1][column1+2]='\0';
                                    array[row1][column1+3]='\0';

                                }
                                else if(column1==column2&&(row1==row2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array[row1+1][column1]='\0';
                                    array[row1+2][column1]='\0';
                                    array[row1+3][column1]='\0';
                                }
                                system("cls");
                                end = clock();
                                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                                time1=calculateCurrentTime(cpu_time_used);
                                time2.hours+=time1.hours;
                                time2.minuts+=time1.minuts;
                                time2.seconds+=time1.seconds;
                                totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                                time2=calculateCurrentTime(totalTime);
                                i--;
                                count3++;
                                grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                                i--;
                                count3++;

                                break;
                            }
                        }

                    }
                    else if (row1>0&&row1<4&&row2>0&&row2<4&&column1>0&&column1<4&&column2>0&&column2<4)
                    {
                        count_number_of_redo=0;
                        count_number_of_undo=0;
                        undo_indicator=0;
                        for(count4; count4<12; count4++)
                        {
                            temp_undo_array[count4]=0;
                        }
                        // test cases checking the order of the dots
here1111:
                        if (column1>column2)
                        {
                            temp=column1;
                            column1=column2;
                            column2=temp;
                        }
                        if (row1>row2)
                        {
                            temp=row1;
                            row1=row2;
                            row2=temp;
                        }
                        r1=row1;
                        c1=column1;
                        r2=row2;
                        c2=column2;

                        line_number=row1*1000+column1*100+row2*10+column2;

                        if (different_lines(12,line_number,different_lines_number))
                        {
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                            i--;
                            count3++;
                            printf("invalid input enter another one in the same line\n");
                            continue;
                        }

                        different_lines_number[i]=line_number;

                        if(turnIndicator==-1)
                        {
                            different_lines_number_for_undo[i]=line_number*-1;
                        }
                        else
                        {
                            different_lines_number_for_undo[i]=line_number;
                        }

                        if(row1==row2&&(column1==column2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array[row1][column1+1]='-';
                            array[row1][column1+2]='-';
                            array[row1][column1+3]='-';
                            if (turnIndicator==-1)
                            {
                                color_array[row1][column1+1]=14;
                                color_array[row1][column1+2]=14;
                                color_array[row1][column1+3]=14;
                            }
                            else
                            {
                                color_array[row1][column1+1]=12;
                                color_array[row1][column1+2]=12;
                                color_array[row1][column1+3]=12;
                            }
                        }
                        else if(column1==column2&&(row1==row2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array[row1+1][column1]='|';
                            array[row1+2][column1]='|';
                            array[row1+3][column1]='|';
                            if (turnIndicator==-1)
                            {
                                color_array[row1+1][column1]=14;
                                color_array[row1+2][column1]=14;
                                color_array[row1+3][column1]=14;
                            }
                            else
                            {
                                color_array[row1+1][column1]=12;
                                color_array[row1+2][column1]=12;
                                color_array[row1+3][column1]=12;
                            }
                        }
                        else
                        {
                            different_lines_number_for_undo[i]=0;
                            different_lines_number[i]=0;
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                            i--;
                            count3++;
                            printf("play again and enter valid input \n");

                            continue;
                        }


                        if(turnIndicator==-1)
                        {
                            NumbOfMov1+=1;
                        }
                        else if(turnIndicator==1)
                        {
                            NumbOfMov2+=1;
                        }

                        if (turnIndicator == (-1))
                        {
                            flag=score1;
                            score1=score1+CheckForClosedSquare(12,r1,c1,r2,c2,different_lines_number);
                        }
                        if(turnIndicator==1)
                        {
                            flag=score2;
                            score2=score2+CheckForClosedSquare(12,r1,c1,r2,c2,different_lines_number);
                        }
                        //type letter in the box closed
                        r1=4*r1-4;
                        c1=4*c1-4;
                        r2=4*r2-4;
                        c2=4*c2-4;

                        if(turnIndicator == (-1))
                        {
                            TypeLettersInTheBox(11,12,r1,c1,r2,c2,array, different_lines_number, turnIndicator,(score1-flag),color_array);
                        }
                        else if (turnIndicator==(1))
                        {
                            TypeLettersInTheBox(11,12,r1,c1,r2,c2,array, different_lines_number, turnIndicator,(score2-flag),color_array);
                        }

                        if (turnIndicator==-1)
                        {

                            if(flag==score1)
                            {
                                turnIndicator=turnIndicator*(-1);
                            }
                        }
                        else if (turnIndicator==1)
                        {
                            if(flag==score2)
                            {
                                turnIndicator=turnIndicator*(-1);

                            }
                        }
                        system("cls");
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,(count3-1),playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                        if(count_number_of_redo!=0)
                        {
                            if(temp_undo_array[count2]>0)
                            {
                                count3--;
                                i++;
                                goto there1;
                            }
                        }
                    }
                    else
                    {
                        system("cls");

                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                        i--;
                        count3++;
                        printf("play again and enter  valid numbers in the same line\n");
                    }
                }
            }
        }
        else if (menu1==5)
        {
            while(2>1)
            {
                system("cls");
                gotoxy(85,17);
                printf("Player vs player mode enter 1");
                gotoxy(85,19);
                printf("Player vs computer mode enter 2");
                gotoxy(85,21);
                printf("Back enter m");
                gotoxy(85,23);
                gets(twoplayers_or_computer11);
                if((twoplayers_or_computer11[0]-'0')==1||(twoplayers_or_computer11[0]-'0')==2)
                {
                    twoplayers_or_computer=twoplayers_or_computer11[0]-'0';
                    system("cls");
                    break;
                }
                if(twoplayers_or_computer11[0]=='m'||twoplayers_or_computer11[0]=='M')
                {
                    goto beg22 ;
                }
            }
            if(twoplayers_or_computer==1)
            {
                gotoxy(85,17);
                puts("Enter player A name:");
                gotoxy(85,19);
                scanf("%s",playerA.name);
                gotoxy(85,21);
                puts("Enter player B name:");
                gotoxy(85,23);
                scanf("%s",playerB.name);
                system("cls");
                grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,60,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds );

                for(i=0,count3=60; i<60; i++,count3--)
                {
                    playerA.num_of_moves=NumbOfMov1;
                    playerB.num_of_moves=NumbOfMov2;
                    playerA.score=score1;
                    playerB.score=score2;

game_5x5_multi:
                    if(new_load_game==2)
                    {
                        grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds );
                        new_load_game=0;
                    }
                    start = clock();
                    printf("\n\n");
                    if(turnIndicator==-1)
                    {
                        gotoxy(17,33);
                        SetConsoleTextAttribute(hconsole,14);
                        printf("%s 's turn",playerA.name);
                        SetConsoleTextAttribute(hconsole,15);
                    }
                    else if(turnIndicator==1)
                    {
                        SetConsoleTextAttribute(hconsole,12);
                        gotoxy(137,33);
                        printf("%s 's turn",playerB.name);
                        SetConsoleTextAttribute(hconsole,15);
                    }

                    printf("\n\n");
                    gets(rows_column);
                    count1=0;
                    if(rows_column[0]=='s'||rows_column[0]=='S')
                    {
                        printf("Enter the save file number\n");
                        scanf("%d",&file_no);
                        //save function
                        save(file_no,menu1,twoplayers_or_computer,i,count3,turnIndicator,temp_undo_array,count_number_of_redo,count_number_of_undo,different_lines_number,array,color_array,different_lines_number_for_undo,playerA,playerB,array2,color_array2,temp_undo_array2,different_lines_number2,different_lines_number2_for_undo);
                        input_array[0]=999;
                        input_array[1]=999;
                        input_array[2]=999;
                        input_array[3]=999;
                    }
                    else if (rows_column[0]=='m'||rows_column[0]=='M')
                    {
                        goto TheBegin ;
                    }
                    else if (rows_column[0]=='e'||rows_column[0]=='E')
                    {
                        exit(1);
                    }
                    for(count=0; count<200; count++)
                    {
                        if(isdigit(rows_column[count]))
                        {
                            input_array[count1]=rows_column[count]-'0';
                            count1++;
                            if(count1>3)
                            {
                                break;
                            }
                        }

                    }
                    row1=input_array[0];
                    column1=input_array[1];
                    row2=input_array[2];
                    column2=input_array[3];
                    if (row1==1&&row2==1&&column1==1&&column2==1&&(count_number_of_redo<count_number_of_undo)) //redo function
                    {
                        for(count2=0; count2<60; count2++)
                        {
                            if(temp_undo_array2[count2]!=0)
                            {
                                count_number_of_redo++;
                                int line_no =temp_undo_array2[count2];
                                temp_undo_array2[count2]=0;
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                goto here11;
                            }
                        }
                    }

                    else if (row1==0&&row2==0&&column1==0&&column2==0&&i>0)           //undo function
                    {

                        for(count2=59; count2>=0; count2--)
                        {
                            if(different_lines_number2[count2]!=0)
                            {
                                count_number_of_undo++;
                                temp_undo_array2[count2]=different_lines_number2[count2];
                                int line_no =different_lines_number2[count2];
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                int score_modifier=CheckForClosedSquare(60,row1,column1,row2,column2,different_lines_number2);
                                if (score_modifier!=0)
                                {
                                    if(turnIndicator==-1)
                                    {
                                        erase_LettersInTheBox(23,60,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array2,different_lines_number2,turnIndicator,score_modifier,color_array2);
                                        score1=score1-score_modifier;
                                        turnIndicator=turnIndicator*-1;
                                    }
                                    else if (turnIndicator==1)
                                    {
                                        erase_LettersInTheBox(23,60,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array2,different_lines_number2,turnIndicator,score_modifier,color_array2);
                                        score2=score2-score_modifier;
                                        turnIndicator=turnIndicator*-1;
                                    }
                                }

                                if(turnIndicator==-1)
                                {
                                    turnIndicator=(turnIndicator*-1);
                                    NumbOfMov2--;


                                }
                                else if(turnIndicator==1)
                                {
                                    turnIndicator=(turnIndicator*-1);
                                    NumbOfMov1--;
                                }

                                different_lines_number2[count2]=0;
                                if(row1==row2&&(column1==column2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array2[row1][column1+1]='\0';
                                    array2[row1][column1+2]='\0';
                                    array2[row1][column1+3]='\0';

                                }
                                else if(column1==column2&&(row1==row2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array2[row1+1][column1]='\0';
                                    array2[row1+2][column1]='\0';
                                    array2[row1+3][column1]='\0';

                                }
                                system("cls");
                                end = clock();
                                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                                time1=calculateCurrentTime(cpu_time_used);
                                time2.hours+=time1.hours;
                                time2.minuts+=time1.minuts;
                                time2.seconds+=time1.seconds;
                                totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                                time2=calculateCurrentTime(totalTime);
                                i--;
                                count3++;
                                grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds );
                                undo_indicator=1;
                                i--;
                                count3++;
                                break;
                            }
                        }
                    }
                    else if (row1>0&&row1<7&&row2>0&&row2<7&&column1>0&&column1<7&&column2>0&&column2<7)
                    {
                        count_number_of_redo=0;
                        count_number_of_undo=0;
                        undo_indicator=0;
                        for(count4; count4<60; count4++)
                        {
                            temp_undo_array2[count4]=0;
                        }
                        // test cases checking the order of the dots
here11:
                        if (column1>column2)
                        {
                            temp=column1;
                            column1=column2;
                            column2=temp;
                        }
                        if (row1>row2)
                        {
                            temp=row1;
                            row1=row2;
                            row2=temp;
                        }
                        r1=row1;
                        c1=column1;
                        r2=row2;
                        c2=column2;
                        line_number=row1*1000+column1*100+row2*10+column2;

                        if (different_lines(60,line_number,different_lines_number2))
                        {
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);

                            i--;
                            count3++;
                            printf("invalid input enter another one in the same line\n");

                            continue;
                        }
                        different_lines_number2[i]=line_number;

                        if(row1==row2&&(column1==column2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array2[row1][column1+1]='-';
                            array2[row1][column1+2]='-';
                            array2[row1][column1+3]='-';
                            if (turnIndicator==-1)
                            {
                                color_array2[row1][column1+1]=14;
                                color_array2[row1][column1+2]=14;
                                color_array2[row1][column1+3]=14;
                            }
                            else
                            {
                                color_array2[row1][column1+1]=12;
                                color_array2[row1][column1+2]=12;
                                color_array2[row1][column1+3]=12;
                            }
                        }
                        else if(column1==column2&&(row1==row2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array2[row1+1][column1]='|';
                            array2[row1+2][column1]='|';
                            array2[row1+3][column1]='|';
                            if (turnIndicator==-1)
                            {
                                color_array2[row1+1][column1]=14;
                                color_array2[row1+2][column1]=14;
                                color_array2[row1+3][column1]=14;
                            }
                            else
                            {
                                color_array2[row1+1][column1]=12;
                                color_array2[row1+2][column1]=12;
                                color_array2[row1+3][column1]=12;
                            }
                        }
                        else
                        {
                            different_lines_number2[i]=0;
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);
                            i--;
                            count3++;
                            printf("play again and enter valid input \n");
                            continue;
                        }

                        if(turnIndicator==-1)
                        {
                            NumbOfMov1+=1;
                        }
                        else if(turnIndicator==1)
                        {
                            NumbOfMov2+=1;
                        }

                        if (turnIndicator == (-1))
                        {
                            flag=score1;
                            score1=score1+CheckForClosedSquare(60,r1,c1,r2,c2,different_lines_number2);
                        }
                        if(turnIndicator==1)
                        {
                            flag=score2;
                            score2=score2+CheckForClosedSquare(60,r1,c1,r2,c2,different_lines_number2);
                        }
                        //type letter in the box closed
                        r1=4*r1-4;
                        c1=4*c1-4;
                        r2=4*r2-4;
                        c2=4*c2-4;

                        if(turnIndicator == (-1))
                        {
                            TypeLettersInTheBox(23,60,r1,c1,r2,c2,array2, different_lines_number2, turnIndicator,(score1-flag),color_array2);
                        }
                        else if (turnIndicator==(1))
                        {
                            TypeLettersInTheBox(23,60,r1,c1,r2,c2,array2, different_lines_number2, turnIndicator,(score2-flag),color_array2);
                        }
                        if (turnIndicator==-1)
                        {
                            if(flag==score1)
                            {
                                turnIndicator=turnIndicator*(-1);
                            }
                        }
                        else if (turnIndicator==1)
                        {
                            if(flag==score2)
                            {
                                turnIndicator=turnIndicator*(-1);

                            }
                        }
                        system("cls");
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,(count3-1),playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);
                        }
                    else
                    {
                        system("cls");
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);

                        grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,(count3),playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);

                        i--;
                        count3++;
                        printf("play again and enter  valid numbers in the same line\n");
                    }
                }
            }
            else if (twoplayers_or_computer==2)
            {
                gotoxy(85,17);
                puts("Enter player A name:");
                gotoxy(85,19);
                scanf("%s",playerA.name);
                system("cls");

                grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,60,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds );

                for(i=0,count3=60; i<60; i++,count3--)
                {
                    playerA.num_of_moves=NumbOfMov1;
                    playerB.num_of_moves=NumbOfMov2;
                    playerA.score=score1;
                    playerB.score=score2;
                    strcpy(playerB.name,"computer");

                game_5x5_single:
                    if(new_load_game==2)
                    {
                        grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds );
                        new_load_game=0;
                    }
                    start = clock();
                    printf("\n\n");
                    if(turnIndicator==-1)
                    {
                        gotoxy(17,33);
                        SetConsoleTextAttribute(hconsole,14);
                        printf("%s 's turn \n\n",playerA.name);
                        SetConsoleTextAttribute(hconsole,15);

                        gets(rows_column);

                        count1=0;
                        if(rows_column[0]=='s'||rows_column[0]=='S')
                        {
                            printf("enter the save file number\n");
                            scanf("%d",&file_no);
                            //save function
                            save(file_no,menu1,twoplayers_or_computer,i,count3,turnIndicator,temp_undo_array,count_number_of_redo,count_number_of_undo,different_lines_number,array,color_array,different_lines_number_for_undo,playerA,playerB,array2,color_array2,temp_undo_array2,different_lines_number2,different_lines_number2_for_undo);
                        input_array[0]=999;
                        input_array[1]=999;
                        input_array[2]=999;
                        input_array[3]=999;
                        }
                        else if (rows_column[0]=='m'||rows_column[0]=='M')
                        {
                            goto TheBegin ;
                        }
                        else if (rows_column[0]=='e'||rows_column[0]=='E')
                        {
                            exit(1);
                        }
                        for(count=0; count<200; count++)
                        {
                            if(isdigit(rows_column[count]))
                            {
                                input_array[count1]=rows_column[count];
                                count1++;
                                if(count1>3)
                                {
                                    break;
                                }
                            }
                        }
                        row1=rows_column[0]-'0';
                        column1=rows_column[1]-'0';
                        row2=rows_column[2]-'0';
                        column2=rows_column[3]-'0';
                    }
                    else if(turnIndicator==1)
                    {
                        SetConsoleTextAttribute(hconsole,12);
                        printf("computer B turn");
                        SetConsoleTextAttribute(hconsole,15);
                        printf("\n\n");
                        compooo=Computer(60,different_lines_number2);
                        column2=compooo%10;
                        compooo=compooo/10;
                        row2=compooo%10;
                        compooo=compooo/10;
                        column1=compooo%10;
                        compooo=compooo/10;
                        row1=compooo;
                    }

                    for(u=0; u<4; u++)
                    {
                        rows_column[u]='\0';
                    }
                    if (row1==1&&row2==1&&column1==1&&column2==1&&(count_number_of_redo<count_number_of_undo)) //redo function
                    {
there:
                        count_number_of_redo2=0;
                        for(count2=0; count2<60; count2++)
                        {
                            if(temp_undo_array2[count2]!=0)
                            {
                                count_number_of_redo2++;
                                count_number_of_redo++;
                                int line_no =abs(temp_undo_array2[count2]);
                                temp_undo_array2[count2]=0;
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                count2++;
                                goto here111;

                            }
                        }
                    }

                    else if (row1==0&&row2==0&&column1==0&&column2==0&&i>0)           //undo function
                    {

                        for(count2=59; count2>=0; count2--)
                        {

                            if(different_lines_number2_for_undo[count2]!=0)
                            {
                                while(different_lines_number2_for_undo[count2]>0)
                                {
                                    count_number_of_undo++;
                                    temp_undo_array2[count2]=different_lines_number2_for_undo[count2];
                                    int line_no =abs(different_lines_number2_for_undo[count2]);
                                    row1=line_no/1000;
                                    line_no=line_no%1000;
                                    column1=line_no/100;
                                    line_no=line_no%100;
                                    row2=line_no/10;
                                    line_no=line_no%10;
                                    column2=line_no;
                                    int score_modifier=CheckForClosedSquare(60,row1,column1,row2,column2,different_lines_number2);
                                    if (score_modifier!=0)
                                    {
                                        erase_LettersInTheBox(23,60,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array2,different_lines_number2,turnIndicator,score_modifier,color_array2);
                                        score2=score2-score_modifier;
                                        NumbOfMov2--;
                                    }
                                    else
                                    {
                                        NumbOfMov2--;
                                    }

                                    different_lines_number2[count2]=0;
                                    different_lines_number2_for_undo[count2]=0;
                                    if(row1==row2&&(column1==column2-1))
                                    {
                                        row1=4*row1-4;
                                        column1=4*column1-4;
                                        array2[row1][column1+1]='\0';
                                        array2[row1][column1+2]='\0';
                                        array2[row1][column1+3]='\0';

                                    }
                                    else if(column1==column2&&(row1==row2-1))
                                    {
                                        row1=4*row1-4;
                                        column1=4*column1-4;
                                        array2[row1+1][column1]='\0';
                                        array2[row1+2][column1]='\0';
                                        array2[row1+3][column1]='\0';
                                    }
                                    count2--;
                                    i--;
                                    count3++;

                                    printf("%d ",temp_undo_array2[count2]);
                                }
                                count_number_of_undo++;
                                temp_undo_array2[count2]=different_lines_number2_for_undo[count2];
                                int line_no =abs(different_lines_number2_for_undo[count2]);
                                row1=line_no/1000;
                                line_no=line_no%1000;
                                column1=line_no/100;
                                line_no=line_no%100;
                                row2=line_no/10;
                                line_no=line_no%10;
                                column2=line_no;
                                int score_modifier=CheckForClosedSquare(60,row1,column1,row2,column2,different_lines_number2);
                                if (score_modifier!=0)
                                {
                                    erase_LettersInTheBox(23,60,(4*row1-4),(4*column1-4),(4*row2-4),(4*column2-4),array2,different_lines_number2,turnIndicator,score_modifier,color_array2);
                                    score1=score1-score_modifier;
                                    NumbOfMov1--;
                                }
                                else
                                {
                                    NumbOfMov1--;
                                }
                                different_lines_number2[count2]=0;
                                different_lines_number2_for_undo[count2]=0;
                                if(row1==row2&&(column1==column2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array2[row1][column1+1]='\0';
                                    array2[row1][column1+2]='\0';
                                    array2[row1][column1+3]='\0';
                                }
                                else if(column1==column2&&(row1==row2-1))
                                {
                                    row1=4*row1-4;
                                    column1=4*column1-4;
                                    array2[row1+1][column1]='\0';
                                    array2[row1+2][column1]='\0';
                                    array2[row1+3][column1]='\0';
                                }
                                system("cls");
                                end = clock();
                                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                                time1=calculateCurrentTime(cpu_time_used);
                                time2.hours+=time1.hours;
                                time2.minuts+=time1.minuts;
                                time2.seconds+=time1.seconds;
                                totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                                time2=calculateCurrentTime(totalTime);
                                i--;
                                count3++;
                                grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                                i--;
                                count3++;
                                break;
                            }
                        }
                    }
                    else if (row1>0&&row1<7&&row2>0&&row2<7&&column1>0&&column1<7&&column2>0&&column2<7)
                    {
                        count_number_of_redo=0;
                        count_number_of_undo=0;
                        for(count4; count4<60; count4++)
                        {
                            temp_undo_array2[count4]=0;
                        }
                        // test cases checking the order of the dots
here111:
                        if (column1>column2)
                        {
                            temp=column1;
                            column1=column2;
                            column2=temp;
                        }
                        if (row1>row2)
                        {
                            temp=row1;
                            row1=row2;
                            row2=temp;
                        }
                        r1=row1;
                        c1=column1;
                        r2=row2;
                        c2=column2;
                        line_number=(row1*1000+column1*100+row2*10+column2);
                        if (different_lines(60,line_number,different_lines_number2))
                        {
                            system("cls");
                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
                            i--;
                            count3++;
                            printf("invalid input enter another one in the same line\n");
                            continue;
                        }

                        different_lines_number2[i]=line_number;
                        if(turnIndicator==-1)
                        {
                            different_lines_number2_for_undo[i]=line_number*-1;
                        }
                        else
                        {
                            different_lines_number2_for_undo[i]=line_number;
                        }

                        if(row1==row2&&(column1==column2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array2[row1][column1+1]='-';
                            array2[row1][column1+2]='-';
                            array2[row1][column1+3]='-';
                            if (turnIndicator==-1)
                            {
                                color_array2[row1][column1+1]=14;
                                color_array2[row1][column1+2]=14;
                                color_array2[row1][column1+3]=14;
                            }
                            else
                            {
                                color_array2[row1][column1+1]=12;
                                color_array2[row1][column1+2]=12;
                                color_array2[row1][column1+3]=12;
                            }
                        }
                        else if(column1==column2&&(row1==row2-1))
                        {
                            row1=4*row1-4;
                            column1=4*column1-4;
                            array2[row1+1][column1]='|';
                            array2[row1+2][column1]='|';
                            array2[row1+3][column1]='|';
                            if (turnIndicator==-1)
                            {
                                color_array2[row1+1][column1]=14;
                                color_array2[row1+2][column1]=14;
                                color_array2[row1+3][column1]=14;
                            }
                            else
                            {
                                color_array2[row1+1][column1]=12;
                                color_array2[row1+2][column1]=12;
                                color_array2[row1+3][column1]=12;
                            }
                        }
                        else
                        {
                            different_lines_number2_for_undo[i]=0;
                            different_lines_number2[i]=0;
                            system("cls");

                            end = clock();
                            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                            time1=calculateCurrentTime(cpu_time_used);
                            time2.hours+=time1.hours;
                            time2.minuts+=time1.minuts;
                            time2.seconds+=time1.seconds;
                            totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                            time2=calculateCurrentTime(totalTime);
                            grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds );
                            i--;
                            count3++;
                            printf("play again and enter valid input \n");

                            continue;
                        }
                        if(turnIndicator==-1)
                        {
                            NumbOfMov1+=1;
                        }
                        else if(turnIndicator==1)
                        {
                            NumbOfMov2+=1;
                        }
                        if (turnIndicator == (-1))
                        {
                            flag=score1;
                            score1=score1+CheckForClosedSquare(60,r1,c1,r2,c2,different_lines_number2);
                        }
                        if(turnIndicator==1)
                        {
                            flag=score2;
                            score2=score2+CheckForClosedSquare(60,r1,c1,r2,c2,different_lines_number2);
                        }
                        //type letter in the box closed
                        r1=4*r1-4;
                        c1=4*c1-4;
                        r2=4*r2-4;
                        c2=4*c2-4;

                        if(turnIndicator == (-1))
                        {
                            TypeLettersInTheBox(23,60,r1,c1,r2,c2,array2, different_lines_number2, turnIndicator,(score1-flag),color_array2);
                        }
                        else if (turnIndicator==(1))
                        {
                            TypeLettersInTheBox(23,60,r1,c1,r2,c2,array2, different_lines_number2, turnIndicator,(score2-flag),color_array2);
                        }

                        if (turnIndicator==-1)
                        {

                            if(flag==score1)
                            {
                                turnIndicator=turnIndicator*(-1);
                            }
                        }
                        else if (turnIndicator==1)
                        {
                            if(flag==score2)
                            {
                                turnIndicator=turnIndicator*(-1);

                            }
                        }
                        system("cls");
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,(count3-1),playerA.name,"computer",time2.hours,time2.minuts,time2.seconds );

                        if(count_number_of_redo!=0)
                        {
                            if(temp_undo_array2[count2]>0)
                            {
                                count3--;
                                i++;
                                goto there;
                            }
                        }
                    }
                    else
                    {
                        system("cls");
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        time1=calculateCurrentTime(cpu_time_used);
                        time2.hours+=time1.hours;
                        time2.minuts+=time1.minuts;
                        time2.seconds+=time1.seconds;
                        totalTime=time2.hours*3600+time2.minuts*60+time2.seconds;
                        time2=calculateCurrentTime(totalTime);
                        grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds );
                        i--;
                        count3++;
                        printf("play again and enter  valid numbers in the same line\n");
                    }
                }
            }
        }
    }



    if (twoplayers_or_computer==1)
    {
        if (score1>score2)
        {
            if (menu1==2)
            {


                strcpy(high[1].name,playerA.name);
                high[1].score=score1;
                checkForPlaceInScoreArray();
                saveHighScoreArray();

            }
            else if (menu1==5)
            {

                strcpy(high[1].name,playerA.name);
                high[1].score=score1;
                checkForPlaceInScoreArray();
                saveHighScoreArray();


            }



        }
        else if (score2>score1)
        {

            if (menu1==2)
            {

                strcpy(high[1].name,playerB.name);
                high[1].score=score2;
                checkForPlaceInScoreArray();
                saveHighScoreArray();

            }
            else if (menu1==5)
            {


                strcpy(high[1].name,playerB.name);
                high[1].score=score2;
                checkForPlaceInScoreArray();
                saveHighScoreArray();

            }

        }

    }
    else if (twoplayers_or_computer==2)
    {
        if (score1>score2)
        {

            if (menu1==2)
            {

                strcpy(high[1].name,playerA.name);
                high[1].score=score1;
                checkForPlaceInScoreArray();
                saveHighScoreArray();

            }
            else if (menu1==5)
            {


                strcpy(high[1].name,playerA.name);
                high[1].score=score1;
                checkForPlaceInScoreArray();
                saveHighScoreArray();

            }

        }

    }












    while(2>1)
    {
        gets(BackToMenu11);
        if(BackToMenu11[0]=='m'||BackToMenu11[0]=='M')
        {
            goto TheBegin ;
        }
        if(BackToMenu11[0]=='e'||BackToMenu11[0]=='E')
        {
            exit(1);
        }
        system("cls");
        if(menu1==2)
        {
            if(twoplayers_or_computer==1)
            {
                grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds);

            }
            else if(twoplayers_or_computer==2)
            {
                grid_display( 11, 11, array, color_array,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);

            }
        }
        else if(menu1==5)
        {
            if(twoplayers_or_computer==1)
            {
                grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,playerB.name,time2.hours,time2.minuts,time2.seconds );
            }
            else if(twoplayers_or_computer==2)
            {
                grid_display( 23, 23, array2, color_array2,NumbOfMov1,NumbOfMov2,score1,score2,count3,playerA.name,"computer",time2.hours,time2.minuts,time2.seconds);
            }
        }

    }



    return 0;
}
