//gauss jordan

#include<bits/stdc++.h>
using namespace std;

void GaussJordan(vector<vector<double>>& matrix, vector<double>& solution)
{
    int n = matrix.size();

    //forward elimination
    for(int i = 0; i<n; ++i)
    {
        double factor = matrix[i][i];
        for(int j = i; j<n+1; ++j)
        {
            matrix[i][j] /= factor;

        }

        //normalize
        for(int k = 0; k<n; ++k)
        {
            if(k!=i)
            {
                factor = matrix[k][i];
                for(int j = i; j<n+1; ++j)
                {
                    matrix[k][j] -= factor*matrix[i][j];
                }
            }
        }

        //iterations print
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

    //backward
    for(int i = 0; i<n; ++i)
    {
        solution[i] = matrix[i][n];
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
  GaussJordan(matrix, solution);

  cout<<"Solution: "<<endl;
  for(int i = 0; i<n; ++i)
  {
      cout<<"x"<<i+1<<" = "<<solution[i]<<endl;
  }



    return 0;
}
