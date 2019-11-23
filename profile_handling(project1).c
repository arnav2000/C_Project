#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct student
 {
    char name[20];
    char edu[20];
    char email[30];
    int bir;
    char phone[10];
 };
 void create_profile();
 void view_profile();
 void edit_profile(char[]);
int main()
{
  int i,j,k;char rep;char repc;
      printf("\t\t\t\tPROFILE HANDLING\t\t\t\t\t\t\t\t\t");
      printf("\n\n");
      printf("\tDo you Have a Account???\n");
      printf("\t((Press Y for Yes and N for No))\n");
      rep=getch();
  if(rep=='N' || rep=='n')
 {
     printf("\tDO you Want To Create it???\n");
     printf("\t((Press Y for Yes and N for No))\n");
     repc=getch();
        if(repc=='N' || repc=='n')
         {
        printf("\tYou entered No\n");
        printf("\tThankyou,Visit Again");
          }
        else if(repc=='Y' || repc=='y')
          {
            create_profile();
          }
 }
   else if(rep=='Y' || rep=='y')
  {
      view_profile();
  }
}
///////////////////////////////////////////////////////////////////////////////
 void create_profile()
 {
    char str[12];char chname[]=".txt";char birth[4];char str1[7];char str2[4];
    struct student e1;
         printf("Enter Name: ");
         gets(e1.name);
         printf("\nEnter Education Qualifications: ");
         gets(e1.edu);
         printf("\nEnter your E-mail: ");
         gets(e1.email);
          printf("\nEnter Phone Number: ");
         gets(e1.phone);
         printf("\nEnter your Birth(Year): ");
         scanf("%d",&e1.bir);
         //printf("\n");
          itoa(e1.bir,birth,10);///////////convert int to string
          strncpy(str2,e1.name,4);
          printf("ff %s ",str2);
        //strcpy(str,str2);
         strcat(birth,str2);
         //str2[8]='\0';
         printf("aa %s ",birth);
         //printf("hello %s\n",str);
         strcpy(str1,birth);
         //strcpy(str,str1);
        // strcat(str,chname);
          //printf(" %s",str1);
          FILE *fp;
     fp=fopen(str1,"w+");
        fprintf(fp,"Name: %s\nEducationQualification: %s\nE-mail: %s\nPhone No.: %s\nBirth(Year): %d",e1.name,e1.edu,e1.email,e1.phone,e1.bir);
     fclose(fp);
     printf("\nYour File Has Been Created With Name %s\n",str1);
 }
 /////////////////////////////////////////////////////////////////////////////////////
  void view_profile()
 {
     char repf;char repd;char repe;int ch;
    char fname[20];struct student e1;char fname1[20];
     printf("Enter Your Filename ");
     gets(fname);
    // strcat(fname,".txt");
     FILE *fp1;
     fp1=fopen(fname,"r");
     if(fp1==NULL)
     {
         printf("No FILE EXIT,TRY AGAIN");
     }
     else
     {
     //fscanf(fp1,"%s\n%s\n%s\n%s\n%d",e1.name,e1.edu,e1.email,e1.phone,&e1.bir);
     printf("\t\t\t*****STUDENT DETAILS******\t\t\n");
     ch=fgetc(fp1);
     while(ch!=EOF)
     {
         putchar(ch);
         ch=fgetc(fp1);
     }
     fclose(fp1);
     printf("Do You Want To Delete The File????\n");
     printf("Press Y for Yes and N for No\n");
     repd=getch();
     if(repd=='Y' || repd=='y')
     {
         printf("Enter Filename to delete..\n");
         scanf("%s",fname1);
       remove(fname1);
       printf("DElete successfully\n");
       printf("Do You Want To Create Again???\n");
       printf("Press Y for Yes and N for No\n");
       repe=getch();
       if(repe=='Y' || repe=='y')
       {
          create_profile();
       }
       else if(repe=='N' || repe=='n')
       {
           printf("\nThankyou,Visit Again..");
       }
     }
     else if(repd=='N' || repd=='n')
     {
     printf("Do You Want To Edit???\n");
     printf("Press Y for Yes and N for No\n");
     repf=getch();
     if(repf=='N' || repf=='n')
     {
         printf("Thankyou,Visit Again\n");
         printf("Press ENTER To Exit..");
     }
     else if(repf=='Y' || repf=='y')
     {
         edit_profile(fname);
     }
 }
     }
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////
  void edit_profile(char fname[])
  {
   FILE *fp2;struct student e2;int ch1;
  fp2=fopen(fname,"a+");
   // fscanf(fp2,"%s\n%s\n%s\n%s\n%d",e1.name,e1.edu,e1.email,e1.phone,&e1.bir);
     printf("\t\t\t*****STUDENT DETAILS******\t\t\n");
     ch1=fgetc(fp2);
     while(ch1!=EOF)
     {
         putchar(ch1);
         ch1=fgetc(fp2);
     }
 //////////////////////////////////////////
        printf("\t\t*****UPDATED STUDENT DETAILS******\t\t\n");
       printf("Enter Udated Name: ");
       gets(e2.name);
       printf("\nEnter Updated Education Qualifications: ");
         gets(e2.edu);
         printf("\nEnter New E-mail: ");
         gets(e2.email);
          printf("Enter New Phone Number: ");
         gets(e2.phone);
          printf("\nEnter Birth(Year)");
          scanf("%d",&e2.bir);
         fprintf(fp2,"\n\n*****UDATED DETAILS*****\n\nName: %s\nEducation Qualification: %s\nE-mail: %s\nPhone no.: %s\nBirth(Year): %d",e2.name,e2.edu,e2.email,e2.phone,e2.bir);
     fclose(fp2);
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
