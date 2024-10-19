#include <stdio.h>

void lruPageReplacement(int referenceString[], int n, int nf) {
    int frames[nf];
    int counter[nf];
    int time = 0;
    int pageFaults = 0;

    // Initialize frames and counter array
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }

    // Process the reference string
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in memory
        for (int j = 0; j < nf; j++) {
            if (frames[j] == referenceString[i]) {
                found = 1;
                counter[j] = ++time;
                break;
            }
        }

        // If page is not found, replace the least recently used page
        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < nf; j++) {
                if (counter[j] < counter[lruIndex]) {
                    lruIndex = j;
                }
            }

            frames[lruIndex] = referenceString[i];
            counter[lruIndex] = ++time;
            pageFaults++;
        }

        // Print current memory state
        printf("Memory: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("E "); // Empty slot
            }
        }
        printf("\n");
    }

    printf("Total number of page faults: %d\n", pageFaults);
}

int main() {
    int referenceString[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int framesCount; // Number of frames
    printf("Enter the no of frames : \t");
    scanf("%d",&framesCount);

    lruPageReplacement(referenceString, n, framesCount);

    return 0;
}
