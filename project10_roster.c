#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h" // Link 2 headers that I will use.
#include "readline.h"
//Khoa Le U11734250. This project is about create a program to add, search for student information that already been input.
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
    ", r for removing from the list, p for printing the list; q for quit.\n");

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
            case 'r': student_list=remove_from_list(student_list);
                break;
            case 'q': clear_list(student_list);
                return 0;
            default:  printf("Illegal code\n"); //Error case
        }
        printf("\n");
    }
}