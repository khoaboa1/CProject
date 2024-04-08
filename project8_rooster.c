#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define INSTRUMENT_LEN 30
#define GROUP_LEN 30

//Khoa Le U11734250. This project is about create a program to add, search for student information that already been input.

struct student{
    char first[NAME_LEN+1];
    char last[NAME_LEN+1];
    char email[EMAIL_LEN+1];
    char instrument[INSTRUMENT_LEN+1];
    char group[GROUP_LEN+1];
    struct student *next;
    };

struct student *add(struct student *list);
void search(struct student *list);
void print_list(struct student *list);
void clear_list(struct student *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;
    struct student *student_list = NULL;

    printf("Operation Code: a for adding to the list, s for searching"
    ", p for printing the list; q for quit.\n");

    for (;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'a': student_list = add(student_list);
                break;
            case 's': search(student_list);
                break;
            case 'p': print_list(student_list);
                break;
            case 'q': clear_list(student_list);
                return 0;
            default:  printf("Illegal code\n"); //Error case
        }
        printf("\n");
    }
}

struct student *add(struct student *list)
{
    //First of all, this is adding operation so I create struct new so user can add the information.
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
// define readline to use for input information.
int read_line(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;
    str[i++] = ch;
    while ((ch = getchar()) != '\n'){
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}  