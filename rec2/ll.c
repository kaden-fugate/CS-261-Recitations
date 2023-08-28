#include <stdlib.h>

#include "ll.h"

// struct node
// {
// 	int val;
// 	struct node *next;
// };

struct node* add_two_num (struct node* l1, struct node* l2)
{
        
	int sum = 0;
    struct node *temp1 = l1, *temp2 = l2, *l3 = NULL, **node = &l3;

    while( temp1 || temp2 || sum > 0 ){ // iterate through list

        if(temp1) // if node exists, add it to total
        {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if(temp2)
        {
            sum += temp2->val;
            temp2 = temp2->next;
        }

        (*node) = malloc( sizeof( struct node ) );
        (*node)->val = sum % 10; // assigns node val with nums from first digit
        sum /= 10; // sum starts at whatever the remainder from prev digit was
        node = &((*node)->next);

    }

    *node = NULL; // if you forget to set null, everything breaks
	        
    return l3;
    
}


