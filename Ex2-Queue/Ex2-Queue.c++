#include <iostream>
#include "queue.h"
using namespace std;
//Function to compute the remaining fuel
double RemainingFuel(double F,double FC, double D){
        return F-FC*D/100;
}
//Function to check if we can start from this station
bool CorrectStation(Queue<double> F, Queue<double> D,double FC, int N){
    bool OK=1;
    double Fuel=F.peek();
    for (int i = 0; i < N; i++)
    {
        if (RemainingFuel(Fuel,FC,D.peek())<0)
        {
            OK=0;
        }
        //Fuel = RemainingFuel(Fuel,FC,D.peek());
        //cout<<"Fuel "<<Fuel<<endl;
        F.dequeue();
        D.dequeue();
        
        Fuel+=F.peek();
        
    }
    return OK;
}

int main() {
    double N,FC;
    double F,D;
    double RemainingF=0;
    cout<<"Enter the number of petrol stations and the fuel consumption:\n";
    cin>>N>>FC;
    Queue<double> Fuel;
    Queue<double> Distance;
    Queue<double> FAux;
    Queue<double> DAux;
    for (int i = 0; i < N; i++)
        {
            cout<<"Enter the fuel and the distance to the next station for station: "<<i<<" :\n";
            cin>>F>>D;
            Fuel.enqueue(F);
            Distance.enqueue(D);
        }
    
    for (int i = 0; i < N; i++)
    {
        if (CorrectStation(Fuel,Distance,FC,N))
        {
            cout<<"We can start the journey from station "<<i<<" .\n";//Found the station, time for a journey!!!
            break;
        }
        //Code to "change" the station if it is not the correct one
        FAux=Fuel;
        DAux=Distance;
        Fuel.dequeue();
        Distance.dequeue();
        Fuel.enqueue(FAux.peek());
        Distance.enqueue(DAux.peek());
        
    }
    
}