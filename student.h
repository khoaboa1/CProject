#include <stdio.h> //In this header, I write all the prototype that I will use for student struct and the function related to it.
#ifndef STUDENT_H
#define STUDENT_H
struct student;
struct student *add (struct student *list);
void search(struct student*list);
struct student *remove_from_list(struct student *list);
void print_list(struct student*list);
void clear_list(struct student*list);
#endif
