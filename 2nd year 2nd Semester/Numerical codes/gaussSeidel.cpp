//seidel

#include<bits/stdc++.h>
using namespace std;

const double e = 1e-9;
const int MAX_itr = 100;

void GaussSeidel(vector<vector<double>>& matrix, vector<double>& b, vector<double>& solution)
{
  int n = matrix.size();

  vector<double> prevSolution(n, 0.0);

  for(int itr = 1; itr<=MAX_itr; ++itr)
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
          solution[i] = sum/matrix[i][i];
      }

      bool converged = true;
      for(int i = 0; i<n; ++i)
      {
          if(abs(solution[i]-prevSolution[i])>e)
          {
              converged = false;
              break;
          }
      }

      cout<<"Iteration "<<itr<<": ";
      for(int i = 0; i<n; ++i)
      {
          cout<<"x"<<i+1<<" = "<<fixed<<setprecision(6)<<solution[i]<<" ";
      }
      cout<<endl;

      if(converged)
      {
          break;
      }

      prevSolution = solution;
  }

}

int main()
{
    int n;
    cout<<"Enter the number of variables: ";
    cin>>n;

    vector<vector<double>> matrix(n, vector<double>(n));
    vector<double> b(n);
    vector<double> solution(n, 0.0);

    cout<<"Enter the matrix with constants: "<<endl;
    for(int i = 0; i<n; ++i)
    {
        for(int j = 0; j<n; ++j)
        {
            cin>>matrix[i][j];
        }
        cin>>b[i];
    }

    GaussSeidel(matrix, b, solution);

    return 0;
}
