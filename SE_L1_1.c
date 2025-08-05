#include<stdio.h>

void main()
{
    FILE *fp;
    int age;
    char name[20];
    char data[100];
    fp = fopen("abc.txt","w");
    if(fp == NULL)
    {
        perror("file opening error:");
    }
    else
    {
        printf("Enter your name and age:\n");
        scanf("%s",&name);
        scanf("%d",&age);
        fprintf(fp,"Name: %s, Age: %d",name,age);
    }
    fclose(fp);
    fp = fopen("abc.txt","r");
    if(fp == NULL)
        perror("file error");
    else
    {
        printf("this is your data:\n");
        fgets(data,sizeof(data),fp);
        printf("\n");
        printf("%s",data);
    }
    fclose(fp);
}