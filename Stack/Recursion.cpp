#include <bits/stdc++.h>
using namespace std ;
// Time Complexity : O( 2^n )
void hanoi(int N, char from, char to, char aux) {
    if(N) {
        hanoi(N - 1, from, aux, to);
        cout<<"Move disk "<<N<<" from "<<from<<" to "<<to<<'\n';
        hanoi(N - 1, aux, to, from);
    }
    return;
}
/// Time Complexity: O( 2^n )
void hanoi2(int N, char from, char to, char aux) {
    int temp;
    while(N > 0) {
        hanoi2(N - 1, from, aux, to);
        cout<<"Move Disk "<<N<<" from "<<from<<" to "<<to<<'\n';
        temp = from;
        from = aux;
        aux = temp;
        --N;
    }
    return;
}
int main() {
    hanoi(4, 'A', 'C', 'B');
    cout<<'\n' ;
    hanoi2(4, 'A', 'C', 'B');
}
