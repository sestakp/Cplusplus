
#include <iostream>

using namespace std;

struct node{
    string ISIN;
    double openPrice;
    double closePrice;
    struct node *lptr;
    struct node *rptr;
};

struct BTree{
    struct node *root;
};

int CalculateIncome(struct node *node){
    return node->closePrice - node->openPrice;
}


struct node* Insert(struct node *root, struct node *node){
    
    if(node == nullptr){
        printf("mistake\n");
    }

    if(root == nullptr){
        return node;
    }

    if(CalculateIncome(node) < CalculateIncome(root)){
        root->rptr = Insert(root->rptr, node);
    }
    else{
        root->lptr = Insert(root->lptr,node);
    }
    
    return root;
}

void InOrderPrint(struct node *root){
    
    if(root == nullptr){
        return;
    }

    InOrderPrint(root->lptr);
    
    cout << "ISIN: " << root->ISIN << 
    ", openPrice: " << root->openPrice << 
    ", closePrice: " << root->closePrice << 
    ", income: " << CalculateIncome(root) << endl;

    InOrderPrint(root->rptr);
    
    delete root->lptr;
    delete root->rptr;
}

int main(){

    struct node *tree = nullptr;

    char isin[12];
    float openPrice;
    float closePrice;

    while(scanf("%12s %f %f",isin,&openPrice,&closePrice) == 3){
        struct node *node = new struct node;
        node->ISIN = isin;
        node->openPrice = openPrice;
        node->closePrice = closePrice;

        tree = Insert(tree,node);
    }
    InOrderPrint(tree);

    return 0;
}