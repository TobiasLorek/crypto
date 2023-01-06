#include <tuple>

std::tuple<int, int>divmod(int dividend, int divisor) {
    return {dividend / divisor, dividend % divisor};
}

std::tuple<int, int, int>extended_gcd(int a, int b)
{
    int A = a;
    int B = b;
    int u = 1;
    do {
        auto [q, r] = divmod(A, B);
        u *= q;
        A = q;
        B = r;
    } while(r != 0);
}
