/*
 * Implement an algorithm to find the kth to last element of 
 * a singly linked list.
 */

#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
auto
kth_last (const forward_list<T> &l, int k)
{
        int len = 0;
        for (auto it = l.begin(); it != l.end(); ++it) {
                ++len;
        }

        auto it = l.begin();
        for (int i = 0; i < len - k; ++i) {
                ++it;
        }
        return it;
}

int
main (void)
{
        forward_list<int> list = {1, 2, 2, 3, 2, 2};
        auto it = kth_last(list, 1);
        cout << *it << endl;
        return 0;
}