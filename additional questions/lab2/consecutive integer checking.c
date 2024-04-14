#include <stdio.h>

int gcd(int a, int b) {
    int min = (a < b) ? a : b;
    int gcd = 1;
    int i;
    for ( i = 2; i <= min; ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int main() {
    int num1, num2;

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    printf("GCD of %d and %d using consecutive integer checking method is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}

