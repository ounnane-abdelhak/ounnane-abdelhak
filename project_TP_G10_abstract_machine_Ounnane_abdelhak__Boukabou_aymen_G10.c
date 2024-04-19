#include "project_TP_G10_header_Ounnane_abdelhak__Boukabou_aymen_G10.h"
#include<stdio.h>

//abstract machine
//procedure that allocate a node of type ami ,it contain 3 fields :friend number;next friend and field to jump to times and ratings
void allocate_ami(PTRami *p)
{
    *p=(PTRami )malloc(sizeof(ami));
    (*p) ->next_time=NULL;
}
//procedure that allocate a node of type time_rate ,it contain 3 fields : rating ; time of rating and next time of rating
void allocate_rate(PTRrate *p)
{
*p=(PTRrate)malloc(sizeof(rate_time));
}
//procedure that assign next time of rating to a node of type time_rate
void ass_next_t(PTRrate p,PTRrate q)
{
p->next_time=q;
}
//procedure that assign rate to a node of type time_rate
void ass_rate(PTRrate p,int rating)
{
p->rate=rating;
}
//procedure that assign time  to a node of type time_rate
void ass_time(PTRrate p,int timing)
{
p->time=timing;
}
//procedure that assign next friend to a node of type ami 
void ass_next_f(PTRami p ,PTRami q )
{
p->next_ami=q;
}
//procedure that assign first time of rating to a node of type ami
void ass_times(PTRami p,PTRrate q)
{
p->next_time=q;
}
//function gives the adress of the first rating time (the content of the field next_time);you give it the adress of type ami and it gives you an adress of type time_rate 
PTRrate times(PTRami p)
{
    return p->next_time;
}
//function gives the adress of the next rating time(the content of the field next_time) ;you give it the adress of type time_rate and it gives you an adress of type time_rate
PTRrate next_t(PTRrate p)
{
return p->next_time;
}
//function gives the content of the field next_ami (adress of next friend)
PTRami next_F(PTRami p)
{
return p ->next_ami;
}
//procedure that assign the friend number(fill the field of person)
void ass_ami_num(PTRami p,int idto)
{
 p->person=idto;
}
//fuction gives the content of the field person in a node of type ami
int read_p(PTRami p)
{
return p->person;
}
//function gives the content of the field time in a node of type time_rate 
int read_t(PTRrate p)
{
return p->time;
}
//function gives the content of the field rate in a node of type time_rate
int read_r(PTRrate p)
{
return p->rate;
}
//end of abstract machine


