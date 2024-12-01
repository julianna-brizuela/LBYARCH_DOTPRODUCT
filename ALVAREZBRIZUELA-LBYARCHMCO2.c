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

	for (i = 0; i < n; i++) {
		a[i] = (float)rand() / RAND_MAX;
        b[i] = (float)rand() / RAND_MAX;
	}
}

int main() {
	// time declarations
	srand(time(NULL)); 
	clock_t startTimeC, endTimeC;
	clock_t startTimeASM, endTimeASM;
	
	// user input
	int input;
	int vector_size;
	
	// vector initialization
	float * a;
	float * b;

	// program output
	float sdot;
	
	printf("What vector size would you like to process?\n[1] 2^20\n[2] 2^24\n[3] 2^28?\nInput: ");
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
			// 2 ^ 28
			vector_size = 268435456;
			input = 0;
			break;
		default:
			break;
	}

	// MEM ALLOCATION
	a = (float*)malloc(vector_size*sizeof(float));
	b = (float*)malloc(vector_size*sizeof(float));
	
	if(a && b) {
		printf("Memory successfully allocated!\n");

	} else {
		printf("Memory unsuccessfully allocated!\n");
	}
	
	printf("\n--------------------\n");
	
	input = 0;
	
	while (input != 2) {
		printf("\nExecute? [1] Yes [2] No\nInput: ");
		scanf("%d", &input);
		
		printf("\n--------------------\n");
		
		switch (input) {
			case 1:
				// EXECUTION
				sdot = 0.0;
				int count = 0;
				double totalTimeC = 0.0;
				double avgTimeC = 0.0;
				double totalTimeASM = 0.0;
				double avgTimeASM = 0.0;
				
				initialize_arrays(a, b, vector_size);
				printf("C KERNEL sdot is: ");
			
				// 20 ITERATIONS OF C KERNEL
				for (count = 0; count < 20; count++) {
					startTimeC = clock();
					sdot = dot_product(a, b, vector_size);
					endTimeC = clock();
					totalTimeC += (double)(endTimeC - startTimeC) / CLOCKS_PER_SEC;
				}
				
				printf("%.2f\n", sdot);
				
				avgTimeC = totalTimeC / 20;
				
				printf("C KERNEL: Average time taken to compute for the dot product for 20 iterations is: %f\n", avgTimeC);
				printf("C KERNEL: Total time taken to compute for the dot product is: %f\n", totalTimeC);
				printf("\n--------------------\n");
				
				printf("ASM KERNEL sdot is: ");
				
				// 20 ITERATIONS OF ASM KERNEL
				for (count = 0; count < 20; count++) {
					startTimeASM = clock();
					sdot = dotProd(a, b, vector_size);
					endTimeASM = clock();
					
					totalTimeASM += (double)(endTimeASM - startTimeASM) / CLOCKS_PER_SEC;
				}
				
				printf("%.2f\n", sdot);
				
				avgTimeASM = totalTimeASM / 20;
																	                                         
				printf("ASM KERNEL: Average time taken to compute for the dot product for 20 iterations is: %f\n", avgTimeASM);
				printf("ASM KERNEL: Total time taken to compute for the dot product is: %f\n", totalTimeASM);
				printf("\n--------------------\n");
				break;
			case 2:
				break;
			default:
				break;
		}
	}
	
	
	free(a);
	free(b);
	
	
	return 0;
	}

