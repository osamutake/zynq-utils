#ifndef _UIO_H
#define _UIO_H

typedef struct UIO_tag {
  volatile unsigned int *pointer;
  int fd;
  unsigned int size;
} UIO;

UIO *uio_open(int uio_n);
volatile unsigned int *uio_access(UIO *uio);
int uio_close(UIO *uio);

#endif
