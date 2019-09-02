#include <stdio.h>
#include <string.h>
#include <ctype.h>

int max(int a, int b){
    return a>b ? a:b;
}

int is_alphabetic(char c){
    return ((c>=65)&&(c<=90))||((c>=97)&&(c<=122));
}

int strcasecmp(char const *a, char const *b) {
    for(;; a++, b++){
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

int main(void) {
    int k, e;
    int is_eof;
    for(int set = 1;; set++) {
        is_eof = (scanf("%d %d", &k, &e) == EOF);
        if(is_eof)
            break;
        char keywords[k][101];
        char apologies[e][101];
        int rank[e], worst = 0;
        for(int i = 0; i < k; i++) {
            scanf(" %[^\n]s", keywords[i]);
            //printf("%s\n", keywords[i]);
        }
        for(int i = 0; i < e; i++){
            rank[i] = 0;
            scanf(" %[^\n]s", apologies[i]);
            //printf("%s\n", apologies[i]);
            char begin = 0, end = 0;
            char word[101] = "";
            while((apologies[i][end]) != '\0' && (apologies[i][begin] != '\0')) {
                while(!is_alphabetic(apologies[i][begin]) && (apologies[i][begin]) != '\0'){
                    begin++;
                }
                if(apologies[i][begin] == '\0')
                    break;
                end = begin;
                while(is_alphabetic(apologies[i][end]) && (apologies[i][end]) != '\0'){
                    word[end-begin] = apologies[i][end];
                    end++;
                }
                if(apologies[i][end] == '\0')
                    break;
                word[end-begin] = '\0';
                for(int j = 0; j < k; j++){
                    if(strcasecmp(word, keywords[j]) == 0){
                        rank[i]++;
                        worst = max(worst, rank[i]);
                    }
                }
                begin = end+1;
            }
        }

        printf("Conjunto de desculpas #%d\n", set);
        for(int i = 0; i < e; i++)
            if(rank[i] == worst)
                printf("%s\n", apologies[i]);
        printf("\n");
    }
    return 0;
}