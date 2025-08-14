#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
int newUSN()
{
    FILE *usnData;
    int usn = 1000;
    usnData = fopen("USN.txt","a+");
    if(usnData == NULL)
    {
        perror("Error while opening file");
        return -1;
    }
    int current = -1;
    while (fscanf(usnData,"%d",&current) != EOF);
    if(current == -1)
    {
        usn = 1000;
        fprintf(usnData,"%d ",usn);
    }
    else
    {
        usn = current+1;
        fprintf(usnData,"%d ",usn);
    }
    fclose(usnData);
    return usn;
}
int searchUSN()
{
    int USN;
    int current;
    printf("Enter your registered USN: \n:");
    scanf("%d",&USN);
    FILE *checkUSN;
    checkUSN = fopen("USN.txt","r");
    if(checkUSN == NULL)
    {
        perror("Error while opening file");
        return -1;
    }
    while (fscanf(checkUSN,"%d",&current) != EOF)
    {
        if(current == USN)
        {return 1;}
    }
    return 0;
}
void RegisterUser()
{
    RU u1;
    /*printf("Enter your name: ");
    scanf("%s",&u1.name);
    printf("Enter your Mobile Number: ");
    scanf("%d",&u1.mob);
    printf("Enter your mail: ");
    scanf("%s",&u1.email);
    printf("Enter your address: ");
    scanf("%s",&u1.address);
    printf("Enter your CMR: ");
    scanf("%f",&u1.CMR);*/
    u1.USN = newUSN();
    u1.OMR = 0;
    u1.loan = false;
    u1.Dues = 0;
    printf("%d ",u1.USN);
}
void subMenu()
{
    int choice = 0;
    while(choice != 4)
    {
        printf("\n---------------Sub Menu-----------------\n");
        printf("1.Update Reading: \n");
        printf("2.Bill: \n");
        printf("3.Report: \n");
        printf("4.Logout: \n:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                return;
            default:
                printf("INVALID INPUT!!!");
                return;
        }
    }
}
void Menu()
{
    int choice = 0;
    while(choice != 3)
    {
        printf("\n---------------Menu-----------------\n");
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
                    printf("Your are Not registered:");
                    Menu();
                break;
            case 2:
                RegisterUser();
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