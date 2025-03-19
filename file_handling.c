#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char fileName[100], data[1000];

    printf("Enter the file name: ");
    scanf("%s", fileName);

    // Writing data to the file
    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error: Cannot open file %s for writing.\n", fileName);
        exit(1);
    }
    printf("Enter data to write to the file: ");
    getchar(); // To consume the newline character left by scanf
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written successfully.\n\n");

    // Reading data from the file
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s for reading.\n", fileName);
        exit(1);
    }
    printf("Contents of the file:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }
    fclose(file);
    printf("\n\n");

    // Appending data to the file
    file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Error: Cannot open file %s for appending.\n", fileName);
        exit(1);
    }
    printf("Enter data to append to the file: ");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data appended successfully.\n");

    return 0;
}
