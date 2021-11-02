/* 
Author: Randall Hunt 
Program: Request.c 
Description: This is the main function of the program summer_camp.c that is modified. 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"

int main(void){
    char code;

    struct request *request_list = NULL;
    printf("Operation Code: a for appending to the list, u for updating a request"
        ", p for printing the list; q for quit.\n");
    for(;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n');
        switch (code)
        {
        case 'a':
            request_list = append_to_list(request_list);
            break;
        case 'u':
            update(request_list);
            break;
        case 'p':
            print_list(request_list);
            break;
        case 'q':
            clear_list(request_list);
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}