#include <bits/stdc++.h>
using namespace std;
// chack Palindrome or not
bool isPalindrome(string str)
{
    queue<char> c;
    int i = 0;
    int j = str.length() / 2;

    while (i < j)
    {
        c.push(str[i]); // push in the Queue
        i++;
    }
    i = str.length() - 1;
    // Check Palindrome or not.
    while (i > j)
    {
        if (c.front() != str[i])
        {
            return false;
        }
        c.pop();
        i--;
    }
    return true;
}
// chack Valid Expression
bool isValidExpression(string a)
{
    bool hasDigits = false;
    string p;
    stack<char> s;
    int i = 0;
    while (i < a.length())
    {
        // Check starting brackets and push in the Stack.
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            s.push(a[i]);
        }
        // Check closing brackets
        else if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            char b = s.top();
            // pop from stack and compare with input character.
            if ((a[i] == ')' && b == '(') || (a[i] == '}' && b == '{' || (a[i] == ']' && b == '[')))
                s.pop();
            else
                return false;
        }
        // Check the Operator
        else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            /*
                if next character of Operator is Closing Brackets,
                means Expression are not valid.
            */
            if (a[i + 1] == ')' || a[i + 1] == '}' || a[i + 1] == ']')
            {
                return false;
            }
        }
        // check that, it have any Digits or not.
        else
        {
            hasDigits = true;
            p += a[i];
        }
        i++;
    }
    // if stack is empty and expression is palindrome and have digits.
    if (s.empty() && isPalindrome(p) && hasDigits)
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    if (isValidExpression(s))
        cout << "Valid Expression.";
    else
        cout << "Invalid Expression!";

    return 0;
}