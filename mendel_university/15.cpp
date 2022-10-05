#include <iostream>


int CountSetBits(char byte){
    int count = 0;

    for(int i = 0; i < 8; i++){
        if(byte & 1 == 1){
            count++;
        }
        byte >>= 1;
    }

    return count;
}


char ParityAndCheckSum(char byteArray[], int size){
    
    char checkSum;
    char byte;
    for(int i = 0; i < size; i++){
        byte = byteArray[i];
        
        if(byte & 0x80 == 1){
            std::cerr << "Value must be in interval 0..127";
            return 0xff;
        }

        if((CountSetBits(byte) % 2) == 1){
            byte |= 0x80;
        }

        if(i > 0){
            checkSum ^= byte;
        }
        else{
            checkSum = byte;
        }

    }

    return checkSum;
}

int main(){

    char arr[3] = {0x1f, 0x1f, 0x0f};

    char checkSum = ParityAndCheckSum(arr,3);

    if(checkSum == 0x0F){
        printf("Correct\n");
    }

    return 0;
}