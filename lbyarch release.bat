nasm -f win64 dotProduct.asm
gcc -c ALVAREZBRIZUELA-LBYARCHMCO2.c -o dotProductinC.obj -m64 -O2
gcc dotProductinC.obj dotProduct.obj -o dotProductinC.exe -m64 -O2
dotProductinC.exe