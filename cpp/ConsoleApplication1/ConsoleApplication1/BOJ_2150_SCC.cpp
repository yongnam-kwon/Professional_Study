// BOJ_2150_SCC
#if 0
#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define VMAX	(10010)

int V, E;
vector<int> edges[VMAX], reverse_edges[VMAX];
bool visited[VMAX];
int stack[VMAX], top;
vector<int> result[VMAX];
int cnt;

void input_() {
	int a, b;
	top = cnt = 0;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		reverse_edges[b].push_back(a);
	}
}

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = true;
	for (int n : edges[node]) {
		if (visited[n]) continue;
		dfs(n);
	}
	stack[++top] = node;
}

void scc1() {
	for (int i = 1; i <= V; i++) {
		if (visited[i]) continue;
		dfs(i);
	}
}

void init() {
	for (int i = 1; i <= V; i++) visited[i] = false;
}

void reverse_dfs(int node) {
	visited[node] = true;
	result[cnt].push_back(node);
	for (int n : reverse_edges[node]) {
		if (visited[n]) continue;
		reverse_dfs(n);
	}
}

void scc2() {
	for (int i = top; i >= 1; i--) {
		if (visited[stack[i]]) continue;
		reverse_dfs(stack[i]);
		cnt++;
	}
}

bool cmp(int n1, int n2) {
	if (result[n1][0] < result[n2][0]) return true;
	return false;
}

void output() {
	vector<int> tmp;
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		sort(result[i].begin(), result[i].end());
		tmp.push_back(i);
	}
	sort(tmp.begin(), tmp.end(), cmp);
	for (int i : tmp) {
		for (int n : result[i]) {
			printf("%d ", n);
		}
		printf("-1\n");
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	input_();
	scc1();
	init();
	scc2();
	output();
	return 0;
}
#endif