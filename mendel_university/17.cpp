#include <iostream>
#include "17.hpp"

unsigned char* UInit(){
    static unsigned char arr[MAXLEN];
    return arr;
}


int ULength(unsigned char* arr){

    int length = 0;
    unsigned char byte;
    for(int i = 0; i < MAXLEN; i++){
        byte = arr[i];
        
        if(byte == 0){
            break;
        }
        
        if((byte & 0x80) == 0x80){
            if((i+1) < MAXLEN){
                if((arr[i+1] & 0x80) == 0x80){
                    length++;
                    i++;
                }
            }
        }
        else{
            length++;
        }
    }

    return length;
}

void UDelete(unsigned char *arr, int N, int K){
    int length = ULength(arr);
    
    if((K+N-1) > length){
        return;
    }

    int offset = 0;

    for(int i = (K+N)-1; i < (length+offset+N); i++){
        arr[i-N] = arr[i];
        arr[i] = 0;

        if((arr[i] & 0x80) == 0x80){
            if((i+1) < MAXLEN){
                if(arr[i+1] & 0x80 == 0x80){
                    offset++;
                }
            }
        }
    }
}


int main(){
    unsigned char *array = UInit();
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 129;
    array[5] = 129;
    array[6] = 0;

    int len = ULength(array);
    if(len != 5){
        printf("mistake, length is %d\n",len);
    }

    UDelete(array,2,4);
    len = ULength(array);
    if(len != 3){
        printf("mistake2, length is %d\n",len);
    }
    return 0;
}