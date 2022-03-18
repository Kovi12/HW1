#include <iostream>
#include "stack.h"
using namespace std;
#define dim 100

//Function to create a new Event
void newEvent(int a[dim][dim],int N) {
    for (int i = 0; i < N; i++)
        {
            cout<<"Enter line "<<i<<" :"<<endl;
            for (int j = 0; j < N; j++)
                cin>>a[i][j];
            cout<<endl;
        }
    cout<<endl;
}
//Finding the specialist
int FindHomer(int a[dim][dim], int N) {
    bool PossibleHomer=1; //this will be changed if the person investigated at the moment speaks to someone , meaning that it cant be Homer
    int id=N-1;           //keeping track of the person investigated
    int TalkedWith=0;     //this will be changed if someone talks with the person investigated
    Stack<int> s1;
    Stack<int> s2;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            s1.push(a[i][j]);
    
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            s2.push(a[i][j]);
    
    for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (s1.peek()==1)
                    PossibleHomer=0;
                s1.pop();
            }
            
            
            for (int j = 0; j < N; j++)
            {
                if (s2.peek()==1)
                    TalkedWith++;
                s2.pop();
                    
            }
            
            if (PossibleHomer && TalkedWith==N-1)
                return id;
            
            PossibleHomer=1;
            TalkedWith=0;
            id--;
            
            
        }
    return id;

}
int main(){
int N;
bool Found=0;//changed if he is found
cout<<"Enter the number of people participating\n";
cin>>N;//number of people
int a[dim][dim]; //comment this if needed
/*int a[dim][dim]={ {0, 0, 1, 1, 1, 1},
                  {0, 0, 1, 1, 1, 1},
                  {0, 1, 0, 1, 0, 1},
                  {0, 0, 0, 0, 0, 0},
                  {1, 0, 1, 1, 1, 1},
                  {0, 0, 0, 1, 1, 0} }; //InputExample, uncomment if needed*/ 
newEvent(a,N);//First event,comment this if needed
while (!Found)
{
    if (FindHomer(a,N)==-1)
    {
        cout<<"Homer Simpson didn't participate. :( ... Creating a new event\n";
        cout<<"Enter the number of people participating\n";
        cin>>N;
        newEvent(a,N);//create event if Homer is not found
    
    }
    else
    {   cout<<"Homer Simpson is the person with id "<<FindHomer(a,N);//Success!!!
        Found=1;
    }

}

}