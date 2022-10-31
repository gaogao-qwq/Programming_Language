#include <stdio.h>
#include <string.h>

int main() {
    char M[10] = {};
    char N[1001] = {}, output[6001] = {};
    scanf("%s%s", M, N);
    for(int i = 0; i <= strlen(N) - 1; i++) {
        char temp1[2] = {N[i]};
        char temp2[5];
        sprintf(temp2, "%d", strlen(N) - i - 1);
        if(N[i] != '0') {
            if (i != 0) {
                strcat(output, "+");
            }
            strcat(output, temp1);
            strcat(output, "*");
            strcat(output, M);
            strcat(output, "^");
            strcat(output, temp2);
        }
    }
    puts(output);
    return 0;
}