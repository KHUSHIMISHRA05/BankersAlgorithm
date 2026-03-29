// ============================================
//  bankers.h — Shared Header File
//  Sabhi members include karenge yeh file
// ============================================

#ifndef BANKERS_H
#define BANKERS_H

#define MAX_VM        5      // Virtual Machines
#define MAX_RESOURCES 3      // CPU, Memory, Storage

// ---- Global Data (khushi.c mein define hoga) ----
extern int allocation[MAX_VM][MAX_RESOURCES];
extern int maximum[MAX_VM][MAX_RESOURCES];
extern int need[MAX_VM][MAX_RESOURCES];
extern int available[MAX_RESOURCES];
extern char *resource_names[];
extern char *vm_names[];

// ---- Function Declarations ----

// khushi.c
void init_matrices();
void calculate_need();
void display_matrices();

// naitik.c
int is_safe(int safe_seq[]);

// pragdeep.c
int request_resources(int vm_id, int request[]);
void simulate_requests();

// priya.c
void explain_safe_unsafe();
void analyse_reliability();
void discuss_limitations();

#endif
