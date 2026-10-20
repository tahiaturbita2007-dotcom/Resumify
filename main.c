#include "resumify.h"

// Helper function to safely read string inputs from the console
void read_input(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int main() {
    PersonalInfo p = {0};
    Education edu[MAX_ENTRIES];
    Experience exp[MAX_ENTRIES];
    Certification certs[MAX_ENTRIES];
    Extracurricular extra[MAX_ENTRIES];
    char skills[MAX_ENTRIES][MAX_STR];
    char languages[MAX_ENTRIES][MAX_STR];

    int edu_count = 0, exp_count = 0, cert_count = 0;
    int extra_count = 0, skill_count = 0, lang_count = 0;
    char choice[8];

    printf("===========================================================\n");
    printf(" R E S U M I F Y - An HTML based Professional CV generator\n");
    printf("===========================================================\n\n");

    // 1. Personal Information
    printf("--- Personal Information ---\n");
    read_input("Full Name: ", p.name, MAX_STR);
    read_input("Location (e.g., City, Country): ", p.location, MAX_STR);
    read_input("Email Address: ", p.email, MAX_STR);
    read_input("Phone Number: ", p.phone, MAX_STR);

    // Dynamic LinkedIn Prompt
    read_input("Include LinkedIn Profile link? (y/n): ", choice, sizeof(choice));
    if (choice[0] == 'y' || choice[0] == 'Y') {
        read_input("LinkedIn URL: ", p.linkedin, MAX_STR);
    }

    // Dynamic GitHub Prompt
    read_input("Include GitHub Profile link? (y/n): ", choice, sizeof(choice));
    if (choice[0] == 'y' || choice[0] == 'Y') {
        read_input("GitHub URL: ", p.github, MAX_STR);
    }

    // Dynamic Personal Website / WordPress / Portfolio Prompt
    read_input("Include Personal Website or Portfolio URL? (y/n): ", choice, sizeof(choice));
    if (choice[0] == 'y' || choice[0] == 'Y') {
        read_input("Website / Portfolio URL: ", p.website, MAX_STR);
    }

    read_input("Professional Summary / About Me: ", p.summary, sizeof(p.summary));

    // 2. Education
    printf("\n--- Education (Max %d) ---\n", MAX_ENTRIES);
    while (edu_count < MAX_ENTRIES) {
        printf("\n[Education Entry %d]\n", edu_count + 1);
        read_input("Institution Name: ", edu[edu_count].institution, MAX_STR);
        read_input("Degree / Qualification: ", edu[edu_count].degree, MAX_STR);
        read_input("Duration (e.g., 2021 - 2025): ", edu[edu_count].duration, 64);
        read_input("Grade / Result (optional): ", edu[edu_count].gpa, 32);
        
        edu_count++;
        if (edu_count >= MAX_ENTRIES) break;

        read_input("Add another education entry? (y/n): ", choice, sizeof(choice));
        if (choice[0] != 'y' && choice[0] != 'Y') break;
    }

    // 3. Work Experience & Projects
    printf("\n--- Work Experience / Projects (Max %d) ---\n", MAX_ENTRIES);
    while (exp_count < MAX_ENTRIES) {
        printf("\n[Experience Entry %d]\n", exp_count + 1);
        read_input("Job Title / Position: ", exp[exp_count].title, MAX_STR);
        read_input("Company / Organization / Client: ", exp[exp_count].organization, MAX_STR);
        read_input("Duration: ", exp[exp_count].duration, 64);
        read_input("Key Responsibilities / Achievements: ", exp[exp_count].description, 512);
        
        exp_count++;
        if (exp_count >= MAX_ENTRIES) break;

        read_input("Add another experience entry? (y/n): ", choice, sizeof(choice));
        if (choice[0] != 'y' && choice[0] != 'Y') break;
    }

    // 4. Certifications & Honors
    printf("\n--- Certifications & Honors (Max %d) ---\n", MAX_ENTRIES);
    while (cert_count < MAX_ENTRIES) {
        printf("\n[Certification Entry %d]\n", cert_count + 1);
        read_input("Title / Award: ", certs[cert_count].title, MAX_STR);
        read_input("Issuing Body / Organization: ", certs[cert_count].issuer, MAX_STR);
        read_input("Date Earned: ", certs[cert_count].date, 32);
        
        cert_count++;
        if (cert_count >= MAX_ENTRIES) break;

        read_input("Add another certification? (y/n): ", choice, sizeof(choice));
        if (choice[0] != 'y' && choice[0] != 'Y') break;
    }

    // 5. Leadership & Extracurricular Activities
    printf("\n--- Leadership & Activities (Max %d) ---\n", MAX_ENTRIES);
    while (extra_count < MAX_ENTRIES) {
        printf("\n[Activity Entry %d]\n", extra_count + 1);
        read_input("Role / Title: ", extra[extra_count].role, MAX_STR);
        read_input("Organization / Club: ", extra[extra_count].organization, MAX_STR);
        read_input("Duration: ", extra[extra_count].duration, 64);
        read_input("Description (optional): ", extra[extra_count].description, 256);
        
        extra_count++;
        if (extra_count >= MAX_ENTRIES) break;

        read_input("Add another activity? (y/n): ", choice, sizeof(choice));
        if (choice[0] != 'y' && choice[0] != 'Y') break;
    }

    // 6. Skills & Competencies
    printf("\n--- Skills & Competencies (Max %d) ---\n", MAX_ENTRIES);
    while (skill_count < MAX_ENTRIES) {
        printf("Skill Entry %d: ", skill_count + 1);
        read_input("", skills[skill_count], MAX_STR);
        
        skill_count++;
        if (skill_count >= MAX_ENTRIES) break;

        read_input("Add another skill category? (y/n): ", choice, sizeof(choice));
        if (choice[0] != 'y' && choice[0] != 'Y') break;
    }

    // 7. Languages Spoken
    printf("\n--- Languages Spoken (Max %d) ---\n", MAX_ENTRIES);
    while (lang_count < MAX_ENTRIES) {
        printf("Language Entry %d: ", lang_count + 1);
        read_input("", languages[lang_count], MAX_STR);
        
        lang_count++;
        if (lang_count >= MAX_ENTRIES) break;

        read_input("Add another language? (y/n): ", choice, sizeof(choice));
        if (choice[0] != 'y' && choice[0] != 'Y') break;
    }

    // Generate output HTML and launch browser
    generateHTML(&p, edu, edu_count, exp, exp_count, certs, cert_count, extra, extra_count, languages, lang_count, skills, skill_count);

    return 0;
}