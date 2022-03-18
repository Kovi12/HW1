#include <iostream>
#include "list.h"
#include <fstream>
#include <vector>
using namespace std;
//Function to compute sum
int Sum(vector<int> v,int St,int Dr){
    int sum=0;
    for (int i = St-1; i < Dr; i++)
        sum+= v[i];

    return sum;
}
//Function to Invert the vector
void Invert(vector<int> &v,int St,int Dr) {
    vector<int> aux=v;
    int k=Dr-1;
    for (int i = St-1; i < Dr; i++)
    {
        v[i]=aux[k];
        k--;
    }
    
}

int main(){

    ifstream in ("input.in.txt");
    ofstream out ("output.out.txt");

    int N,K,St,Dr;
    char type;
    vector<int> A;
    LinkedList<vector<int>> List;
    in >> N;
    in >> K;
    
    for (int i = 1; i <= N; i++)
    {
        A.push_back(i);
    }
    for (int i = 0; i < K; i++)
    {
        in >> type;
        in >> St;
        in >> Dr;

        if (type=='S')
            out << Sum(A,St,Dr)<< endl;
        else if (type=='I')
            Invert(A,St,Dr);
        
        
    }
    
    

out.close();
}