#include <stdio.h>
long long faktorial(long long n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}
int main()
{
    printf("Program untuk menghitung faktorial\n");
    printf("Masukkan nilai N: ");
    long long N;
    scanf("%lld", &N);
    printf("Hasil dari %lld! adalah %lld\n", N, faktorial(N));
}