/*
 * Implement a method to perform basic string compression using the counts of 
 * repeated characters. For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not become smaller than
 * the original string, your method should return the original string. You can
 * assume the string has only uppercase and lowercase letters (a - z).
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool
is_digit (char c)
{
        return (c >= '0') && (c <= '9');
}

void
add_number (string *s, int n)
{
        vector<char> v;
        while (n > 0) {
                v.push_back('0' + n%10);
                n /= 10;
        }
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
                (*s) += (*it);
        }
}


string
compress (const string &s)
{
        string res;
        int len = s.length();

        res += s[0];
        int cur_count = 1;
        for (int i = 1; i < len; ++i) {
                if ( s[i] == s[i-1] ) {
                        ++cur_count;
                } else {
                        if (cur_count > 1) add_number(&res, cur_count);
                        res += s[i];
                        cur_count = 1;
                } 
        }
        if (cur_count > 1) add_number(&res, cur_count);
        return res;
}


int
main (void)
{
        string s;
        cin >> s;
        cout << compress(s) << endl;
        return 0;
}