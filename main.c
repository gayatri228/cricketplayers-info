#include <stdio.h>
#include<string.h>
struct player 
{
   char name[10],country[10],cat[10];
   int age,n_odi,n_t20,n_wkt;
   float b_avg;
};
void accept(struct player p[10],int n);
void display(struct player p[10],int n);
void no_of_batsman(struct player p[10],int n);
void max_age(struct player p[10],int n);
void no_of_bowlers(struct player p[10],int n);
void max_wkt(struct player p[10],int n);
void sorted_data(struct player p[10],int n);

void accept(struct player p[10],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("ENTER NAME \n");
    scanf("%s",p[i].name);
    printf("ENTER COUNTRY \n");
    scanf("%s",p[i].country);
    printf("ENTER CATAGORY (batsman/bowler/all rounder/wc) \n");
    scanf("%s",p[i].cat);
    printf("ENTER AGE \n");
    scanf("%d",&p[i].age);
    printf("ENTER NO OF ODI PLAYED \n");
    scanf("%d",&p[i].n_odi);
    printf("ENTER NO OF T20 PLAYED \n");
    scanf("%d",&p[i].n_t20);
    printf("ENTER AVERAGE BATTING SCORE \n");
    scanf("%f",&p[i].b_avg);
    printf("ENTER NUMBER OF WICKETS TAKEN \n");
    scanf("%d",&p[i].n_wkt);
    

  }
}
void display(struct player p[10],int n)
{
char ch2[20];
  printf("Enter player's name \n:");
  scanf("%s",ch2);
  printf("\nNAME\t\tWICKETS\t\t\tAvg_SCORE\t\t\tCountry\t\t\tAge\n");
   for(int i=0;i<n;i++)
  {
    if((strcmp(ch2,p[i].name)==0))
    {
    printf("-------------------------------------------------------\n");
     printf("%s\t\t\t%d\t\t\t%f\t\t\t%s\t\t\t%d\n",p[i].name,p[i].n_wkt,p[i].b_avg,p[i].country,p[i].age);
    printf("-------------------------------------------------------\n");
    }
  }
}
int main()
{
  struct player p[10];
  int ch;
  int n;
     printf("\n ENTER NUMBER OF PLAYERS ");
      scanf("%d",&n);
    accept(p,n);

  do { 
     printf("\n0.exit \n1.no of batsman of particular country \n2.display data score vise\n3.Batsman with highest age \n4.no of bowlers of particular country \n5.display max wickets \n6.Show particular players the entire board information \n");
    printf("\n****ENTER YOUR CHOICE****\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      no_of_batsman(p,n);
      break;
       
      case 2:
      sorted_data(p,n);
      break;
      
      case 3:
      max_age(p, n);
      break;

      case 4:
      no_of_bowlers(p,n);
      break;

      case 5:
      max_wkt(p,n);
      break;
      
      case 6:
      display(p,n);
      break;

      default:
      break;
    }
    }while(ch!=0);

}
void no_of_batsman(struct player p[10],int n)
{
  char ch1[50];
  printf("ENTER COUNTRY \n");
  scanf("%s",ch1);
  
  printf("BATSMAN FROM THIS COUNTRY ARE :");
  for(int i=0;i<n;i++)
  {
      if((strcmp(ch1,p[i].country)==0)&&(strcmp(p[i].cat,"batsman")==0))
      {
        printf("%s \n",p[i].name);
      }
    
  }

  }

void max_age(struct player p[10],int n)
  {
     int i,index;
     int max=0;
     for( i=0;i<n;i++)
     {
       if(p[i].age>max)
       {
         max=p[i].age;
         index =i;
       }
     }
     printf("Max Age is %d of player : %s \n",max,p[index].name);
           }
void no_of_bowlers(struct player p[10],int n)
{
  char ch1[50];
  printf("ENTER COUNTRY \n");
  scanf("%s",ch1);
  
  printf(" BOWLERS FROM THIS COUNTRY ARE :");
  for(int i=0;i<n;i++)
  {
      if((strcmp(ch1,p[i].country)==0)&&(strcmp(p[i].cat,"bowler")==0))
      {
        printf("%s \n",p[i].name);
      }
    
  }

  }
void max_wkt(struct player p[10],int n)
  {
     int i,index;
     int max=0;
     for( i=0;i<n;i++)
     {
       if(p[i].n_wkt>max)
       {
         max=p[i].n_wkt;
         index=i;
       }
     }
     printf("Max wickets :%d \tName :%s\n",max,p[index].name);

           }
void sorted_data(struct player p[10],int n)
{ 
  int t;
  for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(p[j].b_avg>p[j+1].b_avg)
            {
                t=p[j].b_avg;
                p[j].b_avg=p[j+1].b_avg;
                p[j+1].b_avg=t;
            }
        }
    }
    
    printf("\nCricketer info in terms of runs scored from lowest to highest\n");
    printf("\nNAME\t\tWICKETS\t\t\tAVG_SCORE\t\t\tCountry\n");
    printf("---------------------------------------------------------------\n");
 
    for(int i=0;i<n;i++)
    {
        printf("%s\t\t\t%d\t\t\t%f\t\t\t%s\n",p[i].name,p[i].n_wkt,p[i].b_avg,p[i].country);
    }
}