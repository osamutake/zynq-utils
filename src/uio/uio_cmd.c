#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uio.h"

int my_str2num(const char str[], int *num)
{
  unsigned int value;
  char *p;
  if (strlen(str)>2 && str[0]=='0' && ((str[1]=='x')||str[1]=='X')) {
    // hex
    value = strtol(str+2, &p, 16);
  } else {
    // dec
    value = strtol(str, &p, 10);
  }
  if (*p==0) {
    *num = value;
    return 0;
  } else {
    fprintf(stderr, "ERROR: Irregal number \"%s\" was given.\n", str);
    return 1; // error
  }
}

int show_usage()
{
  fprintf(stderr, "USAGE: uio uio_num byte_offset [value]\n");
  return -1;
}
  
int main(int argc, const char *argv[])
{
  int uio_n, addr, value, write = 0;
  UIO *uio;
  
  if (argc!=3 && argc!=4) {
    return show_usage();
  } else
  if (my_str2num(argv[1], &uio_n)) {
    return 1;
  } else
  if (my_str2num(argv[2], &addr)) {
    return 1;
  } else
  if (argc==4) {
      if (my_str2num(argv[3], &value)) {
        return 1;
      }
      write = 1;
  }
  
  if (addr % 4 != 0) {
    fprintf(stderr, "byte_offset should be an integer multiple of four.\n");
    return 1;
  }
  
  uio = uio_open(uio_n);
  if (!uio) {
    return 1;
  }
  if (write) {
    uio_access(uio)[addr/4] = value;
  } else {
    printf("0x%08x\n", uio_access(uio)[addr/4]);
  }
  uio_close(uio);

  return 0;
}
  
