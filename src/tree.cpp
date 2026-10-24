#include <iostream>
#include "tree.h"
#include "list.h"

int apartment_comparison(short int apart1, short int apart2){
    if(apart1 < apart2){
        return -1;
    }else if (apart1 > apart2)
    {
        return 1;
    }else{
        return 0;
    }
    
}

void add_AVL(const addresses& D, vertex*& p, bool& Rost){

    if(p == NULL){

        p = new vertex;
        p -> adr = D;
        p -> left = NULL;
        p -> right = NULL;
        p -> Bal = 0;
        Rost = true;

    }
    
    else if (apartment_comparison(p ->adr.apartment, D.apartment) > 0){
        add_AVL(D, p -> left, Rost);

            if(Rost == true){

                if(p -> Bal > 0){
                    p -> Bal = 0;
                    Rost = false;
                }
                else if (p -> Bal == 0){
                    p -> Bal = -1;
                    Rost = true;
                }
                else{

                    if(p -> left -> Bal < 0){
                        vertex* q = p -> left;
                        p -> Bal = 0;
                        q -> Bal = 0;
                        p -> left = q -> right;
                        q -> right = p;
                        p = q;
                        Rost = false;
                    }
                    else{
                        vertex* q = p -> left;
                        vertex* r = q -> right;
                        
                        if(r -> Bal < 0){
                            
                            p -> Bal = 1;

                        }else{
                             p -> Bal = 0;
                        }

                        if(r -> Bal > 0){

                            q -> Bal = -1;

                        }else{
                            q -> Bal = 0;
                        }

                        r -> Bal = 0;
                        q -> right = r -> left;
                        p -> left = r -> right;
                        r -> left = q;
                        r -> right = p;
                        p = r;

                        Rost = false;
                    }
                }
            }
    }
    else if (apartment_comparison(p ->adr.apartment, D.apartment) <= 0){
        add_AVL(D, p -> right, Rost);

        if(Rost == true){

            if(p -> Bal < 0){

                p -> Bal = 0;
                Rost = false;

            }else if (p -> Bal == 0){

                p -> Bal = 1;
                Rost = true;

            }else{

                if(p -> right -> Bal > 0){

                    vertex* g = p -> right;
                    p -> Bal = 0;
                    g -> Bal = 0;
                    p -> right = g -> left;
                    g -> left = p;
                    p = g;

                    Rost = false;

                }else{

                    vertex* q = p -> right;
                    vertex* r = q -> left;

                    if(r -> Bal < 0){
                        p -> Bal = 1;
                    }else{
                        p -> Bal = 0;
                    }

                    if(r -> Bal > 0){
                        q -> Bal = -1;
                    }else{
                        q -> Bal = 0;
                    }

                    r -> Bal = 0;
                    q -> left = r -> right;
                    p -> right = r -> left;
                    r -> right = q;
                    r -> left = p;
                    p = r;

                    Rost = false;
                }
            } 
        }
    } 
}

void print_tree(vertex* p){

   if (p == nullptr){
        return;
    }
    print_tree(p->left);
    std::cout << "Bal: " << p->Bal << " | Apt: " << p->adr.apartment << " | ";
    transcodingCP866_for_UTF8(p->adr.name, 32);
    std::cout << "\n";
    print_tree(p->right);

}

void tree_search(vertex* p, short search_apartment){

   if (p == nullptr){
        return;
    }
    
    tree_search(p->left, search_apartment);
    
    if (p->adr.apartment == search_apartment){
        transcodingCP866_for_UTF8(p->adr.name, 32);
        std::cout << "\t";
        transcodingCP866_for_UTF8(p->adr.street, 18);
        std::cout << "\t";
        std::cout << p->adr.number_house << "\t";
        std::cout << p->adr.apartment << "\t";
        transcodingCP866_for_UTF8(p->adr.date_of_settlement, 10);
        std::cout << "\n";
    }
    
    tree_search(p->right, search_apartment);
}

void clear_tree(vertex* p){
    if (p == nullptr){
        return;
    }
    clear_tree(p->left);
    clear_tree(p->right);
    delete p;
}