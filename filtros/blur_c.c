#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../tp2.h"


void blur_c    (
    unsigned char *src,
    unsigned char *dst,
    int cols,
    int filas,
    float sigma,
    int radius)
{
    unsigned char (*src_matrix)[cols*4] = (unsigned char (*)[cols*4]) src;
    unsigned char (*dst_matrix)[cols*4] = (unsigned char (*)[cols*4]) dst;

    int i = radius;
	while(i< (filas - radius)){
		// printf ("i :%i \n" , i);
		int j = radius*4;
		while(j < (cols -radius) *4 ){
			// printf ("j :%i \n" , j);
			int promedio_r = 0;
			int promedio_g = 0;
			int promedio_b = 0;
			int aux_i = i - radius;
			int aux_j = j - radius*4;
			while(aux_i <= (i + radius) ){
				//int aux_j = j - radius*4;
				while(aux_j <= ( j + radius*4 ) ) {
					bgra_t *src_pixel = (bgra_t*)&src_matrix[aux_i][aux_j];
					promedio_r += src_pixel->r;
					promedio_g += src_pixel->g;
					promedio_b += src_pixel->b;
					//aux_j = aux_j + 4;
					aux_j += 4;
				}
				aux_i++;
			}
			promedio_r = promedio_r / (radius*radius);
			promedio_g = promedio_g / (radius*radius) ;
			promedio_b = promedio_b / (radius*radius) ;

			bgra_t *dst_pixel = (bgra_t*)&dst_matrix[i][j];
			

			dst_pixel->r = promedio_r;
			dst_pixel->g = promedio_g;
			dst_pixel->b = promedio_b;
			dst_pixel->a = 255;
			//j = j + 4;
			j += 4;
		}
		i++;

	}

}

int relX( int x ){
	return x;
}

int relY( int y ){
	return y/4;
}

int absX( int x ){
	return x;
}

int absY( int y ){
	return y*4;
}
