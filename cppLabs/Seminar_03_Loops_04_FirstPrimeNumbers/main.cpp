//Вывести первые n простых чисел.

/*number        result
    1           2 
    6           2 3 5 7 11 13 
    12          2 3 5 7 11 13 17 19 23 29 31 37
*/

#include <iostream>


int main()
{
    int n;
    int counter = 0;
    std::cout << "Input the value of n: ";
    std::cin >> n;
    int currentNumber = 2;
    int del = 2;
    int remainder = currentNumber % del;
    while (counter < n)
    {
        bool isPrime = true;
        for (int i = 2; isPrime && i < currentNumber; i++)
        {
            if (currentNumber % i == 0) {
                isPrime = false;
            }
        }
        if (isPrime)
        {
            counter++;
            std::cout << currentNumber << " ";
        }
        currentNumber++;
    }

    return 0;
}