#include <iostream>
#include <string.h>

#define N 20
#define M 25

typedef enum{
    Horizontal,
    Vertical
} Direction;

typedef struct{
    char* text;
    Direction direction;
} Legend;

union Field{
    char letter;
    Legend legend;
    Legend legends[2];
    void *empty = nullptr;
};

Field Crossword[N][M];

bool CheckLegend(int x, int y, Direction direction){
    Legend legend = Crossword[x][y].legend;
    int length = strlen(legend.text);
    int xDiff = 0;
    int yDiff = 0;
    
    if(direction == Horizontal){
        xDiff = 1;
    }
    else{
        yDiff = -1;
    }

    for(int i = 0; i < length; i++){
        x += xDiff;
        y += yDiff;
        if(x < 0 || x > N || y < 0 || y > M){
            std::cerr << "Out of crossword";
            return false;
        }

        char c = Crossword[x][y].letter;
        if(c != legend.text[i]){
            return false;
        }
    }
    return true;
}


int main(){

    return 0;
}