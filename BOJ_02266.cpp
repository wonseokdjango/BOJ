#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int N, K;
int DP[501][501] = {0, };

int main (void) {

    scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {

            if (j == 1)
                DP[i][j] = i;
            else {
                DP[i][j] = numeric_limits<int>::max();
                for (int drop = 1; drop <= i; ++drop) {
                    int tmp = max(DP[i - drop][j], DP[drop - 1][j - 1]) + 1;
                    DP[i][j] = min(DP[i][j], tmp);
                }
            }
        }
    }

    printf("%d\n", DP[N][K]);

    return 0;
}

