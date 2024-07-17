#include <bits/stdc++.h>
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

int main() {
    Stack<char>s ;
    s.push('a')  , s.push('a') , s.push('f') , s.push('a') , s.push('w');
    cout<<s.top()<<endl ;
    s.show() ;
    cout<<endl ;
    while(!s.empty()){
        cout<<s.top();
        s.pop() ;
    }
    cout<<endl ;
    return 0;
}
