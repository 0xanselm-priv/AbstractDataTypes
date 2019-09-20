#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <array>

using namespace std;

int a14(int a, int iSecret);

int a05();

void binSearch(int a[], int x, int lower, int upper);

void largestSubArrayA2(int a[]);

int largestSubArrayA3(int a[], int i, int j);

int f(int a[], int i, int j);

int maxElement(int a[]);

int main() {
    cout << "Hello, Robert!" << endl;
    int sortedArray[] = {3, 4, 6, 9, 11, 17, 25, 31, 44};
    int aArray[] = {15, 5, 10, 7, -5, -11, 13};
    int sArray[] = {3, -7, 4, 9};
    // binSearch(sortedArray, 17, 0, 8);
    // largestSubArrayA2(aArray);
    // largestSubArrayA3(sArray, 0, 3);
    return 0;
}

int a14(int a, int iSecret) {
    int iPrice = 10;
    printf("Secret Number %i \n", iSecret);
    int upperBound = 100;
    int lowerBound = 1;
    do {
        if (a == iSecret) {
            printf("Price is: %i \n", iPrice);
            printf("Lower Bound %i ", lowerBound);
            printf("Upper Bound %i \n", upperBound);
        } else if (a < iSecret) {
            iPrice -= 1;
            printf("Number is higher - ");
            printf("Lower Bound %i ", lowerBound);
            printf("Upper Bound %i ", upperBound);
            lowerBound = a;
            a = (int) floor(0.5 * (a + upperBound));
            printf("a is %i \n", a);
        } else if (a > iSecret) {
            iPrice -= 1;
            printf("Number is lower - ");
            printf("Lower Bound %i ", lowerBound);
            printf("Upper Bound %i ", upperBound);
            upperBound = a;
            a = (int) floor(0.5 * (a + lowerBound));
            printf("a is %i \n", a);
        }
    } while (a != iSecret);
    printf("a: %i. price: %i\n", a, iPrice);
    return iPrice;
}

int a05() {
    int min, max = 0;
    int a[100] = {};
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        a[i] = 100 - i;
    }

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (a[i] < min) {
            min = a[i];
        } else if (a[i] > max) {
            max = a[i];
        }
    }
    printf("A Min:%i", min);
    printf(" Max:%i\n", max);
    printf("A Diff %i", max - min);
    return 0;
}

void largestSubArrayA2(int a[]) {
    //Largest Sum Contiguous Subarray
    int max = INT_MIN;
    int n = 7;
    int pos = INT_MIN;
    int len = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + a[j];
            printf("a[%i]=%i Sum: %i ", j, a[j], sum);
            if (sum > max) {
                max = sum;
                printf("<---%i, ", sum);
                pos = i;
                len = j - i + 1;
            }
        }
        printf("\n");
    }
    printf("Max subarray starting at %i with length %i and sum %i", pos, len, max);
}

void binSearch(int a[], int x, int lower, int upper) {
    if (upper < lower) {
        printf("%i not found in array\n", x);
        return;
    }
    //int mid = (int) floor((lower + upper) / 2);
    int mid = lower + ((upper - lower) / 2);
    if (a[mid] == x) {
        printf("x found at pos %i in Array\n", mid);
    } else {
        if (x < a[mid]) {
            binSearch(a, x, lower, mid - 1);
        } else {
            binSearch(a, x, mid + 1, upper);
        }
    }
}

int largestSubArrayA3(int a[], int i, int j) {
    if (i == j) {
        return a[i];
    } else {
        int mid = (int) floor((i + j) / 2);
        int k = i;
        int t1[mid - i + 1] = {};
        int b = 0;
        while (i <= k and k <= mid) {
            t1[b] = f(a, k, mid);
            k++;
            b++;
        }
        b = 0;
        int opt1 = maxElement(t1);
        int l = mid + 1;
        int t2[j - l + 1] = {};
        while (mid + 1 <= l and l <= j) {
            t2[b] = f(a, mid + 1, j);
            l++;
            b++;
        }
        int opt2 = maxElement(t2);
        int opt = max(largestSubArrayA3(a, i, mid), largestSubArrayA3(a, mid + 1, j), opt1 + opt2);
        cout << "Opt: " << opt << endl;
        return opt;
    }
    return -1;
}

int maxElement(int a[]) {
    int max = INT_MIN;
    for (int i = 0; sizeof(a) / sizeof(a[0]) > i; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int f(int a[], int i, int j) {
    int sum = 0;
    while (i <= j) {
        sum += a[i];
        i++;
    }
    return sum;
}
