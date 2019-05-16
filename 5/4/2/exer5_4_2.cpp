#include <iostream>
using namespace std;
double x[] = {1.0,
              3.0,
              5.0,
              2.0,
              -1.0};
void larger(double y)
{
    for (int i = 0; i < 5; i++)
    {
        x[i] *= y;
        cout << x[i] << endl;
    }
}
void times(double y)
{
    for (int i = 0; i < 5; i++)
    {
        x[i] *= y;
    }
}
int main(void)
{
    double num = 3.2;
    times(num);
    num = 5;
    times(num);
    larger(1);
    return 0;
}