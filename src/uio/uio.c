#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include "uio.h"

int sys_read_numerical_string(const char path[], unsigned int *p_result)
{
  FILE *fp;
  fp = fopen(path, "r");
  if (!fp) {
    perror(path);
    return -1;
  }
  if(fscanf(fp, "0x%08X", p_result)==EOF) {
    perror("fscanf");
    return -1;
  };
  fclose(fp);
  return 0;
}

volatile unsigned int *uio_access(UIO *uio)
{
  return uio->pointer;
}

int uio_close(UIO *uio)
{
  int result = munmap((void*)uio->pointer, uio->size) | close(uio->fd);
  if (result) perror("uio_close");
  free(uio);
  return result;
}

UIO *uio_open(int uio_n)
{
  char text_buffer[128];
  int fd;
  volatile unsigned int *uio_reg;
  unsigned int offset, size;
  UIO *uio;

  if (snprintf(text_buffer, sizeof(text_buffer), "/sys/class/uio/uio%d/maps/map0/offset", uio_n) < 0) {
    perror("uio number out of range");
    return NULL;
  }
  if (sys_read_numerical_string(text_buffer, &offset) != 0) {
    return NULL;
  }
  if (offset % sysconf(_SC_PAGE_SIZE) != 0) {
    fprintf(stderr, "offset must be integer multiple of _SC_PAGE_SIZE = 0x%#lx\n", sysconf(_SC_PAGE_SIZE));
    return NULL;
  }
	
  if (snprintf(text_buffer, sizeof(text_buffer), "/sys/class/uio/uio%d/maps/map0/size", uio_n) < 0) {
    perror("uio number out of range");
    return NULL;
  }
  if (sys_read_numerical_string(text_buffer, &size) != 0) {
    return NULL;
  }
  if (size % sysconf(_SC_PAGE_SIZE) != 0) {
    fprintf(stderr, "length must be integer multiple of _SC_PAGE_SIZE = 0x%#lx\n", sysconf(_SC_PAGE_SIZE));
    return NULL;
  }
	
  if (snprintf(text_buffer, sizeof(text_buffer), "/dev/uio%d", uio_n) < 0) {
    perror("uio number out of range");
    return NULL;
  }
	
  if ((fd = open(text_buffer, O_RDWR | O_SYNC)) < 0) {
    perror("open");
    return NULL;
  }
  
  uio_reg = (volatile unsigned int*)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, offset);
  if (uio_reg == MAP_FAILED) {
    perror("mmap");
    close(fd);
    return NULL;
  }
  
  uio = (UIO*)malloc(sizeof(UIO));
  if (!uio) {
    perror("malloc");
    return NULL;
  }
  uio->pointer = uio_reg;
  uio->fd = fd;
  uio->size = size;
  
  return uio;
}
