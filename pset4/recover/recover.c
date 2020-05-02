#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    }

    unsigned char *buf = (unsigned char *)malloc(sizeof(unsigned char) * 512);
    int cnt = 0;
    FILE *img = NULL;
    while (fread(buf, sizeof(unsigned char), 512, file) == 512)
    {
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            if (cnt)  // not the first one, another jpeg starts
            {
                fclose(img);
            }
            char name[10];
            sprintf(name, "%03d.jpg", cnt);
            img = fopen(name, "w");
            fwrite(buf, sizeof(unsigned char), 512, img);
            ++cnt;
        }
        else // not a jpeg file, or it is part of jpeg, but not the first block
        {
            if (cnt)
            {
                fwrite(buf, sizeof(unsigned char), 512, img);
            }
        }
    }
    fclose(img);
    free(buf);
}
