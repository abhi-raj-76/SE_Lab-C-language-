#include<stdio.h>
#include<stdbool.h>
typedef struct registerUser
{
    char name[150];
    int mob;
    char email[50];
    char address[100];
    float CMR;
    float OMR;
    float Dues;
    bool loan;
}RU;

void Menu()
{
    printf("---------------Menu----------------");
    printf("1.Registered User: ");
    printf("2.Not Registered User: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            break;
        case 2:
            break;
    }
}