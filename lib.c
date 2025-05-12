
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book{
    int id;
    char title[100];
    char author[100];
    struct Book* next;
};
struct Book* head=NULL;
int bookIdCounter=1;
void addBook(){
    struct Book* newBook=(struct Book*)malloc(sizeof(struct Book));
    newBook->id=bookIdCounter++;
    printf("Book title: ");
    scanf("%s",newBook->title);
    printf("Book author: ");
    scanf("%s",newBook->author);
    newBook->next=head;
    head=newBook;
    printf("*Book added successfully!*\n");
}
void displayBooks(){
    struct Book* current=head;
    if(current==NULL) {
        printf("*No books in the library.*\n");
    } 
	else{
        printf("*Books in the library:*\n");
        while(current != NULL) {
            printf("ID: %d, Title: %s, Author: %s\n",current->id,current->title,current->author);
            current=current->next;
        }
    }
}
void removeBook(int bookId){
    struct Book* current=head;
    struct Book* prev=NULL;
    if()
    while(current!=NULL){
        if(current->id==bookId){
            if(prev==NULL) {
                head=current->next;
            } 
			else{
                prev->next=current->next;
            }
            free(current);
            printf("*Book with ID %d removed successfully!*\n\n", bookId);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("*Book with ID %d not found in the library.*\n\n",bookId);
}
int welcomePage(){
    char answer[5];
    int i;
    for(i=0;i<14;i++)
    	printf("*  ");
    printf("\n\nWelcome to the Library Management System!\n\n");
    for(i=0;i<14;i++)
    	printf("*  ");
    printf("\n\nDo you want to manage your library? (yes/no): ");
    scanf("%s",answer);
    return (strcmp(answer,"yes")==0);
}
int main(){
    if(welcomePage()){
        int choice,bookId;
        while(1){
            printf("\nLibrary Management System Menu:\n");
            printf("1.Add a book\n");
            printf("2.Display all books\n");
            printf("3.Remove a book\n");
            printf("0.Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    addBook();
                    break;
                case 2:
                    displayBooks();
                    break;
                case 3:
                    printf("Enter the ID of the book to remove: ");
                    scanf("%d",&bookId);
                    removeBook(bookId);
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }
	else{
        printf("Thanks for visiting this library!\n");
    }
    return 0;
}