#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* genRandNumStr(int len) {
    char* str = malloc(len + 1);
    srand(time(0));

    for (int i = 0; i < len; i++) {
        str[i] = rand() % 10 + '0';
    }

    str[len] = '\0';
    return str;
}

char* genRandLowercaseStr(int len) {
    char* str = malloc(len + 1);
    srand(time(0));

    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }

    str[len] = '\0';
    return str;
}

char* genRandUppercaseStr(int len) {
    char* str = malloc(len + 1);
    srand(time(0));

    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'A';
    }

    str[len] = '\0';
    return str;
}

char* genRandSymbolStr(int len) {
    char* str = malloc(len + 1);
    srand(time(0));
    const char charset[] = "!@#$%^&*()";

    for (int i = 0; i < len; i++) {
        int index = rand() % 10;
        str[i] = charset[index];
    }

    str[len] = '\0';
    return str;
}

char* strConcat(char str1[], char str2[], char str3[], char str4[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);
    int res_len = len1 + len2 + len3 + len4;
    char* res = malloc(res_len + 1);
    strcpy(res, str1);
    strcpy(res + len1, str2);
    strcpy(res + len1 + len2, str3);
    strcpy(res + len1 + len2 + len3, str4);

    res[res_len] = '\0';
    return res;
}

int main() {
    char* num_str = genRandNumStr(10);
    char* lower_case_str = genRandLowercaseStr(5);
    char* upper_case_str = genRandUppercaseStr(5);
    char* symbol_str = genRandSymbolStr(2);
    char* packed_str = strConcat(num_str, lower_case_str, upper_case_str, symbol_str);
    printf("The generated string: %s", packed_str);
    free(num_str);
    free(lower_case_str);
    free(upper_case_str);
    free(symbol_str);
    free(packed_str);
}