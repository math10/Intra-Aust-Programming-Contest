#include <bits/stdc++.h>
using namespace std;

const int ALP_SET_SIZE = 6;
const int GRID_ROW = 5;
const int GRID_COL = 5;

char grid[ALP_SET_SIZE][GRID_ROW][GRID_COL + 1] = {
    {"#####",
     "#...#",
     "#####",
     "#...#",
     "#...#"},

    {"#####",
     "#...#",
     "#####",
     "#...#",
     "#####"},

    {"#####",
     "#....",
     "#....",
     "#....",
     "#####"},

    {"#####",
     "#...#",
     "#...#",
     "#...#",
     "#####"},

    {"#####",
     "#....",
     "#####",
     "#....",
     "#####"},

    {"#####",
     "#....",
     "#####",
     "#....",
     "#...."}
};

bool isEqual(char grid[GRID_ROW][GRID_COL + 1],
             char inputGrid[GRID_ROW][GRID_COL],
             int skip) {
    for (int i = 0; i < GRID_ROW; ++i) {
        for (int j = 0; j < GRID_COL; ++j) {
            if (j == skip) continue;

            int adjustedCol = j - (skip <= j);
            if (grid[i][j] != inputGrid[i][adjustedCol])
                return false;
        }
    }

    return true;
}

bool isEqual(char grid[GRID_ROW][GRID_COL + 1],
             char inputGrid[GRID_ROW][GRID_COL]) {
    for (int skip = 0; skip < GRID_COL; ++skip)
        if (isEqual(grid, inputGrid, skip))
            return true;

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        char inputGrid[GRID_ROW][GRID_COL];
        for (int i = 0; i < GRID_ROW; ++i)
            scanf("%s", inputGrid[i]);

        int matchCount = 0;
        char matchedChar = 0;
        for (int i = 0; i < ALP_SET_SIZE; ++i) {
            if (isEqual(grid[i], inputGrid)) {
                ++matchCount;
                matchedChar = 'A' + i;
            }
        }

        printf("Case %d: ", cs);
        if (matchCount == 1) {
            printf("%c\n", matchedChar);
        } else {
            printf("Ambiguous\n");
        }
    }

    return 0;
}

