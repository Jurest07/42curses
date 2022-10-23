#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int arr[255]{0};
    for (int i = 0; i < s.size(); i++)
        arr[tolower(s[i])]++;
    for (int i = 0; i < s.size(); i++)
    {
        if (arr[s[i]] == 1)
            s[i] = '(';
        else
            s[i] = ')';
    }
    for (int i = 0; i < s.size(); i++)
        cout << s[i];
    cout << endl;
}