#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void Head();
void Welcome();
void Center(char *title);
int log();
void Add_V(int count);
int Check_name(char *str);
int Check_date(int dd, int mm, int yyyy);
void Search_V(int count);
void show(int a);
void View_V(int count);
int Delete_V(int count);
void Up_p();
int menu();
struct V_details{
    int v_id;
    char v_name[30];
    char m_name[50];
    int day, month, year;
}input[];
struct Up_Credential{
    char user[32];
    char pass[32];
}u;
int main()
{
    system("COLOR F1");
    int Option, count = 0;
    int k;

    Head();
    Welcome();
    strcpy(u.user,"Team");
    strcpy(u.pass,"Team");
    top:
    do{
        k = log();
        if(k==0)
        {
            printf("\n\t\t\t\tLogin Failed!!");
            printf("\n\t\t\t\tPlease Try Again...");
            getche();
        }
        else{
            k = 1;
        }
    }while(k!=1);

     do{
         Option = menu();

         switch(Option)

         {
         case 1:
            count++;
            Add_V(count);
            break;
         case 2:
            Search_V(count);
            break;
         case 3:
            View_V(count);
            break;
         case 4:
            count = Delete_V(count);
            break;
         case 5:
            Up_p();
            system("cls");
            goto top;
            break;
         case 6:
             printf("\n\n\n\n\n\t\t\t\t\t                                                        Thank You!!!");
             printf("\n\n\n\n");
            return 0;
            break;
         default:
            printf("\n\n\n\t\t\t\tUnrecognized Number!!");
            printf("\n\n");
            printf("\n\t\t\t\t\t                                                          Try Again..");
            getche();
            break;
         }

     }while(Option!=6);

     return 0;
}
void Head()

{
    printf("\n");
    printf("\t\t\t     #<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=>#");
    printf("\n\t\t\t                           <======================================================================================================>     ");
    printf("\n\t\t\t                           <=======================                                                        =======================>     ");
    printf("\n\t\t\t                           <=======================               Vehicle Management System                =======================>     ");
    printf("\n\t\t\t                           <=======================                                                        =======================>     ");
    printf("\n\t\t\t                           <======================================================================================================>     ");
    printf("\n\t\t\t                           <======================================================================================================>     ");
    printf("\n");
    printf("\n");
}
void Center(char title[])

{
    system("cls");
    Head();
    int a, b, c, d;
    d = strlen(title);

     for(a=1;a<=5;a++)
        {
            printf("\t\t\t\t\t\t    ");
            for(c=1;c<=102;c++)
                {
                    if(a==1||a==5)
                        {
                            printf("=");
                        }
                    else if(a==3)
                        {
                            for(b=1;b<51-(d/2);b++)
                                {
                                    printf(" ");
                                }
                            printf(title);
                            break;
                        }
                    else printf(" ");
                }
                printf("\n");
        }
}
void Welcome()

{
    Center("CSE103");
    printf("\n");
    printf("\n");
    printf("\n\t\t\t                           <======================================================================================================>     ");
    printf("\n\t\t\t                                                                                                                          ");
    printf("\n\t\t\t                                                        ==============================================                    ");
    printf("\n\t\t\t                                                        ==                  WELCOME                 ==                    ");
    printf("\n\t\t\t                                                        ==                    TO                    ==                    ");
    printf("\n\t\t\t                                                        ==                  VEHICLE                 ==                    ");
    printf("\n\t\t\t                                                        ==                 MANAGEMENT               ==                    ");
    printf("\n\t\t\t                                                        ==                  SYSTEM                  ==                    ");
    printf("\n\t\t\t                                                        ==============================================                    ");
    printf("\n");
    printf("\n\t\t\t                           <======================================================================================================>     ");
    printf("\n");
    printf("\n\t\t\t\tPress Enter Key To Continue......");
    getche();
}
int log()

{
  int f;
  char arr1[16], arr2[16];

    printf("\n\n");
    do{
        system("cls");
        Head();
        Center("Login");

        printf("\n\n\t\t\t\tEnter User name : ");
        gets(arr1);

        printf("\n\t\t\t\tEnter Password  : ");
        gets(arr2);

        if(strcmp(u.user, arr1)==0 && strcmp(u.pass, arr2)==0)
        {
            f = 1;
        }
       else
       {
           f = 0;
           printf("\n\n\n\t\t\t\tPlease Try Again....");
           getche();
       }
   }while(f!=1);

    return f;
}
int menu()

{
    system("cls");
    Head();
    Center("Main Menu");

    int a;
    char temp[10];
    printf("\n\n\n");
    printf("\t\t\t\t1.Add Vehicles.");
    printf("\n\t\t\t\t2.Search Vehicles.");
    printf("\n\t\t\t\t3.View Vehicles.");
    printf("\n\t\t\t\t4.Delete Vehicles.");
    printf("\n\t\t\t\t5.Update Password.");
    printf("\n\t\t\t\t6.Exit.");
    printf("\n\n\n");
    printf("\t\t\t\tEnter An Option : ");
    gets(temp);
    a=atoi(temp);

    return a;
}
void Add_V(int count)

{
    system("cls");
    Head();
    Center("ADD VEHICLES DETAILS");
    printf("\n");
    int a, i, j, k, l, m, n;
    char temp[80];
    a = (count-1);
    printf("\n\t\t\t\tENTER VEHICLES DETAILS BELOW: ");
    printf("\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("\n\t\t\t\tVehicle ID NO : ");
    gets(temp);
    input[a].v_id = atoi(temp);
    do{
        printf("\n\t\t\t\tVehicle Name : ");
        gets(input[a].v_name);

        i = Check_name(input[a].v_name);

        if(i==0)
        {
            printf("\n\t\t\t\tInvalid! \n\n Please..Try Again..");
            getchar();
            k = 0;
        }
        else
        {
            k = 1;
        }
    }while(k==0);

    do{
            printf("\n\t\t\t\tVehicle Manufacturer Name : ");
            gets(input[a].m_name);

            j = Check_name(input[a].m_name);

        if(j==0)
        {
            printf("\n\t\t\t\tInvalid! \n\n Please..Try Again..");
            getchar();
            l = 0;
        }
        else
        {
           l = 1;

        }

      }while(l==0);

       do
      {
        printf("\n\t\t\t\tVehicle Manufacture Date (Day/Month/Year): ");
        scanf("%d/%d/%d", &input[a].day, &input[a].month, &input[a].year);
        gets(temp);

        m = Check_date(input[a].day,input[a].month,input[a].year);
        if(m==0)
        {
            printf("\n\t\t\t\tINVALID! \n\n Please..TRY AGAIN..");
            getchar();
            n = 0;
        }
        else
        {
            n = 1;
        }
     }while(n==0);


           printf("\n\t\t\t\tPress Enter To Go To Main Menu...");
           getche();

}
int Check_name(char *str)

{
    int a, flag;
    flag = 0;

    if(strlen(str)<30)
    {
       flag = 1;
    }
    else flag = 0;

    for(a=0;a<=strlen(str)-1;a++)
    {
        if( (str[a]>='A' && str[a]<='Z') || (str[a]>='a' && str[a]<='z') || (str[a]>='0' && str[a]<='9') )
        {
            flag = 1;
        }
        else flag = 0;
    }

    return flag;
}
int Check_date(int dd, int mm, int yyyy)

{
    int i, j, k, found1;

    found1 = 0;

       if(yyyy>=1900 && yyyy<=2023)
        {
            i = 1;
        }
        else
        {
            i = 0;
        }

        if(mm>=1 && mm<=12)
        {
            j = 1;
        }
        else
        {
            j = 0;
        }
        if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
        {
            k = 1;
        }
        else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
        {
            k = 1;
        }
        else if((dd>=1 && dd<=28) && (mm==2))
        {
            k = 1;
        }
        else if((dd==29 && mm==2) && ((/*yyyy%400==0 ||*/ yyyy%4==0) && (yyyy%100!=0)))
        {
            k = 1;
        }
        else
        {
            k = 0;
        }
        if(i==0||j==0||k==0)
        {
            found1 = 0;
        }
        else
        {
            found1 = 1;
        }

        return found1;
}
void Search_V(int count)

{
    system("cls");
    Head();
    Center("SEARCH VEHICLE");
    int a, found2;
    char hi[80];

    printf("\n");
    printf("\n\t\t\t\tEnter Vehicle Name to search: ");
    gets(hi);

    for(a=0;a<count;a++)
    {
        if(strcmp(input[a].v_name, hi)==0)
        {
            found2 = 1;
            break;
        }

        else
        {
            found2 = 0;
        }
    }
    if(found2==1)
    {
        Show(a);
    }
    else
    {
        printf("\n\t\t\t\tVehicle Not Found...");
    }
     printf("\n\n\t\t\t\tPress Enter Key To Go To Main menu...");
     getche();
}
void Show(int a)

{
    printf("\n\t\t\t\tVehicle ID NO : %u",input[a].v_id);
    printf("\n\t\t\t\tVehicle Name : %s",input[a].v_name);
    printf("\n\t\t\t\tVehicle Manufacturer Name : %s",input[a].m_name);
    printf("\n\t\t\t\tVehicle Issued Date By Manufacturer (day/month/year): %d/%d/%d",input[a].day, input[a].month, input[a].year);
}
void View_V(int count)
{
    system("cls");
    Head();
    Center("VIEW VEHICLE DETAILES");

    int a, c = 1;

    if(count==0)
      {
        printf("\n\t\t\t\tNo Records...");
      }
    else
      {
        for(a=0;a<count;a++)
         {
            printf("\n\t\t\t\tVehicle Count: %d",c);
            printf("\n\n\t\t\t\tVehicle ID NO : %u",input[a].v_id);
            printf("\n\t\t\t\tVehicle Name : %s",input[a].v_name);
            printf("\n\t\t\t\tVehicle Manufacturer Name : %s",input[a].m_name);
            printf("\n\t\t\t\tVehicle Issued Date By Manufacturer (day/month/year): %d/%d/%d",input[a].day,input[a].month,input[a].year);
            printf("\n\n\n");
            c++;
         }

      }
      printf("\n\n\t\t\t\tPress Enter Key To Go To Main Menu...");
      getche();
}
int Delete_V(int count)

{
    system("cls");
    Center("DELETE VEHICLE DETAILES");
    printf("\n");

    char temp[30];
    int a, b, found, d;
    found = 0;

    if(count>0)
    {
    printf("\n\t\t\t\tEnter Vehicle ID NO. For Delete: ");
    gets(temp);
    b = atoi(temp);

    for(a=0;a<count;a++)
    {
        if(b==input[a].v_id)
            {
                found = 1;
                d = a;
                break;
            }
    }
    if(found==1)
        {
           for(a=d;a<count;a++)
            {
                input[a] = input[a+1];
            }

            printf("\n\n\n\t\t\t\tRecord deleted successfully.....");
            count--;
        }
    else
        {
            found = 0;
            printf("\n\t\t\t\tNot found");
        }
    printf("\n\n\n\t\t\t\tPress Enter Key To Go To Main Menu...");
    getche();

    }
    else
    {
        printf("\n\t\t\t\tNot Vehicles Reg...");
        getche();
    }

    return count;
}
void Up_p()

{
    system("cls");
    Head();
    Center("UPDATE CREDENTIAL");
    printf("\n");
    int a, f1, f2;
    char temp[32];
    f1 = 1;
    f2 = 1;

   do{
        printf("\n\t\t\t\tNew Username: ");
        gets(temp);

        if((strlen(temp)<4) || (strlen(temp)>32))
        {
            f1 = 0;
        }
        if(!(((temp[0]>='A')&&(temp[0]<='Z')) || ((temp[0]>='a')&&(temp[0]<='z'))))
        {
            f1 = 0;
        }
        for(a=0;a<strlen(temp);a++)
        {
            if(!( ((temp[a]>='A')&&(temp[a]<='Z')) || ((temp[a]>='a')&&(temp[a]<='z'))))
            {
                f1 = 0;
            }
        }
        if(f1==0)
        {
            printf("\n\t\t\t\tWrong Key_Words!!");
            printf("\n\n\t\t\tPlease Try again...");
        }
        else
        {
           f1 = 1;
           strcpy(u.user,temp);
        }
    }while(f1!=1);
    printf("\n\t\t\t\tYour Username has been changed successfully.....");
    printf("\n\n");

    char t[32];

    do{
        printf("\n\t\t\t\tNew Password: ");
        gets(t);

        if((strlen(t)<4) || (strlen(t)>32))
        {
            f2 = 0;
        }
        if(!(((t[0]>='A')&&(t[0]<='Z')) || ((t[0]>='a')&&(t[0]<='z'))))
        {
            f2 = 0;
        }
        for(a=0;a<strlen(t);a++)
        {
            if(!(((t[a]>='A')&&(t[a]<='Z')) || ((t[a]>='a')&&(t[a]<='z')) || ((t[a]>='0')&&(t[a]<='9'))))
            {
                f2 = 0;
            }
        }

        if(f2==0)
        {
            printf("\n\t\t\t\tWrong Key_Words!!");
            printf("\n\n\t\t\t\tPlease Try again...");
        }
        else
        {
           f2 = 1;
           strcpy(u.pass,t);
        }
    }while(f2!=1);

    printf("\n\t\t\t\tYour Password has been changed successfully.....");
    printf("\n\n");
    printf("\n\n\n\t\t\t\tLogin Again -->");
    getche();
}






