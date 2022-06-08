#include <stdio.h>
#include <string.h>

int main(){
    /*char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Name: %s\n", name);*/
    /*char fname[20], lname[20];
    printf("Enter your name: ");
    scanf("%s %s", fname, lname);
    printf("Fistname: %s\nLastname: %s\n", fname, lname);*/
    char text[200];
    printf("Enter text: ");
    fgets(text, 200, stdin);
    text[strlen(text) - 1] = '\0';
    printf("Text: %s\n", text);
    return 0;
}