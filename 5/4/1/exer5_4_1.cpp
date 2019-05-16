#include <iostream>
using namespace std;
void larger(double y)
{
    double x[] = {1.0,
                  3.0,
                  5.0,
                  2.0,
                  -1.0};
    for (int i = 0; i < 5; i++)
    {
        x[i] *= y;
        cout << x[i] << endl;
    }
}
int main(void)
{
    double num = 3.2;
    larger(num);
    num = 5;
    larger(num);
    return 0;
}