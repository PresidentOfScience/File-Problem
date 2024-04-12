#include <stdio.h>

int main(){
    FILE *baca = fopen("testdata.in", "r");
    int T;

    fscanf(baca, "%d\n", &T);
    while(T > 0){
        char S[1000];
        fscanf(baca, "%s\n", S);

        int N;
        fscanf(baca, "%d\n", &N);

        int counter[26] = {0};

        for(int i=0; i<N; i++){
            int idx = 0;
            char initial, result;

            fscanf(baca, "%c %c\n", &initial, &result);
            counter[initial-65]++;

            while(S[idx] != '\0'){
                if(S[idx] == initial && counter[initial-65] <= 1){
                    S[idx] = result;
                }
                idx++;
            }
        }

        int count[26] = {0};
        int idx = 0;
        while(S[idx] != '\0'){
            int index = S[idx] - 65;
            count[index]++;
            idx++;
            counter[idx]++;
        }

        for(int i=0; i<26; i++){
            if(count[i] > 0){
                printf("%c %d\n", i+65, count[i]);
                count[i] = 0;
            }
        }

        T--;
    }
    return 0;
}
