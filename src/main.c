#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

// Structure to represent a user
struct User {
    char name[50];
    int age;
};

// Array to store all users
struct User users[MAX_USERS];
int numUsers = 0;

// Adds a user to the database
void addUser(char *name, int age) {
    if (numUsers >= MAX_USERS) {
        printf("Error: Database is full\n");
        return;
    }
    
    struct User newUser;
    strcpy(newUser.name, name);
    newUser.age = age;
    
    users[numUsers] = newUser;
    numUsers++;
}

// Searches for a user by name and returns their index, or -1 if not found
int findUser(char *name) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    
    return -1;
}

// Removes a user from the database by name
void removeUser(char *name) {
    int index = findUser(name);
    
    if (index == -1) {
        printf("Error: User not found\n");
        return;
    }
    
    // Shift all users after the removed user back by one position
    for (int i = index + 1; i < numUsers; i++) {
        users[i - 1] = users[i];
    }
    
    numUsers--;
}

// Prints all users in the database
void printUsers() {
    if (numUsers == 0) {
        printf("Database is empty\n");
        return;
    }
    
    for (int i = 0; i < numUsers; i++) {
        printf("%s (%d)\n", users[i].name, users[i].age);
    }
}
int main() {
    // Add some example users
    addUser("Alice", 25);
    addUser("Bob", 30);
    
    // Print all users in the database
    printf("All users:\n");
    printUsers();
    
    // Remove Bob from the database
    removeUser("Bob");
    
    // Print all users again
    printf("\nAfter removing Bob:\n");
    printUsers();
    
    return 0;
}