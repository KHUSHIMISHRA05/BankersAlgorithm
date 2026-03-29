// ============================================
//  khushi.c — Task (a)
//  Allocation, Maximum, Need, Available Matrix
//  MEMBER: KHUSHI
// ============================================

#include <stdio.h>
#include <string.h>
#include "bankers.h"

// Resource and VM names
char *resource_names[] = {"CPU", "Memory", "Storage"};
char *vm_names[]       = {"VM0", "VM1", "VM2", "VM3", "VM4"};

// ---- Global Matrix Definitions ----
int allocation[MAX_VM][MAX_RESOURCES];
int maximum[MAX_VM][MAX_RESOURCES];
int need[MAX_VM][MAX_RESOURCES];
int available[MAX_RESOURCES];

// ============================================
//  STEP 1: Initialize all matrices with data
// ============================================
void init_matrices() {
    // --- Allocation Matrix ---
    // How many resources each VM currently holds
    int alloc_data[MAX_VM][MAX_RESOURCES] = {
        {0, 1, 0},   // VM0
        {2, 0, 0},   // VM1
        {3, 0, 2},   // VM2
        {2, 1, 1},   // VM3
        {0, 0, 2}    // VM4
    };

    // --- Maximum Matrix ---
    // Maximum resources each VM may ever need
    int max_data[MAX_VM][MAX_RESOURCES] = {
        {7, 5, 3},   // VM0
        {3, 2, 2},   // VM1
        {9, 0, 2},   // VM2
        {2, 2, 2},   // VM3
        {4, 3, 3}    // VM4
    };

    // --- Available Resources ---
    int avail_data[MAX_RESOURCES] = {3, 3, 2};

    // Copy into global arrays
    for (int i = 0; i < MAX_VM; i++)
        for (int j = 0; j < MAX_RESOURCES; j++) {
            allocation[i][j] = alloc_data[i][j];
            maximum[i][j]    = max_data[i][j];
        }

    for (int j = 0; j < MAX_RESOURCES; j++)
        available[j] = avail_data[j];

    // Calculate Need matrix
    calculate_need();

    printf("\n[Khushi] Matrices initialized successfully!\n");
}

// ============================================
//  STEP 2: Calculate Need = Maximum - Allocation
// ============================================
void calculate_need() {
    for (int i = 0; i < MAX_VM; i++)
        for (int j = 0; j < MAX_RESOURCES; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

// ============================================
//  STEP 3: Display all matrices nicely
// ============================================
void display_matrices() {
    printf("\n");
    printf("============================================================\n");
    printf("          CLOUD SYSTEM — RESOURCE STATE\n");
    printf("============================================================\n");

    // Header
    printf("\n%-6s | %-15s | %-15s | %-15s\n",
           "VM", "Allocation", "Maximum", "Need");
    printf("%-6s | %-5s %-5s %-5s | %-5s %-5s %-5s | %-5s %-5s %-5s\n",
           "", "CPU", "Mem", "Stor",
               "CPU", "Mem", "Stor",
               "CPU", "Mem", "Stor");
    printf("-------+------------------+-----------------+-----------------\n");

    for (int i = 0; i < MAX_VM; i++) {
        printf("%-6s | %-5d %-5d %-5d | %-5d %-5d %-5d | %-5d %-5d %-5d\n",
               vm_names[i],
               allocation[i][0], allocation[i][1], allocation[i][2],
               maximum[i][0],    maximum[i][1],    maximum[i][2],
               need[i][0],       need[i][1],       need[i][2]);
    }

    printf("\nAvailable Resources:  CPU=%-3d  Memory=%-3d  Storage=%-3d\n",
           available[0], available[1], available[2]);
    printf("============================================================\n");
}
