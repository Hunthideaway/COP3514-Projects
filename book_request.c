/*
Author: Randall Hunt 
Program: book_request.c
Description: This program is used to keep track of the books rented out by the teachers by tracking the title, authors name, price of it, and classroom that has it. 
Date: 11/10/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20
struct book{
	char title[TITLE_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char classroom[ROOM_LEN+1];
	double price;
	struct book *next;
};


struct book *add_to_end(struct book *list);
void search(struct book *list);
void print_list(struct book *list);
void clear_list(struct book *list);
int read_line(char str[], int n);
int found(struct book *list,char *title, char *first, char *last, char *class);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void) //main function provided by the professor. 
{
  char code;

  struct book *book_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': book_list = add_to_end(book_list);
                break;
      case 's': search(book_list);
                break;
      case 'p': print_list(book_list);
                break;
      case 'q': clear_list(book_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}


struct book *add_to_end(struct book *list){ //adding new entry to the end of the list
    char title[TITLE_LEN+1]; //variable to store the title 
    char first[NAME_LEN+1]; //variable to store the first name 
    char last[NAME_LEN+1]; //variable to store the last name 

    printf("Enter the title: "); //ask the user to enter the information
    read_line(title, TITLE_LEN + 1); //store the title 
    printf("Enter the Authors first name: ");
    read_line(first, NAME_LEN + 1); //store the first name
    printf("Enter the Authors last name: ");
    read_line(last, NAME_LEN + 1); //store the last name
    char class[ROOM_LEN+1]; //array to store the class that rented the books 
    printf("Enter the classroom: "); //ask the user to select grade level
    read_line(class, ROOM_LEN+1); //store the entered value 

    if(!found(list, title, first, last, class)){ //if the information has not already been entered 
        double pr =0; //variable for the price 
        printf("Enter the price: $"); //ask the user to enter the price 
        scanf("%lf",&pr); //store the price 
        struct book *node = (struct book *)malloc(sizeof(struct book)); //allocate memory for the new node 
        strcpy(node->title, title); //copy the title to the element of the node 
        strcpy(node->first, first); //copy the first name to the element of the node 
        strcpy(node->last, last); //copy the last name to the element of the node 
        node->price =pr; //set node price to price entered by user 
        node->next=NULL; //the node itll point to is NULL since it is added at the end 
        strcpy(node->classroom, class); //copy the class to classroom within the node
        
        struct book *new_node = list; //new node set to the list 
        if(list ==NULL) { //as long as the list is not empty 
            list = node; //list will be set to the node 
        }
        else{
            while(new_node->next !=NULL){ //traverse until we reach then end 
                new_node = new_node->next; //the new_node is set to the next value
            }
            new_node->next = node; //the new nodes next value is the node entered by the user 
        }

    }
    return list; //return the list 

}
int found(struct book *list, char *title, char *first, char *last, char *class ){ //use to check if the elements have been entered previously 
  struct book *new_list = list; //new list set to list.

    if (list != NULL)
    { //if the list is not empty
        while (new_list != NULL)
        { //traverse through all elements within the list
            if (strcmp(new_list->title, title) == 0 && strcmp(new_list->first, first) == 0 && strcmp(new_list->last, last) == 0)
            {                                                 //compare the user input to the list elements
                printf("You already have rented this book."); //inform the user has already taken this book.
                return 1;                                     //return true
            }
            new_list = new_list->next; //check the next node to see if the book exists
        }
    }
    return 0;
}


void search(struct book *list) //search for a specific title. 
{
char title[TITLE_LEN+1]; //variable to store the title that will be searched for 
printf("Enter the book title: "); //ask the user for the title 
read_line(title, TITLE_LEN+1); //read the input 

struct book *new_list= list; //creating a new node 
 if (list != NULL) 
    { //if the list is not empty
        while (new_list != NULL)
        { //traverse through all elements within the list
            if (strcmp(new_list->title, title) == 0)
            {                                                 //compare the user input to the list elements
                printf("Title: %s\n", new_list->title); //printf the title 
                printf("Name: %s %s\n", new_list->first, new_list->last); //print the authors name 
                printf("Price: $%.2lf\n", new_list->price); //print the price 
                printf("Classroom: %s\n", new_list->classroom); //print the classroom that has them 
                
            }
            new_list = new_list->next; //check the next node to see if the book exists
        }
        if(new_list == NULL) //if you are at the end and have not found the book 
        printf("Book Not Found."); //inform the user
        
    }

}


void print_list(struct book *list){ //print the list 

    struct book *new_list = list; //set the node to the list 
    while (new_list != NULL) //while the list has not reach the NULL pointer 
    {
        printf("Title: %s\n", new_list->title); //print the title of the book
        printf("Author: %s %s\n", new_list->first, new_list->last); //print the name of the author 
        printf("Price: %.2lf\n", new_list->price); //print the price of the book 
        printf("Classroom: %s\n", new_list->classroom); //print the classroom that has them
        new_list = new_list->next; //traverse to the next node 
        printf("\n"); //print a new line to seperate the node elements
    }

}
void clear_list(struct book *list) //deallocate the list when exiting 
{
    struct book *tmp; //temp node 
    while (list != NULL) //while you have not reached the NULL pointer 
    {
        tmp = list; //set the temp to the first node 
        list = list->next; //traverse to the next node 
        if(tmp!=NULL) //if the node is not empty 
        free(tmp); //free the memory. 
    }
    

}

int read_line(char str[], int n) //read line given by the professor. 
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
