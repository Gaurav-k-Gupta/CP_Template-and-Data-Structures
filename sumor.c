#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef long long ll;

/* complement mask: (1LL<<33)-1 */
static const unsigned long long COMP_MASK = ((1ULL << 33) - 1ULL);

unsigned long long complement_val(unsigned long long n) {
    return n ^ COMP_MASK;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;

        ll *a = (ll*)malloc(sizeof(ll) * n);
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

        /* used[] marks elements removed from the "multiset" */
        int *used = (int*)calloc(n, sizeof(int));
        /* assigned[] used for final index assignment (to simulate mp.pop_back()) */
        int *assigned = (int*)calloc(n, sizeof(int));

        /* find max element and remove it */
        int max_idx = 0;
        for (int i = 1; i < n; ++i) if (a[i] > a[max_idx]) max_idx = i;
        ll curVal = a[max_idx];
        used[max_idx] = 1;

        ll *res = (ll*)malloc(sizeof(ll) * n);
        res[0] = curVal;

        int i = 1;
        while (i < n) {
            if (i <= 32) {
                unsigned long long comp = complement_val((unsigned long long)curVal);
                unsigned long long maxi = 0ULL;
                int er_idx = -1;
                for (int j = 0; j < n; ++j) {
                    if (used[j]) continue;
                    unsigned long long v = ((unsigned long long)a[j]) & comp;
                    if (v > maxi) {
                        maxi = v;
                        er_idx = j;
                    } else if (v == maxi) {
                        if (er_idx == -1 || a[j] > a[er_idx]) er_idx = j;
                    }
                }
                /* fallback if something unexpected happened */
                if (er_idx == -1) {
                    for (int j = 0; j < n; ++j) if (!used[j]) { er_idx = j; break; }
                }

                curVal |= a[er_idx];
                used[er_idx] = 1;
                res[i] = a[er_idx];
            } else {
                /* pick smallest remaining element */
                int min_idx = -1;
                for (int j = 0; j < n; ++j) {
                    if (used[j]) continue;
                    if (min_idx == -1 || a[j] < a[min_idx]) min_idx = j;
                }
                if (min_idx == -1) {
                    /* shouldn't happen, but safe fallback */
                    for (int j = 0; j < n; ++j) if (!used[j]) { min_idx = j; break; }
                }
                used[min_idx] = 1;
                res[i] = a[min_idx];
            }
            ++i;
        }

        /* compute answer and build idx[] by simulating mp[value].pop_back() */
        long long ans = 0;
        unsigned long long cur = 0ULL;
        int *idx = (int*)malloc(sizeof(int) * n);

        for (int k = 0; k < n; ++k) {
            /* find last occurrence (from end) of res[k] that's not assigned yet */
            int found = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (!assigned[j] && a[j] == res[k]) {
                    assigned[j] = 1;
                    idx[n - k - 1] = j + 1; /* 1-based index */
                    found = 1;
                    break;
                }
            }
            if (!found) {
                /* fallback: shouldn't happen, but pick first unassigned */
                for (int j = 0; j < n; ++j) {
                    if (!assigned[j]) {
                        assigned[j] = 1;
                        idx[n - k - 1] = j + 1;
                        break;
                    }
                }
            }

            cur |= (unsigned long long)res[k];
            ans += (long long)cur;
        }

        printf("%lld\n", ans);
        for (int j = 0; j < n; ++j) {
            if (j) putchar(' ');
            printf("%d", idx[j]);
        }
        putchar('\n');

        free(a);
        free(used);
        free(assigned);
        free(res);
        free(idx);
    }

    return 0;
}
