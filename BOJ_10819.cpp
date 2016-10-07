#include <cstdio>
#include <limits>
#include <cstdlib>
#include <algorithm>

#define MAXN 8

using namespace std;

int N, ANS;
int ARR[MAXN];

void go (int idx) {

    if (idx == N) {
        int tmp = 0;
        for (int i = 0; i < N - 1; ++i)
            tmp += abs(ARR[i] - ARR[i + 1]);
        ANS = max(ANS, tmp);
    }

    for (int i = idx; i < N; ++i) {
        swap(ARR[idx], ARR[i]);
        go(idx + 1);
        swap(ARR[idx], ARR[i]);
    }
}

int main (void) {

    // input.
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &ARR[i]);

    // init and solve.
    ANS = numeric_limits<int>::min();
    go(0);
    printf("%d\n", ANS);

    return 0;
}
