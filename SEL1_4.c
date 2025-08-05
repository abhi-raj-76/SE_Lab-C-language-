#include<stdio.h>
typedef struct Student
{
    int roll;
    char name[100];
    float sub1;
    float sub2;
    float tot;
    float avg;
    char grade;
}ST;
char Grading(float tot)
{
    if(s1.tot < 40)
        s1.grade = 'F';
    else if(s1.avg >= 40 && s1.avg <50)
        s1.grade = 'D';
    else if(s1.avg >= 50 && s1.avg <55)
        s1.grade = 'C';
    else if(s1.avg >= 55 && s1.avg <65)
        s1.grade = 'B';
    else if(s1.avg >= 65 && s1.avg <75)
        s1.grade = 'B+';
    else if(s1.avg >= 75 && s1.avg <85)
        s1.grade = 'A';
    else if(s1.avg >= 85 && s1.avg <100)
        s1.grade = 'A+';
    printf("%d ",s1.tot);
}
void main()
{
    ST s1;
    FILE *fp;
    fp = fopen("student.txt","a+");
    printf("Enter your roll,name,sub1,sub2:\n");
    scanf("%d",&s1.roll);
    scanf("%s",&s1.name);
    scanf("%f",&s1.sub1);
    scanf("%f",&s1.sub2);
    s1.tot = s1.sub1+s1.sub2;
    s1.avg = s1.tot/2;
    s1.grade = Grading(s1.tot);
    if(fp == NULL)
        perror("file error:");
    else
        fprintf(fp,"Name %s Roll %d Sub1 %f Sub2 %f Tot %f Avg %f Grade %c",s1.name,s1.roll,s1.sub1,s1.sub2,s1.tot,s1.avg,s1.grade);
        fputc('\n',fp);
    fclose(fp);
}