/*
 * Implement an algorithm to determine if a string has all unique characters.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Using hash table.
 *
 * Time O(n).
 * Memory O(n^2).
 */
bool
is_unique (const std::string &s)
{
        unordered_map<char, int> m;
        for (auto it = s.begin(); it != s.end(); ++it) {
                if (m.find(*it) != m.end()) {
                        m[*it] += 1;
                } else {
                        m[*it]  = 1;
                }
        }

        bool res = true;
        for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->second != 1) {
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
is_unique_bit (const std::string &s)
{
        const int MAXCHAR = 256;
        vector<int> v(MAXCHAR);
        for (auto it = s.begin(); it != s.end(); ++it) {
                ++v[*it];
        }

        bool res = true;
        for (auto it = v.begin(); it != v.end(); ++it) {
                if (*it > 1) {
                        res = false;
                        break;
                }
        }

        return res;
}

/*
 * Using sorting string.
 *
 * Time O(n*log(n)).
 * Memory O(1).
 */
bool
is_unique_mem (std::string *s)
{
        sort(s->begin(), s->end());

        bool res = true;
        int  len = s->length();
        for (int i = 0; i < len - 1; ++i) {
                if ((*s)[i] == (*s)[i+1]) {
                        res = false;
                        break;
                }
        }

        return res;
}

int
main (void)
{
        string s;
        cin >> s;
        cout << is_unique(s) << endl;
        cout << is_unique_bit(s) << endl;
        cout << is_unique_mem(&s) << endl;
        return 0;
}