#include <stdio.h>
long long pangkat(long long a, long long b)
{
    long long result = 1;
    while (b)
    {
        if (b & 1)
            result *= a;
        b /= 2;
        a *= a;
    }
    return result;
}
int main()
{
    printf("Program untuk menghitung pangkat (X^Y)\n");
    printf("Masukkan nilai X: ");
    long long X;
    scanf("%lld", &X);
    printf("Masukkan nilai Y: ");
    long long Y;
    scanf("%lld", &Y);
    printf("Hasil dari %lld^%lld adalah %lld\n", X, Y, pangkat(X, Y));
}