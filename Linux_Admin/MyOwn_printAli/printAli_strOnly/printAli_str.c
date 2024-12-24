#include <unistd.h>

#define STD_OUT_FD  1

unsigned long stringLen(char data[])
{
    unsigned long count = 0;
    while (*data != '\0')
    {
        data++;
        count++;
    }
    return count;
}

void printAli(char data[]){
    unsigned long len = stringLen(data);
    write(STD_OUT_FD, data, len);
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        printAli(argv[1]);
    }
    else
    {
        printAli("Error no args provided");
    }
    //printAli("Hello World from Ali");
    return 0;
}