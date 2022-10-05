#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <list>

using namespace std;

struct BookRecord{
    string bookNameAndAuthor;
    char EAN[13];
};


bool compare_ean(struct BookRecord r1, struct BookRecord r2){
    
    for(int i = 0; i < 13; i++){
        if(r1.EAN[i] > r2.EAN[i]){
            return true;
        }
        else if(r1.EAN[i] < r2.EAN[i]){
            return false;
        }
    }
    return true;
}


int main(int argc, char *argv[]){

    if(argc < 2){
        cerr << "Missing argument";
        return 2;
    }

    char* filename = argv[1];
    
    fstream my_file;
	my_file.open(filename, ios::in);
	if (!my_file) {
		std::cerr << "No such file";
        return 2;
	}
	else {
        list<struct BookRecord> bookList;
        while(!my_file.eof()){
            struct BookRecord record; 
            getline(my_file, record.bookNameAndAuthor,'\0');
            my_file.read(record.EAN,13);
            bookList.push_back(record);
        }

        bookList.sort(compare_ean);

        for(std::list<BookRecord>::iterator it = bookList.begin(); it != bookList.end();it++){
            std::cout << it->EAN << " : " << it->bookNameAndAuthor << endl; 
        }
	}
	my_file.close();
 
    return 0;
}