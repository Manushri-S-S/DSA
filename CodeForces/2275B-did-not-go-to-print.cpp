#include <iostream>
#include <stack>
#include <vector>

/*
APPROACH:

we are given documents numbered 1 to n
we have a differnt kind of a printer
having commands
1: stores the current document
2:prints the recent stored document 
if no document is stored
it prints the current document
3:quick print that is it prints the current document


we need stack to keep track of stored document

and we need an array to check if the document is printed or not

first we take the n number of documents and the command string s

we check the current document by traversing n times and check its corresponding
command

if it has 1
we store that document number in stack by push

if it is 2

we have 2 options
if the stack is not empty
we pop the top of stack
and make array of index top-1 as true

else if the stack is empty
we print the current document
and make array of index current document -1 as true

the last command
if it is 3

we print the current document
and make array of index current document -1 true

now we count the documents that didnt get printed
and display the document number that didnt print

*/

int main()
{
    int t;
    std::cin >> t;
    for (int z = 1; z <=t; z++)
    {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        std::stack<int> st;
        std::vector<bool> printed(n, false);

        int i;

        for (i = 1; i <= n; i++)
        {
            switch (s[i - 1])
            {
            case '1':
            {
                st.push(i);
                break;
            }
            case '2':
            {
                if (!st.empty())
                {
                    int x = st.top();
                    st.pop();
                    printed[x - 1] = true;
                }
                else
                {
                    printed[i - 1] = true;
                }
                break;
            }
            case '3':
            {
                printed[i - 1] = true;break;
            }
            }
        }
        int count = 0;
        for (i = 0; i < n; i++)
        {
            if (printed[i] == false)
            {
                count++;
            }
        }
        std::cout << count << std::endl;
        if (count != 0)
        {
            for (i = 0; i < n; i++)
            {
                if (printed[i] == false)
                {
                    std::cout << i + 1 << "  ";
                }
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }

    return 0;
}