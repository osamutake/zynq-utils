#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <linux/i2c-dev.h> 

#define DEV_I2C "/dev/i2c-1"
#define LCD_ADDR 0x3e

int lcd_write(const char bytes[], int length, int is_cmd)
{
  int i2c = open(DEV_I2C,O_RDWR);
  if(i2c < 0) {
    fprintf(stderr, "ERROR: unable to open I2C device \"%s\".\n", DEV_I2C);
    return i2c;
  }

  if (ioctl(i2c, I2C_SLAVE, LCD_ADDR)<0) {
    perror("ioctl(I2C_SLAVE)");
    exit(1);
  }
  
  char *buffer = (char*)malloc(length+2);
  buffer[0] = is_cmd ? 0x00 : 0x40; /* control byte */
  strcpy(buffer+1, bytes);          /* data bytes */
  int result = write(i2c, buffer, length+1);
  free(buffer);
  
  close(i2c);
  
  return result;
}

unsigned int my_str2num(const char str[])
{
  unsigned int value;
  char *p;
  if (strlen(str)>2 && str[0]=='0' && ((str[1]=='x')||str[1]=='X')) {
    value = strtol(str+2, &p, 16); /* hex */
  } else {
    value = strtol(str, &p, 10);   /* dec */
  }
  if (*p!=0) {
    fprintf(stderr, "ERROR: Irregal number \"%s\" was given.\n", str);
    exit(1);
  }
  return value;
}

void show_usage()
{
  fprintf(stderr, "USAGE:\n");
  fprintf(stderr, "lcd-control \"Hello!\" \n");
  fprintf(stderr, "lcd-control -c 0x39 0x14 0x78 ...\n");
  exit(1);
}

int main(int argc, const char *argv[])
{
  int i;
  char *buffer;
  if (argc < 2) show_usage();
  if (strcmp(argv[1], "-c")==0) {
    buffer = (char*)malloc(argc-2);
    for(i = 2; i < argc; i++) {
      buffer[i-2] = my_str2num(argv[i]);
    }
    lcd_write(buffer, argc-2, 1);
    free(buffer);
  } else {
    for(i = 1; i < argc; i++) {
      if (i != 1) lcd_write(" ", 1, 0);
      lcd_write(argv[i], strlen(argv[i]), 0);
    }
  }
  return 0;
}
