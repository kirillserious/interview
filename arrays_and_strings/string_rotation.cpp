/*
 * Assume you have a method isSubstring which checks if one word is a substring
 * of another. Given two strings, s1 and s2, write code to check if s2 is
 * a rotation of sl using only one call to isSubstring (e.g., "waterbottle" is
 * a rotation of"erbottlewat").
 */
#include <iostream>
#include <string>

using namespace std;

bool
isSubstring (const string &s, const string &subs)
{
        int slen   = s.length();
        int sublen = subs.length();

        int e = 0;
        for (int i = 0; i < slen; ++i) {
                if (s[i] == subs[e]) {
                        ++e;
                        if (e == sublen) {
                                return true;
                        }
                } else {
                        e = 0;
                }
        }
        return false;
}

bool
is_rotation (const string &s1, const string &s2)
{
        return (s1.length() == s2.length()) ? isSubstring(s1 + s1, s2) : false;
}

int
main (void)
{
        string s1, s2;
        cin >> s1 >> s2;
        cout << is_rotation(s1, s2) << endl;
        return 0;
} 