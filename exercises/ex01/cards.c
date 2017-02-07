#include <stdio.h>
#include <stdlib.h>

int main() {
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		int val = 0;
		
		val = updateVal(card_name[0]);
		
		count = incrementCount(count, val);
		
		printCount();
	}
	return 0;
}

int updateVal(char cardFace){ //To pass in a pointer, int * var
	int val;
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
			continue;
		default:
			val = atoi(cardFace);
			if ((val < 1) || (val > 10)) {
				puts("I don't understand that value!");
				continue;
			}
		}
	return val;
}


 // Increments count based on the card value:
int incrementCount(int cardCount, int cardVal) {
	if ((cardVal > 2) && (cardVal < 7)) {
		cardCount++;
	} else if ((cardVal == 10) || (cardVal == 11)) {
		cardCount--;
	}
	return cardCount;
}

//prints current count:
void printCount(int count){
	printf("current count: %i\n", count);
}