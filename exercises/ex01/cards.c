/*
This is the cards.c file, which takes in card input and increments a 
count variable depending on which card face is passed through the 
kernel.

name: Anne Ku
No copyright
No license

How to run:

$ cd ~/ExercisesinC/exercises/ex01
$ gcc cards.c -o cards && ./cards 
*/

#include <stdio.h>
#include <stdlib.h>
int updateVal(char);
int incrementCount(int, int);
void printCount(int);

int main() {
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		int val = 0;

		val = updateVal(card_name[0]);

		if (val == 100) {
			break;
		}
		count = incrementCount(count, val);
		
		printCount(count);
	}
	return 0;
}

/* Takes in a card face value (from user input) and 
	returns the numerical value of the card.
*/
int updateVal(char cardFace){ //To pass in a pointer, int * var
	int val;
	char arr[] = "X";
	switch(cardFace) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			val = 100;
			break;
		default:
			arr[0] = cardFace;
			val = atoi(arr);
			if ((val < 1) || (val > 10)) {
				puts("I don't understand that value!");
				val = 0;
				break;
			}
		}
	return val;
}

 /* Takes in the card value and current card count and increments the
 	cardCount. 
 */
int incrementCount(int cardCount, int cardVal) {
	if ((cardVal > 2) && (cardVal < 7)) {
		cardCount++;
	} else if ((cardVal == 10) || (cardVal == 11)) {
		cardCount--;
	}
	return cardCount;
}

//prints current count
void printCount(int count){
	printf("current count: %i\n", count);
}