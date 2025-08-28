//gauss without pivot

#include<bits/stdc++.h>
using namespace std;

void NaiveGauss(vector<vector<double>>& matrix, vector<double>& solution)
{
   int n = matrix.size();

   //forward elimination
   for(int i = 0; i<n; ++i)
   {
       //diagonal eliment ke 1 banabo
       double factor = matrix[i][i];
       for(int j = i; j<n+1; ++j)
       {
           matrix[i][j] /= factor;
       }

       //elimination
       for(int k = i+1; k<n; ++k)
       {
           factor = matrix[k][i];
           for(int j = i; j<n+1; ++j)
           {
               matrix[k][j] -= factor*matrix[i][j];
           }
       }
   }

   //backward substitution
   for(int i = n-1; i>=0; --i)
   {
       solution[i] = matrix[i][n];
       for(int j = i+1; j<n; ++j)
       {
           solution[i] -= matrix[i][j] * solution[j];
       }

   }
}

int main()
{
  int n;
  cout<<"Enter the number of unknown variables: ";
  cin>>n;

  vector<vector<double>> matrix(n, vector<double>(n+1));


  cout<<"Enter the augmented matrix of coefficients and constants: "<<endl;
  for(int i = 0; i<n; ++i)
  {
      for(int j = 0; j<n+1; ++j)
      {
          cin>>matrix[i][j];
      }
  }

  vector<double> solution(n);
  NaiveGauss(matrix, solution);

  cout<<"Solution: "<<endl;
  for(int i = 0; i<n; ++i)
  {
      cout<<"x"<<i+1<<" = "<<solution[i]<<endl;
  }



    return 0;
}
