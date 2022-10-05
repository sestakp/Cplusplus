#include "1.hpp"
#include <iostream>

using namespace std;

int Start(M *M, Mnozina K){
    
    if(M == nullptr){
        cerr << "Uninitialized M" << endl;
        return 1;
    }

    if(K > MAX || K < 0){
        cerr << "Out of interval" << endl;
        return 1;
    }

    M->Max = K;
    return 0;
}

int Sjednot(M *A, M *B, M *C){
    if(A == nullptr || B == nullptr || C == nullptr){
        cerr << "Uninitialized Set" << endl;
        return 1;
    }

    C->Max = A->Max;
    if(B->Max > A->Max) {C->Max = B->Max; }

    for(int i = 0; i < A->Max; i++){
        C->M[i] = A->M[i]; 
    }

    for(int i = 0; i < B->Max; i++){
        C->M[i] |= B->M[i];
    }
    
    return 0;
}

int Vypis(M *M){
    
    if(M == nullptr){
        cerr << "Uninitialized M" << endl;
        return 1;
    }

    for(int i = 0; i < M->Max; i++){
        if(M->M[i]){
            std::cout << i << ", ";
        }
    }

    return 0;
}



int main(){

    return 0;
}