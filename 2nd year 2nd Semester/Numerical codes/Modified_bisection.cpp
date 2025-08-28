#include <bits/stdc++.h>
using namespace std;

float horners(float *coff, int n, float x)
{
    float result = coff[n];

    for(int i = n-1; i>=0; i--)
    {
        result = result * x + coff[i];
    }
    return result;
}

void MBisection(float* coff, int n, float a, float b, float e) 
{
    float fa = horners(coff, n, a);
    float fb = horners(coff, n, b);

    if(fa * fb > 0)
    {
        cout<<"No root exits in the interval"<<endl;
    }

    float c = 0.0, fc = 0.0;
    
    do{
        c = (a+b)/2.0f;
        fc = horners(coff, n, c);

        if(fc == 0.0f)
        break;

        if(fa*fc < 0)
        {
            b = c;
            fb = fc;
        }else{
            a = c;
            fa = fc;
        }
    }while(abs(b-a) >= e);

    cout<<"Root: "<<c<<endl;
}

int main()
{
    int n;
    float a, b, e;
    cout << "Enter two intervals: ";
    cin >> a >> b;

    cout << "Enter error: ";
    cin >> e;

    cout << "Enter degree: ";
    cin >> n;

    float coff[n + 1];
    cout << "Enter coefficients: ";
    for (int i = n; i >= 0; i--)
    {
        cin >> coff[i];
    }

    MBisection(coff, n, a, b, e);

    return 0;
}