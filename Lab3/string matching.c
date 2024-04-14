#include <stdio.h>
#include <string.h>

void bruteForceStringMatch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "ABABCABABABCABCABAB";
    char pattern[] = "ABABC";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Indices of pattern occurrences:\n");
    bruteForceStringMatch(text, pattern);

    return 0;
}
