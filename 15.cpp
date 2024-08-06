// my code for seive of eratotheres

#include <iostream>
#include <vector>
using namespace std;

int countprime(int n)
{
    int count = 0;
    vector<bool> primes;
    for (int i = 0; i < n; i++)
    {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            count++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                primes[j] = 0;
            }
        }
    }
    return count;
}
int main()
{cout<<"Hi";
    cout << countprime(50);
    return 0;
}