#include <iostream>
//#include <cstdio>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int shift = 4;
    char *env;
    if(argc > 1){
        shift = atoi(argv[1]);
    }
    else if((env = getenv("POSUV")) != NULL){
        shift = atoi(env);    
    }

    char c;
    while((c = getchar()) != '\n'){
        //small letters to upper
        if(c >= 97 && c <= 122){
            c -= 32;
        }
        else if(c <= 65 || c >= 90){
            //Not a letter
            std::cout << c;
            continue;
        }

        c = c+shift;
        if(c > 90){
            c -= 65;
        }        

        std::cout << c;
    }

    return 0;
}