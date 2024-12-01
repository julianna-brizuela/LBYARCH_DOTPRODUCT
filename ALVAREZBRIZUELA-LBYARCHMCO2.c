#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float dotProd(float * a, float * b, int n);

float dot_product(float * a, float * b, int n) {
	int i;
	float sdot = 0.0;
	
	for (i= 0; i < n; i++) {
		sdot += a[i]*b[i];
	}
	
	return sdot;
}

void initialize_arrays(float * a, float * b, int n) {
	int i;
	
	srand(time(NULL)); 
	
	for (i = 0; i < n; i++) {
		a[i] = ((float)rand()/(float)(RAND_MAX))*0.5;
		b[i] = ((float)rand()/(float)(RAND_MAX))*0.5;
	}
}

int main() {
	// time declarations
	clock_t startTime, endTime;
	double totalTime;
	
	// user input
	int input;
	int vector_size;
	
	// vector initialization
	float * a;
	float * b;

	// program output
	float sdot;
	
	printf("What vector size would you like to process?\n[1] 2^20\n[2] 2^24\n[3] 2^30?\nInput: ");
	scanf("%d", &input);
	
	switch(input) {
		case 1:
			vector_size=1048576;
			input = 0;
			break;
		case 2:
			vector_size = 16777216;
			input = 0;
			break;
		case 3:
			vector_size = 1073741824;
			input = 0;
			break;
		default:
			break;
	}
	
	
	a=(float*)malloc(vector_size*sizeof(float));
	b=(float*)malloc(vector_size*sizeof(float));
	initialize_arrays(a, b, vector_size);
	
	if(a && b) {
		printf("Memory successfully allocated!\n");
		int i = 0;
	} else {
		printf("Memory unsuccessfully allocated!\n");
	}
	
	printf("\n--------------------\n");
	
	int count = 0;
	
	while (input != 3) {
		// kernel initialization
		sdot = 0.0;
		count= count + 1;
		printf("\nEXECUTION %d: Which kernel would you like to run?\n[1] C Kernel\n[2] ASM Kernel\n[3] Exit\nInput: ", count);
		scanf("%d", &input);
		
		switch(input) {
			case 1:
				startTime = clock();
				sdot = dot_product(a, b, vector_size);
				printf("sdot is: %f\n", sdot);
				endTime = clock();
				
				totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
				printf("Total time taken to compute for the dot product is: %f\n", totalTime);
				printf("\n--------------------\n");
				break;
			case 2:
				startTime = clock();
				sdot = dotProd(a, b, vector_size);
				printf("sdot is: %f\n", sdot);
				endTime = clock();
				
				totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
				printf("Total time taken to compute for the dot product is: %f\n", totalTime);
				printf("\n--------------------\n");
				break;
			case 3:
				printf("Bye bye, my goat Sir Hiroki.");
				break;
			default:
				break;
		}	
	}
	
	
	free(a);
	free(b);
	
	return 0;
}
