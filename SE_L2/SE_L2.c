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
    bool loan;
}RU;

void Menu()
{
    printf("Registered User: ");
    printf("Not Registered User: ");
}