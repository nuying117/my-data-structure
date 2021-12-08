#include "AvlTree.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int ac, char** av)
{
    using MyAvlTree = AvlTree<int>;

    MyAvlTree tree;
    //vector<int> myData = {5,6,7,4,32,2,9};
    vector<int> myData = {100, 50, 20, 110, 112, 109, 51, 56, 58, 40};

    for_each(myData.begin(), myData.end(), [&tree](const int& n){
        tree.add(n);
    });
    
    cout << "Inner order: ";
    tree.innerOrderTraverse([](const int& n){
        cout << n << ", ";
    });
    cout << endl;

    cout << "Pre order: ";
    tree.preOrderTraverse([](const int& n){
        cout << n << ", ";
    });
    cout << endl;

    cout << "Post order: ";
    tree.postOrderTraverse([](const int& n){
        cout << n << ", ";
    });
    cout << endl;

    cout << "height: " << tree.height() << endl;
    cout << "left height: " << tree.leftHeight() << endl;
    cout << "right height: " << tree.rightHeight() << endl;

    return 0;
}