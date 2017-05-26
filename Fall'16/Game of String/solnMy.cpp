#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 7, MAXL = 5;
char str [MAX][MAXL];
int idx [MAX];

bool comp (int a, int b) {
    return strcmp (str [a], str [b]) < 0;
}

int main () {
    int n, k;
    //freopen ("Game_of_strings_dataset_6.txt", "r", stdin);
    //freopen ("Game_of_strings_output_6.txt", "w", stdout);
    while (scanf ("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf ("%s", &str [i]);
            idx [i] = i;
        }
        sort (idx, idx + n, comp);
        scanf ("%d", &k);
        for (int i = 0; k && i < n; i++) {
            if (!i) {
                printf ("%s", str [idx [i]]);
                k--;
            } else if (strcmp (str [idx [i]], str [idx [i - 1]])) {
                printf ("%s", str [idx [i]]);
                k--;
            }
        }
        printf ("\n");
    }
    return 0;
}
