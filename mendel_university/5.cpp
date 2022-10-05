#include <stdio.h>
#include <stdlib.h>

struct Data{
    char* name;
    int numb;
    int salary;
};

short rel(void *A, void *B){
    Data a = *((Data*)A);
    Data b = *((Data*)B);

    if(a.salary < b.salary){
        return -1;
    }
    else if(a.salary > b.salary){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    TypSeznam S;

    Zacni(&S, rel);
    
    char* name;
    int numb;
    int salary;

    while(scanf("%s %d %d",name,&numb,&salary) == 3){
        Data d;
        d.name = name;
        d.numb = numb;
        d.salary = salary;

        Vloz(&S, (void*)&d);

        Data d;
    }
    
    Vypis(&S, Jak);   

    return 0;
}