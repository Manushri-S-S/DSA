#include <iostream>
#include <string>
using namespace std;
/*
Approach

we need to select one character from denominator and delete it in the numerator
we need to check for all the denominator characters
even if one is not found 
we can move to next 

ex:
sinx/n = six
here we had only n in s2
we found that in s1 and deleted it 
and found the s1 to be "six" 
note:
six it can be any order 
isx or xis

we also need to check if the denominator is having any remaining 
if it has it is a no

*/
int main()
{

    int t = 0;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int l1 = 0, l2 = 0;
        string s1, s2;

        cin >> l1 >> l2;
        cin >> s1 >> s2;

        bool valid = true;
        for (int i = 0; i < l2 && s2[i] != '\0'; i++)
        {
            char key = s2[i];
            size_t idx = s1.find(key);
            
            if (idx == string::npos)
            {
                valid = false;
                break;
            }
            else
            {
                s1.erase(idx, 1);
            }
        }

        int n = s1.length(), s = 0, i1 = 0, x = 0;
        if (n != 3)
        {
            cout << "NO" << endl;
            continue;
        }
        if (valid == true)
        {
            for (int i = 0; i < n; i++)
            {
                if (s1[i] == 's')
                {
                    s++;
                }
                if (s1[i] == 'i')
                {
                    i1++;
                }
                if (s1[i] == 'x')
                {
                    x++;
                }
            }

            if (s == 1 && i1 == 1 && x == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}