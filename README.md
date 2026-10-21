# RESUMIFY 📄✨

RESUMIFY is a modular C application that generates minimalist, ATS-friendly HTML CVs via interactive console prompts. It collects structured data across education, experience, and skills, outputs a print-ready cv.html with embedded CSS, and automatically launches it in your browser.

![C99 Standard](https://img.shields.io/badge/Standard-C99-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-success.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

---

## 🚀 Key Features

* **Universal & Flexible:** Designed for all professions—software engineers can include GitHub repositories, while designers, writers, and business professionals can selectively include personal portfolios, WordPress blogs, or professional websites.
* **Modular Multi-File Architecture:** Cleanly separated into header definitions (`resumify.h`), HTML/CSS generation engine (`generator.c`), and application control flow (`main.c`).
* **Minimalist & ATS-Friendly:** Renders a clean black-and-white print layout using embedded CSS, avoiding clutter while keeping typography modern and professional.
* **Smart Optional Fields:** Dynamic prompting ensures optional fields (like secondary URLs, GPA, or extracurricular descriptions) are completely omitted if left blank, preventing empty tags or broken links.
* **Instant Browser Preview:** Automatically invokes system commands (`start`, `open`, or `xdg-open`) to display your newly generated `cv.html` file the moment input finishes. From there, press `Ctrl + P` to save as a high-quality PDF.

---

## 📊 Workflow Flowchart

```text
┌─────────────────────────────────────────────────────────┐
│                      START PROGRAM                      │
└────────────────────────────┬────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────┐
│                 1. PERSONAL INFORMATION                 │
│  - Prompts for Name, Location, Email, Phone             │
│  - Optional prompts (y/n) for LinkedIn, GitHub, Website │
│  - Prompts for Professional Summary                     │
└────────────────────────────┬────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────┐
│                2. SECTION DATA COLLECTION               │
│  Loop until user finishes or reaches MAX_ENTRIES (10):  │
│  - Education (Institution, Degree, Duration, GPA)       │
│  - Work / Projects (Title, Company, Duration, Desc)     │
│  - Certifications (Title, Issuer, Date)                 │
│  - Leadership & Activities (Role, Org, Duration, Desc)  │
│  - Skills & Competencies (List items)                   │
│  - Languages Spoken (List items)                        │
└────────────────────────────┬────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────┐
│                 3. HTML & CSS GENERATION                │
│  - Opens file stream for 'cv.html'                      │
│  - Writes HTML5 document structure                      │
│  - Embeds responsive, print-ready CSS inside <style>    │
│  - Dynamically renders populated section structs        │
│  - Omits empty optional fields automatically            │
└────────────────────────────┬────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────┐
│                     4. AUTO-LAUNCH                      │
│  - Closes file stream                                   │
│  - Triggers system command (start / open / xdg-open)    │
│  - Displays success message and opens browser           │
└────────────────────────────┬────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────┐
│                       END PROGRAM                       │
└─────────────────────────────────────────────────────────┘

```

---

## 📂 Project Structure

```text
Resumify/
│
├── resumify.h       # Struct definitions, macro constants, and function prototypes
├── generator.c      # HTML/CSS template engine and file writing logic
└── main.c           # Console input loops, data collection, and program control

```

---

## 🛠️ Getting Started & Compilation

### Prerequisites

* A C compiler supporting the C99 standard (e.g., **GCC** via MinGW on Windows, Clang on macOS, or GCC on Linux).

### Compilation & Execution

Open your terminal inside the project directory and run the following commands:

**1. Compile the multi-file source code:**

```bash
gcc main.c generator.c -o resumify

```

**2. Run the executable:**

* **Windows (PowerShell / Command Prompt):**
```powershell
.\resumify.exe

```


* **macOS / Linux:**
```bash
./resumify

```



---

## 📝 How to Use

1. Launch the executable.
2. Follow the interactive console prompts to enter your personal information, education history, work experience/projects, certifications, leadership activities, technical skills, and languages spoken.
3. Answer `y/n` when prompted for optional professional links (LinkedIn, GitHub, Portfolio website).
4. Once completed, `cv.html` will be generated in your project folder and **automatically open in your web browser** for immediate review!

---

---

## 👤 Author

**Tahiat Tarannum Urbita**

* **GitHub:** [@tahaturbita2007-dotcom](https://github.com/tahiaturbita2007-dotcom)
* **Project Repository:** [RESUMIFY](https://github.com/tahiaturbita2007-dotcom/Resumify)


## 📄 License

This project is open-source and available under the [MIT License](LICENSE).



