#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int N;
vector<vector<int> > ADJ;

vector<int> COMPT;
vector<int> VISIT;
set<int> GROUPED;

void dfs2 (int here, int compt) {

    COMPT[here] = compt;

    ++VISIT[here];
    if (VISIT[here] >= 2)
        GROUPED.insert(here);

    for (unsigned int i = 0; i < ADJ[here].size(); ++i) {
        int there = ADJ[here][i];
        if (!VISIT[there] || (COMPT[there] == compt && VISIT[there] < 2))
            dfs2(there, compt);
    }
}

int main (void) {

    int TC;
    scanf("%d", &TC);

    while (TC--) {

        // input and convert to graph.
        scanf("%d", &N);
        ADJ.assign(N, vector<int>());
        for (int s = 1; s <= N; ++s) {
            int e;
            scanf("%d", &e);
            ADJ[s - 1].push_back(e - 1);
        }

        // solve.
        COMPT.assign(N, 0);
        VISIT.assign(N, 0);
        GROUPED.clear();

        int compt = 0;
        for (int i = 0; i < N; ++i) {
            if (!COMPT[i])
                dfs2(i, ++compt);
        }

        printf("%d\n", N - (int)GROUPED.size());
    }

    return 0;
}
