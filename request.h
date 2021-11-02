/* 
Author: Randall Hunt 
Program: request.h
Desprition: This program is a modification of summer_camp.c

*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef READLINE_H 
#define READLINE_H
#define EMAIL_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30
#endif
//declare the variables. 
struct request{
    char first[NAME_LEN+1];
    char last[NAME_LEN+1];
    char email[EMAIL_LEN+1];
    int age;
    char status[STATUS_LEN+1];
    struct request *next;
};



//function to add a request to the list
struct request* append_to_list(struct request *list);

//function to update the status of a request
void update(struct request *list);

//function to print the list
void print_list(struct request *list);

//function to deallocate the memory allocated to store the list
void clear_list(struct request *list);

