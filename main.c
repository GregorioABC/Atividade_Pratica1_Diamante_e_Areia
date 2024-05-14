#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1001
int contar_diamantes(char *linha) {
    int count = 0;
    int len = strlen(linha);
    char stack[MAX_LENGTH];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (linha[i] == '<') {
            stack[++top] = '<';
        } else if (linha[i] == '>' && top >= 0) {
            count++;
            top--;
        }
    }
    return count;
}
int main() {
    int N;
    char linha[MAX_LENGTH];
    scanf("%d", &N);
    getchar(); 
    for (int i = 0; i < N; i++) {
        fgets(linha, MAX_LENGTH, stdin);
        linha[strcspn(linha, "\n")] = '\0';
        printf("%d\n", contar_diamantes(linha));
    }
    return 0;
}
