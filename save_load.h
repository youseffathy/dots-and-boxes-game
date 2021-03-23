FILE *save1;
typedef struct
{
    char name[50];
    int score;
    int num_of_moves;

} player;
typedef struct
{
    double hours ;
    double minuts ;
    double seconds ;

} timeee;
timeee time2 ;
void save(int file_no,int menu1,int twoplayer_computer,int i, int count3,int turn,int temp_undo_array[12],int count_no_redo,int count_no_undo,int different_lines_array[12],char array[11][11],int color_array[11][11],int different_lines_no_for_undo[12],player playerA,player playerB,char array2[23][23],int color_array2[23][23],int temp_undo_array2[60],int different_lines_array2[60],int different_lines_number_for_undo2[60])
{
    int j,k;
    if(file_no==1)
    {
        save1 = fopen("save1.txt","w");
    }
    else if (file_no==2)
    {
        save1 = fopen("save2.txt","w");
    }
    else if (file_no==3)
    {
        save1 = fopen("save3.txt","w");
    }
    fprintf(save1,"%d %d %d %d %d ",menu1,twoplayer_computer,i,count3,turn);
    fprintf(save1,"%d %d ",count_no_redo,count_no_undo);
    for(j=0; j<11; j++)
    {
        for(k=0; k<11; k++)
        {
            fprintf(save1,"%c",array[j][k]);
        }
    }
    fprintf(save1," ");
    for(j=0; j<11; j++)
    {
        for(k=0; k<11; k++)
        {
            fprintf(save1,"%d ",color_array[j][k]);
        }
    }
    for(j=0; j<12; j++)
    {
        fprintf(save1,"%d ",different_lines_no_for_undo[j]);
    }
    fprintf(save1,"%s %d %d %s %d %d ",playerA.name,playerA.num_of_moves,playerA.score,playerB.name,playerB.num_of_moves,playerB.score);
    for(j=0; j<23; j++)
    {
        for(k=0; k<23; k++)
        {
            fprintf(save1,"%c",array2[j][k]);
        }
    }
    fprintf(save1," ");
    for(j=0; j<23; j++)
    {
        for(k=0; k<23; k++)
        {
            fprintf(save1,"%d ",color_array2[j][k]);
        }
    }
    for(j=0; j<60; j++)
    {
        fprintf(save1,"%d ",temp_undo_array2[j]);
    }
    for(j=0; j<60; j++)
    {
        fprintf(save1,"%d ",different_lines_array2[j]);
    }
    for(j=0; j<60; j++)
    {
        fprintf(save1,"%d ",different_lines_number_for_undo2[j]);
    }
    for(j=0; j<12; j++)
    {
        fprintf(save1,"%d ",temp_undo_array[j]);
    }

    for(j=0; j<12; j++)
    {
        fprintf(save1,"%d ",different_lines_array[j]);
    }
    fprintf(save1,"%0.lf %0.lf %0.lf",time2.hours,time2.minuts,time2.seconds);
    fclose(save1);

}
void Load(int file_no,int *menu1,int *twoplayer_computer,int *i, int *count3,int *turn,int temp_undo_array[12],int *count_no_redo,int *count_no_undo,int different_lines_array[12],char array[11][11],int color_array[11][11],int different_lines_no_for_undo[12],char playerAname[50],int *playerAnum_of_moves,int *playerAscore,char playerBname[50],int *playerBnum_of_moves,int *playerBscore,char array2[23][23],int color_array2[23][23],int temp_undo_array2[60],int different_lines_array2[60],int different_lines_number_for_undo2[60])
{
    int j,k;
    if(file_no==1)
    {
        save1 = fopen("save1.txt","r");
    }
    else if (file_no==2)
    {
        save1 = fopen("save2.txt","r");
    }
    else if (file_no==3)
    {
        save1 = fopen("save3.txt","r");
    }
    fscanf(save1,"%d %d %d %d %d ",menu1,twoplayer_computer,i,count3,turn);
    fscanf(save1,"%d %d ",count_no_redo,count_no_undo);
    for(j=0; j<11; j++)
    {
        for(k=0; k<11; k++)
        {
            fscanf(save1,"%c",&array[j][k]);
        }
    }
    fprintf(save1," ");
    for(j=0; j<11; j++)
    {
        for(k=0; k<11; k++)
        {
            fscanf(save1,"%d ",&color_array[j][k]);
        }
    }
    for(j=0; j<12; j++)
    {
        fscanf(save1,"%d ",&different_lines_no_for_undo[j]);
    }
    fscanf(save1,"%s %d %d %s %d %d ",playerAname,playerAnum_of_moves,playerAscore,playerBname,playerBnum_of_moves,playerBscore);
    for(j=0; j<23; j++)
    {
        for(k=0; k<23; k++)
        {
            fscanf(save1,"%c",&array2[j][k]);
        }
    }
    fprintf(save1," ");
    for(j=0; j<23; j++)
    {
        for(k=0; k<23; k++)
        {
            fscanf(save1,"%d ",&color_array2[j][k]);
        }
    }
    for(j=0; j<60; j++)
    {
        fscanf(save1,"%d ",&temp_undo_array2[j]);
    }
    for(j=0; j<60; j++)
    {
        fscanf(save1,"%d ",&different_lines_array2[j]);
    }
    for(j=0; j<60; j++)
    {
        fscanf(save1,"%d ",&different_lines_number_for_undo2[j]);
    }
    for(j=0; j<12; j++)
    {
        fscanf(save1,"%d ",&temp_undo_array[j]);
    }

    for(j=0; j<12; j++)
    {
        fscanf(save1,"%d ",&different_lines_array[j]);
    }
    fscanf(save1,"%lf %lf %lf",&time2.hours,&time2.minuts,&time2.seconds);
    fclose(save1);
}
