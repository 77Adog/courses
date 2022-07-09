#include <stdio.h>
#include<stdlib.h>
#define MAXN 1000000

int a[MAXN] = {0};
int b[MAXN] = {0};

void sort(int a[], int len);
void sink(int [], int k, int hi);


int main() 
{
    srand(10000);
    for (int i = 0; i < MAXN ; i++) {
        a[i] = rand() % 100000;
    }

    sort(a, MAXN);
    int isSorted = 1;
    for (int i = 0; i < MAXN - 1 ; i++) {
        if (a[i] > a[i + 1]) {
            isSorted = 0;
            break;
        }
    }


    if (isSorted == 1) printf("Sort successfully\n");
    else printf("Sort fail\n");
}

void sink(int a[], int k, int hi)
{
    while (2 * k <= hi) {
        int j = 2 * k;
        if (j < hi && a[j] < a[j + 1]) j++;
        if (!(a[k] < a[j])) break;
        int temp = a[k];
        a[k] = a[j];
        a[j] = temp;
        k =j;
    }
}

void sort(int a[], int len) {
    for (int i = (len - 1) / 2 ; i >= 1 ; i--) sink(a, i, len - 1);
    int k = len - 1;
    while (k > 1) {
        int temp = a[1];
        a[1] = a[k];
        a[k] = temp;
        sink(a, 1, --k);
    }
    int i;
    for (i = 0 ; i < len - 1 ; i++) {
        if (a[0] < a[i]) break;
    }
    i--;
    int v = a[0];
    for (int k = 0 ; k < i ; k++) {
        a[k] = a[k + 1];
    }
    a[i] = v;
}