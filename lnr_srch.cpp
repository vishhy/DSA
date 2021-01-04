#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int arr[10];
    int n;
    int t = -1;

    for (int i = 1; i <= 10; i++)
    {
        cout << "Enter member " << i << " of the series" << endl;
        cin >> arr[i];
    }
    cout << "The list of members is: " << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Enter the no. that you want to search: " << endl;
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        if (arr[i] == n)
        {
            t = i;
            break;
        }
    }
    if (t != -1)
        cout << "No. found at " << t << " position" << endl;
    else
    {
        cout << "No. not found";
    }

    return 0;
}