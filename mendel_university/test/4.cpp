#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int shift = 4;

    if(argc > 1){
        shift = atoi(argv[1]);
    }

    char c;
    while((c = getchar()) != EOF){
        
        if(c < 'A' || c > 'Z'){
            //Not a letter
            std::cout << c;
            continue;
        }

        c = c+shift;
        if(c > 'Z'){
            c -= 'A';
        }        

        std::cout << c;
    }

    return 0;
}