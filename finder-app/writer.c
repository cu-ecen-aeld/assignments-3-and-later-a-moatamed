#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "ERROR: Two arguments are needed.");
        printf("Two arguments are needed.\n");
        return 1;
    }

    // Assign command line arguments to variables
    char *writestr = argv[2];
    char *writefile = argv[1];

    // Open syslog using log_user facility
    openlog("writer", LOG_CONS , LOG_USER);

    // Open file to write or create it if it doesn't exist.
    int fd = open(writefile, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd == -1) {
        syslog(LOG_ERR, "ERROR: Can't open or create the file: %s", writefile);
        printf("Can't open or create the file.\n");
        closelog();
        return 1;
    }

    // Write the string into the file
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);
    ssize_t nr = write(fd, writestr, strlen(writestr));

    // Check if the string has been written properly
    if (nr == -1) {
        syslog(LOG_ERR, "ERROR: Can't write the string into the file: %s", writefile);
        printf("Can't write the string into the file.\n");
        closelog();
        close(fd);
        return 1;
    }

    // Check for partial writing
    if (nr < strlen(writestr)) {
        syslog(LOG_ERR, "ERROR: Couldn't write the whole string to the file: %s", writefile);
        printf("Couldn't write the whole string.\n");
    }

    // Close the log and the file
    closelog();
    close(fd);

    return 0;
}

