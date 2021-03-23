void erase_LettersInTheBox(int length, int n,int r1, int c1, int r2, int c2, char array[length][length], int diffLineArr [n], int turn, int difference,int color_array[length][length] )
{

    int a, b, c, d,l1, l2, l3, l4, l5, l6 ;
    a=r1;
    b=c1;
    c=r2;
    d=c2;
    a=(a+4)/4;
    b=(b+4)/4;
    c=(c+4)/4;
    d=(d+4)/4;


    if(n==12)
    {


        if(difference==1)
        {
            if(r1==r2&&r1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
            }
            else if (r1==r2&&r1==4)
            {
                l1=(a+1)*1000+b*100+(c+1)*10+d;
                l2=a*1000+b*100+(c+1)*10+(d-1);
                l3=a*1000+(b+1)*100+(c+1)*10+d;
                l4=(a-1)*1000+b*100+(c-1)*10+d;
                l5=(a-1)*1000+b*100+c*10+(d-1);
                l6=(a-1)*1000+(b+1)*100+c*10+d;

                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }

                }
                else if(check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1-2][c1+2]=15;
                        array[r1-2][c1+2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1-2][c1+2]=15;
                        array[r1-2][c1+2]='\0';
                    }
                }

            }

            else if (r1==r2&&r1==8)
            {
                if (turn==-1)
                {
                    color_array[r1-2][c1+2]=15;
                    array[r1-2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1-2][c1+2]=15;
                    array[r1-2][c1+2]='\0';
                }
            }
            else if (c1==c2&&c1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
            }
            else if (c1==c2&&c1==4)
            {
                l1=a*1000+(b+1)*100+c*10+(d+1);
                l2=a*1000+b*100+(c-1)*10+(d+1);
                l3=(a+1)*1000+b*100+c*10+(d+1);
                l4=a*1000+(b-1)*100+c*10+(d-1);
                l5=a*1000+(b-1)*100+(c-1)*10+d;
                l6=(a+1)*1000+(b-1)*100+c*10+d;
                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }
                }
                else if (check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1-2]=15;
                        array[r1+2][c1-2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1-2]=15;
                        array[r1+2][c1-2]='\0';
                    }
                }

            }
            else if (c1==c2&&c1==8)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1-2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1-2]='\0';
                }
            }



        }
        else if (difference==2)
        {
            if(r1==r2&&r1==4)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1-2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1-2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1-2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1-2][c1+2]='\0';
                }
            }
            else if (c1==c2&&c1==4)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1+2][c1-2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1+2][c1-2]='\0';
                }
            }
        }

    }
    else if (n==60)
    {

        if(difference==1)
        {
            if(r1==r2&&r1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
            }
            else if (r1==r2&&(r1==4||r1==8||r1==12||r1==16))
            {
                l1=(a+1)*1000+b*100+(c+1)*10+d;
                l2=a*1000+b*100+(c+1)*10+(d-1);
                l3=a*1000+(b+1)*100+(c+1)*10+d;
                l4=(a-1)*1000+b*100+(c-1)*10+d;
                l5=(a-1)*1000+b*100+c*10+(d-1);
                l6=(a-1)*1000+(b+1)*100+c*10+d;

                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }

                }
                else if(check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1-2][c1+2]=15;
                        array[r1-2][c1+2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1-2][c1+2]=15;
                        array[r1-2][c1+2]='\0';
                    }
                }

            }

            else if (r1==r2&&r1==20)
            {
                if (turn==-1)
                {
                    color_array[r1-2][c1+2]=15;
                    array[r1-2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1-2][c1+2]=15;
                    array[r1-2][c1+2]='\0';
                }
            }
            else if (c1==c2&&c1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                }
            }
            else if (c1==c2&&(c1==4||c1==8||c1==12||c1==16))
            {
                l1=a*1000+(b+1)*100+c*10+(d+1);
                l2=a*1000+b*100+(c-1)*10+(d+1);
                l3=(a+1)*1000+b*100+c*10+(d+1);
                l4=a*1000+(b-1)*100+c*10+(d-1);
                l5=a*1000+(b-1)*100+(c-1)*10+d;
                l6=(a+1)*1000+(b-1)*100+c*10+d;
                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=15;
                        array[r1+2][c1+2]='\0';
                    }
                }
                else if (check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1-2]=15;
                        array[r1+2][c1-2]='\0';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1-2]=15;
                        array[r1+2][c1-2]='\0';
                    }
                }

            }
            else if (c1==c2&&c1==20)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1-2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1-2]='\0';
                }
            }



        }
        else if (difference==2)
        {
            if(r1==r2&&(r1==4||r1==8||r1==12||r1==16))
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1-2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1-2][c1+2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1-2][c1+2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1-2][c1+2]='\0';
                }
            }
            else if (c1==c2&&(c1==4||c1==8||c1==12||c1==16))
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1+2][c1-2]='\0';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=15;
                    color_array[r1+2][c1-2]=15;
                    array[r1+2][c1+2]='\0';
                    array[r1+2][c1-2]='\0';
                }
            }
        }


    }




}
void TypeLettersInTheBox(int length, int n,int r1, int c1, int r2, int c2, char array[length][length], int diffLineArr [n], int turn, int difference,int color_array[length][length] )
{
    int a, b, c, d,l1, l2, l3, l4, l5, l6 ;
    a=r1;
    b=c1;
    c=r2;
    d=c2;
    a=(a+4)/4;
    b=(b+4)/4;
    c=(c+4)/4;
    d=(d+4)/4;


    if(n==12)
    {



        if(difference==1)
        {
            if(r1==r2&&r1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    array[r1+2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    array[r1+2][c1+2]='B';
                }
            }
            else if (r1==r2&&r1==4)
            {
                l1=(a+1)*1000+b*100+(c+1)*10+d;
                l2=a*1000+b*100+(c+1)*10+(d-1);
                l3=a*1000+(b+1)*100+(c+1)*10+d;
                l4=(a-1)*1000+b*100+(c-1)*10+d;
                l5=(a-1)*1000+b*100+c*10+(d-1);
                l6=(a-1)*1000+(b+1)*100+c*10+d;

                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=14;
                        array[r1+2][c1+2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=12;
                        array[r1+2][c1+2]='B';
                    }

                }
                else if(check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1-2][c1+2]=14;
                        array[r1-2][c1+2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1-2][c1+2]=12;
                        array[r1-2][c1+2]='B';
                    }
                }

            }

            else if (r1==r2&&r1==8)
            {
                if (turn==-1)
                {
                    color_array[r1-2][c1+2]=14;
                    array[r1-2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1-2][c1+2]=12;
                    array[r1-2][c1+2]='B';
                }
            }
            else if (c1==c2&&c1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    array[r1+2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    array[r1+2][c1+2]='B';
                }
            }
            else if (c1==c2&&c1==4)
            {
                l1=a*1000+(b+1)*100+c*10+(d+1);
                l2=a*1000+b*100+(c-1)*10+(d+1);
                l3=(a+1)*1000+b*100+c*10+(d+1);
                l4=a*1000+(b-1)*100+c*10+(d-1);
                l5=a*1000+(b-1)*100+(c-1)*10+d;
                l6=(a+1)*1000+(b-1)*100+c*10+d;
                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=14;
                        array[r1+2][c1+2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=12;
                        array[r1+2][c1+2]='B';
                    }
                }
                else if (check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1-2]=14;
                        array[r1+2][c1-2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1-2]=12;
                        array[r1+2][c1-2]='B';
                    }
                }

            }
            else if (c1==c2&&c1==8)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1-2]=14;
                    array[r1+2][c1-2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1-2]=12;
                    array[r1+2][c1-2]='B';
                }
            }



        }
        else if (difference==2)
        {
            if(r1==r2&&r1==4)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    color_array[r1-2][c1+2]=14;
                    array[r1+2][c1+2]='A';
                    array[r1-2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    color_array[r1-2][c1+2]=12;
                    array[r1+2][c1+2]='B';
                    array[r1-2][c1+2]='B';
                }
            }
            else if (c1==c2&&c1==4)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    color_array[r1+2][c1-2]=14;
                    array[r1+2][c1+2]='A';
                    array[r1+2][c1-2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    color_array[r1+2][c1-2]=12;
                    array[r1+2][c1+2]='B';
                    array[r1+2][c1-2]='B';
                }
            }
        }

    }
    else if (n==60)
    {

        if(difference==1)
        {
            if(r1==r2&&r1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    array[r1+2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    array[r1+2][c1+2]='B';
                }
            }
            else if (r1==r2&&(r1==4||r1==8||r1==12||r1==16))
            {
                l1=(a+1)*1000+b*100+(c+1)*10+d;
                l2=a*1000+b*100+(c+1)*10+(d-1);
                l3=a*1000+(b+1)*100+(c+1)*10+d;
                l4=(a-1)*1000+b*100+(c-1)*10+d;
                l5=(a-1)*1000+b*100+c*10+(d-1);
                l6=(a-1)*1000+(b+1)*100+c*10+d;

                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=14;
                        array[r1+2][c1+2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=12;
                        array[r1+2][c1+2]='B';
                    }

                }
                else if(check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1-2][c1+2]=14;
                        array[r1-2][c1+2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1-2][c1+2]=12;
                        array[r1-2][c1+2]='B';
                    }
                }

            }

            else if (r1==r2&&r1==20)
            {
                if (turn==-1)
                {
                    color_array[r1-2][c1+2]=14;
                    array[r1-2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1-2][c1+2]=12;
                    array[r1-2][c1+2]='B';
                }
            }
            else if (c1==c2&&c1==0)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    array[r1+2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    array[r1+2][c1+2]='B';
                }
            }
            else if (c1==c2&&(c1==4||c1==8||c1==12||c1==16))
            {
                l1=a*1000+(b+1)*100+c*10+(d+1);
                l2=a*1000+b*100+(c-1)*10+(d+1);
                l3=(a+1)*1000+b*100+c*10+(d+1);
                l4=a*1000+(b-1)*100+c*10+(d-1);
                l5=a*1000+(b-1)*100+(c-1)*10+d;
                l6=(a+1)*1000+(b-1)*100+c*10+d;
                if(check_3_lines(n,diffLineArr,l1,l2,l3))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1+2]=14;
                        array[r1+2][c1+2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1+2]=12;
                        array[r1+2][c1+2]='B';
                    }
                }
                else if (check_3_lines(n,diffLineArr,l4,l5,l6))
                {
                    if (turn==-1)
                    {
                        color_array[r1+2][c1-2]=14;
                        array[r1+2][c1-2]='A';
                    }
                    else if (turn==1)
                    {
                        color_array[r1+2][c1-2]=12;
                        array[r1+2][c1-2]='B';
                    }
                }

            }
            else if (c1==c2&&c1==20)
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1-2]=14;
                    array[r1+2][c1-2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1-2]=12;
                    array[r1+2][c1-2]='B';
                }
            }



        }
        else if (difference==2)
        {
            if(r1==r2&&(r1==4||r1==8||r1==12||r1==16))
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    color_array[r1-2][c1+2]=14;
                    array[r1+2][c1+2]='A';
                    array[r1-2][c1+2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    color_array[r1-2][c1+2]=12;
                    array[r1+2][c1+2]='B';
                    array[r1-2][c1+2]='B';
                }
            }
            else if (c1==c2&&(c1==4||c1==8||c1==12||c1==16))
            {
                if (turn==-1)
                {
                    color_array[r1+2][c1+2]=14;
                    color_array[r1+2][c1-2]=14;
                    array[r1+2][c1+2]='A';
                    array[r1+2][c1-2]='A';
                }
                else if (turn==1)
                {
                    color_array[r1+2][c1+2]=12;
                    color_array[r1+2][c1-2]=12;
                    array[r1+2][c1+2]='B';
                    array[r1+2][c1-2]='B';
                }
            }
        }


    }



}

int check_3_lines(int n,int array[],int a,int b, int c )
{
    int i;
    int z=0;
    for(i=0; i<n; i++)
    {
        if(a==array[i] || b==array[i] || c==array[i])
        {
            z=z+1;
        }
    }
    if(z==3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
