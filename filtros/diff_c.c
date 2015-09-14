
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../tp2.h"

void diff_c (
	unsigned char *src,
	unsigned char *src_2,
	unsigned char *dst,
	int m, // ancho
	int n, // alto
	int src_row_size,
	int src_2_row_size,
	int dst_row_size
) {
	printf ("diff !!! \n");
	printf ("n : %i  m : %i  . \n" , n ,m);
	printf ("src_row_size: %i , src_2_row_size : %i ,  dst_row_size : %i . \n" ,src_row_size , src_2_row_size , dst_row_size);
	unsigned char (*src_matrix)[src_row_size] = (unsigned char (*)[src_row_size]) src;
	unsigned char (*src_2_matrix)[src_2_row_size] = (unsigned char (*)[src_2_row_size]) src_2;
	unsigned char (*dst_matrix)[dst_row_size] = (unsigned char (*)[dst_row_size]) dst;
	int i = 0;
	while(i<m){
		// printf ("i :%i \n" , i);

		
		int j = 0;
		while(j < (n/4)){
			// printf ("j :%i \n" , j);
			*dst_matrix[j*4] = 0;//abs(*src_matrix[j*4] - *src_2_matrix[j*4]);
			*dst_matrix[(j*4) + 1] =0;//abs(*src_matrix[(j*4) + 1] - *src_2_matrix[(j*4) + 1]);
			*dst_matrix[(j*4) + 2] = 0;//abs(*src_matrix[(j*4) + 2] - *src_2_matrix[(j*4) + 2]);
			*dst_matrix[(j*4) + 3] = 255;
			j ++;
		}
		i++;
		src_matrix = (unsigned char (*)[(i+ 1) * src_row_size]) src;
		src_2_matrix = (unsigned char (*)[(i+ 1) * src_2_row_size]) src_2;
		dst_matrix = (unsigned char (*)[(i+ 1) * dst_row_size]) dst;
		 
		
	}
}

