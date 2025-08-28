#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
int arr[n];
int i = 0;
while(n--) {
cin >> arr[i];
i++;
}
for ( int j = 0; j < i-1; j++) {
for ( int k= 0; k < i-j-1; k++) {
if(arr[k] < arr[k+1]) {
arr[k] = arr[k] + arr[k+1];
arr[k+1] = arr[k] - arr[k+1];
arr[k] = arr[k] - arr[k+1];
}
}
}
for ( int t = 0; t < i; t++) {
cout << arr[t] << endl;
}
}
