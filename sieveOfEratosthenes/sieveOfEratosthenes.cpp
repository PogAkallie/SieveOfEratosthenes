#include <iostream>
using namespace std;

void init(bool arr[], size_t n)
{
    for (int i = 0; i < n + 1; i++)
        arr[i] = 0;
}

void print(const bool arr[], size_t n)
{
    for (int i = 0; i < n + 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sieveEratosthenes(bool arr[], size_t n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == 0) //value 0 if it is not canceled 
        {
            for (int j = i * i; j <= n; j += i) //j+=i, because every time we cancel is from diff num
            {
                arr[j] = 1; //the elemnt of the arr becomes 1, 
                            //because it is canceled
            }
        }
    }
}

void printAllPrimes(bool arr[], size_t n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!arr[i])
            cout << i << " ";
        //printing the index of the num, which determens 
        //if a number is prime or not
    }
}

void deleteArr(bool arr[])
{
    if (arr != 0)
    {
        delete[] arr;
        arr = nullptr;
    }
}

int main()
{
    int n = 0;
    cin >> n;

    //creating dynamic array to store the numbers 
    //creating type bool arr in order to mark and cancel
    //0-mark, 1-cancel
    bool* arr = new bool[n + 1]; //n+1, because we wanto to check
                                    //all the numbers including n
    
    //initialising all elem inside the arr with 0
    init(arr, n);

    /*print(arr, n);*/

    sieveEratosthenes(arr, n);

    printAllPrimes(arr, n);

    deleteArr(arr);

    return 0;

}

