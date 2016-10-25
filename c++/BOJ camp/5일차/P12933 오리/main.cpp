#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

bool visit[2501];

int main() {

	char duck[2501];

	scanf("%s", duck);

	int cnt = 0, ans=0;
	while (cnt < strlen(duck)) {
		int type = -1;
		for (int i = 0; i < strlen(duck); i++) {
			if (visit[i] == true) continue;
			switch (type) {
			case -1:
				if (duck[i] == 'q') visit[i] = true, type = 1, cnt++;
				break;
			case 0:
				if (duck[i] == 'q') visit[i]=true, type = 1, cnt++;
				break;
			case 1:
				if (duck[i] == 'u') visit[i] = true, type = 2, cnt++;
				break;
			case 2:
				if (duck[i] == 'a') visit[i] = true, type = 3, cnt++;
				break;
			case 3:
				if (duck[i] == 'c') visit[i] = true, type = 4, cnt++;
				break;
			case 4:
				if (duck[i] == 'k') visit[i] = true, type = 0, cnt++;
				break;
			}
		}
		if (type == 0) {
			ans++;
		}
		else {
			ans = -1;
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}