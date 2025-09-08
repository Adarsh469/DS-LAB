#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100], str2[100], temp[100];
    int choice, n;

    while (1) {
        printf("\n===== STRING FUNCTIONS MENU =====\n");
        printf("1. strlen\n");
        printf("2. strcpy\n");
        printf("3. strncpy\n");
        printf("4. strcat\n");
        printf("5. strncat\n");
        printf("6. strcmp\n");
        printf("7. strncmp\n");
        printf("8. strchr\n");
        printf("9. strrchr\n");
        printf("10. strstr\n");
        printf("11. strtok\n");
        printf("12. memset\n");
        printf("13. memcpy\n");
        printf("14. strdup\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Length: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter number of characters to copy: ");
                scanf("%d", &n);
                strncpy(str2, str1, n);
                str2[n] = '\0';
                printf("Copied string: %s\n", str2);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 5:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                printf("Enter number of characters to append: ");
                scanf("%d", &n);
                strncat(str1, str2, n);
                printf("Concatenated string: %s\n", str1);
                break;

            case 6:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                printf("Comparison result: %d\n", strcmp(str1, str2));
                break;

            case 7:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Comparison result: %d\n", strncmp(str1, str2, n));
                break;

            case 8:
                printf("Enter string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter character to find: ");
                char c1;
                scanf(" %c", &c1);
                if (strchr(str1, c1))
                    printf("First occurrence: %s\n", strchr(str1, c1));
                else
                    printf("Character not found.\n");
                break;

            case 9:
                printf("Enter string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter character to find: ");
                char c2;
                scanf(" %c", &c2);
                if (strrchr(str1, c2))
                    printf("Last occurrence: %s\n", strrchr(str1, c2));
                else
                    printf("Character not found.\n");
                break;

            case 10:
                printf("Enter main string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter substring: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                if (strstr(str1, str2))
                    printf("Substring found: %s\n", strstr(str1, str2));
                else
                    printf("Substring not found.\n");
                break;

            case 11:
                printf("Enter string (tokens separated by ,): ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                char *token = strtok(str1, ",");
                while (token) {
                    printf("Token: %s\n", token);
                    token = strtok(NULL, ",");
                }
                break;

            case 12:
                printf("Enter string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter character to fill: ");
                char c3;
                scanf(" %c", &c3);
                printf("Enter number of characters to set: ");
                scanf("%d", &n);
                memset(str1, c3, n);
                printf("Modified string: %s\n", str1);
                break;

            case 13:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter number of characters to copy: ");
                scanf("%d", &n);
                memcpy(temp, str1, n);
                temp[n] = '\0';
                printf("Copied string: %s\n", temp);
                break;

            case 14:
                printf("Enter string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                char *dup = strdup(str1);
                printf("Duplicated string: %s\n", dup);
                free(dup);
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
