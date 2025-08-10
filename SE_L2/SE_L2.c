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
int newUSN()
{

}
int searchUSN()
{
    int USN;
    printf("Enter your registered USN: \n:");
    scanf("%d",&USN);
    return 1;
}
void RegisterUser()
{
    RU u1;
    printf("Enter New user name:");
    scanf("%s",&u1.name);
    printf("Enter New user Mobile Number:");
    scanf("%d",&u1.mob);
    printf("Enter New user mail:");
    scanf("%s",&u1.email);
    printf("Enter New user address:");
    scanf("%s",&u1.address);
    printf("Enter New user CMR:");
    scanf("%f",&u1.CMR);
    u1.USN = newUSN();
    u1.OMR = 0;
    u1.loan = false;
    u1.Dues = 0;
}
void subMenu()
{
    int choice = 0;
    while(choice != 4)
    {
        printf("---------------Sub Menu-----------------\n");
        printf("1.Update Reading: \n");
        printf("2.Bill: \n");
        printf("3.Report: \n");
        printf("4.Exit: \n:");
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