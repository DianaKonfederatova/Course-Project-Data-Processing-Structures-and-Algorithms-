#include <iostream>
#include "tree.h"
#include "list.h"

void add_AVL(const addresses& D, vertex*& p, bool& Rost){

    if(p == NULL){

        p = new vertex;
        p -> adr = D;
        p -> left = NULL;
        p -> right = NULL;
        p -> Bal = 0;
        Rost = true;

    }
    
    else if (compareStrings(p ->adr.name, D.name) > 0){
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
    else if (compareStrings(p ->adr.name, D.name) < 0){
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

    std::cout << "Bal: " << p->Bal << " | ";
    transcodingCP866_for_UTF8(p->adr.name, 32);
    std::cout << "\n";

    print_tree(p->right);
}
