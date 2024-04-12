#include <stdio.h>
#include <string.h>

struct code{
	int K;
	char str[1000];
};

int main(){
	int T;
	struct code data[1000];
	FILE *baca = fopen("testdata.in", "r");
	
	fscanf(baca, "%d", &T);
	for(int i=0; i<T; i++){
		char string[1200];

		fscanf(baca, "%d\n", &data[i].K);
		fscanf(baca, "%[^\n]", data[i].str);

		int shifting = data[i].K;
		strcpy(string, data[i].str);
		int length = strlen(string);

		for(int j=0; j<length; j++){
			if(string[j] == '0') string[j] = 'O';
			else if(string[j] == '1') string[j] = 'I';
			else if(string[j] == '3') string[j] = 'E';
			else if(string[j] == '4') string[j] = 'A';
			else if(string[j] == '5') string[j] = 'S';
			else if(string[j] == '6') string[j] = 'G';
			else if(string[j] == '7') string[j] = 'T';
			else if(string[j] == '8') string[j] = 'B';
		}

		for(int j=0; j<length; j++){
			if(string[j] >= 'A' && string[j] <= 'Z') string[j] -= shifting;
		}
		
		for(int j=0; j<length; j++){
			if(!(string[j] >= 'A' && string[j] <= 'Z') && string[j] != ' ') string[j] = 'Z' - ('A' - string[j] - 1);
		}

		printf("Case #%d: %s\n", i+1, string);
	}
	
	return 0;
}
