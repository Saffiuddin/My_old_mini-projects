#include<stdio.h>//HEADER FILES
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int empID,flag;//GLOBAL VAR
struct employee
{
int empid[30],start,end,num,des[30],i,age[30];
float basic[30],hra[30],ma[30],pf[30],insurance[30],da[30],gross[30],net[30],sa[30],be[30],de[30];//CALC VALUES
char name[30][50],desn[30][50];
}e;
//CREDITS
void sshan()
{
        printf("\n\t\t\t\tDEVELOPERS:SAFFI&SANDY\n");
        printf("\t\t\t\tPROGRAM-TESTING:NEHAL\n");
        printf("\t\t\t\tDEBUGGING:ARSHAD&SHAHUL\n\n");
}
//STANDARD INPUT
void input()
{
printf("\nEnter the total no.of employees:");
scanf("%d",&e.num);
printf("\nENTER THE EMPLOYEE DETAILS:-\n");
printf("___________________________\n");
for(e.i=0;e.i<e.num;e.i++)
{
    printf("\n\tEmployee ID:");
    scanf("%d",&e.empid[e.i]);
    printf("\n\tEmployee name:");
    scanf("%s",e.name[e.i]);
    printf("\n\tage:");
    scanf("%d",&e.age[e.i]);
    printf("\n\tBasic salary:");
    scanf("%f",&e.basic[e.i]);
    //DESIGNATION ALLOCATION//
   while(1)
    {
     printf("\n\tSelect Designation:-\n\tPRESS...\n\t'1' for PROGRAMMER,'2' for SUPERVISOR,\n\t'3' for TECHNICAL SUPPORT,'4' for HR MANAGER,\n\t'5' for SYSTEM ANALYST,'6' for SOFTWARE QUALITY ANALYST\n\tEnter here:");
    scanf("%d",&e.des[e.i]);
    if(e.des[e.i]==1)
    {
    e.sa[e.i]=11500;
    strcpy(e.desn[e.i],"PROGRAMMER");
    break;
    }
    else if(e.des[e.i]==2)
    {
    e.sa[e.i]=12000;
    strcpy(e.desn[e.i],"SUPERVISOR");
    break;
    }
    else if(e.des[e.i]==3)
    {
            e.sa[e.i]=8000;
            strcpy(e.desn[e.i],"TECHNICAL SUPPORT");
            break;
    }
    else if(e.des[e.i]==4)
    {
            e.sa[e.i]=7500;
            strcpy(e.desn[e.i],"HR MANAGER");
            break;
    }
    else if(e.des[e.i]==5){
            e.sa[e.i]=9800;
            strcpy(e.desn[e.i],"SYSTEM ANALYST");
            break;
    }
    else if(e.des[e.i]==6)
    {
            e.sa[e.i]=10250;
            strcpy(e.desn[e.i],"SOFTWARE QUALITY ANALYST");
            break;
    }
    else{
    printf("\nInvalid designation,Enter correctly!");
    printf("\n\tSelect Designation:-\n\tPRESS...\n\n\t'1' for PROGRAMMER,'2' for SUPERVISOR,\n\t'3' for TECHNICAL SUPPORT,'4' for HR MANAGER,\n\t'5' for SYSTEM ANALYST,'6' for SOFTWARE QUALITY ANALYST\n\n\tEnter here:");
    scanf("%d",&e.des[e.i]);
    }
}
}
}
//PERFORMS THE CALCULATION
void calc()
{
    for(e.i=0;e.i<e.num;e.i++)
{
    e.hra[e.i]=(e.basic[e.i]/100)*10;
    e.ma[e.i]=(e.basic[e.i]/100)*5;
    e.da[e.i]=(e.basic[e.i]/100)*3;
    e.pf[e.i]=(e.basic[e.i]/100)*6.67;
    e.insurance[e.i]=(e.basic[e.i]/100)*5;
    e.gross[e.i]=e.basic[e.i]+e.hra[e.i]+e.da[e.i]+e.ma[e.i]+e.sa[e.i];
    e.net[e.i]=e.gross[e.i]-(e.pf[e.i]+e.insurance[e.i]);
    e.be[e.i]=e.hra[e.i]+e.da[e.i]+e.ma[e.i]+e.sa[e.i];
    e.de[e.i]=e.pf[e.i]+e.insurance[e.i];
}
}
//GENERATES THE PAYSLIP
void payslip_display(int k)
{
        printf("\nSalary Slip for %s:-\n\n",e.name[k]);
        printf("\tEmployee ID: %d\n",e.empid[k]);
        printf("\tCurrent Designation: %s\n",e.desn[k]);
        printf("\n\nEARNINGS:-   (in Rs.)\n");
        printf("--------\n");
        printf("\n\tBasic Salary: %.2f\n",e.basic[k]);
        printf("\tHouse Rent Allowance: %.2f\n",e.hra[k]);
        printf("\tMedical Allowance: %.2f\n",e.ma[k]);
        printf("\tDearness Allowance: %.2f\n",e.da[k]);
        printf("\tSpecial Allowance: %.2f\n",e.sa[k]);
        printf("\n\tGross Salary: Rs.%.2f\n",e.gross[k]);
        printf("\t------------\n\n");
        printf("\nDEDUCTIONS:-   (in Rs.)\n");
        printf("----------\n\n");
        printf("\tPf: %.2f\n",e.pf[k]);
        printf("\tInsurance: %.2f\n\n",e.insurance[k]);
        printf("\tTotal deductions: Rs.%.2f\n",e.pf[k]+e.insurance[k]);
        printf("\t----------------\n\n");
        printf("\t\t\t\tPAY SUMMARY:-\n\t\t\t\t-----------\n\tNet Salary: Rs.%.2f\n\t----------\n\n",e.net[k]);
  }
//To get the payslip
void payslip_gen()
{
while(1)
{
int in;
printf("\nPAYSLIP GENERATION\n");
printf("------------------\n");
printf("\n\n Press '1' to continue or '0' to exit:");
scanf("%d",&in);
if(in==1)
{
printf("\n\n\tEnter employee ID to get payslip:");
scanf("%d",&empID);
flag=0;
for(int j=0;j<e.num;j++)
{
if (empID==e.empid[j])
        {
        flag=1;
        payslip_display(j);
        while(1)
        {
        printf("\n Do you want to continue(1/0):");
        scanf("%d",&e.end);
        if(e.end==0)
        {
           return;
        }
        else if(e.end==1)
            break;
        else
            printf("\nInvalid input!");
        }
        }
        }
        if(!flag){
        printf("No Record Found!!\n");
        while(1)
        {

        printf("\n Press '1' to continue or '0' to exit:");
        scanf("%d",&e.end);
        if(e.end==0){
            return;
        }
        else if(e.end==1)
            break;
        else
            printf("\nInvalid input!");
        }
        }
        }
        else
            break;
}
}
//PAYROLL AS LIST
void display()
{
printf("\n\t________________\n");
printf("\n\tEMPLOYEE PAYROLL");
printf("\n\t________________\n");
for(int z=0;z<e.num;z++)
{
printf("\n\t%d.NAME:%s\t\tEMPID:%d\t\tAGE:%d",z+1,e.name[z],e.empid[z],e.age[z]);
printf("\n\n\tBasic Salary(in Rs.):%.2f\n\tBENEFITS(in Rs.):%.2f\n\tDEDUCTIONS(in RS.):%.2f\n",e.basic[z],e.be[z],e.de[z]);
printf("\n\n\tNET SALARY(in Rs.):%.2f\n\n\n",e.net[z]);
}
printf("\n\n\n\n");
return;
}
//BASIC OPTIONS
void options()
{
while(1){

        int choice;
        printf("\nPlease choose from the options\n");
        printf("\n\t\t1.View Employee Payroll\n");
        printf("\t\t2.Generate payslip\n");
        printf("\t\t3.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:display();
                break;
        case 2:payslip_gen();
                break;
        case 3:sshan();
                exit(0);
                break;
        default:printf("Invalid command!,Enter again correctly...");
                break;
        }
}
}
//MAIN FUNCTION()
int main()
{
printf("\t\t\t\t______________________\n\n");
printf("\t\t\t\tREALSOFT PRIVATE Ltd.\n");//GROUP NAME
printf("\t\t\t\t______________________\n\n");
printf("\n\t\t\tEMPLOYEE PAYROLL MANAGEMENT SYSTEM\n");
printf("\t\t\t----------------------------------\n\n");
printf("\nPress '1' to continue (or)'0' to exit:");
scanf("%d",&e.start);
while(1)
    {
    if(e.start==1)
    {
        break;
    }
    else if(e.start==0)
    {
        sshan();
        exit(0);
    }
    else
    {
        printf("Invalid command!,Enter again correctly...");
        scanf("%d",&e.start);
    }
}
//FUNCTION CALL STATEMENTS
input();
calc();
options();
getch();
return 0;
}

