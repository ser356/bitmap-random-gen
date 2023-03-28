/*
PROGRAMA QUE CREA UN BITMAP DE 32x32 PIXELES CON COLORES ALEATORIOS
@autor: ser356
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define WIDTH 32
#define HEIGHT 32

int main(void)
{
    
    FILE *fp;
    fp = fopen("random.bmp", "w");
    if (fp == NULL)
    {
        printf("Error en la creación del archivo");
    }
    
    //CONSULTAR REFERENCIA EN https://en.wikipedia.org/wiki/BMP_file_format
   
    char header[54] = {0x42, 0x4D, 0x36}; 
    
    int size = 54 + 3 * WIDTH * HEIGHT;
    header[2] = size;
    header[3] = size >> 8;
    header[4] = size >> 16;
    header[5] = size >> 24;
   
    header[6] = 0;
    header[7] = 0;
    header[8] = 0;
    header[9] = 0;
    //offset
    header[10] = 54;
    header[11] = 0;
    header[12] = 0;
    header[13] = 0;
   

    header[14] = 40;
    header[15] = 0;
    header[16] = 0;
    header[17] = 0;
    //width
    header[18] = WIDTH;
    header[19] = WIDTH >> 8;
    header[20] = WIDTH >> 16;
    header[21] = WIDTH >> 24;
    //height
    header[22] = HEIGHT;
    header[23] = HEIGHT >> 8;
    header[24] = HEIGHT >> 16;
    header[25] = HEIGHT >> 24;
    //planes
    header[26] = 1;
    header[27] = 0;
    //bits per pixel
    header[28] = 24;
    header[29] = 0;
    //compression
    header[30] = 0;
    header[31] = 0;
    header[32] = 0;
    header[33] = 0;
    
    header[34] = 0;
    header[35] = 0;
    header[36] = 0;
    header[37] = 0;
    
    header[38] = 0;
    header[39] = 0;
    header[40] = 0;
    header[41] = 0;
    
    header[42] = 0;
    header[43] = 0;
    header[44] = 0;
    header[45] = 0;
   
    header[46] = 0;
    header[47] = 0;
    header[48] = 0;

    header[49] = 0;
   
    
    header[50] = 0;

    header[51] = 0;

    header[52] = 0;

    //SE ESCRIBEN LOS 52 ELEMENTOS DEL HEADER EN EL ARCHIVO
    fwrite(header, sizeof(char), 54, fp);


    //EN EL RESTO DE CELDAS SE ESCRIBEN LOS COLORES
    srand(time(NULL));
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            fwrite(&b, sizeof(char), 1, fp);
            fwrite(&g, sizeof(char), 1, fp);
            fwrite(&r, sizeof(char), 1, fp);
        }
    }
    fclose(fp);
    return 0;

}