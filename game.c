#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int size = 3;
char words[][200] = {"tree", "house", "car"};

void printHangman(int errornum);
void printBlanks(int len);
void play(int guesses, char *word);
char * getWord();

int main()
{
    printf("Welcome to hangman:\n");
    char *word = getWord();

	printf("The word that I choose have %d characters. You may start guessing the characters.\n", strlen(word));
	printf("You can guess the alphabets in the word one by one or you may guess the whole word.\n\n", strlen(word));
	
	int maxguesses = 5;
	play(maxguesses, word);
    return 0;
}

void printBlanks(int len)
{
	int i;
	printf("You have %d characters to fill: \n", len);
	for (i = 0; i < len; i++)
	{
		printf("_");
	}
	printf("\n");
}

void printHangman(int errornum)
{
	switch (errornum)
	{
		case 1:
			printf("|\\___\n\n");
			break;
		case 2:
	        printf("|\\___\n");
	        printf("|   O\n");
	        printf("|   |\n\n");
			break;
		case 3:
			printf("|\\___\n");
        	printf("|   O\n");
        	printf("|  /|\\\n\n");
			break;
		case 4:
	        printf("|\\___\n");
	        printf("|   O\n");
	        printf("|  /|\\\n");
	        printf("|  / \\\n");
			break;
		case 5:
			printf("|\\___\n");
			printf("|   |\n");
	        printf("|   O\n");
	        printf("|  /|\\\n");
	        printf("|  / \\\n");
			printf("|\n");
			printf("=========\n\n");
			break;
		default: 
        	printf("Error: wrong case %d\n\n", strerror(errno));
	}
}

char * getWord()
{
	srand(time(NULL));
    int index = rand()%size;
    char *word = words[index];
	return word;
}

void play (int guesses, char *word)
{	              
 
    char guess[250]; 
	int value;
	int cntr = 0;
	while (cntr < guesses)
	{	
		printBlanks(strlen(word));
		scanf("%s", guess);
		value = strcmp(guess, word);
		if (value != 0) 
		{ 
			cntr++;
			printHangman(cntr);
			if (cntr == guesses) 
			{ 
				printf("You lose!");
				return;
			}
			printf("Wrong, you have %d guesses left\n\n", guesses - cntr);
		}
		else 
		{
			printf("You're right, you won!");
		}
	}
}
