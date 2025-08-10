#include<stdio.h>
#include<stdbool.h>
typedef struct registerUser
{
    char name[150];
    int mob;
    int USN;
    char email[50];
    char address[100];
    float CMR;
    float OMR;
    float Dues;
    bool loan;
}RU;
int searchUSN()
{
    int USN;
    int USNArr[50];
    printf("Enter your registered USN: \n:");
    scanf("%d",&USN);
    for(int i = 0; i<50; i++)
    {
        if(USN == USNArr[i])
            return 1;
        else
            return 0;
    }
}
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
                int found = searchUSN();
                if(found == 1) 
                    subMenu();
                else
                    Menu();
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