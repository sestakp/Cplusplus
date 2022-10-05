#include <iostream>

struct ListItem{
    double data;
    struct ListItem *next;
};

#define HASHTABLESIZE 128

ListItem* hashTable[HASHTABLESIZE];

int Length( ListItem *root){
    int length = 0;

    while(root != nullptr){
        length++;
        root = root->next;
    }

    return length;
}

void PrintSynonymsCount(ListItem *hashTable[]){

    for(int i = 0; i < HASHTABLESIZE; i++){
        
        int count = Length(hashTable[i]);

        if(count != 0){
            std::cout << "index: " << i << ", synonyms: " << count << std::endl;
        }
    }
}

int main(){
    return 0;
}