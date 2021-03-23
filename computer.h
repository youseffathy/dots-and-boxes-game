
int Computer(int n, int diffLinesArray[])
{
    int r1, r2, c1, c2,i,k,score, random ;
    int line ;
    int flag = 0 ;
    int scorearray1[12];
    int scorearray2[60];
    int linesArray1[12]= {1112,1213,2122,2223,3132,3233,1121,2131,1222,2232,1323,2333};

    int linesArray2[60]= {1112,1213,1314,1415,1516,2122,2223,2324,2425,2526,3132,3233
                          ,3334,3435,3536,4142,4243,4344,4445,4546,5152,5253,5354,5455
                          ,5556,6162,6263,6364,6465,6566,1121,2131,3141,4151,5161,1222
                          ,2232,3242,4252,5262,1323,2333,3343,4353,5363,1424,2434,3444
                          ,4454,5464,1525,2535,3545,4555,5565,1626,2636,3646,4656,5666
                         };

    for(i=0; i<12; i++)
    {
        scorearray1[i]=0;
    }
    for(i=0; i<60; i++)
    {
        scorearray2[i]=0;
    }

    if(n==12)
    {

        for(i=0; i<12; i++)
        {
            line=linesArray1[i];
            c2=line%10;
            line=line/10;
            r2=line%10;
            line=line/10;
            c1=line%10;
            line=line/10;
            r1=line;
            scorearray1[i]=CheckForClosedSquare(12,r1,c1,r2,c2,diffLinesArray);

        }

        for(i=0; i<12; i++)
        {
            if(scorearray1[i]==2)
            {
                for(k=0; k<12; k++)
                {
                    if(linesArray1[i]==diffLinesArray[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    return linesArray1[i] ;
                }
            }
            flag=0;

        }

        flag=0;

        for(i=0; i<12; i++)
        {
            if(scorearray1[i]==1)
            {
                for(k=0; k<12; k++)
                {
                    if(linesArray1[i]==diffLinesArray[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    return linesArray1[i] ;
                }
            }
            flag=0;

        }
        flag=0;

        for(i=0; i<12; i++)
        {
            random=rand()%12;
            if(scorearray1[random]==0)
            {
                for(k=0; k<12; k++)
                {
                    if(linesArray1[random]==diffLinesArray[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    return linesArray1[random] ;
                }
            }
            flag=0;

        }


    }
    else if (n==60)
    {

        for(i=0; i<60; i++)
        {
            line=linesArray2[i];
            c2=line%10;
            line=line/10;
            r2=line%10;
            line=line/10;
            c1=line%10;
            line=line/10;
            r1=line;
            scorearray2[i]=CheckForClosedSquare(60,r1,c1,r2,c2,diffLinesArray);

        }


        for(i=0; i<60; i++)
        {
            if(scorearray2[i]==2)
            {
                for(k=0; k<60; k++)
                {
                    if(linesArray2[i]==diffLinesArray[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    return linesArray2[i] ;
                }
            }
            flag=0;

        }

        flag=0;

        for(i=0; i<60; i++)
        {
            if(scorearray2[i]==1)
            {
                for(k=0; k<60; k++)
                {
                    if(linesArray2[i]==diffLinesArray[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    return linesArray2[i] ;
                }
            }
            flag=0;

        }
        flag=0;

        for(i=0; i<60; i++)
        {

            random=rand()%60;

            if(scorearray2[random]==0)
            {
                for(k=0; k<60; k++)
                {
                    if(linesArray2[random]==diffLinesArray[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    return linesArray2[random] ;
                }
            }
            flag=0;

        }


    }

}

void gotoxy(int x,int y)
{
    COORD pos = {x,y};

    HANDLE hconsole =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hconsole,pos);

}
