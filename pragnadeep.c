// ============================================
//  pragnadeep.c — Task (d) + (e)
//  Dynamic Resource Request Simulation
//  MEMBER: PRAGDEEP
// ============================================

#include <stdio.h>
#include "bankers.h"

int request_resources(int vm_id, int request[]) {
    printf("\n------------------------------------------------------------\n");
    printf("[Pragdeep] %s requesting: CPU=%d  Memory=%d  Storage=%d\n",
           vm_names[vm_id], request[0], request[1], request[2]);
    printf("------------------------------------------------------------\n");

    for (int j = 0; j < MAX_RESOURCES; j++) {
        if (request[j] > need[vm_id][j]) {
            printf("DENIED: Request exceeds maximum need for %s!\n",
                   resource_names[j]);
            return 0;
        }
    }
    printf("CHECK 1 PASSED: Request <= Need\n");

    for (int j = 0; j < MAX_RESOURCES; j++) {
        if (request[j] > available[j]) {
            printf("WAITING: %s not available right now.\n",
                   resource_names[j]);
            return 0;
        }
    }
    printf("CHECK 2 PASSED: Request <= Available\n");

    for (int j = 0; j < MAX_RESOURCES; j++) {
        available[j]         -= request[j];
        allocation[vm_id][j] += request[j];
        need[vm_id][j]       -= request[j];
    }
    printf("Tentative allocation done. Checking safety...\n");

    int safe_seq[MAX_VM];
    int safe = is_safe(safe_seq);

    if (safe) {
        printf("\nREQUEST GRANTED: System remains in SAFE state.\n");
        return 1;
    } else {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            available[j]         += request[j];
            allocation[vm_id][j] -= request[j];
            need[vm_id][j]       += request[j];
        }
        printf("\nREQUEST DENIED: Would cause UNSAFE state. Rolled back.\n");
        return 0;
    }
}

void simulate_requests() {
    printf("\n\n============================================================\n");
    printf("        DYNAMIC REQUEST SIMULATION — PRAGDEEP\n");
    printf("============================================================\n");

    int req1[MAX_RESOURCES] = {1, 0, 2};
    request_resources(1, req1);

    int req2[MAX_RESOURCES] = {3, 3, 0};
    request_resources(4, req2);

    int req3[MAX_RESOURCES] = {0, 2, 0};
    request_resources(0, req3);

    printf("\n============================================================\n");
    printf("          SIMULATION COMPLETE\n");
    printf("============================================================\n");
}
