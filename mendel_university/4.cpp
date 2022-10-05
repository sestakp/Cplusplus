#include <string.h>

enum Color{
    White,
    Black
};

enum ChessPiece{
    King, //kral
    Queen, //kralovna
    Rook, //vez
    Bishop, //strelec
    Knight, // Kun
    Pawn //pesec
};


//can be saved in file, it has constant size.
typedef struct {
    Color color;
    ChessPiece chessPiece;
    char position[2];
} ChessMan;



 ChessMan game[32]; //16pieces each color


void GetPosition(char position[2], int ResultFunc(ChessMan*)){
    
    for(int i = 0; i < 32; i++){
        if(strcmp(game[i].position,position) == 0){
            ResultFunc(&(game[i]));
            return;
        }
    }

    ResultFunc(nullptr);
}

int main()
{
    return 0;
}