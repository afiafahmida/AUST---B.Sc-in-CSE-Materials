#include <stdio.h>

int main()
{
    long long int n, m, a = 1, n2, m2, prod = 0;

    scanf("%lld %lld %lld", &n, &m, &a);

    n2 = n/a;

    if (n%a != 0)
        n2++;

    m2 = m/a;

    if (m%a != 0)
        m2++;

    prod = n2 * m2;

    printf("%lld", prod);

    return 0;
}
