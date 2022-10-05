#include <list>


#define MAX 65565

typedef unsigned long long Multiset; 

typedef struct {
    std::list<Multiset> M;
    Multiset Max;
}M;

int Start(M *M, Multiset K);

int Vloz(M *M, Multiset C);

int Vypis(M *M);