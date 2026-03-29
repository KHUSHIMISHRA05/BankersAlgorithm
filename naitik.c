// ============================================
//  naitik.c — Task (c) + (e)
//  Banker's Safety Algorithm
//  MEMBER: NAITIK
// ============================================

#include <stdio.h>
#include "bankers.h"

int is_safe(int safe_seq[]) {
    int work[MAX_RESOURCES];
    int finish[MAX_VM];
    int count = 0;

    for (int j = 0; j < MAX_RESOURCES; j++)
        work[j] = available[j];

    for (int i = 0; i < MAX_VM; i++)
        finish[i] = 0;

    printf("\n[Naitik] Running Safety Algorithm...\n");
    printf("Initial Work (Available): CPU=%d  Memory=%d  Storage=%d\n",
           work[0], work[1], work[2]);
    printf("\n%-5s | %-20s | %-20s | %-10s\n",
           "Step", "VM Selected", "Work After", "Finish");
    printf("------+----------------------+----------------------+----------\n");

    int step = 1;
    while (count < MAX_VM) {
        int found = 0;

        for (int i = 0; i < MAX_VM; i++) {
            if (finish[i] == 0) {
                int can_alloc = 1;
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_alloc = 0;
                        break;
                    }
                }

                if (can_alloc) {
                    for (int j = 0; j < MAX_RESOURCES; j++)
                        work[j] += allocation[i][j];

                    finish[i] = 1;
                    safe_seq[count++] = i;
                    found = 1;

                    printf("%-5d | %-20s | CPU=%-3d Mem=%-3d Str=%-3d | DONE\n",
                           step++, vm_names[i],
                           work[0], work[1], work[2]);
                    break;
                }
            }
        }

        if (!found) {
            printf("\n[Naitik] *** UNSAFE STATE DETECTED ***\n");
            printf("No VM can proceed — Deadlock risk!\n");
            return 0;
        }
    }

    printf("\n[Naitik] *** SAFE STATE CONFIRMED ***\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < MAX_VM; i++) {
        printf("%s", vm_names[safe_seq[i]]);
        if (i < MAX_VM - 1) printf(" --> ");
    }
    printf("\n");
    return 1;
}
