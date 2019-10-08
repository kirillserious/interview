/*
 * There are three types of edits that can be performed on strings: insert
 * a character, remove a character, or replace a character. Given two strings, 
 * write a function to check if they are one edit (or zero edits) away.
 */
#include <iostream>
#include <string>

using namespace std;

enum States
{
        INSERT,
        REMOVE,
        REPLACE
};

bool
one_away (const string &s1, const string &s2)
{
        States state;
        switch (s1.length() - s2.length()) {
                case -1:
                state = INSERT;
                break;
                case  1:
                state = REMOVE;
                break;
                case 0:
                state = REPLACE;
                break;
                default:
                return false;
        }
        int len = (state == INSERT)? s1.length() : s2.length();
        int pos = 0;
        while (pos < len) {
                if (s1[pos] != s2[pos]) break;
                ++pos;
        }
        if (pos == len) return false;
        switch (state) {
                case INSERT:
                        return s1.substr(pos) == s2.substr(pos + 1);
                case REMOVE:
                        return s1.substr(pos + 1) == s2.substr(pos);
                case REPLACE:
                        return s1.substr(pos + 1) == s2.substr(pos + 1);
        }

        return false;
}

int
main (void)
{
        string s1, s2;
        cin >> s1 >> s2;
        cout << one_away(s1, s2) << endl;
        return 0;
} 