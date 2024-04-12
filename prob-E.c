#include <stdio.h>

int main(){
	int T, N, area, perimeter;
	FILE *baca = fopen("testdata.in", "r");
	
	fscanf(baca, "%d", &T);
	
	for(int i=0; i<T; i++){
		int A[1000], diff[1000], sum = 0, sumdiff = 0;
		fscanf(baca, "%d", &N);

		for(int j=0; j<N; j++){
			fscanf(baca, "%d", &A[j]);
			sum += A[j];
		}
		
		for(int j=0; j<N-1; j++){
			diff[j] = A[j+1] - A[j];
			if(diff[j] < 0) diff[j] = A[j] - A[j+1];
			sumdiff += diff[j];
		}
		
		perimeter = 2*2*N + 2*A[0] + 2*A[N-1] + 2*sumdiff;
		area = 2*2*sum;

		printf("Case #%d: %d %d\n", i+1, perimeter, area);
	}
	
	return 0;
}
