#include <iostream>

using namespace std;

int main()
{
    int a,b;
    auto Multiply = [](int a, int b)->int{ //lambda expression which return a value of integer
        return a*b;
    };
    int Product = Multiply(2,10);
    cout << "The value of Product is: " << Product;
}