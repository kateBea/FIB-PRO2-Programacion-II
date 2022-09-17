// X11338   MODIFICACIÓ D'UN BINTREE DE PARELLS

#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"

#if true
void sumak(BinTree<ParInt>& a, int k)
/*Pre: a = A */
/*Post: a es com a A amb k sumat al segon component de cada node */
{
    if (not a.empty())
    {
        BinTree<ParInt> left = a.left();
        BinTree<ParInt> right = a.right();
        sumak(left, k);
        sumak(right, k);
        ParInt val = ParInt(a.value().primer(), a.value().segon() + k);
        a = BinTree<ParInt> (val, left, right);
    }
}
#endif

/*read tree from std intput*/
void read_tree(BinTree<ParInt>& a)
{
    ParInt val;
    if (val.llegir())
    {
        BinTree<ParInt> left;
        BinTree<ParInt> right;
        read_tree(left);
        read_tree(right);
        a = BinTree<ParInt> (val, left, right);
    }
}

std::ostream& operator<<(std::ostream& _cout, const BinTree<ParInt>& A)
{
    A.value().escriure(); return _cout;
}

template <typename OBJ_TYPE>
void print_tree(const BinTree<OBJ_TYPE>& a)
{
    if (not a.empty())
    {
        std::cout << a.value();
        print_tree(a.left());
        print_tree(a.right());     
    }
}

#if false
int main(int, char**)
{
    BinTree<ParInt> myTree;
    read_tree(myTree);
    sumak(myTree, 4);
    print_tree(myTree); 

    return 0;
}
#endif

/*PUBLIC TEST*/
//1 1 2 2 5 0 0 0 0 0 4 3 7 1 0 0 0 0 6 -1 0 0 0 0 3 2 0 0 0 0

/*
a =  1 1
    /   \
   2 2   3 2
   /  \
 5 0  4 3
     / \
   7 1  6 -1
*/