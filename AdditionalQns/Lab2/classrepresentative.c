#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to find winner index
int findWinner(int *votes, int index, int n, int currentWinner) {
    if (index > n) return currentWinner;
    if (votes[index] > votes[currentWinner])
        currentWinner = index;
    return findWinner(votes, index + 1, n, currentWinner);
}

int main() {
    int students, candidates;

    // Input number of students and candidates
    printf("Enter number of students (voters): ");
    scanf("%d", &students);

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    // Dynamic allocation for votes array (index 0 = foul votes)
    int *votes = (int *)calloc(candidates + 1, sizeof(int));

    // Dynamic allocation for candidate names
    char **names = (char **)calloc(candidates, sizeof(char *));
    for (int i = 0; i < candidates; i++) {
        names[i] = (char *)calloc(50, sizeof(char)); // max name length = 49
    }

    // Input candidate names
    printf("Enter names of candidates:\n");
    for (int i = 0; i < candidates; i++) {
        printf("Candidate %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // Voting process
    printf("\nPress Enter to start voting...\n");
    getchar(); // consume newline
    getchar(); // wait for faculty to press Enter

    for (int i = 0; i < students; i++) {
        int choice;
        printf("\nStudent %d, enter candidate number (1-%d): ", i + 1, candidates);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= candidates) {
            votes[choice]++; // valid vote
            printf("Vote recorded for %s ✅\n", names[choice - 1]);
        } else {
            votes[0]++; // foul vote
            printf("Invalid vote ❌ (counted as foul)\n");
        }
    }

    // Display results
    printf("\n=== Election Results ===\n");
    for (int i = 1; i <= candidates; i++) {
        printf("%s received %d votes\n", names[i - 1], votes[i]);
    }
    printf("Foul votes: %d\n", votes[0]);

    // Find winner using recursion
    int winnerIndex = findWinner(votes, 1, candidates, 1);
    printf("\nWinner: %s 🎉 with %d votes!\n", names[winnerIndex - 1], votes[winnerIndex]);

    // Free allocated memory
    for (int i = 0; i < candidates; i++) {
        free(names[i]);
    }
    free(names);
    free(votes);

    return 0;
}
