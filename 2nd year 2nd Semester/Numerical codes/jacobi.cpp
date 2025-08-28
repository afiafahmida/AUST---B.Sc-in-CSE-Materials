//jacobi

#include<bits/stdc++.h>
using namespace std;

const double e = 1e-9;
const int MAX_itr = 1000;

void jacobi(vector<vector<double>>& matrix, vector<double>& b, vector<double>& solution)
{
    int n = matrix.size();

    vector<double> newSolution(n, 0.0);

    for(int itr = 0; itr<MAX_itr; ++itr)
    {
        for(int i = 0; i<n; ++i)
        {
            double sum = b[i];
            for(int j = 0; j<n; ++j)
            {
                if(i != j)
                {
                    sum -= matrix[i][j]*solution[j];
                }
            }
            newSolution[i] = sum/matrix[i][i];
        }

        bool converged = true;
        for(int i = 0; i<n; ++i)
        {
            if(abs(newSolution[i] - solution[i])>e)
            {
                converged = false;
                break;
            }
        }
        if(converged)
        {
            cout<<"Converged after "<<itr+1<<" iteration"<<endl;
            return;
        }

        solution = newSolution;
        cout<<"Iteration "<<itr+1<<": ";
        for(int i = 0; i<n; ++i)
        {
            cout<<"x"<<i+1<<" = "<<solution[i]<<"  ";
        }
        cout<<endl;
    }

    cout<<"Maximum iteration reached. The solution may not have converged.";
}

int main()
{

  int n;
  cout<<"Enter the number of unknown variables: ";
  cin>>n;

  vector<vector<double>> matrix(n, vector<double>(n+1));
  vector<double> b(n);

  cout<<"Enter the augmented matrix of coefficients and constants: "<<endl;
  for(int i = 0; i<n; ++i)
  {
      for(int j = 0; j<n; ++j)
      {
          cin>>matrix[i][j];
      }
      cin>>b[i];
  }

  vector<double> solution(n, 0.0);
  jacobi(matrix, b, solution);
    return 0;
}


