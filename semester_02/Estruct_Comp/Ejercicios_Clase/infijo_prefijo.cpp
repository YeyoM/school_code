#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int precedencia(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

bool esOperador(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    return true;
  }
  else {
    return false;
  }
}

string InfijoAPrefijo(stack<char> s, string infix) {
  string prefix;
  reverse(infix.begin(), infix.end());
  for (int i = 0; i < infix.length(); i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
    }
    else if (infix[i] == ')') {
      infix[i] = '(';
    }
  }
  for (int i = 0; i < infix.length(); i++) {
    if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
      prefix += infix[i];
    }
    else if (infix[i] == '(') {
      s.push(infix[i]);
    }
    else if (infix[i] == ')') {
      while ((s.top() != '(') && (!s.empty())) {
          prefix += s.top();
          s.pop();
      }
      if (s.top() == '(') {
          s.pop();
      }
    }
    else if (esOperador(infix[i])) {
      if (s.empty()) {
        s.push(infix[i]);
      }
      else {
        if (precedencia(infix[i]) > precedencia(s.top())) {
          s.push(infix[i]);
        }
        else if ((precedencia(infix[i]) == precedencia(s.top()))
          && (infix[i] == '^')) {
          while ((precedencia(infix[i]) == precedencia(s.top()))
            && (infix[i] == '^')) {
            prefix += s.top();
            s.pop();
          }
          s.push(infix[i]);
        }
        else if (precedencia(infix[i]) == precedencia(s.top())) {
          s.push(infix[i]);
        }
        else {
          while ((!s.empty()) && (precedencia(infix[i]) < precedencia(s.top()))) {
            prefix += s.top();
            s.pop();
          }
          s.push(infix[i]);
        }
      }
    }
  }
  while (!s.empty()) {
      prefix += s.top();
      s.pop();
  }
  reverse(prefix.begin(), prefix.end());
  return prefix;
}

int main()
{

    string infix, prefix;
    cout << "Enter a Infix Expression :" << endl;
    cin >> infix;
    stack<char> stack;
    cout << "INFIX EXPRESSION: " << infix << endl;
    prefix = InfijoAPrefijo(stack, infix);
    cout << endl
         << "PREFIX EXPRESSION: " << prefix;

    return 0;
}