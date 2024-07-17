#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std ;
template<class t>
class StackNode{
public:
    StackNode *next ;
    t val ;
};
template<class t >
class Stack{
public:
    StackNode<t> *Top ;
    int siz ;
    Stack(){
        Top=nullptr , siz=0 ;
    }
    void push(t elemnt )
    {
        StackNode<t> *temp = new StackNode<t> ;
        temp->val=elemnt ;
        temp->next=Top ;
        Top=temp ;
        siz++ ;
    }
    void pop(){
        StackNode<t> *temp=Top ;
        Top=Top->next ;
        delete temp ;
        siz-- ;
    }

    t top()
    {
        return Top->val ;
    }
    bool empty()
    {
        return !Top ;
    }
    bool is_full()
    {
        return false ;
    }
    void show()
    {
        StackNode<t> *temp=Top ;
        while(temp!=nullptr){
            cout<<temp->val<<" " , temp=temp->next ;
        }
    }
    int Size()
    {
        return siz;
    }
    ~Stack()
    {
        StackNode<t>*temp=Top ;
        while(Top!=nullptr){
            temp=Top ;
            Top=Top->next ;
            delete temp ;
        }
        delete Top ;
    }
};
/*
 * precedence for mathematical operation
 * power '^' have the higher precedence
 * then '*' , '*' and '%'
 * then '+' and '-'
 */
int precedence (char op) {
    if (op == '^')
        return 4 ;
    if (op == '/' or op == '*' or op == '%')
        return 3 ;
    if (op == '+' or op == '-') {
        return 2 ;
    }
    return -1 ;
}
// check if the character is alphabet or not
bool isAlpha (char c) {
    bool Small_alpha = ('a' <= c && c <= 'z') ;
    bool Capital_alpha = ('A' <= c && c <= 'Z') ;
    return Small_alpha or Capital_alpha  ;
}
// check if the character is digit or not
bool isDigit (char c) {
    return  ('0' <= c and c <= '9') ;
}
// check if the character is space
bool isSpace(char c) {
    return c == ' ';
}
// Convert an infix expression to its equivalent postfix expression.
string infixTopostfix (string expression) {
    string output = "" ;
    Stack<char> operators ;

    int len = expression.size() ;
    for (int i = 0 ; i < len ; ++i) {

        if (isSpace(expression[i]))
            continue;

        if (  isDigit(expression[i]) or isAlpha(expression[i]) ) {
            output.push_back(expression[i]) ;
        } else if (expression[i] == '(') {
            operators.push('(') ;
        } else if (expression[i] == ')') {
            while (operators.empty() == 0 && operators.top() != '(') {
                output.push_back(operators.top()) ;
                operators.pop() ;
            }
            operators.pop() ;
        } else {
            while (operators.empty() == 0 &&  (precedence(expression[i]) <= precedence(operators.top()))) {
                output+= operators.top() ;
                operators.pop() ;
            }
            operators.push(expression[i]) ;
        }
    }
    while (operators.empty() == 0) {
        output.push_back(operators.top());
        operators.pop() ;
    }
    return output ;
}
// ======================== evaluation postfix expression ========================

/*
 * evaluate the mathematical expression with operator '+', '-', '^', '*', '/'
 * if the operator is not supported return 0
 */
double calc (double left_operand , char op , double right_operand) {
    if (op == '+') return left_operand + right_operand ;
    if (op == '^') return powf(left_operand,right_operand);
    if (op == '-') return left_operand - right_operand ;
    if (op == '/') return left_operand / right_operand ;
    if (op == '*') return left_operand * right_operand ;
    // If the operator is not one of the supported operators, return 0.0
    return 0.0;
}

double evaluation_postfix (string expression) {
    Stack<double> evaluator ;
    int len = (int)expression.size() ;
    for (int i = 0 ; i < len ; ++i) {
        if (isDigit(expression[i])) {
            evaluator.push(expression[i] - '0') ;
        } else {
            double right_op  = evaluator.top() ;
            evaluator.pop() ;
            double left_op  = evaluator.top() ;
            evaluator.pop() ;
            evaluator.push(calc(left_op , expression[i]  , right_op)) ;
        }
    }
    return evaluator.top() ;
}
int main()  {
    // here is some samples you can use .
    string ex=infixTopostfix("3*9+7^(1+2)-1") ;
    cout << ex << '\n' ;
    cout << evaluation_postfix(ex) << '\n'  ;
}