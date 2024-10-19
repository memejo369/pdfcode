#include <stdio.h>
#include <limits.h>

void lfuPageReplacement(int referenceString[], int n, int nf) {
    int frames[nf];
    int counter[nf];
    int pageFaults = 0;

    // Initialize frames and frequency array
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
                counter[j]++;
                break;
            }
        }

        // If page is not found, replace the least frequently used page
        if (!found) {
            int lfuIndex = 0;
            for (int j = 1; j < nf; j++) {  
                if (counter[j] < counter[lfuIndex]) {
                    lfuIndex = j;
                }
            }

            frames[lfuIndex] = referenceString[i];
            counter[lfuIndex] = 1;
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
    int referenceString[] = {3, 4, 5, 4, 3, 4, 7, 2, 4, 5, 6, 7, 2, 4, 6};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int framesCount = 3; // Number of frames

    lfuPageReplacement(referenceString, n, framesCount);

    return 0;
}
