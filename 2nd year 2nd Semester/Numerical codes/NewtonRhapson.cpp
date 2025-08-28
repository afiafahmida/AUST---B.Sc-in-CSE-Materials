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

double df(double x, double coff[], int p){
   double ok = 0.0;

   for(int i = 0; i<=p; i++)
    {
        ok += (p-1) * coff[i] * pow(x, p-1);
    }
    return ok;
}

void NR(double x0, double e, double coff[], int p){
   double x1, f1, f0, df0;
   df0 = df(x0, coff, p);
   f0 = f(x0, coff, p);
    
    int i = 1;
   do{
    if (df0 == 0.0){
        cout<<"Error!!"<<endl;
    }
    x1 = x0 - (f0/df0);
    x0 = x1;

    cout<<"Iteration: "<<i<<endl;
   cout<<"x1: "<<x1<<endl;
   i++;
    
   }while((abs(f(x1, coff, p))>e));

   cout<<"Root: "<<x1<<endl;  

}

int main(){
   int p;
   double x0, e;
   cout<<"Enter initial guess and error: ";
   cin>>x0>>e;
   cout<<"Enter power: ";
   cin>>p;
   double* coff = new double[p +1 ];
   cout<<"Enter the coeffiecient: ";
   for(int i = 0; i<=p; i++)
   {
    cin>>coff[i];

   }

   NR(x0, e, coff, p);
}
