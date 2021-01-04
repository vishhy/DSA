#include<iostream>
using namespace std;

int main()
{
    int a[]= {3, 4, -66, 12, 23, 5, 90};
    int n=7;

    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            if(a[i]>a[i+1])
            {
                int b= a[i];
                a[i]= a[i+1];
                a[i+1]= b;
            }
        }
    }
    cout<<"Sorted list is: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<"\n";
    }
    return 0;
}