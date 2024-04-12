#include <stdio.h>
#include <string.h>

int main(){
	char name[120][120], pohon[120][120], nama[120];
	int N, T;
	
	FILE *baca = fopen("testdata.in", "r");

	fscanf(baca, "%d\n", &N);
	for(int i=0; i<N; i++){
		fscanf(baca, "%[^#]#%[^\n]\n", name[i], pohon[i]);
	}

	fscanf(baca, "%d", &T);
	for(int i=0; i<T; i++){
		fscanf(baca, "%s", nama);
		for(int j=0; j<N; j++){
			if(strcmp(nama, name[j]) == 0){
				printf("Case #%d: %s\n", i+1, pohon[j]);
				break;
			}
			else if(j == N-1) printf("Case #%d: N/A\n", i+1);
		}
	}
	
	fclose(baca);
	
	return 0;
}
