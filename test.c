#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main()
{
    uint8_t buffer[6] = {0};

    /* Read info from sht20 */
    int fd = open("/dev/mlx90614", O_RDWR);
    if (fd < 0) {
    	printf("Error: cannot open file.\n");
	    return -1;
    }

    printf("Open success\n");
    while(1) {
    	read(fd, &buffer, 6);
        
        /* Calculate temperatue */
        for(int idx = 0; idx < 6; idx+=2) {
            printf("%e,", (buffer[idx] | buffer[idx+1] << 8) * 0.02 - 273.15);
        }
    	printf("\n");
	    sleep(1);
    }
    close(fd);
    return 0;
}
