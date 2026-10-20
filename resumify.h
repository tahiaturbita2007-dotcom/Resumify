#ifndef RESUMIFY_H
#define RESUMIFY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256
#define MAX_ENTRIES 10

// Personal Info
typedef struct {
    char name[MAX_STR];
    char location[MAX_STR];
    char email[MAX_STR];
    char phone[MAX_STR];
    char linkedin[MAX_STR];
    char github[MAX_STR];    // Optional
    char website[MAX_STR];   // Optional (WordPress, Portfolio, etc.)
    char summary[1024];
} PersonalInfo;

// Education
typedef struct {
    char degree[MAX_STR];
    char institution[MAX_STR];
    char duration[64];
    char gpa[32];
} Education;

// Experience / Projects
typedef struct {
    char title[MAX_STR];
    char organization[MAX_STR];
    char duration[64];
    char description[512];
} Experience;

// Certifications & Awards
typedef struct {
    char title[MAX_STR];
    char issuer[MAX_STR];
    char date[32];
} Certification;

// Extracurricular / Leadership
typedef struct {
    char role[MAX_STR];
    char organization[MAX_STR];
    char duration[64];
    char description[256];
} Extracurricular;

// Function Prototypes
void read_input(const char *prompt, char *buffer, size_t size);

void generateHTML(PersonalInfo *p, 
                  Education edu[], int edu_count, 
                  Experience exp[], int exp_count, 
                  Certification certs[], int cert_count,
                  Extracurricular extra[], int extra_count,
                  char languages[][MAX_STR], int lang_count,
                  char skills[][MAX_STR], int skill_count);

#endif