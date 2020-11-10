#include <string>
#include <iostream>
#include "utstack.h" 

char BracketPair(char bracket) {
	switch (bracket) {
	case '}':return '{';
	case ')':return '(';
	case ']':return '[';
	}
}

bool TheCorrectString(const string &s) {
	bool flag = true;
	TStack<char> stack;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
			stack.push(s[i]);
		if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
			if (stack.empty()) {
				flag=false;
				break;
			}
			else 
				if (stack.top() == BracketPair(s[i])) 
				stack.pop();
				else {
					flag = false;
					break;
				}
		return (stack.empty() && flag);
	}
}

int main(int argc, char** argv) 
{
	string st;
	if (argc > 1)
		st = argv[1];
	cout << TheCorrectString(st) << endl;
	return 0;
}
