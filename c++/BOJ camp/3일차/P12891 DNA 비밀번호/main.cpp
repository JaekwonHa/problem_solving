#include <stdio.h>

int main() {
	int n[4];
	int alp[26];
	alp['A' - 'A'] = 0;
	alp['C' - 'A'] = 0;
	alp['G' - 'A'] = 0;
	alp['T' - 'A'] = 0;

	int S, P;
	char str[1000010];
	scanf("%d %d %s", &S, &P, str);
	scanf("%d %d %d %d", n, n + 1, n + 2, n + 3);

	int ans = 0;
	for (int i = 0; i < P; i++) alp[str[i] - 'A']++;
	if (alp['A'-'A'] >= n[0] && alp['C' - 'A'] >= n[1] && alp['G' - 'A'] >= n[2] && alp['T' - 'A'] >= n[3]) ans++;

	for (int i = 1; i <= S-P; i++) {
		alp[str[i+P-1] - 'A']++, alp[str[i - 1] - 'A']--;
		if (alp['A' - 'A'] >= n[0] && alp['C' - 'A'] >= n[1] && alp['G' - 'A'] >= n[2] && alp['T' - 'A'] >= n[3]) ans++;
	}
	printf("%d\n", ans);

	return 0;
}