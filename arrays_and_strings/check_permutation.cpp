/*
 * Given two strings, write a method to deside if one is a permutation of
 * the other.
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Using sorting of strings.
 * 
 * Time O(n log(n)).
 * Memory O(1).
 */
bool
check_permutation_sort (string *s1, string *s2)
{
        sort(s1->begin(), s1->end());
        sort(s2->begin(), s2->end());

        return *s1 == *s2;
}

/*
 * Using hash table.
 * 
 * Time O(n).
 * Memory O(n^2).
 */
bool
check_permutation_hash (const string &s1, const string &s2)
{
        unordered_map <char, int> m;
        for (auto it = s1.begin(); it != s1.end(); ++it) {
                if (m.find(*it) != m.end()) {
                        m[*it] += 1;
                } else {
                        m[*it]  = 1;
                }
        }
        for (auto it = s2.begin(); it != s2.end(); ++it) {
                if (m.find(*it) != m.end()) {
                        m[*it] -=  1;
                } else {
                        m[*it]  = -1;
                }
        }
        bool res = true;
        for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->second != 0) {
                        res = false;
                        break;
                }
        }
        return res;
}

/*
 * Using bit array.
 * 
 * Time O(n).
 * Memory O(1).
 */
bool
check_permutation_bit (const string &s1, const string &s2)
{
        const int MAX_CHAR = 256;
        vector<int> v(MAX_CHAR);
        for (auto it = s1.begin(); it != s1.end(); ++it) {
                v[*it] += 1;
        }
        for (auto it = s2.begin(); it != s2.end(); ++it) {
                v[*it] -= 1;
        }
        bool res = true;
        for (auto it = v.begin(); it != v.end(); ++it) {
                if (*it != 0) {
                        res = false;
                        break;
                }
        }
        return res;
}


int
main (void)
{
        string s1, s2;
        cin >> s1 >> s2;
        cout << check_permutation_hash(s1, s2)   << endl;
        cout << check_permutation_bit(s1, s2)    << endl;
        cout << check_permutation_sort(&s1, &s2) << endl;
        return 0;
}