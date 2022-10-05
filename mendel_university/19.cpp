#include <iostream>
#include <fstream>

using namespace std;

struct ListItem{
    float data;
    struct ListItem *lptr;
    struct ListItem *rptr;
};

void Insert(struct ListItem** first, struct ListItem* newNode)
{
    struct ListItem* current;
 
    if (*first == NULL)
        *first = newNode;
 
    else if ((*first)->data >= newNode->data) {
        newNode->rptr = *first;
        newNode->rptr->lptr = newNode;
        *first = newNode;
    }
 
    else {
        current = *first;
 
        while (current->rptr != NULL &&
               current->rptr->data < newNode->data)
            current = current->rptr;
 
        newNode->rptr = current->rptr;
 
        if (current->rptr != NULL)
            newNode->rptr->lptr = newNode;
 
        current->rptr = newNode;
        newNode->lptr = current;
    }
}

void printListToStdin(struct ListItem* first)
{
    while (first != NULL) {
        cout << first->data << ", ";
        first = first->rptr;
    }
}

int printListToFile(struct ListItem* first, char* filename){
    ofstream my_file;
	my_file.open(filename, ios::binary);
	if (!my_file) {
		cerr << "No such file";
        return 1;
	}
	else {
        while (first != NULL) {
            my_file << first->data << ", ";
            first = first->rptr;
        }           
        
	}
	my_file.close();
    return 0;
}

int main(int argc, char *argv[]){

    struct ListItem *first = NULL;

    float numb;
    while(scanf("%f",&numb) == 1){
        struct ListItem *item = new struct ListItem;
        item->data = numb;
        Insert(&first,item);
    }

    struct ListItem *item = first;

    if(argc < 2){
        printListToStdin(first);
    }
    else{
       return printListToFile(first,argv[1]);
    }
    return 0;
}