#include <Func.hpp>

namespace mt
{
    int cout(int x)
    {
        int sum = 0;
        int a;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
}