#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 4
bool prefers(int prefer[2 * N][N], int w, int m, int m1) {
for (int i = 0; i < N; i++) {
if (prefer[w][i] == m) return true;
if (prefer[w][i] == m1) return false;
}
return false;
}
void stableMarriage(int prefer[2 * N][N]) {
int wPartner[N];
bool mFree[N];
for (int i = 0; i < N; i++) {
wPartner[i] = -1;
mFree[i] = true;
}
int freeCount = N;
while (freeCount > 0) {
int m;
for (m = 0; m < N; m++)
if (mFree[m]) break;
for (int i = 0; i < N && mFree[m]; i++) {
int w = prefer[m][i];
if (wPartner[w - N] == -1) {
wPartner[w - N] = m;
mFree[m] = false;
freeCount--;
} else {
int m1 = wPartner[w - N];
if (prefers(prefer, w, m, m1)) {
wPartner[w - N] = m;
mFree[m] = false;
mFree[m1] = true;
}
}
}
}
printf("Woman\tMan\n");
for (int i = 0; i < N; i++)
printf("%d\t%d\n", i + N, wPartner[i]);
}

int main() {
int prefer[2 * N][N] = {
{7, 5, 6, 4}, {5, 4, 6, 7}, {4, 5, 6, 7}, {4, 5, 6, 7},
{0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}
};
stableMarriage(prefer);
return 0;
}
