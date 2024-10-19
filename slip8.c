#include <stdio.h>
#include <stdbool.h>

int findOptimal(int page[], int n, int index, int frame[], int framesCount) {
    int farthest = index, chosen = 0;
    for (int i = 0; i < framesCount; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == page[j]) {
                if (j > farthest) {
                    farthest = j;
                    chosen = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return chosen;
}

void optimalPageReplacement(int page[], int n, int framesCount) {
    int frames[framesCount], page_faults = 0;
    for (int i = 0; i < framesCount; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        bool page_found = false;
        for (int j = 0; j < framesCount; j++)
            if (frames[j] == page[i])
                page_found = true;

        if (!page_found) {
            int p=findOptimal(page, n, i + 1, frames, framesCount);
            frames[p] = page[i];
            page_faults++;
        }

        printf("Memory: ");
        for (int j = 0; j < framesCount; j++)
            printf("%d ", frames[j] != -1 ? frames[j] : -1);
        printf("\n");
    }

    printf("Total number of page faults: %d\n", page_faults);
}

int main() {
    int referenceString[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int framesCount;
    printf("Enter the no of frames : \t");
    scanf("%d",&framesCount);
    optimalPageReplacement(referenceString, n, framesCount);
    return 0;
}
