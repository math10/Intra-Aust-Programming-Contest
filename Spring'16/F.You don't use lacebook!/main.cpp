#include <stdio.h>

const int MAX_N = 10000 + 7;

int n;
int first_list [MAX_N];
int second_list[MAX_N];

int to_remove() {
    int not_to_remove = 0;

    for (int i = 0; i < n; ++i) {
        if (first_list[i] != second_list[not_to_remove])
            continue;

        ++not_to_remove;
    }

    return n - not_to_remove;
}

int main() {
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; scanf("%d", &t);

    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", first_list + i);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", second_list + i);
        }

        printf("Case %d: %d\n", cs, to_remove());
    }

    return 0;
}
