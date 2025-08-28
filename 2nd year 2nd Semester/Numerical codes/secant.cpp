#include<bits/stdc++.h>
using namespace std;

double f(double x, double coff[], int p){
   double ok = 0.0;
   for(int i =0; i<=p; i++)
   {
    ok += coff[i] * pow(x, p-1);

   }
   return ok;

    }

void secant(double x1, double x2, double e, double coff[], int p)
{
    double x0, f1, f2;

    int i = 1;
    do{
         f1 = f(x1, coff, p);
         f2 = f(x2, coff, p);

         x0 = ((f2*x1)-(f1*x2))/(f2-f1);

         //update
         x1 = x2;
         x2 = x0;

         cout<<endl;
         cout<<"Iteration: "<<i<<endl;
         cout<<"x1: "<<x1<<endl;
         cout<<"x2: "<<x2<<endl;
         i++;
    }while((abs((x0-x2)/x0))>e);

    cout<<"Root: "<<x0<<endl;
}

int main(){
 double x1, x2, e;
 int p;

 cout<<"Enter two guesses: ";
 cin>>x1>>x2;

 cout<<"Error: ";
 cin>>e;

cout<<"Enter power: ";
cin>>p;

double* coff = new double[p+1];
 cout<<"Enter coefficients: ";
 for(int i =0; i<=p; i++){
    cin>>coff[i];
 }

 cout<<endl;
 secant(x1, x2, e, coff, p);

    return 0;
}
