#include <stdio.h>

#define MAX_LENGTH 255

int main() {
    FILE *fp = NULL;
    fp = fopen("test.txt", "r");

    if (fp == NULL) {
        return -1;
    }

    char temp_line[MAX_LENGTH];
    while (!feof(fp)) {
        fgets(temp_line, MAX_LENGTH, fp);
        printf("%s\n", temp_line);
    }

    /*teststst
     */
    //test
    rewind(fp);

    while (!feof(fp)) {
        fgets(temp_line, MAX_LENGTH, fp);
        printf("%s\n", temp_line);
    }

    fclose(fp);

    return 0;
}