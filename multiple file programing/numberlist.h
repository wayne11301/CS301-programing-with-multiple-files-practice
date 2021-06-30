// a basic linked list class from Gaddis, ch. 17.2
#ifndef NUMBERLIST_H
#define NUMBERLIST_H
// replacing NULL by nullptr -- if you are using Code::Blocks,
// remember to set the build option that you are using C++11 or later

class NumberList
{
    private:
        // adding this for double comparison
        static const double EPSILON;

        struct ListNode {
            double value;
            ListNode *next;
        };
        ListNode * head; //!< points to start of list

    public:
        /** Default constructor */
        NumberList() {
            head = nullptr;
        }
        /** Default destructor */
        ~NumberList();

        // standard list operations
        // add to end of list
        void appendNode(double);
        // inserts in order
        void insertNode(double);
        void deleteNode(double);
        // replace first occurrence of "before" with "after"
        void replaceOne(double before, double after);
        // get sum of all values
        int sum() const;

        void displayList() const;
};

#endif // NUMBERLIST_H
