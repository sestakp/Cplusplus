#include <iostream>
//#include <cstdio>
#include <stdlib.h>

int calculateUtf8CharsFromStdIn(){
    int acc = 0;
    char c;
    int size;
    while((c = getchar()) != '\n'){
        
        if((c & 0b11110000) != 0){
            size = 4;
        }
        else if((c & 0b11100000) != 0){
            size = 3;
        }
        else if((c & 0b11000000) != 0){
            size = 2;
        }
        else if((c & 0b1000000) != 0){
            size = 1;
        }
        
        bool correct = true;
        while(size > 0){
            if((c = getchar()) == '\n'){
                return acc;
            }

            if((c & 0b11000000) != 128) {
                correct = false;
                break;
            }               
        }

        if(correct){
            acc++;
        }
    }
    return acc;
}


int main(){
    return 0;
}