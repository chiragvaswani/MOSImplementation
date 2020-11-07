#include <stdio.h>
int main() {
 FILE *input;
 FILE *output;
 //fopen() function is used to open a file named example.txt in read mode
 input = fopen ('input.txt', 'r');
 output = fopen ('output.txt', 'w');

}

void INIT() {
    // insert your code here
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
    C = false;
    PC=0;
    SI=none;


}

LOAD() {
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
                m[b][k] = temp[i];
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

MOS() {
    //if SI=1
    READ();

    //if SI=2
    WRITE();

    //if SI=3
    TERMINATE();
}

READ() {
    // insert your code here
};

WRITE() {
    // insert your code here
};

TERMINATE() {
    // insert your code here
};
