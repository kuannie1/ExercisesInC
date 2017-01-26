#include <stdio.h>
#include <stdlib.h>
int main()
{
	char card_name[3];
	int count = 0;
	int val = 0;
	while (card_name[0] != 'x') {
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		val = calcCardVal(card_name);
		// switch(card_name[0]) {
		// 	case 'K':
		// 	case 'Q':
		// 	case 'J':
		// 		val = 10;
		// 		break;
		// 	case 'A':
		// 		val = 11;
		// 		break;
		// 	case 'x':
		// 		continue;
		// 	default:
		// 		val = atoi(card_name);
		// 		if ((val < 1) || (val > 10)) {
		// 			puts("I don't understand that value!");
		// 			continue;
		// 		}
		// }
		count = incrementCount(count, val);
		printf("Current count: %i\n", count);
	}
	return 0;
}

// 3 functions: 
//one for determining value, 
//one for incrementing count --> Done!
//one TBD

 // Determines the card's point value by its string input
int calcCardVal(cardFace) {
	int cardVal = 0;
	switch(cardFace) {
		case 'K':
		case 'Q':
		case 'J':
			cardVal = 10;
			break;
		case 'A':
			cardVal = 11;
			break;
		case 'x':
			break;
		default:
			cardVal = cardFace - '0';
			if ((cardVal < 1) || (cardVal > 10)) {
				puts("I don't understand that value!");
				break;
			} else {
				break;
			}
	}
	return cardVal;
}

 // Increments count based on the card value:
int incrementCount(cardCount, cardVal) {
	if ((cardVal > 2) && (cardVal < 7)) {
		cardCount++;
	} else if (cardVal == 10) {
		cardCount--;
	}
	return cardCount;
}