#include <stdio.h>
#include <stdlib.h>
#define MEMORY_SIZE 1000

typedef struct {
    int start;
    int size;
    int process_id;
} MemoryBlock;

MemoryBlock memory[MEMORY_SIZE];
int num_processes = 0;

void initializeMemory() {
	int i;
    for (i = 0; i < MEMORY_SIZE; ++i) {
        memory[i].start = -1;
        memory[i].size = -1;
        memory[i].process_id = -1;
    }
}

void allocateMemory(int process_id, int size) {
    // Implementing first-fit algorithm 
    int i;
	for (i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i].size >= size && memory[i].process_id == -1) {
            memory[i].size = size;
            memory[i].process_id = process_id;
            break;
        }
    }
}

void deallocateMemory(int process_id) {
    // Deallocating memory when process completes
    int i;
	for (i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i].process_id == process_id) {
            memory[i].process_id = -1;
            memory[i].size = -1;
            break;
        }
    }
}

void displayMemoryStatus(int time_unit) {
    int total_fragmentation = 0;
    int wasted_memory_blocks = 0;
    int free_block_size = 0;
    int i;
	for (i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i].size == -1) {
            free_block_size++;
        } else {
            if (free_block_size > 0) {
                wasted_memory_blocks++;
                total_fragmentation += free_block_size - 1;
                free_block_size = 0;
            }
        }
    }
    printf("Time Unit: %d\n", time_unit);
    printf("Average Fragmentation: %.2f\n", (float)total_fragmentation / MEMORY_SIZE);
    printf("Number of Wasted Memory Blocks: %d\n", wasted_memory_blocks);
    printf("-------------------------\n");
}

int main() {
    int no_of_times = 5; // Set no of simulation time units
    initializeMemory();
    // Simulation loop
    int time_unit;
	for (time_unit = 1; time_unit <= no_of_times; ++time_unit) {   
        // allocation 
        int process_size = rand() % 200 + 1; //   random number to be set as size (between 1 and 200)
        allocateMemory(num_processes, process_size);
        num_processes++;
        // deallocation 
        if (time_unit % 2 == 0) {
            int process_to_deallocate = rand() % num_processes;
            deallocateMemory(process_to_deallocate);
        }
        displayMemoryStatus(time_unit);
    }
    return 0;
}
