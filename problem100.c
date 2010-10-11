#include <stdio.h>
main() {
	int i, j, k, x;
	while(1) {
		x = fscanf(stdin, "%d %d\n", &i, &j);
		if(x == EOF) break;
		k = i * j;
		printf("%d %d %d\n", i, j, k);
	}
}
