// ============================================
//  priya.c — Task (b) + (f) + (g)
//  Theory: Safe/Unsafe States, Reliability,
//          Practical Limitations
//  MEMBER: PRIYA
// ============================================

#include <stdio.h>
#include "bankers.h"

void explain_safe_unsafe() {
    printf("\n============================================================\n");
    printf("     SAFE vs UNSAFE STATES — Explained by Priya\n");
    printf("============================================================\n");

    printf("\n>> SAFE STATE:\n");
    printf("   A system is in SAFE STATE if there exists at least one\n");
    printf("   safe sequence where all VMs can complete without deadlock.\n");

    printf("\n>> UNSAFE STATE:\n");
    printf("   No safe sequence exists. Deadlock MAY occur.\n");
    printf("   Banker's Algorithm always keeps system in SAFE state.\n");

    printf("\n>> KEY RULE:\n");
    printf("   Safe State   => No Deadlock (guaranteed)\n");
    printf("   Unsafe State => Deadlock POSSIBLE (not certain)\n");
    printf("   Deadlock     => Always Unsafe State\n");

    printf("\n>> In Cloud Computing:\n");
    printf("   Safe   = All VMs can eventually get their resources\n");
    printf("   Unsafe = Some VMs may wait forever (service disruption)\n");
    printf("============================================================\n");
}

void analyse_reliability() {
    printf("\n============================================================\n");
    printf("   RELIABILITY & AVAILABILITY ANALYSIS — Priya\n");
    printf("============================================================\n");

    printf("\n1. IMPROVED RELIABILITY:\n");
    printf("   - Resources given only when system stays safe.\n");
    printf("   - Prevents circular wait — major cause of system crash.\n");
    printf("   - Virtual machines do not starve indefinitely.\n");

    printf("\n2. IMPROVED AVAILABILITY:\n");
    printf("   - Cloud services stay running without manual intervention.\n");
    printf("   - No need to restart VMs due to deadlock.\n");
    printf("   - SLA (Service Level Agreements) can be maintained.\n");

    printf("\n3. COMPARISON:\n");
    printf("   Without Banker's   | With Banker's Algorithm\n");
    printf("   -------------------|--------------------------\n");
    printf("   Deadlock possible  | Deadlock avoided\n");
    printf("   Manual recovery    | Automatic prevention\n");
    printf("   Service downtime   | Continuous availability\n");
    printf("============================================================\n");
}

void discuss_limitations() {
    printf("\n============================================================\n");
    printf("   PRACTICAL LIMITATIONS OF BANKER'S ALGORITHM — Priya\n");
    printf("============================================================\n");

    printf("\n1. FIXED NUMBER OF PROCESSES:\n");
    printf("   Real cloud VMs are created/destroyed dynamically.\n");

    printf("\n2. MAXIMUM DECLARED IN ADVANCE:\n");
    printf("   VMs must declare max resources before starting.\n");
    printf("   In practice, workloads are unpredictable.\n");

    printf("\n3. PERFORMANCE OVERHEAD:\n");
    printf("   Safety check runs on EVERY request.\n");
    printf("   With 1000s of VMs, this becomes very slow.\n");

    printf("\n4. RESOURCE TYPES:\n");
    printf("   Cloud has GPU, network bandwidth too.\n");
    printf("   Banker's handles limited resource types only.\n");

    printf("\n>> CONCLUSION:\n");
    printf("   Banker's Algorithm needs modifications for\n");
    printf("   real-world large-scale cloud systems.\n");
    printf("============================================================\n");
}
