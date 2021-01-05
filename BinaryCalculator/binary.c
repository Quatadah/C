#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int powertwo(int n)
{
    int prod = 1;
    for (int i =0 ;i<n ; i++)
    {
        prod *= 2;
    }
    return prod;
}


int decimalPos(char *byte)
{   
    int sum = 0;
    int counter = 0;
    int len = strlen(byte);
    char *p = byte + len - 1 ;
    while(p != byte)
    {
        if (*p == '1')
            sum += powertwo(counter);
        counter++;
        p--;
    }
    return sum;
}


void init(char *res)
{
    for (int i =0; i < 8; i++)
    {
        res[i]='0';
    }
}

char *binary(unsigned int n,char *res)
{
    init(res);
    int r;
    int index = 7;
    while(n>=1)
    {
        r = n - 2 * (n/2);
        res[index]=r+'0';
        n = n / 2;
        index --;
    }
    return res;    
}

char *addition(char *str1, char *str2,char *res)
{
    init(res);
    int len = 7;
    char save = '0';
    while(len > 0)
    {
        if (str1[len] + str2[len] + save == '1'+'1'+'0')
        {
            res[len]='0';
            save = '1';
        }
        else if (str1[len] + str2[len] + save == '1' + '0' + '0')
        {
            res[len]='1';
            save = 0;
        }
        else if (str1[len] + str2[len] + save == '0' + '0' + '0')
        {
            res[len]='0';
            save = 0;
        }
        len --;
    }       
    return res;
}

char *binaryNeg(int n,char *result)
{
    init(result);
    char *res;
    init(res);
    binary(-n,res);
    for(int i = 0; i <8 ;i ++)
    {
        if (res[i]=='0')
            res[i]='1';
        else if (res[i]=='1')
            res[i]=='0';
    }
    addition(res,"00000001",result);
    return result;
}

void showStr(char *str)
{
    for(int i = 0; i<8;i++)
        printf("%c",str[i]);
    printf("\n");
}

int main(int argc,char *argv[])
{
    char byte[] ="01000011";
    int dec = decimalPos(byte);
    printf("the decimal of 00100011 is %d \n",dec);


    char res[8];
    int x = 127;
    binary(x,res);
    printf("the binary form of %d is : ",x);
    showStr(res);

    printf("\n\n");
    int y = -23;
    binaryNeg(y,res);
    printf("the binary form of %d is : ",y);
    showStr(res);

    return 0;
}