#include <stdio.h>

int main(){
	long int A, B;
	FILE *baca = fopen("testdata.in", "r");
	fscanf(baca, "%ld %ld", &A, &B);
	printf("%ld\n", A+B);
	fclose(baca);
	
	return 0;
}
