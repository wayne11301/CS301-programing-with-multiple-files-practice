
#include <iostream>
#include "numberlist.h"

using namespace std;

const double NumberList::EPSILON = 0.000001;


// replace first occurrence of "before" with "after"
void NumberList::replaceOne(double before, double after) {
    for (ListNode* nodePtr = head;
        nodePtr != NULL;
        nodePtr = nodePtr->next) {
        if (nodePtr->value == before) {
            nodePtr->value = after;
            return;
        }
    }
    return;
}

/** destructor to free memory for all elements in list */
NumberList::~NumberList()
{
    ListNode * nodePtr, * nextNode;

    nodePtr = head;
    while (nodePtr != NULL) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

/** display list to console
    rewritten to show similarity to working with arrays */
void NumberList::displayList() const {
    for (ListNode *nodePtr = head;
         nodePtr != NULL;
         nodePtr = nodePtr->next)
        cout << nodePtr->value << endl;
}

void NumberList::insertNode(double num) {
    ListNode * node = new ListNode;
    node->next = head;
    node->value = num;
    head = node;
}

/** add to end of list */
void NumberList::appendNode(double num) {
    // cannot put num into list directly
    // must construct a node
    ListNode *newNode;

    // use this to go through list
    // serves same purpose as loop counter
    // for array processing
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode->value = num;
    // always have to initialize the pointer
    newNode->next = NULL;

    // usually best to handle special cases
    // first
    if (!head) // like (NULL == head)
        head = newNode;
    else {
        nodePtr = head;
        /** should make sure you understand why the condition
            checks nodePtr->next instead of nodePtr */
        while (nodePtr->next)   // same as (nodePtr->head != NULL)
            nodePtr = nodePtr->next;

        // the actual appending
        nodePtr->next = newNode;
    }
}

// delete a value from the list
void NumberList::deleteNode(double num) {
    ListNode * nodePtr;
    ListNode * previousNode;

    // handle special case first
    if (head->value == num) {
        // save pointer to 2nd element
        nodePtr = head->next;
        // free first element's memory
        delete head;
        head = nodePtr;
    }
    else {
        nodePtr = head;
        previousNode = head;
        while (nodePtr != NULL && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        /** if nodePtr is not at the end of the list,
           (What would that mean?)
           link the previous node to the node after nodePtr,
           then delete nodePtr
           */
        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
