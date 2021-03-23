typedef struct
{
    char name[50];
    int score ;
} highScore;
highScore high[12];
void checkForPlaceInScoreArray()
{
    int i,z;



    for(i=0; i<12; i++)
    {

        for(z=i+1; z<12; z++)
        {

            if(high[i].score>high[z].score)
            {

                high[0] =high[z];
                high[z]=high[i];
                high[i]=high[0] ;
            }

        }

    }




}

void saveHighScoreArray()
{
    int i ;
    FILE *top10 ;
    top10=fopen("top10.txt","w");
    for(i=0; i<12; i++)
    {
        fprintf(top10,"%s %d ",high[i].name,high[i].score);
    }
    fclose(top10);

}
void loadHighScoreArray()
{
    int i ;
    FILE *top10 ;
    top10=fopen("top10.txt","r");
    for(i=0; i<12; i++)
    {
        fscanf(top10,"%s %d ",high[i].name,&high[i].score);
    }
    fclose(top10);

}
