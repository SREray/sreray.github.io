#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>

const int N = 50;

char s[N + 5][10];

char t1[100], t2[100];

int rand(int l, int r) { return rand() % (r - l + 1) + l; }

std::vector<int> to[N + 5];

int main() {
	srand(107);
	_splitpath(__FILE__, t1, t2, NULL, NULL);
	strcat(t1, t2);
	chdir(t1);
	for(int i = 1; i <= N; i++) for(int j = 0; j < 8; j++) s[i][j] = rand(1, 36) <= 26 ? rand('a', 'z') : rand('0', '9');
	for(int i = 1; i <= N; i++) to[rand(0, i - 1)].push_back(i);
	while(rand(0, 70) == 0) to[rand(0, N)].push_back(rand(0, N));
	for(int i = 0; i <= N; i++) if(to[i].empty()) to[i].push_back(rand(0, N));
	for(int i = 0; i <= N; i++) std::random_shuffle(to[i].begin(), to[i].end());
	strcpy(s[0], "entry");
	FILE *flog = fopen("info.log", "w");
	fprintf(flog, "n = %d\n", N);
	for(int u = 0; u <= N; u++) {
		fprintf(flog, "%d: %s\n", u, s[u]);
		mkdir(s[u]), chdir(s[u]);
		FILE *findex = fopen("index.md", "w");
		char ch = 'A';
		for(int v : to[u]) {
			fprintf(flog, "\t%c: %d,%s\n", ch, v, s[v]);
			fprintf(findex, "[%c](/riddle/maze/%s)\n", ch, s[v]);
			ch++;
		}
		fclose(findex);
		chdir("..");
	}
	fclose(flog);
	return 0;
}