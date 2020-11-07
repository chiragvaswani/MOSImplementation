#include<stdio.h>
#include<string.h>

int IC,C;
char IR[4],R[4]; //Instruction register and register
int SI; // System interrupts
char M[100][4]; //stores the data to be printed as output
char buffer[41];//for temporary storage of data
int i=0,loc;
int t=0,a=0;
int j;
FILE *fp,*fp1; //for read and write files

void EXECUTEUSERPROGRAM();
void LOAD();
void MOS();
void START();
void READ();
void WRITE();
void TERMINATE();
void init();
void clearbuff();

int main()
{
    //Open read and write files
    fp = fopen("inputfile.txt","r");
    fp1 = fopen("outputfile.txt","w");
    LOAD();
    return 0;
}



void EXECUTEUSERPROGRAM() //Performs GD,PD,LR,SR,BT,CR
{
    for(i=0;i<4;i++)
    {
        IR[i]=M[IC][i];
    }
    loc = ((int)IR[2] -48)*10 + ((int)IR[3] -48); //typecasting
    IC++;
    printf("\n\n%d\n\n",loc);
    if(IR[0] == 'G' && IR[1] =='D')
    {
        SI = 1;
        printf("\nIN GD\n");
        MOS();
    }

    else if(IR[0] == 'P' && IR[1] =='D')
    {
        SI = 2;
        printf("\nIN PD\n");
        for(int i=loc;i<loc+10;i++)
        {
            printf("M[%d] : ",i);
            for(j=0;j<4;j++)
            {
                printf("%c",M[i][j]);
            }
            printf("\n");
        }
    MOS();
    }

    else if(IR[0] == 'H')
    {
        SI = 3;
        printf("Program Terminated");
        MOS();
    }

    else if(IR[0]=='L' && IR[1]=='R')
    {
        printf("\nIn LR\n");
        for(i=0;i<4;i++)
        {
            R[i]=M[loc][i];   //R<-M[IC]
            printf("%c",R[i]);
        }
        EXECUTEUSERPROGRAM();
    }

    else if(IR[0]=='S' && IR[1]=='R')
    {
        printf("\nIN SR\n" );
        printf("\nmemory stored with data-->>");
        for(i=0;i<4;i++)
        {
            M[loc][i]=R[i];   //M[IC]->R
            printf("%c",M[loc][i]);
        }
        EXECUTEUSERPROGRAM();
    }

    else if(IR[0]=='C' && IR[1]=='R')
    {
        for(i=0;i<4;i++)
        {
            if(R[i]==M[loc][i])
            {
               printf("\nStrings Match!\n");
               C=1;
            }
            else
            {
                C=0;
                printf("\nStrings Don't Match!\n");
                break;
            }
        }
        EXECUTEUSERPROGRAM();
    }

    else if(IR[0]=='B' && IR[1]=='T')
    {
        if(C==1)
        {
            IC=loc;
            printf("\nValue of IC ->>%d", IC); //prints pointer location between 0-99
        }

    EXECUTEUSERPROGRAM();
    }

}

void init()
{
    int i, j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<4;j++)
        {
            M[i][j]='\0';   //initializing the memory with \0
        }
    }

    for(i=0;i<4;i++)
    {
        IR[i]=R[i]='\0';
    }

}

void READ()
{
    int i, j, k;

    if(fgets(buffer,41,fp)!=NULL)
    {

        k=0;
        for(i=loc;i<loc+10;i++)
        {
            printf("M[%d] : ",i);
            for(j=0;j<4 && buffer[k]!='\0';j++)
            {
                M[i][j]=buffer[k];
                k++;

                printf("%c",M[i][j]); //printing the characters in input file 4 at a time
            }
            printf("\n");
        }

    }
    EXECUTEUSERPROGRAM();
}
void clearbuff()
{
    for(int asd=0;asd<41;asd++)
    {
    buffer[asd]=NULL;
    }
}
void WRITE()
{
    int i, j, k;
    IR[3] = '0';
    k=0;
    printf("\n");
    clearbuff();
    for(i=loc; i<loc+10; i++)
    {
    for(j=0; j<4 && M[i][j]!='$'; j++)
    {
        if(M[i][j]=='\n')
        {
            buffer[k]=' ';
        }
        else
            buffer[k] = M[i][j];
        printf("%c",buffer[k]);
        k++;
    }
    }
    buffer[k]='\n';
    printf("\nString is\n");
    for(int as=0;as<41;as++)
    {
        printf("%c",buffer[as]);
    }
    fputs(buffer,fp1);
    EXECUTEUSERPROGRAM();
}

void TERMINATE()
{
// Two blank lines in the output file
    memset(buffer,0,41);
    buffer[0]='\n';
    buffer[1]='\n';
    fputs(buffer,fp1);
}

void MOS()
{
    switch(SI)
    {
        case 1:
            READ();
            break;
        case 2:
            WRITE();
            break;
        case 3:
            TERMINATE();
            break;
        default:
            SI = 0;
    }
}


void START()
{
    IC = 0; //Instruction Counter
    EXECUTEUSERPROGRAM();
}

void LOAD()
{
    int t=0;
    int i,j,k;
    while(getc(fp)!=EOF)//get all the characters in the input file
    {
        fseek(fp,-1,SEEK_CUR);
        memset(buffer,0,42);
        fgets(buffer,42,fp);

    if(buffer[0] == '$' && buffer[1] == 'A' && buffer[2] =='M' && buffer[3] == 'J')
    {
        printf("\nProcess started..\n");
        t=0;
        init();
    }
    else if(buffer[0] == '$' && buffer[1] == 'D' && buffer[2] =='T' && buffer[3] == 'A')
    {
        START();
    }

    else if(buffer[0] == '$' && buffer[1] == 'E' && buffer[2] =='N' && buffer[3] == 'D')
        continue;

else
    {
        for(int k=t;k<t+10;k++)
        {
            printf("M[%d]:",k);
            for(int i=0;i<4;i++)
            {
                M[k][i]=buffer[a];
                a++;
                printf("%c",M[k][i]);
            }
            printf("\n");
        }
        t=t+10;
        a=0;
    }
    }
    fclose(fp);
    fclose(fp1);
}



