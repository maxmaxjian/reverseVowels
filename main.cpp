#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class solution {
  public:
    string reverseVowels(const string & str) {
        stack<char> st;
        queue<char> qu;
        string vows{"aeio"};
        for (auto ch : str) {
            qu.push(ch);
            if (vows.find(ch) != string::npos)
                st.push(ch);
        }
        
        string rev;
        while (!qu.empty()) {
            if (vows.find(qu.front()) == string::npos)
                rev += qu.front();
            else {
                rev += st.top();
                st.pop();
            }
            qu.pop();
        }

        return rev;
    }
};

int main() {
    // string s{"hello"};
    string s{"leetcode"};
    
    solution soln;
    string rev = soln.reverseVowels(s);
    std::cout << "Before reversing:\n";
    std::cout << s << std::endl;
    std::cout << "After reversing:\n";
    std::cout << rev << std::endl;
}
