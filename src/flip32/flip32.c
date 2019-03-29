#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "USAGE: flip32 input_file\n");
        return -1;
    }
   
    int fd;
    struct stat stbuf;
    long file_size, i;
    u_int32_t *buffer;
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Input file not found.\n");
        return -1;
     }
   
    if (fstat(fd, &stbuf) == -1) {
        fprintf(stderr, "fstat failed.\n");
        return -1;
    }

    file_size = stbuf.st_size;
    buffer = (u_int32_t*)malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return -1;
    }
   
    if (read(fd, buffer, file_size)!=file_size) {
        fprintf(stderr, "read failed.\n");
        return -1;
    }
   
    close(fd);
   
    for(i=0; i<file_size/4; i++) {
        buffer[i] = __builtin_bswap32(buffer[i]);
    }
   
    fwrite(buffer, 1, file_size, stdout);
}
