#include <string.h>
#include <iostream>
#define HASHTABLESIZE 41 //prime number

struct item{
    char *item;
    int count;
    struct item *next;
};

item *hashTable[HASHTABLESIZE];

void Init(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        hashTable[i] = nullptr;
    }
}

unsigned int hash(char *item){
    unsigned int hash = 0;
    for(int i = 0; i < strlen(item); i++){
        hash += item[i];
    }
    hash %= HASHTABLESIZE;

    return hash;
}  

struct item* Search(char *str){
    int index = hash(str);

    struct item* item = hashTable[index];

    while(item != nullptr){
        if(strcmp(item->item, str) == 0){
            return item;
        }
    }

    return nullptr;
}

void Insert(char *str){

    struct item *item = Search(str);
    if(item != nullptr){
        item->count++;
        return;
    }
    else{
        item = (struct item *)malloc(sizeof(struct item));

        if(item == NULL){
            std::cerr << "Internal error\n";
            return;
        }

        item->item = str;
        item->count = 1;
        item->next = nullptr;

        int index = hash(str);
        struct item *iter = hashTable[index];

        if(iter == nullptr){
            hashTable[index] = item;
            return;
        }

        while(iter->next != nullptr){
            iter = iter->next;
         } 
         iter->next = item;

    }
}

int main(int argc, char *argv[]){

    char str[255];

    Init();
    
    while(scanf("%s", str) == 1){
        
        char *stri = (char*)malloc(strlen(str));
        if(stri == nullptr){
            std::cerr << "Intern error";
            return 1;
        }

        memcpy(stri,str,strlen(str));

        Insert(stri);
    }

    for(int i = 0; i < HASHTABLESIZE; i++){
        struct item *item = hashTable[i];
                
        
        while(item != nullptr){
            printf("Item: %s, Count: %d\n",item->item, item->count);
            item = item->next;
        }
    }


    return 0;
}