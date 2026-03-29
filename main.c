// ============================================
//  main.c — Entry Point
//  Connects all 4 members' work together
// ============================================

#include <stdio.h>
#include "bankers.h"

int main() {
    printf("\n");
    printf("************************************************************\n");
    printf("*     BANKER'S ALGORITHM — CLOUD RESOURCE MANAGER         *\n");
    printf("*   Group: Khushi | Priya | Naitik | Pragdeep             *\n");
    printf("************************************************************\n");

    printf("\n[STEP 1 - KHUSHI] Initializing Cloud System Matrices...\n");
    init_matrices();
    display_matrices();

    printf("\n[STEP 2 - PRIYA] Explaining Safe/Unsafe States...\n");
    explain_safe_unsafe();

    printf("\n[STEP 3 - NAITIK] Checking Initial System Safety...\n");
    int safe_seq[MAX_VM];
    int result = is_safe(safe_seq);
    if (result)
        printf("\nSystem is initially in SAFE STATE.\n");
    else
        printf("\nSystem is initially in UNSAFE S
