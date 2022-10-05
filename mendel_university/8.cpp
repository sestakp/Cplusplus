#include <stdio.h>
struct node{
    int data;
    struct node *next;
};

void mySwap (struct node *node_1, struct node *node_2)
{
	int temp = node_1->data;
	node_1->data = node_2 -> data;
	node_2 -> data = temp;
}

void BubbleSort(struct node *head)
{
	int swapped;

	struct node *lPtr; // left pointer will always point to the start of the list
	struct node *rPrt = NULL; // right pointer will always point to the end of the list
	do
	{	
		swapped = 0;
		lPtr = head;
		while(lPtr->next != rPrt)
		{
			if (lPtr->data < lPtr->next->data) 
			{
				mySwap(lPtr, lPtr->next); 
                swapped = 1; 
			}
			lPtr = lPtr->next;
		}
		//as the largest element is at the end of the list, assign that to rPtr as there is no need to
		//check already sorted list
		rPrt = lPtr;

	}while(swapped);
}

void printList(struct node* root){
    while(root != NULL){
        printf("%d\n",root->data);
        root = root->next;
    }   
}

int main(){
    
    struct node root;
    root.data = 1;

    struct node p1;
    p1.data = 2;

    struct node p2;
    p2.data = 3;

    root.next = &p1;
    p1.next = &p2;
    p2.next = NULL;
    
    BubbleSort(&root);
    printList(&root);
    return 0;
}