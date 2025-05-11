#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_LINE 1024

char *read_hash_from_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open hash file");
        return NULL;
    }

    static char hash[MAX_LINE];
    if (fgets(hash, sizeof(hash), file) == NULL) {
        perror("Failed to read hash");
        fclose(file);
        return NULL;
    }

    fclose(file);
    // Remove newline if present
    hash[strcspn(hash, "\n")] = 0;
    return hash;
}

int crack_password(const char *target_hash, const char *wordlist_path) {
    FILE *wordlist = fopen(wordlist_path, "r");
    if (!wordlist) {
        perror("Failed to open wordlist file");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), wordlist)) {
        line[strcspn(line, "\n")] = 0; // Remove newline

        struct crypt_data data;
        data.initialized = 0;

        char *hashed = crypt_r(line, target_hash, &data);
        if (hashed && strcmp(hashed, target_hash) == 0) {
            printf("Password found: %s\n", line);
            fclose(wordlist);
            return 0;
        }
    }

    printf("Password not found.\n");
    fclose(wordlist);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hash_file> <wordlist_file>\n", argv[0]);
        return 1;
    }

    char *target_hash = read_hash_from_file(argv[1]);
    if (!target_hash) {
        return 1;
    }

    return crack_password(target_hash, argv[2]);
}
