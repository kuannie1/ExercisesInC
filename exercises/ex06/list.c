/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    Node *current = *list;

    if (current == NULL) {
        return -1;
    }

    int headVal = current -> val;

    **list = *(current->next);

    return headVal;
}


/* Adds a new element to the beginning of the list.
 * 
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    Node *newElement = make_node(val, *list);
    *list = newElement; //the list points to this new element node
}


/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    // FILL THIS IN!
    Node *current = *list;
    int count = 0;
    if (current->val == val) {
    	pop(list);
    	count = count + 1;
    }

    while (current->next != NULL) {
        if (current->next->val == val) {
            // Make a copy of the old node:
            Node *old = (current->next);

            //If next next node is NULL then
            if (current->next->next == NULL) {
            	current->next = NULL;
            	break;
            }
            //If not, then skip over the old one
            else {
            	printf("hello\n");
            	*(current->next) = *current->next->next;
            	break;
            }            
            //increment
            count = count + 1;
            //then free old node
            free(old);
        }
        current = current->next;
    }
    return count;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
	Node *current = *list;
	Node *newhead = make_node(pop(list), NULL);
	while (current->next != NULL) {
		//Make the first of the original list the head of the new list
		Node *newfirst = make_node(pop(list), newhead);
		//Then make the new head equal that newfirst for looping
		newhead = newfirst;
		//update the list:
		current = *list;
	}
	newhead = make_node(current->val, newhead);
	*list = newhead;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);
    head->next->next->next->next = make_node(5, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 2);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
