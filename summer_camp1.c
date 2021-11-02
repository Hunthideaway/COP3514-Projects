/* 
Author: Randall Hunt 
Program: summer_camp.c
Description: The program stores requests using a linked list. The program is used to manage the registration requests for the summer camp, which is for a pottery painting store. The stored values should contain the 
users first name, last name, email address, age and the status. 
*/ 
//includes and definitions. 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30
//declare the variables. 
struct request{
    char first[NAME_LEN+1];
    char last[NAME_LEN+1];
    char email[EMAIL_LEN+1];
    int age;
    char status[STATUS_LEN+1];
    struct request *next;
};
//declare the functions that will be used. 
struct request *append_to_list(struct request *list);
void update(struct request *list);
void print_list(struct request *list);
void clear_list(struct request *list);
int read_line(char str[], int n);
//main. 
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
int read_line(char str[], int n){
    int ch, i=0;
    while(isspace(ch = getchar()));
    str[i++] = ch;
    while((ch = getchar()) != '\n'){
        if(i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
