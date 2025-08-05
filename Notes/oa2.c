#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    char share[20]; // buffer for storing each share as string

    for (int i = 0; i < N; i++) {
        scanf("%s", share);

        if (share[0] == '-') {
            // Negative share, Jasmine is not interested
            printf("NO\n");
        } else {
            // Check if share is a palindrome
            if (isPalindrome(share)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}
