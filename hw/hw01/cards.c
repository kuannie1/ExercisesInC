#include <stdio.h>
#include <stdlib.h>

// Consider: making one helper function (in calcCardVal) for characters, and one for numbers?
int main()
{
	char card_name[3];
	int count = 0;
	int val;
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
int calcCardVal(char cardFace) {
	int cardVal;
	switch(cardFace) {
		case 'K':
		case 'Q':
		case 'J':
			cardVal = 10;
			break;
		case 'A':
			cardVal = 11;
			break;
		case '1':
			cardVal = 1;
			break;
		case '2':
			cardVal = 2;
			break;
		case '3':
			cardVal = 3;
			break;
		case '4':
			cardVal = 4;
			break;
		case '5':
			cardVal = 5;
			break;
		case '6':
			cardVal = 6;
			break;
		case '7':
			cardVal = 7;
			break;
		case '8':
			cardVal = 8;
			break;
		case '9':
			cardVal = 9;
			break;
		default:
			cardVal = 0;
			break;
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