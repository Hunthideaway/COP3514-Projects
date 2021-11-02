/* 
Author: Randall Hunt 
Program: request.c
Description: this program is the continuation of summer_camp.c. 

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"

struct request* delete(struct request* list) {

char first[NAME_LEN+1];
char last[NAME_LEN+1];
char email[EMIAL_LEN+1];

printf("\n enter first name:\n");
scanf("%s",first);
printf("\n enter last name:\n");
scanf("%s",last);
printf("\n enter email address:\n");
scanf("%s",email);

struct request *p = list;
struct request *temp = list;

while(p != NULL) {
// check the data to be deleted
if((strcmp(list->first,first)==0) && (strcmp(list->last,last)==0) &&
(strcmp(list->email,email)==0)) {
break;
}
temp = p;
p = p->next;    
}
// if no data found return NULL
if(p==NULL) {
printf(" no data found to be deleted");
return p;
  }
temp->next = p->next;
// delete node
free(p);
//return the list head
return list;
}   
struct request* append(struct request* list) {
char first[NAME_LEN+1];
char last[NAME_LEN+1];
char email[EMIAL_LEN+1];

printf("\n enter first name:\n");
scanf("%s",first);
printf("\n enter last name:\n");
scanf("%s",last);
printf("\n enter email address:\n");
scanf("%s",email);

struct request * new_node = (struct request*)malloc(sizeof(struct request));

strcpy(new_node->first,first);
strcpy(new_node->last,last);
strcpy(new_node->email,email);
new_node->next = NULL;

struct request *p = list
struct request *temp = list;

while(p != NULL) {
// check the data if already present
if((strcmp(list->first,first)==0) && (strcmp(list->last,last)==0) &&
(strcmp(list->email,email)==0)) {
break;
}
temp = p;
p = p->next;    

  }

// if list is empty , make it as first node
if(list == NULL) {
list = new_node;
// return head of list
return list;

}

// data already exist 
if(temp!=NULL) {
printf(" request already existed in the waiting list");
return NULL;

}

// data is not present insert node at last of list
temp->next = new_node;
// return list head
return list;

}

void clearList(struct request* list) {
struct request * temp = list;
struct request * p = list;

while(p!=NULL) { 
temp = p;
p = p->next;
// delete previous node
free(temp);
}

}
        
//find if a request already exists in the list.
struct request *find(struct request *req, struct request *list) {
if(list == NULL){
return NULL;
}
struct request* curr = list;
while(curr != NULL) {
//compare the first name, last name and email address to the current list and request. 
if(strcmp(curr -> last, req -> last) ==0 && strcmp(curr -> first, req -> first) ==0 && strcmp(curr -> email, req -> email) ==0) {
return curr;
}
curr = curr -> next;
}
return NULL;
}

struct request *append_to_list(struct request *list) {
struct request *new_request = (struct request*)malloc(sizeof(struct request));
new_request -> next = NULL;

//ask the user for the last name. 
printf("\n");
printf("Enter Student's Last Name: ");
read_line(new_request -> last, NAME_LEN+1);
//ask the user for the first name. 
printf("Enter Student's First Name: ");
read_line(new_request -> first, NAME_LEN+1);
//ask the user for the email address.
printf("Enter Student's Email: ");
read_line(new_request -> email, EMAIL_LEN+1);

//make sure it doesn't already exist in the list. 
if(find(new_request, list) != NULL) {
printf("Request already exists.\n");
clear_list(new_request);
return list;
}

//age. 
printf("Enter Student's Age: ");
scanf("%d", &(new_request -> age));

//status of the student. 
strcpy(new_request -> status,"pending");

if(list == NULL) {
return new_request;
}

//add the given information to the bottom of the list.
struct request* current = list;
while(current -> next != NULL) {
current = current -> next;
}
current -> next = new_request;
return list;
}

void update(struct request *list) {
struct request *update_request = (struct request*)malloc(sizeof(struct request));
update_request -> next = NULL;
    
// ask for the last name of the student.
printf("Enter Student's Last Name: ");
read_line(update_request -> last, NAME_LEN+1);
// ask for the fisrt name of the student.   
printf("Enter Student's First Name: ");
read_line(update_request -> first, NAME_LEN+1);
//ask for the email of the student. 
printf("Enter Student's Email: ");
read_line(update_request -> email, EMAIL_LEN+1);
//ask for the new status of the student. 
printf("Enter new status: ");
read_line(update_request -> status, STATUS_LEN+1);
    
//find the student in the list or tell the student the request does not exist. 
struct request *request_found = find(update_request, list);
if(request_found == NULL) {
printf("Request does not exists.\n");
clear_list(update_request);
return ;
}

//student status. 
strcpy(request_found -> status, update_request -> status);
}
void print_list(struct request *list){
if(list == NULL) {
return ;
}

//output the information of the first student.
printf("---------------------------\n");
printf("Student Last Name: %s\n", list -> last);
printf("Student First Name: %s\n", list -> first);
printf("Student Email: %s\n", list -> email);
printf("Student Age: %d\n", list -> age);
printf("Request Status: %s\n\n", list -> status);

//repeat for the rest of the students. 
print_list(list -> next);
}
void clear_list(struct request *list) { 
if(list == NULL) {
return;
}
//clear the list. 
clear_list(list -> next);
//clear the memory. 
free(list);
}