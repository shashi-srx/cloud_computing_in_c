#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


void displayInputs(int sh[][100], int nt, int nv) {
    printf("\n");
    for (int i = 0; i < nt; i++) printf("   T%d", i + 1); printf("\n");
    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < nt; j++) {
            printf("%5d", sh[i][j]);
        }
        printf("  V%d\n", i + 1);
    }
    printf("\n");
}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void getTranspose(int sh[][100], int nt, int nv, int transpose[][100]) {
    for (int i = 0; i < nt; i++) {
        for (int j = 0; j < nv; j++) {
            transpose[i][j] = sh[j][i];
        }
    }
}

int getTaskIndex(int sh[][100], int nt, int nv) {
    int transpose[100][100];
    getTranspose(sh, nt, nv, transpose);
    int subs[100];
    for (int i = 0; i < nt; i++) {
        int temp[100];
        for (int j = 0; j < nv; j++) {
            temp[j] = transpose[i][j];
        }
        qsort(temp, nv, sizeof(int), compare);
        subs[i] = temp[1] - temp[0];
    }
    int maxIndex = 0;
    for (int i = 1; i < nt; i++) {
        if (subs[i] > subs[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void updateSH(int sh[][100], int nt, int nv, int taskIndex, int vmIndex) {
    int addedTime = sh[vmIndex][taskIndex];
    for (int i = 0; i < nt; i++) sh[vmIndex][i] += addedTime;
    for (int i = 0; i < nv; i++) sh[i][taskIndex] = INT_MAX;
}

int main() {
    int sh[100][100];
    int nt, nv;
    int machines[100] = {0};
    printf("Enter number of tasks: ");
    scanf("%d", &nt);
    printf("Enter number of machines: ");
    scanf("%d", &nv);

    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < nt; j++) {
            int tmp;
            printf("Enter for task %d VM %d: ", j + 1, i + 1);
            scanf("%d", &tmp);
            sh[i][j] = tmp;
        }
    }

    displayInputs(sh, nt, nv);

    for (int i = 0; i < nt; i++) {
        int taskIndex = getTaskIndex(sh, nt, nv);
        int transpose[100][100];
        getTranspose(sh, nt, nv, transpose);
        int vmIndex = 0;
        int minTime = INT_MAX;
        for (int j = 0; j < nv; j++) {
            if (transpose[taskIndex][j] < minTime) {
                minTime = transpose[taskIndex][j];
                vmIndex = j;
            }
        }

        printf("T%d in V%d takes %d time\n", taskIndex + 1, vmIndex + 1, minTime);
        machines[vmIndex] += minTime;

        updateSH(sh, nt, nv, taskIndex, vmIndex);
    }

    int maxTime = 0;
    for (int i = 0; i < nv; i++) {
        if (machines[i] > maxTime) {
            maxTime = machines[i];
        }
    }
    printf("\nTotal time taken: %d\n", maxTime);
    return 0;
}

