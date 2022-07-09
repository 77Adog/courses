# Sort #

## Basic Require ##

- The data should be total order which means that arbitrary two datas are comparable

> All the implementation will use C. They can be checked using the follow code.

``` c
#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

int a[MAXN] = {0};
int b[MAXN] = {0}; // May be used in mergesort.

void sort(int a[], int len);

int main() 
{
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

```

## Selection Sort ## 

``` c
void sort(int a[], int len)
{
    for (int i = 0; i < len ; i++) {
        int min = i;
        for(int j = i + 1 ; j < len ; j++) {
            if (a[min] > a[j]) min = j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
```

## Insertion Sort ##

```c
void sort(int a[], int len)
{
    for (int i = 0; i < len ; i++) {
        int j = i - 1;
        for ( ; j >= 0 ; j--) {
            if (a[j] < a[i]) break;
        }
        j++;
        int temp = a[i];
        for (int k = i ; k > j ; k--) {
            a[k] = a[k - 1];
        }
        a[j] = temp;
    }
}
```

## Shell Sort ##

```c
void sort(int a[], int len) 
{
    int h = 1;
    while (h < len / 3) h = 3 * h + 1;

    while (h >= 1) {
        for (int i = h; i < len ; i++) {
            for (int j = i ; j >= h && a[j] < a[j-h]; j -= h) {
                int temp = a[j];
                a[j] = a[j - h];
                a[j - h] = temp;
            }
        }
        h = h / 3;
    }
}

```

## Shuffle ##

> Shuffle(洗牌)

```c
void shuffle(int a[], int len) 
{
    for (int i = 0 ; i < len ; i++) {
        int r = rand() % (i + 1);
        int temp = a[r];
        a[r] = a[i];
        a[i] = temp;
    }
}
```

## Merge Sort ##

```c
int min(int a, int b) 
{
    if (a < b) return a;
    else return b;
}

void sort(int a[], int len)
{
    for (int i = 1 ; i < len ; i *= 2) {
        for (int j = 0 ; j < len ; j += 2 * i) {
            merge(a, b, j, min(j + i, len), min(j + 2 * i, len));
        }
    }
}

void merge(int a[], int b[], int lo, int mid, int hi)
{
    int p = lo;
    int q = mid;
    int r = lo;
    while(p < mid && q < hi) {
        if (a[p] < a[q]) {
            b[r] = a[p];
            p++;
            r++;
        } else {
            b[r] = a[q];
            q++;
            r++;
        }
    }
    while(p < mid) {
        b[r] = a[p];
        p++;
        r++;
    }
    while (q < hi) {
        b[r] = a[q];
        q++;
        r++;
    }
    for (int i = lo ; i < hi ; i++) {
        a[i] = b[i];
    }
}
```
## Quick Sort ##

```c
void sort(int a[], int len)
{
    shuffle(a, len);
    reSort(a, 0, len);
}

void reSort(int a[], int lo, int hi)
{
    if (lo <= hi) return;
    int lt = lo;
    int gt = hi - 1;
    int i = lo;
    int v = a[lo];
    while (i <= gt) {
        if (a[i] < v) {
            int temp = a[lt];
            a[lt] = a[i];
            a[i] = temp;
            lt++;
            i++;
        } else if (a[i] > v) {
            int temp = a[i];
            a[i] = a[gt];
            a[gt] = temp;
            gt--;
        } else {
            i++;
        }
    }
    reSort(a, lo, lt);
    reSort(a, gt + 1, hi);
}
```

## Stability ##

| Sort type | stable? |
| --- | --- |
| Insertion Sort | Yes |
| Selection Sort | No |
| Shell Sort | No |
| Merge Sort | Yes |
| Quick Sort | No |