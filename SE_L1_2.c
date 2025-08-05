#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    FILE *even;
    FILE *odd;
    char digStr[100];
    fp = fopen("data.txt","r");
    even = fopen("even.txt","w");
    odd = fopen("odd.txt","w");
    if(fp == NULL || even == NULL || odd == NULL)
        perror("file error");
    else
    {
        while((fscanf(fp,"%s",digStr))!= EOF)
        {
            int digit = atoi(digStr);
            if(digit % 2 == 0)
                fprintf(even,"%d ",digit);
            else
                fprintf(odd,"%d ",digit);
        }
    }
    fclose(even);
    fclose(odd);
    fclose(fp);
}