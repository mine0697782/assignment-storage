#include <iostream>
#include <stack>
using namespace std;

string s;
int s_length;
stack<char> c, pn;
stack<int> p;

void input()
{
   cin >> s;
   s_length = s.size();
}

int check(char x)
{
   if(x == '(') return 0;
   if(x == '+' || x == '-') return 1;
   else if(x == '*' || x == '/') return 2;
   else if(x == ')') return 3;
   else return -1;
}

void postfix()
{
   int i, count = 0;
   for(i = 0 ; i < s_length ; i++){
      int a = check(s[i]);
      if(a != -1) {
         if(p.empty() == true){ // stack empty
            c.push(s[i]);
            p.push(a);
         }
         else if(p.top() >= a && a!= 0){
            pn.push(c.top());
            c.pop();
            p.pop();
            c.push(s[i]);
            p.push(a);
         }
         else if(a == 3){ // close ()
            while(1){
               if(p.top() == 0){
                  c.pop();
                  p.pop();
                  break;
               }
               pn.push(c.top());
               c.pop();
               p.pop();
            }
         }
         else {
            c.push(s[i]);
            p.push(a);
         }
      }
      else if(i == s_length - 1){
         while(c.empty() == false){
            pn.push(c.top());
            c.pop();
            p.pop();
         }
      }
      else {
         pn.push(s[i]);
      }
   }
}

int calculation()
{
   int count = 0, a = -99999, b = 0;
   stack<char> ccl;
   stack<int> ab;
   while(pn.size() != 0 || ab.size() != 1){
      if(pn.empty() == false){
         if(pn.top() == '+' || pn.top() == '-' || pn.top() == '*' || pn.top() =='/'){
            count = 0;
            ccl.push(pn.top());
            pn.pop();
         }
         else {
            count++;
            ab.push(pn.top() - 48);
            pn.pop();
         }
      }
      
      if(count == 2){
         a = ab.top();
         ab.pop();
         b = ab.top();
         ab.pop();
         char z = int(ccl.top());
         ccl.pop();
         if(z == '+') ab.push(a + b);
         else if(z == '-') ab.push(a - b);
         else if(z == '*') ab.push(a * b);
         else if(z == '/') ab.push(a / b);
         count = ab.size();
      }
   }
   return ab.top();
}

int main() {
   int i;
   cout << "input start" << endl;
   input();
   postfix();
   cout << "calculation start" << endl;
   cout << calculation() << endl;
   return 0;
}
