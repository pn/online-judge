#include <stdio.h>
#define CACHE_SIZE 1000000
int cyc_len[CACHE_SIZE];

int getValue(int n) {
	if(n < CACHE_SIZE) {
		if(cyc_len[n] > 0)
			return cyc_len[n];
		else
			return cyc_len[n] = 1 + getValue(n%2?3*n+1:n/2);
	} else return 1 + getValue(n%2?3*n+1:n/2);
}

int main() {
	int i, j, k, x;
	//memset(cyc_len, 0, sizeof(int)*CACHE_SIZE);
	cyc_len[1] = 1;

	while(1) {
		x = fscanf(stdin, "%d %d\n", &i, &j);
		if(x == EOF) break;
		int max = 0;
		for(k = i; k <= j; k++) {
			int val = getValue(k);
			if(val > max) max = val;
		}
		printf("%d %d %d\n", i, j, max);
	}
	return 0;
}
