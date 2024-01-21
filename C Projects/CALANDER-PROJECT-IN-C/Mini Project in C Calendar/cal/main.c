 #include<stdio.h>
#include<conio.h>
struct date
{
    int dd;
    int mm;
    int yy;
};
struct date date;
int leapyr(int year)
{
    if(year % 400==0 || (year % 100!=0 && year %4 ==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getnoofdays(int month,int year)
{
    
    switch(month)
    {
        case 1:return(31);
        case 2:if(leapyr(year)==1)
        return 29;
        else
        return 28;
        case 3:return(31);
        case 4:return(30);
        case 5:return(31);
        case 6:return(30);
        case 7:return(31);
        case 8:return(31);
        case 9:return(30);
        case 10:return(31);
        case 11:return(30);
        case 12:return(31);
        
    }
}
int getDayNumber(int day,int mon,int year)
{
    int res,t1,t2;
    year=year-1600;
    while(year>100)
    {
        res=res+5;
        year=year-100;
        
    }
    res=res%7;
    t1=((year-1)/4);
    t2=(year-1)-t1;
    t1=(t1*2)+t2; 
    t1=t1%7;
    res=res+t1;
    res=res%7;
    t2=0;
    for(t1=1;t1<mon;t1++)
    {
        t2+=getnoofdays(t1,year);
    }
    t2=t2+day;
    t2=t2%7;
    res=res+t2;
    res=res%7;
    if(year>2000)
    {
        res=res+1;
    }
    res=res%7;
    return res;
}
char *getName(int day)
{
    switch(day)
    {
    case 1:return("Sunday");
    case 2:return("Monday");
    case 3:return("Tuesday");
    case 4:return("Wednesday");
    case 5:return("Thursday");
    case 6:return("Friday");
    case 7:return("Saturday");
    default:return("Error");
    }
}
char *getday(int dd,int mm,int yy)
{
    int day;
    if(!(mm>=1&&mm<=12))
    {
        return("Invalid month value!!");
    }
    if(!(dd>=1&&dd<=getnoofdays(mm,yy)))
    {
        return("Invalid date");
    }
    if(yy>1600)
    {
        day=getDayNumber(dd,mm,yy);
        day=day%7;
        return(getName(day));
    }
    else
    {
        return("please enter year more than 1600");
    }
     
}
int main()
{
    int choice;
    while(1)
    {
        
        printf("\n1.Find out the day!!");
        printf("\n2.Exit");
        
    
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
           printf("\nEnter the date in the format dd mm yyyy:");
           scanf("%d %d %d",&date.dd,&date.mm,&date.yy);
           printf("Day is %s",getday(date.dd,date.mm,date.yy));
           break;
        case 2:
           printf("\nexit"); 
           exit(0);
        
    }
    }

}
