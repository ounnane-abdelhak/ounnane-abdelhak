#include<stdio.h>
#include<stdlib.h>
#ifndef     project_h    
#define     project_h  

//the used struct 


typedef struct ami ami;
typedef struct rate_time rate_time;
struct rate_time  // create a struct for node of type rate_time
{
  int rate;
  int time;
  rate_time *next_time;
};

 struct ami // create a struct for node of type ami
 {
  int person;
  ami *next_ami;
 rate_time *next_time;
 };
 typedef ami *PTRami;
 typedef rate_time *PTRrate;
//the two available pointers PTRami and PTRrate
#endif




      //abstract machine :
//procedure that allocate a node of type ami ,it contain 3 fields :friend number;next friend and field to jump to times and ratings
void allocate_ami(PTRami *p);
//procedure that allocate a node of type time_rate ,it contain 3 fields : rating ; time of rating and next time of rating
void allocate_rate(PTRrate *p);
//procedure that assign next time of rating to a node of type time_rate
void ass_next_t(PTRrate p,PTRrate q);
//procedure that assign rate to a node of type time_rate
void ass_rate(PTRrate p,int rating);
//procedure that assign time  to a node of type time_rate
void ass_time(PTRrate p,int timing);
//procedure that assign next friend to a node of type ami 
void ass_next_f(PTRami p ,PTRami q );
//procedure that assign first time of rating to a node of type ami
void ass_times(PTRami p,PTRrate q);
//function gives the adress of the first rating time (the content of the field next_time);you give it the adress of type ami and it gives you an adress of type time_rate 
PTRrate times(PTRami p);
//function gives the adress of the next rating time(the content of the field next_time) ;you give it the adress of type time_rate and it gives you an adress of type time_rate
PTRrate next_t(PTRrate p);
//function gives the content of the field next_ami (adress of next friend)
PTRami next_F(PTRami p);
//procedure that assign the friend number(fill the field of person)
void ass_ami_num(PTRami p,int idto);
//fuction gives the content of the field person in a node of type ami
int read_p(PTRami p);
//function gives the content of the field time in a node of type time_rate 
int read_t(PTRrate p);
//function gives the content of the field rate in a node of type time_rate
int read_r(PTRrate p);

//end of abstract machine 


  

