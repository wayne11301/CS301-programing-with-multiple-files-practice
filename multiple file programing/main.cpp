#include <iostream>
#include "numberlist.h"

using namespace std;

int main()
{
    NumberList list;
    list.appendNode(2.5);
    list.appendNode(7.9);
    cout << "Displaying list first time: " << endl;
    list.displayList();
    // should not have any effect
    list.deleteNode(8.4);
    list.deleteNode(7.9);
    cout << "Displaying list second time: " << endl;
    list.displayList();
    list.deleteNode(2.5);
    cout << "Displaying list third time: " << endl;
    list.displayList();
    list.insertNode(3.8);
    list.insertNode(4.8);
    cout << "Displaying list to check insertNode -- should get 4.8, then 3.8: " << endl;
    list.displayList();
    // adding on to existing code
    list.insertNode(4.8);
    list.replaceOne(4.8, 0.1);
    list.replaceOne(3.7, 1.0);
    cout << "Displaying list to check replaceOne -- should get 0.1, 4.8, then 3.8: " << endl;
    list.displayList();
    system("pause");
    return 0;
}
