#include"project_TP_G10_abstract_machine_Ounnane_abdelhak__Boukabou_aymen_G10.c"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<windows.h>

//table of students that contain the adresses of the first friend node of type ami  
PTRami students[31];
//table contain the removed students
int removed[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//table used to preserve the shared friends and friends of a student
int friends[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


void menu2()
{




}





 //next 2 procedures and 2 functions are used  in the other procedures ,we create it to help us
// procedure that create a new node of type ami and tie it up to the series of friends
void add_ami(int idfrom,int idto)
{PTRami l,q;
allocate_ami(&q);ass_ami_num(q,idto);ass_next_f(q,NULL);
if((students[idfrom-1])==NULL)//traiting the case of the student have no friends
{
  students[idfrom-1]=q;
}
else//if there were friends
{
    l=students[idfrom-1];
    
while (next_F(l) != NULL)
{
 l=next_F(l);
}
ass_next_f(l,q);
//we created new node of type ami and tie it to the chain
}
}




//procedure that create a new time_rate node and add it to the chain of times and ratings
void add_time_rate(int idfrom,int idto, int rate,int time)
{PTRrate d,q;
    allocate_rate(&q);ass_rate(q,rate);ass_time(q,time);ass_next_t(q,NULL);//create new node of type rate_time
    PTRami l=students[idfrom-1];
while (read_p(l) != idto  &&  l !=NULL)//traiting the case of the friend have any ratings 
{
  l=next_F(l);
}
if (times(l)==NULL)
{ 
  ass_times(l,q); //tie the node to the chain
}
else
{
d=times(l);
while (next_t(d) !=NULL)
{
d=next_t(d);
}
ass_next_t(d,q);
//we created new node of type time_rate and tie it to the chain
}
}




//fuction that verifies if the idto exist in the list of friend of idfrom 
bool friend_exist(int idfrom,int idto)
{PTRami q;
bool exist=false;

q=students[idfrom-1];

while (q!=NULL)
{
if(read_p(q)==idto)
{
  exist=true;
}
q=next_F(q);
}
return exist;
}




//procedure that verifies if the time exist between two students
bool time_exist(int idfrom,int idto,int time)//the function search by passing through all the idfrom friends
{PTRami q;PTRrate l;
bool exist=false;
q=students[idfrom-1];

while (q!=NULL  && read_p(q)!=idto)
{
q=next_F(q);
}
if(q!=NULL)
{
l=times(q);
while (l!=NULL)
{
if(read_t(l)==time){exist=true;}
l=next_t(l);
}
}
return exist;
}
//






//procedure that load the file
void read_file()
{
  // create the list
int idfrom,idto,time,rate;
     FILE *pf;
     int i=0,j=0;
     pf=fopen("Dutch_college_social_network","r");
     
while (fscanf(pf,"%d %d %d %d",&idfrom,&idto,&rate,&time)==4)
{
  if(i!=idfrom  ||  j!=idto) //if the IDfrom or the IDto change we create a node of type friend 
  {
add_ami(idfrom,idto);
  }
  add_time_rate(idfrom,idto,rate,time);//we always create a node of type time_rate
i=idfrom;j=idto;
}
fclose(pf);
//end on creation of the list   
}
//






//procedure to display the social network
void display(int op,int student)
{                          //all this operations are for a better display
  
PTRami l;
PTRrate s;
int j=0;
if(op==1){
for (int i = 0; i < 32; i++)
{l=students[i];
if (removed[i]==0)
{ 
printf("                                 |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                              \n");
printf("                                          The Student %d ratings:                                           \n",i+1);
printf("                                 |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                              \n");
}
if(l==NULL && removed[i]==0){  printf("he didn't rate any one\n");}
  while (l!=NULL)
  {
    printf("|--------------------------------------------------------------------------------------------------------------------|\n");
    if((int)log10(read_p(l))+1==2)
    {
    printf("| student %d :                                                                                                       | \n",read_p(l));}else{
    printf("| student %d :                                                                                                        | \n",read_p(l));
    }
    s=times(l);
 
   while (s !=NULL)
   {
    j++;
    if(j%3==0)
    {
    if(read_r(s)!=-1)
    {
    printf("| the rating:%d  The time:%d     | \n",read_r(s),read_t(s));}
    else
    {
    printf("| the rating:%d  The time:%d    | \n",read_r(s),read_t(s));
    }
    }
    else
    {
      if(read_r(s)!=-1)
      {
    printf("| the rating:%d  The time:%d     ",read_r(s),read_t(s));
    }
    else
    {
    printf("| the rating:%d  The time:%d    ",read_r(s),read_t(s));
    }
    }
  s=next_t(s);
   }
   if(j%3!=0)
   {
   for(int i=1;i<=(3-(j%3));i++)
   {
printf("                                     ");
   }
   }
if(j%3==1){printf("    ");}
if(j%3==2){printf("  ");}


   if(j%3!=0)
   {
    printf("|\n");
   }
    printf("|--------------------------------------------------------------------------------------------------------------------|\n");
j=0;
l=next_F(l);
}  
  }
  }
  if(op==2)
  {
    l=students[student-1];
if (removed[student-1]==0)
{ 
printf("                                 |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                              \n");
printf("                                          The Student %d ratings:                                           \n",student);
printf("                                 |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                              \n");
}
if(l==NULL && removed[student-1]==0)
{
printf("he didn't rate any one\n");
}
  while (l!=NULL)
  {
    printf("|--------------------------------------------------------------------------------------------------------------------|\n");
    if((int)log10(read_p(l))+1==2)
    {
    printf("| student %d :                                                                                                       | \n",read_p(l));}else{
    printf("| student %d :                                                                                                        | \n",read_p(l));
    }
    s=times(l);
 
   while (s !=NULL)
   {
    j++;
    if(j%3==0)
    {
    if(read_r(s)!=-1)
    {
    printf("| the rating:%d  The time:%d     | \n",read_r(s),read_t(s));}else{
    printf("| the rating:%d  The time:%d    | \n",read_r(s),read_t(s));
    
    }
    }
    else
    {if(read_r(s)!=-1)
    {
        printf("| the rating:%d  The time:%d     ",read_r(s),read_t(s));
        }
        else
        {
    printf("| the rating:%d  The time:%d    ",read_r(s),read_t(s));
    }
    }
  s=next_t(s);
   }
   if(j%3!=0){
   for(int i=1;i<=(3-(j%3));i++)
   {
printf("                                     ");
   }
   }
if(j%3==1){printf("    ");}
if(j%3==2){printf("  ");}


   if(j%3!=0)
   {
    printf("|\n");
    }
    printf("|--------------------------------------------------------------------------------------------------------------------|\n");
j=0;
l=next_F(l);}  
  }
}
 //



//procedure to add new friend with new rating in specific time
void add_new_f(int idfrom,int idto ,int rate,int time)

{
 if (friend_exist(idfrom,idto)==0)//if the idto dosn't exist in the list of the idfrom we create a node of type ami
 {
 add_ami(idfrom,idto);
 }
  add_time_rate(idfrom,idto,rate,time);//add a node time_rate
}







//procedure to delete a student from the network
void remov_student(int idto)
{int i=0;
PTRami s,q;
PTRrate l,p;

for(i=0;i<=31;i++)//we pass through all the students and search for the student
{
 q=students[i];
 if(friend_exist(i+1,idto)==1)
 {
 if(read_p(q) == idto)// we find the student thet we want to remove
 {
  students[i]=next_F(q);
  l=times(q);
  while(l!=NULL)
  {p=next_t(l);
    free(l);//free all nodes of type time rate
    l=p;
  }
  free(q);//free the node of friend
 }else
{
 while(q!=NULL && next_F(q)!=NULL  )
 {
  if(read_p(next_F(q))==idto)
 {
  l=times(next_F (q));s=next_F(next_F(q)) ;free(next_F(q));
ass_next_f(q,s);
  
while(l!=NULL)
  {p=next_t(l);
    free(l);
    l=p;
  }
 
 }
 q=next_F(q);}
 }
 }
 }
q=NULL;
 q=students[idto-1];

while (q!= NULL)
{
  l=times(q);
  while (l!=NULL)
  {
p=next_t(l);
   free(l);
   l=p;
  } 
s=next_F(q);
free(q);
q=s;
}
students[idto-1]=NULL;
removed[idto-1]=1;
}





//procedure to delete a rating between two friends at a specific time from the network
void remov_friendship_rate(int idfrom,int idto,int time)
{
PTRami s,q;
PTRrate p,l;
bool exi=false;
q=students[idfrom-1];
s=q;
if (friend_exist(idfrom,idto)==1)//searching for the rating node that we want to delete
{
 while (q != NULL)
 {
 if(read_p(q)==idto)
 {l=times(q);
 
 if(read_t(l) == time)
 {exi=true;
  ass_times(q,next_t(l));
  free(l);
 }else
{
 while(l!=NULL && next_t(l)!=NULL  )
 {if(read_t(next_t(l))==time)
 {exi=true;
  p=next_t(l);
ass_next_t(l,next_t(next_t(l)));
free(p);
 break; 
 }l=next_t(l);}
 }
  break;
 }

 q=next_F(q);
 }
 if(exi==0){printf("time dosn't exist\n");}else{printf("done !\n");}
}else
{printf("the idfrom didn't rate the idto\n");}
//if the rated student dosn't have rating we must remove it
if(q!=NULL && times(q)==NULL)
{if(s==q)
{
  students[idfrom-1]=next_F(q);
  free(q);
}else{
  //we find the previous of q
  while(next_F(s)!=q)
  {
    s=next_F(s);
  }
  //free q and assign the privious friend before q and next friend after q
  ass_next_f(s,next_F(q));
  free(q);
}
}}




//procedure to find friends of idfrom in specific time and load it in friends table
void find_fr_in_time(int idfrom,int time)
{
PTRami q=students[idfrom-1];
PTRrate l;
while(q!=NULL)
{l=times(q);
while(l!=NULL)
{
if(read_t(l)==time && read_r(l)>=1)
{
  friends[read_p(q)-1]++;
}
l=next_t(l);
}
q=next_F(q);
}
friends[32]=0;
}






//procedure to find shared friends between idfrom1 and idfrom2 in specific time and load it in friends table
void find_shared_f(int idfrom1,int idfrom2,int time)
{find_fr_in_time(idfrom1,time);
find_fr_in_time(idfrom2,time);
friends[32]=1;
}





//procedure to read friends table,must be always used after "find_fr_in_time" and "find_shared_f" procedures
void read_friend_tab()
{int j=0;//friend[32] is an option to now if we are using "shared friend" or "find friend in spicefic time"
  if(friends[32]==0){printf("the friends of the student idfrom are :\n");}
 if(friends[32]==1){printf("the shared friends between this two student are :\n");} 
for (int i = 0; i <= 31; i++)
{
 if(friends[i]==friends[32]+1)//in case of shared friends we search for 2 in friends tab         ,in find friends of person we search for 1 in friends tab 
 {
  j++;//in case of the idfrom had no friends or shared friends between idfrom1 and idfrom2
  printf("student number %d .\n",i+1);
 }
  friends[i]=0;//intialize the table of friends to 0
}

if(j==0){if(friends[32]==0){printf("he hadn't friends in that time.\n");}
else
{printf("they hadn't a shared friends in that time.\n");}; }
friends[32]=0;
}
//





//procedure that calculate the average of a student's rating 
void calc_avreg(int idfrom)
{PTRami p;
PTRrate l;
int j=0;
float sum=0;
for(int i=0;i<=31;i++)///search for all persons that rate him ,keep the sum of ratings and how many times they rate him
{p=students[i];
while(p!=NULL)
{
if(read_p(p)==idfrom){l=times(p);
  while (l!=NULL)
  {
   j++;
   sum+=read_r(l);
   l=next_t(l);
  }
 
}p=next_F(p); 
}

}
sum=sum/j;//divide the sum by the number of times of rating
  
printf("the average is : %f \n",sum);
}








//procedure that gives the closest friends of a student 
void close_friend(int idfrom)
{
PTRami q=students[idfrom-1];
PTRrate l;
int i=0,  rate=-1, time=0;
while(q!=NULL)//we pass through all fatings of idfrom
{l=times(q);
while (l!=NULL)
{
 if(time<=read_t(l))//we keep the rating of the last time
 {
time=read_t(l);
rate=read_r(l);
 }

 l=next_t(l);
}
if(rate>=2){i++;printf("the student %d is a close friend for %d .\n",read_p(q),idfrom);}//if the rating was bigger then or equal to 2 ,we consider him as a close friends
q=next_F(q);
}
if(i==0){printf("the student %d has no close friends.\n",idfrom);}//in case of he dosn't have a close friends
}





//procedure that estimate the strength of a friendship 
void strength_friend(int idfrom1,int idfrom2,int time)
{
PTRami q=students[idfrom1-1];
PTRrate l;
int rate1=-2,rate2=-2,avg;
if(friend_exist(idfrom1,idfrom2)==1)//search for the rating in that time of idfrom1
{
while(q!=NULL  && read_p(q)!=idfrom2  )
{
 q=next_F(q);
}
l=times(q);
while (l!=NULL && read_t(l)!=time )
{
 l=next_t(l);
}
if(l!=NULL)
{
rate1=read_r(l);
}
}
if(friend_exist(idfrom2,idfrom1)==1)//search for the rating in that time of idfrom2
{
q=students[idfrom2-1];

while(q!=NULL && read_p(q)!=idfrom1 )
{
 q=next_F(q);
}
l=times(q);

while (l!=NULL && read_t(l)!=time )
{
 l=next_t(l);
}
if(l!=NULL)
{rate2=read_r(l);}}
avg=(rate1+rate2)/2;//the strength of the friendship is the sum of the there ratings to each other divided by 2 

if(rate1==-2 && rate2==-2)//in case of no one rated the other
{
  printf("no one rated the other in that time .\n");
}
if((rate1==-2 && rate2!=-2) || (rate2!=-2  && rate1==-2))//in case of only one of then rated the other 
{
  if(rate1==-2)
{
  printf("the strength of their friendship is : %d \n note: student %d didn't rate\n",rate2,idfrom1);
}
if(rate2==-2)
{
  printf("the strength of their friendship is : %d \n note: student %d didn't rate\n",rate1,idfrom2);
  }
}
if(rate1!=-2 && rate2!=-2)//in case of both rate
{
  printf("the strength of their friendship is : %d \n",avg);
  }
}





//procedure that print the menu
void MENU()
{
  printf("-----------------------------------------------------THE MENU---------------------------------------------------------\n");
printf("|-1- add a friendship rating at a specific time ?                                                                    |\n");
printf("|-2- remove a student from the social network ?                                                                      |\n");
printf("|-3- remove a friendship rating between 2 students at specific time ?                                                |\n");
printf("|-4- find all friends of a student at a specific time ?                                                              |\n");
printf("|-5- find shared friends of two student at specific time ?                                                           |\n");
printf("|-6- check the strength of friendship between two student at specific time ?                                         |\n");
printf("|-7- find the closest friends of a given student ?                                                                   |\n");
printf("|-8- calculate the average friendship rating of a student across all time points ?                                   |\n");
printf("|-9- display the results ?                                                                                           |\n");
printf("|-10- exit.                                                                                                          |\n");
printf("|--------------------------------------------------------------------------------------------------------------------|\n");
printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~enter your choice~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
printf("|--------------------------------------------------------------------------------------------------------------------|\n             here :");
}
//


 int main()
{
  int i,op,time ,rate,idfrom1,idfrom2,idto,firstchoice=1;
  
  
  //load the social network
  read_file();
  //
  //print the menu
MENU();
scanf("%d",&i);
// repeat printing the menu until the user enter 10 
while(i!=10){
if(firstchoice==0){
MENU();
scanf("%d",&i);}
firstchoice=0;

switch(i)
{//the option 1: 
case 1: 
 printf("enter the number of the the first student :\n");
  printf("if you want to return enter 0 (the return option is available only now.)\n ");
 scanf("%d",&idfrom1);
 if(idfrom1==0){break;}
 
  //verify if student exist
 while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33)
 {printf("this student dosn't exist.\n");
 printf("reenter the number of the first student :\n");
 
  printf("if you want to return enter 0 (the return option is available only now.)\n");
scanf("%d",&idfrom1);
 
 }
 if(idfrom1==0){break;}
  printf("enter the number of the scond student :\n");
 scanf("%d",&idto);
 //verify if student exist and dosn't equal to ID from 
 while(removed[idto-1]==1 || idto<=0  || idto>=33 || idto==idfrom1) 
 {if(idto==idfrom1)
 {
  printf("impossible IDto can't be equal to IDfrom.\n");
  }
  else
  {printf("the student dosn't exist.\n");}
 printf("reenter the number of the second student  : \n");
 scanf("%d",&idto);
 }
 //take the time
 printf("enter the time :\n");
 scanf("%d",&time);
 //verify if the time exist
 while(time_exist(idfrom1,idto,time)==1||(time!=927846000 && time!=920588400 && time!=918774000 && time!=913330800 && time!=915145200 && time!=916959600 && time!=924217200)  ) 
 {if(time_exist(idfrom1,idto,time)==1){printf("The time already exist.\n reenter the time :\n");}else{printf("this time is not available \n reenter the time : \n");}
  scanf("%d",&time);
 }//take the rate
  printf("enter the rate :\n");
 scanf("%d",&rate);
 //verify if the rate is between -1 and 3
while (rate>=4 || rate<=-2) 
{
  printf("the rate is no available\n");
   printf("reenter the rate :\n");
 scanf("%d",&rate);
}//add the friend
add_new_f(idfrom1,idto,rate,time);
//verify if the new friend was created to check if the memory is not full
if(time_exist(idfrom1,idto,time)==0){printf("failed no more avalaible space in memory .\n");}else{
printf("done !\n");}
  break;
//the option 2:
case 2: 
 printf("enter the number of the the student you want to delete :\n");
  printf("(if you want to return enter 0 )\n    ");
 scanf("%d",&idfrom1);
 //verify if student exist
 while(idfrom1<0 ||idfrom1>=33 || removed[idfrom1-1]==1  ) 
 {if(idfrom1==0){break;}
 else 
 {printf("this student dosn't exist.\n");
  printf("reenter the student you want to delete :\n");
  printf("(if you want to return enter 0)\n    ");
 scanf("%d",&idfrom1);}
 }
 //if the input was 0 the program will return to the menu
 if(idfrom1==0){break;}
 //remove the student
 remov_student(idfrom1);
 printf("done ! \n");
 break;
 //the option 3:
case 3: 
printf("enter the number of the first student :\n");
 printf("if you want to return enter 0 (the return option is available only now. )\n");
 scanf("%d",&idfrom1);
 if(idfrom1==0){break;}
 
//verify if student exist
  while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33)   
 {printf("this student dosn't exist.\n");
  printf("if you want to return enter 0 (the return option is available only now.)\n ");
 printf("reenter the number of the first student :\n");

 scanf("%d",&idfrom1);
 
 }
 if(idfrom1==0){break;}
 printf("enter the number of the scond student \n");
 scanf("%d",&idto);
 //verify if student exist and dosn't equal to ID from
 while(removed[idto-1]==1 || idto<=0  || idto>=33 || idto==idfrom1) 
 {if(idto==idfrom1){printf("impossible IDto can't be equal to IDfrom.\n");}else
  {printf("the student dosn't exist.\n");}
 printf("reenter the number of the second student  : \n");
 scanf("%d",&idto);
 }
 //take the time
 printf("enter the time :\n");
 scanf("%d",&time);
 //remove the rating at that time
 remov_friendship_rate(idfrom1,idto,time);
break;
//the option 4:
case 4:
printf("enter the number of the student :\n");
 printf("if you want to return enter 0 (the return option is available only now. )\n");
 scanf("%d",&idfrom1);
 if(idfrom1==0){break;}
 
 //verify if student exist
  while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33)
 {printf("this student dosn't exist.\n");
  printf("if you want to return enter 0 (the return option is available only now. )\n");
  printf("reenter the number of the student :\n");
   scanf("%d",&idfrom1);
   
 }
 if(idfrom1==0){break;}
 // receive the time
 printf("enter the time :\n");
 scanf("%d",&time);
 //find the friends and put it in the table
find_fr_in_time(idfrom1,time);
//read the table of the friends
read_friend_tab();
//
break;
//the option 5:
case 5:
printf("enter the number of the the first student:\n");
 printf("if you want to return enter 0 (the return option is available only now.)\n ");
 scanf("%d",&idfrom1);
 if(idfrom1==0){break;}

 

//verify if student exist
 while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33)
 {printf("this student dosn't exist.\n");
 printf("if you want to return enter 0 (the return option is available only now. )\n");
  printf("reenter the number of the first student :\n");
 scanf("%d",&idfrom1);
 
 }
 if(idfrom1==0){break;}
printf("enter the  number of the scond student : \n");
scanf("%d",&idfrom2);
//verify if student exist and dosn't equal to ID from 
 while(removed[idfrom2-1]==1 || idfrom2<=0  || idfrom2>=33 || idfrom2==idfrom1)
 {if(idto==idfrom1){printf("impossible IDto can't be equal to IDfrom.\n");}else
  {printf("the student dosn't exist.\n");}
 printf("reenter the number of the second student  : \n");
 scanf("%d",&idfrom2);
 }//receive the time
printf("enter the time :\n");
 scanf("%d",&time);
find_shared_f(idfrom1,idfrom2,time);
read_friend_tab();
break;
//the option 6:
case 6:
printf("enter the number of the the first student :\n");
printf("if you want to return enter 0 (the return option is available only now. )\n");
scanf("%d",&idfrom1);
if(idfrom1==0){break;}
 //verify if student exist
 while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33)
 {printf("this student dosn't exist.\n");
 printf("if you want to return enter 0 (the return option is available only now. )\n");
printf("reenter the number of the first student :\n");
 scanf("%d",&idfrom1);
 
 }
 if(idfrom1==0){break;}
printf("enter the  number of the scond student : \n");
scanf("%d",&idfrom2); 
 //verify if student exist and dosn't equal to ID from 
while(removed[idfrom2-1]==1 || idfrom2<=0  || idfrom2>=33 || idfrom2==idfrom1)
 {if(idto==idfrom1){printf("impossible IDto can't be equal to IDfrom.\n");}else
  {printf("the student dosn't exist.\n");}
 printf("reenter the number of the second student  : \n");
 scanf("%d",&idfrom2);
 }
 //receive the time
printf("enter the time :\n");
 scanf("%d",&time);
strength_friend(idfrom1,idfrom2,time);
break;
//the option 7:
case 7:
printf("enter the number of the student :\n");
printf("if you want to return enter 0 \n ");
scanf("%d",&idfrom1);
if(idfrom1==0){break;}
 //verify if student exist
 while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33) 
 {printf("this student dosn't exist.\n");
 printf("if you want to return enter 0 \n ");
  printf("reenter the number of the student :\n");
 scanf("%d",&idfrom1);
 
 }
 if(idfrom1==0){break;}
 //find and print the close friends
close_friend(idfrom1);
break;
//the option 8:
case 8:
printf("enter the number of the student :\n");
printf("if you want to return enter 0\n ");
scanf("%d",&idfrom1);
if(idfrom1==0){break;}
 while(removed[idfrom1-1]==1 || idfrom1<0  || idfrom1>=33){ //verify if student exist
  printf("reenter the number of the student :\n");
  printf("if you want to return enter 0 \n ");
 scanf("%d",&idfrom1);
 
 }
 if(idfrom1==0){break;}
 //calculate the averege and print it
calc_avreg(idfrom1);
break;
//the option 9:
case 9:
printf("Options :\n-------------------------------------\n| -1- display all the list.         |\n| -2- display a specefic student.   |\n-------------------------------------\n enter your option :\n    here :");
scanf("%d",&op); 
//verify if the option is avalaible (1 or 2)
while(op<=0 || op>=3){printf("your option is not avalaible\n reenter:\n");scanf("%d",&op);}
if(op==2){
printf("enter the number of the student :\n   ");
scanf("%d",&idfrom1);
//verify if student exist
 while(removed[idfrom1-1]==1 || idfrom1<=0  || idfrom1>=33)
 {printf("this student dosn't exist.\n");
  printf("reenter the number of the student :\n   ");
 scanf("%d",&idfrom1);}}
 //display the list it depends on the option
display(op,idfrom1);
break;
//the option 10:
case 10:
printf("Thanks for using ,have a great time !\n");
break;
default:printf("your choice is not available.\n");
  break;
}
}
if(firstchoice==1){printf("Thanks for using ,have a great time !\n");}
printf("press any key ...");
getch();


}
