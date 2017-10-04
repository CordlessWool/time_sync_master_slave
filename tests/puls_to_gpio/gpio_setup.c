//
// Created by wolle on 08.05.17.
//

#include "gpio_setup.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int gpio_setup(int gpio)
{
    int fd;
    char buf[100];

    fd = open("/sys/class/gpio/export", O_WRONLY);

    if(fd == -1)
    {
        fprintf(stderr, "Failed to open export for writing!\n");
		return -1;
    }

    sprintf(buf, "%d", gpio);
    write(fd, buf , strlen(buf)  );

    close(fd);

    sprintf(buf,"/sys/class/gpio/gpio%d/direction", gpio);
    printf("%s\n",buf);

    fd = open(buf, O_RDWR);
    //write IN in direction
    sprintf(buf, "out");
    write(fd,buf , strlen(buf));

    close(fd);

    //writing the edge
/*
    sprintf(buf,"/sys/class/gpio/gpio%d/edge", gpio);
    printf("%s\n",buf);

    fd = open(buf, O_RDWR);
    sprintf(buf, "both");
    write(fd,buf , strlen(buf));

    close(fd);
*/
    sprintf(buf,"/sys/class/gpio/gpio%d/value", gpio);
    printf("%s\n",buf);

    fd = open(buf, O_RDONLY);

    return fd;
}
