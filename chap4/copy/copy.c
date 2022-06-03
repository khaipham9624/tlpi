#include "copy.h"

int main(int argc, char **argv)
{
#define BUFFER_SIZE 128
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = 0;
    ssize_t bytesWritten = 0;

    if (argc != 3 || strcmp(argv[1], "help") == 0)
    {
        usageErr("%s source_file destination_file\n", argv[0]);
    }

    // mo de doc
    int sourcefd = open(argv[1], O_RDONLY);
    if (sourcefd < 1)
    {
        errExit("opening file %s", argv[1]);
    }

    // mo de ghi
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    mode_t modes = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // rw-rw-rw-
    int destfd = open(argv[2], flags, modes);
    if (destfd < 0)
    {
        errExit("opening file %s", argv[2]);
    }

    do
    {
        bytesRead = read(sourcefd, buffer, BUFFER_SIZE);
        if (bytesRead > 0)
        {
            bytesWritten = write(destfd, buffer, bytesRead);
            if (bytesWritten < bytesRead)
            {
                errExit("writing to file %s", argv[2]);
            }
        }
    }
    while(bytesRead > 0);

    if (close(sourcefd) < 0)
    {
        errExit("closing file %s", argv[1]);
    }
    if (close(destfd) < 0)
    {
        errExit("closing file %s", argv[2]);
    }
    exit(EXIT_SUCCESS);
}