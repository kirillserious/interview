/*
 * Write a method to replace all spaces in a string with '%20'. You may assume
 * that the string has sufficient space at the end to hold the additional
 * characters, and that you are given the "true" length of the string.
 */ 
#include <iostream>
#include <string>

using namespace std;

void
urlify (string *s, int n)
{
        int offset = s->length() - n;
        for (int i = n - 1; i >= 0; --i) {
                if ((*s)[i] != ' ') {
                        (*s)[i + offset] = (*s)[i];
                } else {
                        (*s)[i + offset]     = '0';
                        (*s)[i + offset - 1] = '2';
                        (*s)[i + offset - 2] = '%';
                        offset -= 2;
                }
        }
}

int
main (void)
{
        string s;
        getline(cin, s);
        int n;
        cin >> n;
        urlify(&s, n);
        cout << s << endl;
        return 0;
}