#include<iostream>
#include<stack>
#include<string>
using namespace std;
void evaluate(string s1) {
	//postfix evaluation
	stack<int> ev;
	int result = 0, p = 0, op1, op2;
	int len = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		len++;
	}
	for (int i = 0; i < len; i++) {

		if (s1[i] >= '0' && s1[i] <= '9') {
			p = s1[i] - '0';

			//cout << "p" << p << endl;
			ev.push(p);
			//pushing operands
		}
		else
		{
			switch (s1[i])
			{
			case '+':

				op1 = ev.top();
				ev.pop();
				op2 = ev.top();
				ev.pop();
				//popping out operands and caclculating result
				result = op1 + op2;
				ev.push(result);
				//pushing result into stack
				break;

			case '-':
				op1 = ev.top();
				ev.pop();
				op2 = ev.top();
				ev.pop();
				result = op2 - op1;
				ev.push(result);
				break;

			case '*':
				op1 = ev.top();
				ev.pop();
				op2 = ev.top();
				ev.pop();
				result = op2 * op1;
				ev.push(result);
				break;

			case '/':
				op1 = ev.top();
				ev.pop();
				op2 = ev.top();
				ev.pop();
				result = op2 / op1;
				ev.push(result);
				break;
			}
		}

	}
	cout << ev.top() << endl;

}
//function to calculate precedence of operators
int prec(char a) {
	if (a == '+' || a == '-') {
		return 1;
	}
	if (a == '*' || a == '/') {
		return 2;
	}
	if (a == '{' || a == '(' || a == '[') {
		return 0;
	}

	return -1;
}

int main() {
	char choice;

	while (1) {
	options: cout << endl << "enter your choice" << endl << "1.Calculator" << endl << "2.exit" << endl;
		cin >> choice;
		int k = 1, len, newStringLen;
		string s, ns1;
		stack<char> st;

		switch (choice)
		{
		case '2':
			return 0;
			break;
		default: cout << "enter valid choice" << endl;

			break;

		case '1':

			cout << "enter an expression" << endl;
			cout << "Infix  ";
			cin >> s;
			//s is expression to be evaluated
			len = s.length();
			if ((len == 1) && (s[0] >= '0' && s[0] <= '9'))
			{
				cout << "evaluation  " << s << endl;

			}
			//if single digit is entered by user
			else if ((len == 2) && (s[0] == '-') && (s[1] >= '0' && s[1] <= '9')) { cout << "evaluation  " <<s[0]<<s[1]<<endl; }
			//if a negative single digit number is entered 
			else {
				//infix to postfix
				for (int i = 0; i < len; i++) {
					k = 1;
					if (s[i] >= '0' && s[i] <= '9')
					{//if it is a number adding it to the new string ns1
						ns1 = ns1 + s[i];
					}
					else

					{//push when open bracket comes
						if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
							st.push(s[i]);

						}
						else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
						{
							//if it is operator, check precedence with top of stack
							//push if high
							if (!st.empty()) {
								if (prec(s[i]) > prec(st.top()))
								{
									st.push(s[i]);
								}
								//else add top to new string ns1 and push the incoming one
								else
								{
									ns1 = (ns1 + st.top());
									st.pop();
									st.push(s[i]);
								}
							}
							else
							{//if stack is empty
								st.push(s[i]);
							}
						}
						else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
						{
							if (st.empty())
							{
								cout << "wrong input";
								goto options;
							}
							//checking for an opening bracket for every closing bracket
							while (k) {
								if (st.top() == '{' || st.top() == '(' || st.top() == '[') {
									st.pop();
									k = 0;
								}
								else {
									ns1 = (ns1 + st.top());
									st.pop();
								}

							}
						}
						else {
							cout << "enter valid operators only" << endl;

							goto options;
						}
					}


				}
				while (!st.empty()) {
					//adding leftout elements in the stack to new string ns1
					ns1 = (ns1 + st.top());
					st.pop();
				}
				newStringLen = ns1.length();


				if (ns1.length() < 3) {
					cout << "invalid expression" << endl;
					goto options;
					//getchar();
					//getchar();
					//return 0;
				}
				else {
					cout << "postfix  ";
					cout << ns1 << endl;
					cout << "evaluation  ";
					//sending obtained postfix expression to evaluate
					evaluate(ns1);

				}
			}
			break;
			getchar();

		}

	}
	return 1;
}
