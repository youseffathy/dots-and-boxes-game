int twoplayers_or_computer;
void grid_display( int row, int column, char array[row][column],int color_array[row][column],int no_of_moves1,int no_of_moves2,int score1,int score2,int remainig_lines,char playerA_name[],char playerB_name[],double hours,double minuts,double seconds )
{
    int i,j;
    HANDLE hconsole;
    hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
    printf("Exit enter e\nStart new game enter m\nSave game enter s\n");




    for(i=0; i<row; i++)
    {
        gotoxy(72,i+10);
        for(j=0; j<column; j++)
        {
            SetConsoleTextAttribute(hconsole,color_array[i][j]);
            printf("%c ",array[i][j]);
        }
        printf("\n");
    }


    SetConsoleTextAttribute(hconsole,15);
    gotoxy(72,j+14);
    printf("Undo enter 0000 ,Redo enter 1111\n");
    SetConsoleTextAttribute(hconsole,14);
    gotoxy(17,j+14);
    printf("Number of %s moves : %d\n",playerA_name,no_of_moves1);
    SetConsoleTextAttribute(hconsole,12);
    gotoxy(137,j+14);
    printf("Number of %s moves : %d\n",playerB_name,no_of_moves2);
    SetConsoleTextAttribute(hconsole,14);
    gotoxy(17,j+16);
    printf("%s 's score   %d\n",playerA_name,score1);
    SetConsoleTextAttribute(hconsole,12);
    gotoxy(137,j+16);
    printf("%s 's score  is %d\n\n",playerB_name,score2);
    SetConsoleTextAttribute(hconsole,15);
    gotoxy(72,j+16);
    printf("Remaining lines : %d",remainig_lines);
    gotoxy(72,j+18);
    printf("Time taken  %.0lf : %.0lf : %.0lf\n\n",hours,minuts,seconds);


    if(remainig_lines==0)
    {
        if (twoplayers_or_computer==1)
        {
            if (score1>score2)
            {

                SetConsoleTextAttribute(hconsole,14);
                gotoxy(74,j+20);
                printf("%s has won ",playerA_name);
                SetConsoleTextAttribute(hconsole,15);
            }

            else if (score2>score1)
            {


                SetConsoleTextAttribute(hconsole,12);
                gotoxy(74,j+20);
                printf("%s has won ",playerB_name);
                SetConsoleTextAttribute(hconsole,15);
            }
            else
            {
                gotoxy(74,j+20);
                printf("It is a draw ");
            }
        }

        else if (twoplayers_or_computer==2)
        {
            if (score1>score2)
            {

                SetConsoleTextAttribute(hconsole,14);
                gotoxy(74,j+20);
                printf("%s has won ",playerA_name);
                SetConsoleTextAttribute(hconsole,15);
            }
            else if (score2>score1)
            {
                SetConsoleTextAttribute(hconsole,12);
                gotoxy(64,j+20);
                printf("Computer  has won ");
                SetConsoleTextAttribute(hconsole,15);
            }
            else
            {
                gotoxy(74,j+20);
                printf("It is a draw ");
            }
        }

        printf("\n");
        printf("\n");




    }


}




timeee calculateCurrentTime(double a)
{
    timeee z ;
    z.hours=a/3600;
    z.hours= (int)z.hours%24;
    a=(int)a%3600;
    z.minuts=(int)a/60;
    z.minuts=(int)z.minuts%60;
    a=(int)a%60;
    z.seconds=a;
    return z ;

}



