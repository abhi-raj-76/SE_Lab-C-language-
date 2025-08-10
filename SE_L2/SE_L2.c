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
    int choice = 0;
    while(choice != 3)
    {
        printf("---------------Menu-----------------\n");
        printf("1.Registered User: \n");
        printf("2.Not Registered User: \n");
        printf("3.Exit: \n:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                return;
            default:
                printf("INVALID INPUT!!!");
                return;
        }
    }
}
void main()
{
    Menu();
}