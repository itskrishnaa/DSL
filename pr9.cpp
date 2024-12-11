#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to preprocess string: remove non-alphanumeric characters and convert to lowercase
string preprocessString(const string& str) {
    string result;
    for (char ch : str) {
        if (isalnum(ch)) {
            result += tolower(ch);
        }
    }
    return result;
}

// Function to reverse a string using a stack
string reverseString(const string& str) {
    stack<char> charStack;
    for (char ch : str) {
        charStack.push(ch);
    }

    string reversed;
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }
    return reversed;
}

// Function to check if the string is a palindrome
bool isPalindrome(const string& str) {
    string processed = preprocessString(str);
    string reversed = reverseString(processed);
    return processed == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Print original string
    cout << "Original string: " << input << endl;

    // Reverse string using stack
    string reversed = reverseString(preprocessString(input));
    cout << "Reversed string: " << reversed << endl;

    // Check for palindrome
    if (isPalindrome(input)) {
        cout << "The given string is a palindrome." << endl;
    } else {
        cout << "The given string is not a palindrome." << endl;
    }

    return 0;
}
