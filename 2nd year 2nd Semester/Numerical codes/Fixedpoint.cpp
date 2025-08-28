#include<bits/stdc++.h>
using namespace std;

double f(double x, double coff[], int p){
    double ok=0.0;

    for(int i = 0; i<=p; i++)
    {
        ok += coff[i] * pow(x, p-1);
    }
    return ok;

    }

double g(double x, double coff[], int p){
   double ok = 0.0;

   for(int i =0; i<p; i++)
   {
    ok = x * ok + coff[i];
   }
   return ok;
}   

void fpi(double x0, double e, int max_i, double coff[], int p){
    int step = 1;
    double x1;

    do{
        x1 = g(x0, coff, p);
        step++;

        if(step > max_i){
            cout<<"Not convergent"<<endl;
        }
        x0 = x1;
    }while(abs(f(x1, coff, p))>e);

    cout<<"Root: "<<x1<<endl;
}

int main(){

    int p, max_i;
    double x0, e;
    cout<<"Enter initial guess and error: ";
    cin>>x0>>e;
    cout<<"Enter maximum iteration and power: ";
    cin>>max_i>>p;

    double* coff = new double[p + 1];
    for(int i = 0; i<=p; i++)
    {
        cin>>coff[i];
    }

    fpi(x0, e, max_i, coff, p);
}