#include<stdio.h>
int getmax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
void countsort(int a[], int n, int pos) {
    const int k = 10;
    int c[k] = {0};
    int b[n];
    for (int i = 0; i < n; i++)
        ++c[(a[i] / pos) % 10];
    for (int i = 1; i < k; i++)
        c[i] +=c[i - 1];
    for (int i = n-1;i >=0;i--)
        b[--c[(a[i] / pos) % 10]] = a[i];
    for (int i = 0; i<n; i++)
        a[i] = b[i];
}
void radixsort(int a[], int n) {
    int max = getmax(a, n);

    for (int pos = 1; max / pos > 0; pos *= 10) {
        countsort(a, n, pos);
    }
}
int main() {
    int a[] = {12, 67, 45, 9, 8};
    int n = sizeof(a) / sizeof(a[0]);
    radixsort(a, n);
    printf("The sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
