#include <stdio.h>
#include <stdlib.h>


union floatUnion{
    float fval;
    unsigned char bval[4];
};

int main(){

    floatUnion numb;
    while(scanf("%f",&numb.fval) == 1){
        float number = numb.fval;

        numb.bval[3] <<= 1;
        numb.bval[2] >>= 7;
        numb.bval[3] = numb.bval[3] | numb.bval[2];

        int count = 0;
        while(numb.bval[3]){
            count += numb.bval[3] & 1;
            numb.bval[3] >>= 1;
        } 

        if(count >= 6){
            printf("%f\n",number);
        }

    }
    return 0;
}