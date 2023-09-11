#ifndef DICT_H
#define DICT_H

#include <stdio.h>
#include <string.h>
  
#define MAX_SIZE                                           \
    100 // Maximum number of elements in the map
  
int len = 0; // Current number of elements in the map
char keys[MAX_SIZE][100]; // Array to store the keys
char values[MAX_SIZE][100]; // Array to store the values

// Function to get the index of a key in the keys array
int getIndex(char key[])
{
	int i;
    for (i = 0; i < len; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1; // Key not found
}
  
// Function to insert a key-value pair into the map
void insert(char key[], char *value)
{
    int index = getIndex(key);
    if (index == -1) { // Key not found
        strcpy(keys[len], key);
        strcpy(values[len], value);
        len++;
    }
    else { // Key found
        strcpy(values[index], value);
    }
}
  
// Function to get the value of a key in the map
char * get(char key[])
{
    int index = getIndex(key);
    if (index == -1) { // Key not found
        return NULL;
    }
    else { // Key found
        return values[index];
    }
}
  
// Function to print the map
void printMap()
{
	int i;
    for (i = 0; i < len; i++) {
        printf("%s: %d\n", keys[i], values[i]);
    }
}

#endif

