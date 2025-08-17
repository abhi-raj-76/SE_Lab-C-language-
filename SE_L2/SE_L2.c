#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct registerUser
{
    char name[50];
    char mob[15];
    int USN;
    char email[100];
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
void fetchData(int usn)
{
    int current;
    RU usr;
    FILE *actData;
    actData = fopen("userData.txt","a+");
    while (fscanf(actData,"%d",&current) == 1)
    {
        if(current == usn)
        {
            fscanf(actData,"|%49[^|]|%14[^|]|%99[^|]|%99[^|]|%f|%f|%d|%f",
                          usr.name, usr.mob, usr.email, usr.address,
                          &usr.CMR, &usr.OMR, &usr.loan, &usr.Dues);
            usr.USN = usn;
            printf("%s %d",usr.name,usr.USN);
        }
        while (fgetc(actData) != '\n' && !feof(actData)){}//if match then run and read the other data otherwise skip until next line \n not found
    }
    

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
        {
            fetchData(USN);
            return 1;
        }
    }
    return 0;
}
void RegisterUser()
{
    RU u1;
    printf("Enter your name: ");
    scanf("%s",u1.name);
    printf("Enter your Mobile Number: ");
    scanf("%s",u1.mob);
    printf("Enter your mail: ");
    scanf("%s",u1.email);
    printf("Enter your address: ");
    scanf("%s",u1.address);
    printf("Enter your CMR: ");
    scanf("%f",&u1.CMR);
    u1.USN = newUSN();
    u1.OMR = 0;
    u1.loan = false;
    u1.Dues = 0;
    FILE *userDataFile;
    userDataFile = fopen("userData.txt","a+");
    //printf("%d %d %s %s %f",u1.USN,u1.mob,u1.email,u1.CMR);
    fprintf(userDataFile,"%d|%s|%s|%s|%s|%f|%f|%d|%f",u1.USN,u1.name,u1.mob,u1.email,u1.address,u1.CMR,u1.OMR,u1.loan,u1.Dues);
    fputc('\n',userDataFile);
    fclose(userDataFile);
    return;
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
                subMenu();
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