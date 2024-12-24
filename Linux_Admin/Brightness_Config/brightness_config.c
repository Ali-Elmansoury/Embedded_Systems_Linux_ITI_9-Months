#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // File path to the brightness control
    const char *brightness_file = "/sys/class/backlight/intel_backlight/brightness";
    
    // Open the brightness file
    int fd = open(brightness_file, O_RDWR);
    if (fd == -1) {
        perror("Error opening brightness file");
        return 1;
    }

    // Check if argument is passed
    if (argc > 1) {
        // Map percentage arguments to brightness values
        if (strcmp(argv[1], "0%") == 0) {
            dprintf(fd, "%s", "1200");
            printf("Brightness set to 0%% → 1200\n");
        } else if (strcmp(argv[1], "25%") == 0) {
            dprintf(fd, "%s", "30900");
            printf("Brightness set to 25%% → 30900\n");
        } else if (strcmp(argv[1], "50%") == 0) {
            dprintf(fd, "%s", "60600");
            printf("Brightness set to 50%% → 60600\n");
        } else if (strcmp(argv[1], "75%") == 0) {
            dprintf(fd, "%s", "90300");
            printf("Brightness set to 75%% → 90300\n");
        } else if (strcmp(argv[1], "100%") == 0) {
            dprintf(fd, "%s", "120000");
            printf("Brightness set to 100%% → 120000\n");
        } else {
            printf("Invalid argument. Use 0%%, 25%%, 50%%, 75%%, or 100%% to set brightness.\n");
        }
    } else {
        printf("No argument provided. Usage: sudo ./bc <0|25|50|75|100>\n");
    }

    // Close the file descriptor
    close(fd);
    return 0;
}

