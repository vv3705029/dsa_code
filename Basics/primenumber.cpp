#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int a = 0;
    cout << "Enter a number:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            a++;
        }
    }
    if (a == 2)
    {
        cout << "Is a prime number."<<endl;
    }
    else
    {
        cout << "Is not a prime number."<<endl;
    }
    cout<<sqrt(2)<<endl;
    cout<<double(1.00000+2)<<endl;
    return 0;
}
