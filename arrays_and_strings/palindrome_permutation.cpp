/*
 * Given a string, write a function to check if it is a permutation of
 * a palin­drome. A palindrome is a word or phrase that is the same forwards 
 * and backwards. A permutation is a rearrangement of letters. The palindrome
 * does not need to be limited to just dictionary words. 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool
check (const string &s)
{
        const int MAX_CHAR = 256;
        vector <int> v(MAX_CHAR);

        int odd_count = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
                if (*it == ' ') continue;
                odd_count += (++v[*it] % 2) ? 1 : -1; 
        }

        return odd_count <= 1;
}

int
main (void)
{
        string s;
        getline(cin, s);
        cout << check(s) << endl;
        return 0;
}