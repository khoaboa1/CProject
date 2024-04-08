#include <stdio.h> //For this one, I define and write all the code that I will need relate to list of student
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "readline.h" // I need to link readline because for some functions, I will use it.
#define EMAIL_LEN 100
#define NAME_LEN 30
#define INSTRUMENT_LEN 30
#define GROUP_LEN 30
struct student{
    char first[NAME_LEN+1];
    char last[NAME_LEN+1];
    char email[EMAIL_LEN+1];
    char instrument[INSTRUMENT_LEN+1];
    char group[GROUP_LEN+1];
    struct student *next;
    };
struct student *add(struct student *list)
{
    //First of all, this is adding operation so I create struct new so user can add the information.ﬁ
    struct student *new;
    struct student *p;
    //Create list that base on how many student user add.
    new = malloc(sizeof(struct student)); 
    if (new == NULL){
        printf("malloc failed"); //error message.
        return list;
    }

//Input student information.
    printf("Enter student last name: "); 
    read_line(new->last, NAME_LEN);
    printf("Enter student first name: "); 
    read_line(new->first, NAME_LEN);
    printf("Enter email address: "); 
    read_line(new->email, EMAIL_LEN);
    printf("Enter instrument: "); 
    read_line(new->instrument, INSTRUMENT_LEN);
    printf("Enter group: "); 
    read_line(new->group, GROUP_LEN);
    
    for(p=list;p!=NULL; p=p->next){ //Checks if a student exists
        if ( ((strcmp(p->last,new->last))==0) && ((strcmp(p->email,new->email))==0) ){
            printf("Request already exists");
            return list;
        }
    }

    if (list == NULL)
        return new;

    else
    {
        p = list;

        while(p-> next!=NULL){
            p=p->next;   
        }
        
        new->next = NULL;
        p->next = new;
        return list;
    }
}
void search(struct student *list)
{
    struct student *a;
    struct student b;
// I determine if student equal to 1 so I can start to look for it.
    int student=1;
// Then input the first name and last name so we can use string compare to look for it.
    printf("Enter student last name: "); 
    read_line(b.last, NAME_LEN);
    printf("Enter student first name: "); 
    read_line(b.first, NAME_LEN);
//Search through the list to find.
    for (a = list; a != NULL; a = a->next)
        if ( ((strcmp(a->last,b.last))==0) && ((strcmp(a->first,b.first))==0) )
        {
            printf("%s\t %s\t %s\t %s\t %s\t\n", a->last, a->first, a->email, a->instrument, a->group); //print information that already added for this student.
            student = 0; //Return student to 0 if not exist.
        }
    if(student)
        printf("Student not found.");
}
struct student *remove_from_list(struct student *list){
    // This function is for removing the node that user want.
    struct student *cur, *prev;
    char LAST[NAME_LEN+1];
    char FIRST[NAME_LEN+1];
    char EMAIL[NAME_LEN+1];
    printf("Enter student last name:");
    read_line(LAST,NAME_LEN+1);
    printf("Enter student first name:");
    read_line(FIRST,NAME_LEN+1);
    printf("Enter student email:");
    read_line(EMAIL,NAME_LEN+1);

    // I use the for loop from the class to search for the node by using strcmp as second condition.
    for (cur=list, prev=NULL; cur!=NULL; prev=cur, cur=cur->next ){
        if ((strcmp(cur->last, LAST)==0) && (strcmp(cur->first, FIRST)==0) && (strcmp(cur->email, EMAIL)==0))
            break;
    }
    if (cur == NULL){ 
        printf("Student not found\n");
        return list;
    }
    else if (prev == NULL)
        list = list->next;
    else
        prev->next = cur->next;
    printf("\n%s %s %s %s %s removed", LAST, FIRST, EMAIL, cur -> instrument, cur -> group);//make annoucement that the info has been cleared
    free (cur); //free the memory
    return list;
}
// Print out the list follow the structure.
void print_list(struct student *list) 
{
    struct student *p;
    for(p= list; p!=NULL; p = p->next)
        printf("%s\t %s\t %s\t %s\t %s\t\n", p->last, p->first, p->email, p->instrument, p->group);
        
    printf("\n");
}
//Clear the clist that already been used.
void clear_list(struct student *list) 
{
    struct student *p;
    while(list != NULL){
        p = list;
        list = list->next;
        if( p!= NULL)
            free(p);
    }
}