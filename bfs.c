//GPS NAVIGATION 
#include <stdio.h>
int visited[11] = {0};
int adj[11][11] = {0};
void bfs(int start, int n) {
int q[11], f = 0, r = 0;
q[r++] = start;
visited[start] = 1;
while (f < r) {
int curr = q[f++];
printf("%d ", curr);
for (int i = 1; i <= n; i++) {
if (adj[curr][i] && !visited[i]) {
q[r++] = i;
visited[i] = 1;
}
}
}
}
int main() {
int edges[][2] = {
{1,2}, {1,3}, {2,3}, {2,4}, {2,5},
{3,6}, {3,7}, {4,5}, {4,8}, {4,9},

{5,9}, {6,7}, {8,9}, {9,10}
};
for (int i = 0; i < 14; i++) {
adj[edges[i][0]][edges[i][1]] = 1;
adj[edges[i][1]][edges[i][0]] = 1;
}
printf("Reachable nodes from source 1: ");
bfs(1, 10);
printf("\n");
return 0;
}
