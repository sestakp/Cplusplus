#include <list>


#define MAX 65565

typedef int Mnozina; 

typedef struct {
    bool M[MAX];
    Mnozina Max;
}M;

int Zacni(M *M, Mnozina K);

int Sjednot(M *A, M *B, M *C);

int Vypis(M *M);