#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 100 // Total memory size

typedef struct {
    int id;
    int size;
    bool allocated;
} Block;

Block memory[MEMORY_SIZE];

// Function prototypes
void initializeMemory();
void displayMemory();
int bestFit(int size);
int worstFit(int size);
int nextFit(int size, int *lastIndex);
int mostFit(int size);

int main() {
    initializeMemory();

    int choice, size, blockId;
    bool exitProgram = false;
    int lastIndex = 0;

    while (!exitProgram) {
        printf("\n--- Memory Allocation Menu ---\n");
        printf("1. Best Fit\n");
        printf("2. Worst Fit\n");
        printf("3. Next Fit\n");
        printf("4. Most Fit\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the block to allocate: ");
                scanf("%d", &size);
                blockId = bestFit(size);
                if (blockId != -1)
                    printf("Block allocated successfully. Block ID: %d\n", blockId);
                else
                    printf("Not enough memory available.\n");
                break;

            case 2:
                printf("Enter the size of the block to allocate: ");
                scanf("%d", &size);
                blockId = worstFit(size);
                if (blockId != -1)
                    printf("Block allocated successfully. Block ID: %d\n", blockId);
                else
                    printf("Not enough memory available.\n");
                break;

            case 3:
                printf("Enter the size of the block to allocate: ");
                scanf("%d", &size);
                blockId = nextFit(size, &lastIndex);
                if (blockId != -1) {
                    printf("Block allocated successfully. Block ID: %d\n", blockId);
                } else {
                    printf("Not enough memory available.\n");
                    lastIndex = 0;
                }
                break;

            case 4:
                printf("Enter the size of the block to allocate: ");
                scanf("%d", &size);
                blockId = mostFit(size);
                if (blockId != -1)
                    printf("Block allocated successfully. Block ID: %d\n", blockId);
                else
                    printf("Not enough memory available.\n");
                break;

            case 5:
                exitProgram = true;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        displayMemory();
    }

    return 0;
}

void initializeMemory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i].id = i;
        memory[i].size = MEMORY_SIZE;
        memory[i].allocated = false;
    }
}

void displayMemory() {
    printf("\n--- Memory Status ---\n");
    printf("ID\tSize\tAllocated\n");

    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%d\t%d\t", memory[i].id, memory[i].size);
        if (memory[i].allocated)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int bestFit(int size) {
    int bestFitId = -1;
    int minFreeSize = MEMORY_SIZE + 1;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size < minFreeSize) {
            bestFitId = i;
            minFreeSize = memory[i].size;
        }
    }

    if (bestFitId != -1) {
        // Split the block if there is remaining free space
        int remainingSize = memory[bestFitId].size - size;
        if (remainingSize > 0) {
            memory[bestFitId].size = size;
            int newId = bestFitId + 1;
            for (int i = MEMORY_SIZE - 1; i > newId; i--) {
                memory[i] = memory[i - 1];
                memory[i].id = i;
            }
            memory[newId].id = newId;
            memory[newId].size = remainingSize;
            memory[newId].allocated = false;
        }

        memory[bestFitId].allocated = true;
        return memory[bestFitId].id;
    }

    return -1;
}

int worstFit(int size) {
    int worstFitId = -1;
    int maxFreeSize = -1;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size > maxFreeSize) {
            worstFitId = i;
            maxFreeSize = memory[i].size;
        }
    }

    if (worstFitId != -1) {
        // Split the block if there is remaining free space
        int remainingSize = memory[worstFitId].size - size;
        if (remainingSize > 0) {
            memory[worstFitId].size = size;
            int newId = worstFitId + 1;
            for (int i = MEMORY_SIZE - 1; i > newId; i--) {
                memory[i] = memory[i - 1];
                memory[i].id = i;
            }
            memory[newId].id = newId;
            memory[newId].size = remainingSize;
            memory[newId].allocated = false;
        }

        memory[worstFitId].allocated = true;
        return memory[worstFitId].id;
    }

    return -1;
}

int nextFit(int size, int *lastIndex) {
    int startIndex = *lastIndex;

    do {
        if (!memory[startIndex].allocated && memory[startIndex].size >= size) {
            // Split the block if there is remaining free space
            int remainingSize = memory[startIndex].size - size;
            if (remainingSize > 0) {
                memory[startIndex].size = size;
                int newId = startIndex + 1;
                for (int i = MEMORY_SIZE - 1; i > newId; i--) {
                    memory[i] = memory[i - 1];
                    memory[i].id = i;
                }
                memory[newId].id = newId;
                memory[newId].size = remainingSize;
                memory[newId].allocated = false;
            }

            memory[startIndex].allocated = true;
            *lastIndex = startIndex;
            return memory[startIndex].id;
        }

        startIndex = (startIndex + 1) % MEMORY_SIZE;
    } while (startIndex != *lastIndex);

    return -1;
}

int mostFit(int size) {
    int mostFitId = -1;
    int minFreeSize = MEMORY_SIZE + 1;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= size && memory[i].size < minFreeSize) {
            mostFitId = i;
            minFreeSize = memory[i].size;
        }
    }

    if (mostFitId != -1) {
        // Split the block if there is remaining free space
        int remainingSize = memory[mostFitId].size - size;
        if (remainingSize > 0) {
            memory[mostFitId].size = size;
            int newId = mostFitId + 1;
            for (int i = MEMORY_SIZE - 1; i > newId; i--) {
                memory[i] = memory[i - 1];
                memory[i].id = i;
            }
            memory[newId].id = newId;
            memory[newId].size = remainingSize;
            memory[newId].allocated = false;
        }

        memory[mostFitId].allocated = true;
        return memory[mostFitId].id;
    }

    return -1;
}
