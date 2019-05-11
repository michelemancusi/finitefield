# Finite Fields (Galois Fields)

In this repository there are two C files: in order to write a code that enable you to do multiplication and exponentiation in 
finite field between numbers greater than 2^(64), you have to copy and paste the few  lines of important_file.c in your main
and outside the main you have to write #include "big_galois_lib.c" (just to inlude the big_galois_lib.c file in your code and
to call the functions you want). Then you can compute, for example, multiplication in finite field GF(2^l) between b and c 
(both written as arrays of bools), just writing in your main: 

bool * a; 
a=malloc(l*sizeof(bool));
a=big_galois_mul(b,c, l, poly_irr[l]);
