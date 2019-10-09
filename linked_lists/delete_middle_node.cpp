/*
 * Implement an algorithm to delete a node in the middle (i.e., any node but
 * the first and last node, not necessarily the exact middle) of a singly 
 * linked list, given only access to that node.
 */

#include <iostream>

template <typename T>
struct mylist
{
        T          val;
        mylist<T> *ptr;
};

template <typename T>
void
delete_node (mylist<T> *node) 
{
        mylist<T> *next = node->ptr;
        for (; next->ptr != nullptr; next = next->ptr, node = node->ptr) {
                node->val = next->val;
        }
        node->val = next->val;
        delete next;
        node->ptr = nullptr;
}

int
main (void)
{
        mylist<int> l;
        mylist<int> *ptr = &l;
        for (int i = 0; i < 7; ++i) {
                ptr->val = i;
                ptr->ptr = new mylist<int>;
                ptr = ptr->ptr;
        }
        ptr->val = 7;
        ptr->ptr = nullptr;

        int n;
        std::cin >> n;

        ptr = &l;
        for (int i = 0; i < n; ++i, ptr = ptr->ptr);
        delete_node(ptr);

        ptr = &l;
        while (ptr->ptr != nullptr) {
                std::cout << ptr->val << ' ';
                ptr = ptr->ptr;
        }
        std::cout << ptr->val << std::endl;
        return 0;
}