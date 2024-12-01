Group Members:
Alvarez, Ysabela Erika U.
Brizuela, Julianna Victoria M.
LBYARCH — X22

## Introduction
This project performs a dot product calculation between vectors A and B, and returns the final result in sdot—all of which are single-precision floats. For each kernel version (C and x86-64), the project will output the final result, the average time taken, and the total time taken to execute the calculation twenty times. This calculation is done for the following vector sizes = {2^20, 2^24, 2^28}.


## Program Execution
Upon executing the program, the user is asked to choose among the provided vector sizes in the prompt to allocate memory for arrays A and B. The contents of A and B are then randomly generated before the calculation is executed. After selecting the desired vector size to be used, both kernel versions of the dot product calculation will run 20 times. The start and end times of each iteration are recorded to measure the average and total time. This process repeats for the rest of the program, which allows the user to run as many kernels as they want until the user decides to exit.


## Sample Program Output
This is the sample output of the program, showing the computed dot product and the total time taken to compute it. The top portion displays the result for the C kernel, while the bottom portion displays the result for the ASM kernel. In the image, it can be seen that both dot product results of the kernels are the same, therefore, acting as each other's "sanity checks" and confirming both programs' correctness. 
![image](https://github.com/user-attachments/assets/70c3c5df-3b0d-4278-99d6-f76145e38e51)

In addition to this, tests were also performed with a smaller vector size and initialized data, wherein it was also computed manually to further determine the correctness of the program. 
![image](https://github.com/user-attachments/assets/2fe93908-f4ea-483c-b96b-f3e377c608cf)


## Performance Analysis
In order to compare the runtime speed between the C kernel and the ASM kernel, each kernel was tested with varying vector sizes of 2^20, 2^24, and 2^28. For each vector size, the program was run a total of 20 times. Upon completing all 20 runs for each version, the average runtime speed was computed.

For a vector size of 2^20, the x86-64 kernel performed significantly faster than the C kernel, with a difference of 0.00285. The x86-64 kernel ran slightly faster when executed in Release mode, whereas the C kernel had no significant change in execution time.
![image](https://github.com/user-attachments/assets/1f60ffa4-3615-43f2-9533-7bebfa4d2d6c)


For a vector size of 2^24, the ASM kernel also performed faster than the C kernel, with a difference of 0.03975. Here, both kernels run faster in Debug mode.
![image](https://github.com/user-attachments/assets/d5342d3e-4b5f-4c2c-bb39-697ee7de011e)


Lastly, with a vector size of 2^28, the ASM kernel performed faster than the C kernel, with a difference of 0.648. In terms of the modes, both kernels performed slightly better when executed in Release mode.
![image](https://github.com/user-attachments/assets/eb7ef85e-bac9-40f3-a5a0-2b859c33e233)


From these tests, it can be deduced that the ASM kernel has an ultimately higher performance speed than the C kernel, even as the vector size increases. It can also be said that the Release mode yields faster execution times, since it provides optimized performance.


## Demo Presentation
The demo video presentation can be viewed here: https://youtu.be/VmSEnMWSmGY
