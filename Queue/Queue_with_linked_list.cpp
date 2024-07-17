#include <bits/stdc++.h>
using namespace std ;
template<class t>
class QueueNode{
public :
    QueueNode *next ;
    t val ;
    QueueNode(){
        next=nullptr ;
    }
};
template<class t>
class Queue{
public:
    Queue(){
        Front=Back=nullptr ;
    }
    void push(t ele)
    {
        auto *temp=new QueueNode<t> ;
        temp->val=ele ;
        if( !Front ){
            Front=Back=temp ;
        }
        else{
            Back->next=temp ;
            Back=temp ;
        }
    }
    void pop()
    {
        QueueNode<t> *temp=Front ;
        Front=Front->next ;
        delete temp ;
    }
    t front()
    {
        return Front->val ;
    }
    t back()
    {
        return Back->val ;
    }
    void show()
    {
        QueueNode<t> *temp=Front ;
        while(temp!= nullptr){
            cout<<temp->val<<' ' , temp=temp->next ;
        }
    }
    bool empty()
    {
        return Front== nullptr ;
    }
    bool is_full()
    {
        return false ;
    }
private:
    QueueNode<t> *Front , *Back;
};
int main() {
    Queue<int>q ;
    q.push(2) , q.push(3) , q.push(834) , q.push(89) , q.push(20) ;
    cout<<q.front() <<endl ;
    cout<<q.back()<<endl ;
    q.show() ;
    cout<<endl ;
    cout<<q.back()<<endl ;
    q.pop() , q.pop() ;
    while(!q.empty()){
        cout<<q.front()<<' ' ;
        q.pop() ;
    }
    return 0;
}
