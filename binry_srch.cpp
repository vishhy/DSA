#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

void binry_srch(int a[], int n, int n1);
//n1 for no. to search, n for the size of array
int main()
{
    int arr[]= {2, 3, 6, 8, 45, 66, 89, 91};
    int n=8;
    binry_srch(arr, 8, 44);

    return 0;
}

void binry_srch(int a[], int n, int n1) {

    int l, u, m;
    l=0, u= n-1;
    

    while(l<=u) {
       m= (l+u)/2;
        if(n1== a[m]) {
            cout<<"Element found at "<<m<<" position."<<endl;
            return;
        }
       else if(n1>a[m])
            l=m+1;
        else
            u=m-1;
    }
    cout<<"Element not found";
}