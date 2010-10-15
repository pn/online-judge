#include <stdio.h>
#include <string.h>
#define CACHE_SIZE 500000
#define TYP unsigned int
#define GETVAL(n) (n%2?3*n+1:n/2)
TYP cyc_len[CACHE_SIZE];

TYP getValue(TYP n) {
	if(n < CACHE_SIZE) {
		if(cyc_len[n] > 0) {
			return cyc_len[n];
		} else {
			return cyc_len[n] = 1 + getValue(GETVAL(n));
		}
	} else {
		return 1 + getValue(GETVAL(n));
	}
}

TYP i, j, k, x;
int main() {
	cyc_len[1] = 1;

	while((x = fscanf(stdin, "%d %d\n", &i, &j)) != EOF) {
		TYP max = 0, maxnum = 0;
		for(k = (i<j?i:j); k <= (j>i?j:i); k++) {
			TYP val = getValue(k);
			if(val > max) { max = val; maxnum = k;}
		}
		printf("%d %d %d\n", i, j, max);
	}
	return 0;
}
