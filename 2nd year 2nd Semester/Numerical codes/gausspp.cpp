//gauss with partial pivoting

#include<bits/stdc++.h>
using namespace std;

void swapRows(vector<vector<double>>& matrix, int r1, int r2)
{
  swap(matrix[r1], matrix[r2]);
}

void gausspp(vector<vector<double>>& matrix, vector<double>& solution)
{
   int n = matrix.size();

   //selecting pivot ...row with maximum abs value
   for(int i = 0; i<n; ++i)
   {
       int pivot_row = i;
       for(int k = i+1; k<n; ++k)
       {
           if(abs(matrix[k][i]) > abs(matrix[pivot_row][i]))
           {
               pivot_row = k;
           }
       }
       if(abs(matrix[pivot_row][i]) < 1e-9)
       {
           cout<<"Pivot element too close to zero!"<<endl;
           return;
       }

       swapRows(matrix, i, pivot_row);

       //forward elimination
       for(int k = i+1; k<n; ++k)
       {
           double factor = matrix[k][i] / matrix[i][i];
           for(int j = i; j<n+1; ++j)
           {
               matrix[k][j] -= factor*matrix[i][j];
           }
       }

       cout<<"Iteration "<<i+1<<":"<<endl;
       for(int r = 0; r<n; ++r)
       {
           for(int c = 0; c<n+1; ++c)
           {
               cout<<matrix[r][c]<<" ";
           }
           cout<<endl;
       }
       cout<<endl;
   }

   //backward substitution

   for(int i = n-1; i>=0; --i)
   {
       solution[i] = matrix[i][n];
       for(int j = i+1; j<n; ++j)
       {
           solution[i] -= matrix[i][j]*solution[j];
       }
       solution[i] /= matrix[i][i];
   }

}

int main()
{
  int n;
  cout<<"Enter the number of variable: ";
  cin>>n;

  vector<vector<double>> matrix(n, vector<double>(n+1));
  vector<double> solution(n);

  cout<<"Enter the augmented matrix, all the coefficients with constants: "<<endl;
  for(int i = 0; i<n; ++i)
  {
      for(int j = 0; j<n+1; ++j)
      {
          cin>>matrix[i][j];
      }
  }

   gausspp(matrix, solution);

   cout<<"solution: "<<endl;
   for(int i = 0; i<n; ++i)
   {
       cout<<"x"<<i+1<<" = "<<solution[i]<<endl;
   }


    return 0;
}
