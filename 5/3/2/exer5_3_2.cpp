#include <iostream>
#include <math.h>
using namespace std;
double square(double x)
{
    return x * x;
}
double circle(int i)
{
    double num;
    num = square(i) * M_PI;
    return num;
}
int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << circle(i) << endl;
    }
    return 0;
}