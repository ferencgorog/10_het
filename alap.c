#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// "gcc alap.c -o alap"-al lefordítjuk
// "sudo cp alap /usr/local/bin/", hogy ne kelljen ./-t használni

// Struktúra a sablonok adatainak tárolására
typedef struct {
    const char *id;
    const char *description;
    const char *filename;
    const char *content;
} Template;

// Templateket itt készítettem el
Template templates[] = {
    {"c",     "C source code", "[main.c]", 
     "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}\n"},
    {"cs",    "C# source code", "[Program.cs]", 
     "using System;\n\nclass Program {\n    static void Main() {\n        Console.WriteLine(\"Hello World!\");\n    }\n}\n"},
    {"flask", "Flask source code", "[app.py]", 
     "from flask import Flask\n\napp = Flask(__name__)\n\n@app.route(\"/\")\ndef hello_world():\n    return \"<p>Hello, World!</p>\"\n\nif __name__ == \"__main__\":\n    app.run(debug=True)\n"},
    {"go",    "Go source code", "[main.go]", 
     "package main\n\nimport \"fmt\"\n\nfunc main() {\n    fmt.Println(\"Hello, World!\")\n}\n"},
    {"java",  "Java source code", "[Main.java]", 
     "public class Main {\n    public static void main(String[] args) {\n        System.out.println(\"Hello, World!\");\n    }\n}\n"},
    {"nuon",  "prepare a virt. env. for Nushell", "[on]", 
     "# Nushell virtual environment setup\n"},
    {"py",    "Python 3 source code", "[main.py]", 
     "def main():\n    print(\"Hello, World!\")\n\nif __name__ == \"__main__\":\n    main()\n"},
    {"rust",  "Rust source code", "[main.rs]", 
     "fn main() {\n    println!(\"Hello, World!\");\n}\n"},
    {"sh",    "Bash source code", "[main.sh]", 
     "#!/bin/bash\n\necho \"Hello, World!\"\n"}
};

int num_templates = sizeof(templates) / sizeof(templates[0]); // Templatek száma

void print_help() {
    printf("Usage: alap <template_id> [option]\n");
    puts("");
    printf("Available options:\n");
    puts("");
    printf("-h, --help       show this help\n");
    printf("--stdout         don't create source file, print result to stdout\n");
    puts("");
    printf("Available templates:\n");
    puts("");
    
    for (int i = 0; i < num_templates; i++) {
        printf("* %-10s - %s %s\n", templates[i].id, templates[i].description, templates[i].filename);
    } // 10 helyet foglaltam le a temolatek neveinek, a minusz jel pedig balra igazítsa a szöveget 
}

Template* find_template(const char *id) {
    for (int i = 0; i < num_templates; i++) {
        if (strcmp(templates[i].id, id) == 0) {
            return &templates[i]; // ha van olyan, amit beírtunk a terminálba, akkor itt vissza adja
        }
    }
    return NULL; // Különben nem ad vissza semmit
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        print_help();
        return 0;
    }

    bool use_stdout = false;
    const char *target_id = NULL; // alapból NULL érték, ha esetleg nem írna be semmit a felhasználó

    for (int i = 1; i < argc; i++) { //végig megyünk a beírt parancssori argumentumokon
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "--stdout") == 0) {
            use_stdout = true;
        } else if (target_id == NULL) {
            target_id = argv[i];
        }
    }

    if (target_id != NULL) {
        Template *tmpl = find_template(target_id);
        
        if (tmpl == NULL) {
            fprintf(stderr, "Hiba: Ismeretlen sablon '%s'.\n", target_id);
            return 1;
        }

        char filename[256];
        int len = strlen(tmpl->filename);
        strncpy(filename, tmpl->filename + 1, len - 2); //  itt levágjuk a kapcsos zárójeleket
        filename[len - 2] = '\0';

        if (use_stdout) {
            printf("%s", tmpl->content);
        } else {
            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                fprintf(stderr, "Hiba a fajl letrehozasakor");
                return 1;
            }
            fputs(tmpl->content, file);
            fclose(file);
            printf("Letrehozva: %s\n", filename);
        }
    } else {
         print_help();
    }

    return 0;
}