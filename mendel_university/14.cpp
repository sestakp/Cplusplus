#include "14.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void Init(struct List *l){
    l = new List;
    l->head = nullptr;
}


void Add(struct List *l, void *data, int position){

    struct Element *elemToInsert = new Element;
    
    elemToInsert->data = data;

    struct Element *elem = l->head;

    if(elem == nullptr){
        elem = elemToInsert;
        return;
    }

    for (int i = 0; i < position; i++){
        if(elem->next == nullptr){
            break;
        }
        elem = elem->next;
    }

    elemToInsert->next = elem->next;
    elem->next = elemToInsert;
}

void Save(struct List *l, char* filename){
    fstream my_file;
	my_file.open(filename, ios::in);
	if (!my_file) {
		cerr << "No such file";
        return;
	}
	else {
        struct Element *elem = l->head;

        while(elem != nullptr){
            my_file << TransformDataToString(elem->data) << endl;
        }
	}
	my_file.close();   
}

int main(){
    return 0;
}