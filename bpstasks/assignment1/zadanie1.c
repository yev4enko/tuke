#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

#define BUFFER 2048

struct options
{
    int sifrovanie;
    int desifrovanie;
    int heslo;
    int vstup;
    int vystup;
};

int main(int argc, char *argv[])
{
    int fdin = 0;
    int fdout = 0;
    int opt;

    char buffer[BUFFER];
    ssize_t read_bytes;
    ssize_t write_bytes;

    char *infile = NULL;
    char *outfile = NULL;
    char *password = NULL;

    static struct options names = {0};

    while ((opt = getopt(argc, argv, "sdp:i:o:")) != -1)
    {
        switch (opt)
        {
        case 's':
            names.sifrovanie = 1;
            break;

        case 'd':
            names.desifrovanie = 1;
            break;

        case 'p':
            names.heslo = 1;
            password = optarg;
            break;

        case 'i':
            names.vstup = 1;
            infile = optarg;
            break;

        case 'o':
            names.vystup = 1;
            outfile = optarg;
            break;

        default:
            printf("chyba\n");
            break;
        }
    }

    if ((!names.sifrovanie && !names.desifrovanie) || !names.heslo || !names.vstup || !names.vystup)
    {
        printf("chyba\n");
        return 1;
    }

    if (names.sifrovanie && names.desifrovanie)
    {
        printf("chyba\n");
        return 1;
    }

    fdin = open(infile, O_RDONLY);
    if (fdin == -1)
    {
        printf("chyba\n");
        return 1;
    }

    fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdout == -1)
    {
        printf("chyba\n");
        close(fdin);
        return 1;
    }

    int shift = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        shift += password[i];
    }

    shift = shift % 26;

    while ((read_bytes = read(fdin, buffer, BUFFER)) > 0)
    {
        for (int i = 0; i < read_bytes; i++)
        {
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
            {
                if (names.sifrovanie)
                    buffer[i] = 'a' + (buffer[i] - 'a' + shift) % 26;

                if (names.desifrovanie)
                    buffer[i] = 'a' + (buffer[i] - 'a' - shift + 26) % 26;
            }

            if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
                if (names.sifrovanie)
                    buffer[i] = 'A' + (buffer[i] - 'A' + shift) % 26;

                if (names.desifrovanie)
                    buffer[i] = 'A' + (buffer[i] - 'A' - shift + 26) % 26;
            }
        }

        write_bytes = write(fdout, buffer, read_bytes);

        if (write_bytes == -1)
        {
            printf("chyba\n");
            close(fdin);
            close(fdout);
            return 1;
        }
    }

    if (read_bytes == -1)
    {
        printf("chyba\n");
        close(fdin);
        close(fdout);
        return 1;
    }

    close(fdin);
    close(fdout);

    return 0;
}