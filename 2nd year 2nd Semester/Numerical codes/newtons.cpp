#include<bits/stdc++.h>
using namespace std;

float horners(vector<float>& coff, double x)
{
    float result = 0.0;
    int degree = coff.size()-1;
    for(int i = degree; i>=0; i--)
    {
        result = result * x + coff[i];
    }
    return result;
}

vector<float> df(vector<float>& coff)
{
    vector<float> dev;
    int degree = coff.size()-1;
    for(int i = 1; i<degree; i++)
    {
        dev.push_back(coff[i]*i);
    }
    return dev;
}

vector<float> synthetic(vector<float>& coff, float x)
{
    int degree = coff.size()-1;
    vector<float> result(degree);

    result[0] = coff[0];
    for(int i = 1; i<degree; i++)
    {
        result[i] = coff[i] + x*result[i-1];
    }
    return result;
}

vector<float> newtons(vector<float>& coff, float x, float e, int maxI)
{
    vector<float> roots;
    vector<float> polynomial = coff;

    int i = 0;
    float xr = x;
    float x0;

    do{
        i++;
        x0 = xr;
        float f = horners(polynomial, x0);
        vector<float> synD = synthetic(polynomial, x0);
        float df = horners(synD, x0);

        xr = x0 - (f/df);
        cout<<endl;
        cout<<"Itr: "<<i<<endl;
        cout<<"root: "<<x0<<endl;


       if(abs(xr - x0)<e)
       {
        roots.push_back(xr);
        polynomial = synthetic(polynomial, xr);
       }
    }while(abs(xr-x0)>=e && i<maxI);

    return roots;
}

void showinterval(vector<float>& coff)
{
    int degree = coff.size()-1;
    vector<float> possibleRoots;
    float  maxcoff = abs(coff[0]);

    for(int i = 1; i<=degree; i++)
    {
        float c = abs (coff[i]);
        if(c > maxcoff){
            maxcoff = c;
        }
    }

    for(int i =1; i<+degree; i++)
    {
        possibleRoots.push_back(maxcoff/abs(coff[i]));
    }

    cout<<"Possible intervals of roots: ";
    for(float z : possibleRoots)
    {
        cout<<"(-inf,"<<-z<<")";
        cout<<"("<<-z<<", +inf)";
        
    }
    cout<<endl;
}

int main()
{
    int n;
    float x, e;
    cout<<"Enter the initial guess: ";
    cin>>x;

    cout<<"Enter the error: ";
    cin>>e;

    cout<<"Enter the degree: ";
    cin>>n;

    vector<float> coff(n+1);
    cout<<"Enter the coefficient: ";
    for(int i=n; i>=0; i--)
    {
        cin>>coff[i];
    }
    
    int maxI;
    cout<<"Enter the maximum number of iterations: ";
    cin>>maxI;
 
    vector<float> roots = newtons(coff, x, e, maxI);
    cout<<"Roots: ";
    for(float root: roots)
    {
        cout<<root<<" ";
    }
    cout<<endl;

    showinterval(coff);

    return 0;
    
}