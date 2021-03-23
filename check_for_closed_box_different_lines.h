
int CheckForClosedSquare(int n,int r1, int c1, int r2, int c2, int array[])
{
    int i, l1, l2, l3, l4, l5, l6 ;
    int z  = 0 ;
    int z2 = 0 ;

    if(n==12)
    {



        if(r1==r2 && r1==1)
        {
            l1=(r1+1)*1000+c1*100+(r2+1)*10+c2;
            l2=r1*1000+c1*100+(r2+1)*10+(c2-1);
            l3=r1*1000+(c1+1)*100+(r2+1)*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }
        }

        else if (r1==r2 && r1==2)
        {
            l1=(r1+1)*1000+c1*100+(r2+1)*10+c2;
            l2=r1*1000+c1*100+(r2+1)*10+(c2-1);
            l3=r1*1000+(c1+1)*100+(r2+1)*10+c2;
            l4=(r1-1)*1000+c1*100+(r2-1)*10+c2;
            l5=(r1-1)*1000+c1*100+r2*10+(c2-1);
            l6=(r1-1)*1000+(c1+1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3 )
                {
                    z=z+1;
                }
                else if (array[i]==l4 || array[i]==l5 || array[i]==l6)
                {
                    z2=z2+1;
                }
            }
            if((z+z2)==6)
            {
                return 2 ;
            }
            else if (z==3)
            {
                return 1 ;
            }
            else if (z2==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }
        }

        else if (r1==r2 && r1==3)
        {
            l1=(r1-1)*1000+c1*100+(r2-1)*10+c2;
            l2=(r1-1)*1000+c1*100+r2*10+(c2-1);
            l3=(r1-1)*1000+(c1+1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }

        }

        else if (c1==c2 && c1==1)
        {
            l1=r1*1000+(c1+1)*100+r2*10+(c2+1);
            l2=r1*1000+c1*100+(r2-1)*10+(c2+1);
            l3=(r1+1)*1000+c1*100+r2*10+(c2+1);

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }
        }
        else if (c1==c2 && c1==3)
        {
            l1=r1*1000+(c1-1)*100+r2*10+(c2-1);
            l2=r1*1000+(c1-1)*100+(r2-1)*10+c2;
            l3=(r1+1)*1000+(c1-1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }

        }

        else if (c1==c2 && c1==2)
        {
            l1=r1*1000+(c1+1)*100+r2*10+(c2+1);
            l2=r1*1000+c1*100+(r2-1)*10+(c2+1);
            l3=(r1+1)*1000+c1*100+r2*10+(c2+1);
            l4=r1*1000+(c1-1)*100+r2*10+(c2-1);
            l5=r1*1000+(c1-1)*100+(r2-1)*10+c2;
            l6=(r1+1)*1000+(c1-1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3 )
                {
                    z=z+1;
                }
                else if (array[i]==l4 || array[i]==l5 || array[i]==l6)
                {
                    z2=z2+1;
                }
            }
            if((z+z2)==6)
            {
                return 2 ;
            }
            else if (z==3)
            {
                return 1 ;
            }
            else if (z2==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }

        }

    }


    else if (n==60)
    {



        if(r1==r2 && r1==1)
        {
            l1=(r1+1)*1000+c1*100+(r2+1)*10+c2;
            l2=r1*1000+c1*100+(r2+1)*10+(c2-1);
            l3=r1*1000+(c1+1)*100+(r2+1)*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }
        }

        else if (r1==r2 && (r1==2||r1==3||r1==4||r1==5))
        {
            l1=(r1+1)*1000+c1*100+(r2+1)*10+c2;
            l2=r1*1000+c1*100+(r2+1)*10+(c2-1);
            l3=r1*1000+(c1+1)*100+(r2+1)*10+c2;
            l4=(r1-1)*1000+c1*100+(r2-1)*10+c2;
            l5=(r1-1)*1000+c1*100+r2*10+(c2-1);
            l6=(r1-1)*1000+(c1+1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3 )
                {
                    z=z+1;
                }
                else if (array[i]==l4 || array[i]==l5 || array[i]==l6)
                {
                    z2=z2+1;
                }
            }
            if((z+z2)==6)
            {
                return 2 ;
            }
            else if (z==3)
            {
                return 1 ;
            }
            else if (z2==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }
        }

        else if (r1==r2 && r1==6)
        {
            l1=(r1-1)*1000+c1*100+(r2-1)*10+c2;
            l2=(r1-1)*1000+c1*100+r2*10+(c2-1);
            l3=(r1-1)*1000+(c1+1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }

        }

        else if (c1==c2 && c1==1)
        {
            l1=r1*1000+(c1+1)*100+r2*10+(c2+1);
            l2=r1*1000+c1*100+(r2-1)*10+(c2+1);
            l3=(r1+1)*1000+c1*100+r2*10+(c2+1);

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }
        }
        else if (c1==c2 && c1==6)
        {
            l1=r1*1000+(c1-1)*100+r2*10+(c2-1);
            l2=r1*1000+(c1-1)*100+(r2-1)*10+c2;
            l3=(r1+1)*1000+(c1-1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3)
                {
                    z=z+1;
                }
            }
            if(z==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }

        }

        else if (c1==c2 &&(c1==2||c1==3||c1==4||c1==5))
        {
            l1=r1*1000+(c1+1)*100+r2*10+(c2+1);
            l2=r1*1000+c1*100+(r2-1)*10+(c2+1);
            l3=(r1+1)*1000+c1*100+r2*10+(c2+1);
            l4=r1*1000+(c1-1)*100+r2*10+(c2-1);
            l5=r1*1000+(c1-1)*100+(r2-1)*10+c2;
            l6=(r1+1)*1000+(c1-1)*100+r2*10+c2;

            for(i=0; i<n; i++)
            {
                if(array[i]==l1 || array[i]==l2 || array[i]==l3 )
                {
                    z=z+1;
                }
                else if (array[i]==l4 || array[i]==l5 || array[i]==l6)
                {
                    z2=z2+1;
                }
            }
            if((z+z2)==6)
            {
                return 2 ;
            }
            else if (z==3)
            {
                return 1 ;
            }
            else if (z2==3)
            {
                return 1 ;
            }
            else
            {
                return 0 ;
            }

        }

    }


}


int different_lines(int n,int line_number,int array[])
{
    int i, z ;
    for(i=0; i<n; i++)

    {
        if(line_number==array[i])
        {
            z=1;
            break;
        }
    }
    if (z==1)
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }

}
