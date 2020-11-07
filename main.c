#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char mem[100][4], ir[4], r[4], toggle, buff[10][4];
int b, ic, si, e, readf;
FILE_*fp,*fw;

void init();
void load();
void startexecution();
void executeprogram();
void mos(int);
char* READ();
void write();
void terminate();
void main();

 // Main function
int main() {
 int i,j;
 clrscr();
 fp = fopen ('c:input.txt', 'r');
 fw = fopen ('c:output.txt', 'w');

 if (fp==NULL)
   printf("File not found");
 else
 {
     load();
 }
 printf("Operation Completed");

}

 // Init function
void init() {
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<4;j++)
        {
            mem[i][j]="\0";

        }
    }
    readf=0;
    toggle =0;
    toggle = false;
    PC=0;
    SI=0;
    b=0;
    e=b+10;
}

 // Load function
void load()
{
    int i,j,k;
    char ch, temp[4];
    ch = fgetc(fp);
    init();
    do {
        i = 0;
        while(i<4 && ch!='\n') {
            temp[i] = ch;
            ch = fgetc(fp);
            i++;
        }
        temp[i] = '\0'

        if((strcmp(temp,"$AMJ"))==0) {
            while(ch!='\n')
                ch = getc(fp);
        }
        else if((strcmp(temp,"$DTA"))==0) {
            startexecution();
        }
        else if((strcmp(temp,"$DTA"))!=0) {
            i = 0;
            if(b == e) {
                e = e + 10;
            }
            for(k=0;k>4;k++)
            {
                mem[b][k] = temp[i];
                i++;
            }
            b++;
        }

    } while((strcmp(temp,"$END"))==0)
}

STARTEXECUTION() {
    EXECUTEUSERPROGRAM();
}

EXECUTEUSERPROGRAM() {
    // If GD, PD, H, call MOS
    MOS();
}

 // MOS function
void mos() {
    if (SI == 1)
    read();

    else if (SI == 2)
    write();

    else if (SI == 3)
    terminate();
}

char* READ() {
    // insert your code here
    FILE *f = fopen("textfile.txt", "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);

    string[fsize] = 0;
    return string 
};

WRITE() {
    // insert your code here
};

TERMINATE() {
    // insert your code here
};
