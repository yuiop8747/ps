#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <functional>
#include <queue>
#include <math.h>
#include <memory.h>

int readInt();

long long readLong();

long long x, y;

void GatherInput() {
    x = readLong();
    y = readLong();
}

bool Prepared = false;
static const int K = 447214;
int LUT[K + 1];

void Prepare() {
    if (!Prepared) {
        LUT[0] = 0;
        for (int i = 1; i <= K; i++) {
            int val = i;
            for (int n = 1; n * (n + 1) / 2 <= i; n++) {
                int j = i - n * (n + 1) / 2;
                val = std::min(val, n + LUT[j]);
            }
            LUT[i] = val;
        }
        Prepared = true;
    }
}

long long ComputeMaxN(long long x) {
    double nn = (-1 + sqrt(1 + 8 * x)) / 2;
    return (long long) floor(nn);
}

long long Tri(long long n) {
    return n * (n + 1) / 2;
}

long long Compute(long long x) {
    if (x <= K) return LUT[x];

    long long opt = x;
    long long Q = ComputeMaxN(x);
    while (x - Tri(Q) <= K) {
        opt = std::min(opt, Q + LUT[x - Tri(Q)]);
        Q--;
    }
    return opt;
}

void Solve() {
/* prepare LUT */
    Prepare();

/* reduce range */
    long long maxn_y = ComputeMaxN(y);
    x = std::max(x, (maxn_y - 1) * maxn_y / 2);

/* compute */
    long long val = 0;
    for (long long i = x; i <= y; i++) {
        val = std::max(val, Compute(i));
    }

/* print */
    printf("%lld\n", val);
}

int main() {
#ifdef BOJ
    int T = 1;
#else
    setbuf(stdout, NULL);
    int T = readInt();
#endif
    for (int test_case = 1; test_case <= T; test_case++) {
        GatherInput();
#ifndef BOJ
        printf("Case #%d\n", test_case);
#endif
        Solve();
    }
    return 0;
}

int readInt() {
    int p;
    scanf("%d", &p);
    return p;
}

long long readLong() {
    long long p;
    scanf("%lld", &p);
    return p;
}