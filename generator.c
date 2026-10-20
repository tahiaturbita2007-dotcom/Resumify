#include "resumify.h"

void generateHTML(PersonalInfo *p, 
                  Education edu[], int edu_count, 
                  Experience exp[], int exp_count, 
                  Certification certs[], int cert_count,
                  Extracurricular extra[], int extra_count,
                  char languages[][MAX_STR], int lang_count,
                  char skills[][MAX_STR], int skill_count) {

    FILE *file = fopen("cv.html", "w");
    if (!file) {
        printf("Error: Could not create output HTML file.\n");
        return;
    }

    fprintf(file, "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n");
    fprintf(file, "<meta charset=\"UTF-8\">\n");
    fprintf(file, "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(file, "<title>%s - Resume</title>\n", p->name);
    
    // Minimalist ATS-Friendly Styling
    fprintf(file, "<style>\n");
    fprintf(file, "  body { font-family: 'Segoe UI', Arial, sans-serif; margin: 40px auto; max-width: 800px; color: #222; line-height: 1.5; padding: 0 20px; }\n");
    fprintf(file, "  h1 { font-size: 28px; text-transform: uppercase; margin-bottom: 5px; letter-spacing: 1px; }\n");
    fprintf(file, "  .contact-info { font-size: 14px; color: #444; margin-bottom: 20px; }\n");
    fprintf(file, "  .contact-info span:not(:last-child)::after { content: ' • '; margin: 0 5px; }\n");
    fprintf(file, "  a { color: #222; text-decoration: none; border-bottom: 1px dotted #555; }\n");
    fprintf(file, "  h2 { font-size: 16px; text-transform: uppercase; border-bottom: 1px solid #222; padding-bottom: 3px; margin-top: 25px; margin-bottom: 12px; letter-spacing: 0.5px; }\n");
    fprintf(file, "  .section-item { margin-bottom: 12px; }\n");
    fprintf(file, "  .item-header { display: flex; justify-content: space-between; font-weight: bold; font-size: 15px; }\n");
    fprintf(file, "  .item-sub { font-style: italic; color: #555; font-size: 14px; }\n");
    fprintf(file, "  p { margin: 4px 0; font-size: 14px; }\n");
    fprintf(file, "  ul { margin: 5px 0; padding-left: 20px; font-size: 14px; }\n");
    fprintf(file, "  li { margin-bottom: 3px; }\n");
    fprintf(file, "  @media print { body { margin: 0; padding: 0; } }\n");
    fprintf(file, "</style>\n</head>\n<body>\n");

    // Dynamic Contact Info Header
    fprintf(file, "  <h1>%s</h1>\n", p->name);
    fprintf(file, "  <div class=\"contact-info\">\n");
    if (strlen(p->location) > 0) fprintf(file, "    <span>%s</span>\n", p->location);
    if (strlen(p->email) > 0) fprintf(file, "    <span><a href=\"mailto:%s\">%s</a></span>\n", p->email, p->email);
    if (strlen(p->phone) > 0) fprintf(file, "    <span>%s</span>\n", p->phone);
    if (strlen(p->linkedin) > 0) fprintf(file, "    <span><a href=\"%s\" target=\"_blank\">LinkedIn</a></span>\n", p->linkedin);
    if (strlen(p->github) > 0) fprintf(file, "    <span><a href=\"%s\" target=\"_blank\">GitHub</a></span>\n", p->github);
    if (strlen(p->website) > 0) fprintf(file, "    <span><a href=\"%s\" target=\"_blank\">Portfolio/Website</a></span>\n", p->website);
    fprintf(file, "  </div>\n");

    // Summary
    if (strlen(p->summary) > 0) {
        fprintf(file, "  <h2>Professional Summary</h2>\n");
        fprintf(file, "  <p>%s</p>\n", p->summary);
    }

    // Education
    if (edu_count > 0) {
        fprintf(file, "  <h2>Education</h2>\n");
        for (int i = 0; i < edu_count; i++) {
            fprintf(file, "  <div class=\"section-item\">\n");
            fprintf(file, "    <div class=\"item-header\"><span>%s</span><span>%s</span></div>\n", edu[i].institution, edu[i].duration);
            fprintf(file, "    <div class=\"item-sub\">%s %s</div>\n", edu[i].degree, strlen(edu[i].gpa) > 0 ? edu[i].gpa : "");
            fprintf(file, "  </div>\n");
        }
    }

    // Work Experience / Professional Projects
    if (exp_count > 0) {
        fprintf(file, "  <h2>Work Experience & Projects</h2>\n");
        for (int i = 0; i < exp_count; i++) {
            fprintf(file, "  <div class=\"section-item\">\n");
            fprintf(file, "    <div class=\"item-header\"><span>%s</span><span>%s</span></div>\n", exp[i].title, exp[i].duration);
            fprintf(file, "    <div class=\"item-sub\">%s</div>\n", exp[i].organization);
            if (strlen(exp[i].description) > 0) {
                fprintf(file, "    <p>%s</p>\n", exp[i].description);
            }
            fprintf(file, "  </div>\n");
        }
    }

    // Certifications & Honors
    if (cert_count > 0) {
        fprintf(file, "  <h2>Certifications & Honors</h2>\n");
        for (int i = 0; i < cert_count; i++) {
            fprintf(file, "  <div class=\"section-item\">\n");
            fprintf(file, "    <div class=\"item-header\"><span>%s</span><span>%s</span></div>\n", certs[i].title, certs[i].date);
            fprintf(file, "    <div class=\"item-sub\">%s</div>\n", certs[i].issuer);
            fprintf(file, "  </div>\n");
        }
    }

    // Leadership & Extracurricular Activities
    if (extra_count > 0) {
        fprintf(file, "  <h2>Leadership & Activities</h2>\n");
        for (int i = 0; i < extra_count; i++) {
            fprintf(file, "  <div class=\"section-item\">\n");
            fprintf(file, "    <div class=\"item-header\"><span>%s</span><span>%s</span></div>\n", extra[i].role, extra[i].duration);
            fprintf(file, "    <div class=\"item-sub\">%s</div>\n", extra[i].organization);
            if (strlen(extra[i].description) > 0) {
                fprintf(file, "    <p>%s</p>\n", extra[i].description);
            }
            fprintf(file, "  </div>\n");
        }
    }

    // Skills
    if (skill_count > 0) {
        fprintf(file, "  <h2>Skills & Competencies</h2>\n");
        fprintf(file, "  <ul>\n");
        for (int i = 0; i < skill_count; i++) {
            fprintf(file, "    <li>%s</li>\n", skills[i]);
        }
        fprintf(file, "  </ul>\n");
    }

    // Languages
    if (lang_count > 0) {
        fprintf(file, "  <h2>Languages</h2>\n");
        fprintf(file, "  <ul>\n");
        for (int i = 0; i < lang_count; i++) {
            fprintf(file, "    <li>%s</li>\n", languages[i]);
        }
        fprintf(file, "  </ul>\n");
    }

    fprintf(file, "</body>\n</html>\n");
    fclose(file);

    printf("\n[Success] Universal CV successfully generated as 'cv.html'!\n");

    // Auto-launch browser
    #ifdef _WIN32
        system("start cv.html");
    #elif __APPLE__
        system("open cv.html");
    #else
        system("xdg-open cv.html");
    #endif
}