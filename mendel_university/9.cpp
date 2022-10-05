#include "9.hpp"
#include <iostream>

using namespace std;

int Start(M *M, Multiset K){
    
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

int Vloz(M *M, Multiset C){
    if(M == nullptr){
        cerr << "Uninitialized M" << endl;
        return 1;
    }

    if(C > M->Max || C < 0){
        std::cerr << "Out of valid interval" << endl;
        return 1;
    }

    M->M.push_back(C);

    return 0;
}

int Vypis(M *M){
    
    if(M == nullptr){
        cerr << "Uninitialized M" << endl;
        return 1;
    }

    for(std::list<Multiset>::iterator it = M->M.begin(); it != M->M.end(); it++){
        std::cout << *it << ", ";
    }

    return 0;
}



int main(){

    M m;
    Start(&m,500);
    Vloz(&m, 10);
    Vloz(&m, 10);
    Vloz(&m, 10);
    Vloz(&m, 501);
    Vloz(&m, -1);
    Vypis(&m);


    return 0;
}