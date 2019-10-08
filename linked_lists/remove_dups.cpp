/*
 * Write code to remove duplicates from an unsorted linked list.
 */
#include <iostream>
#include <forward_list>
#include <unordered_set>

using namespace std;

template<typename Comparable>
void
remove_hash (forward_list<Comparable> *l)
{
        unordered_set<Comparable> s;

        auto fit  = l->begin();
        auto sit  = l->begin();
        s.insert(*fit);

        fit++;
        while (fit != l->end()) {
                if (s.find(*fit) != s.end()) {
                        fit = l->erase_after(sit);
                        
                } else {
                        s.insert(*fit);
                        fit++;
                        sit++;
                }
        }
}

int
main (void)
{
        forward_list<int> list = {1, 2, 2, 3, 2, 2};
        remove_hash(&list);
        for (auto it = list.begin(); it != list.end(); ++it) {
                cout << *it << ' ';
        }
        cout << endl;
        return 0;
}