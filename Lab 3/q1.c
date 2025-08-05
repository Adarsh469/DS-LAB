#include <stdio.h>

int length(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void concatenate(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}

void insert(char main[], char sub[], int pos) {
    int lenMain = length(main);
    int lenSub = length(sub);

    if (pos < 0 || pos > lenMain) return;

    for (int i = lenMain; i >= pos; i--) {
        main[i + lenSub] = main[i];
    }

    for (int i = 0; i < lenSub; i++) {
        main[pos + i] = sub[i];
    }
}


void deleteSubstring(char main[], char sub[]) {
    int lenMain = length(main);
    int lenSub = length(sub);

    for (int i = 0; i <= lenMain - lenSub; i++) {
        int found = 1;
        for (int j = 0; j < lenSub; j++) {
            if (main[i + j] != sub[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            for (int j = i; j <= lenMain - lenSub; j++) {
                main[j] = main[j + lenSub];
            }
            lenMain -= lenSub;
            i--;
        }
    }
}


int main() {
    char str1[300], str2[100], sub[100];
    int choice, pos;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("Length of first string: %d\n", length(str1));
    printf("Length of second string: %d\n", length(str2));

    concatenate(str1, str2);
    printf("After concatenation: %s\n", str1);

    if (compare(str1, str2))
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    printf("Enter substring to insert: ");
    scanf("%s", sub);
    printf("Enter position to insert at (0-based index): ");
    scanf("%d", &pos);
    insert(str1, sub, pos);
    printf("After insertion: %s\n", str1);

    printf("Enter substring to delete: ");
    scanf("%s", sub);
    deleteSubstring(str1, sub);
    printf("After deletion: %s\n", str1);

    return 0;
}
