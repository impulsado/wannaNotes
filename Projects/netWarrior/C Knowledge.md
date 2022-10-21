**Title:** C Knowledge
**Tags:** [[netWarrior]]
**Topics:** #C 

---
# C Knowledge

## includes
Tells the preprocessor to insert the contents of another file into the source code at the point where the #include directive is found.

## define
Definition of macros within your source code. These macro definitions allow constant values to be declared for use throughout your code.

## functions
``main() ``First function in the program that is executed.
`int main()` The function should return an integer value. If all worked, it must return 0.

## arguments
`argv` and `argc` are how command line arguments are passed to `main()` in C and C++.
`argc` is the number of strings in `argv`.

## structures
Are a way to group several related variables into one place.

## pointer
Is a variable that contains the memory address of another variable that contains the data in an array. This means that the pointer points to the physical space where the data or variable is located. 
```c
#include <stdio.h>

#define SIZE 4

void main() {
	int c = 2;
	int *dc = &c;

	printf("\nEl contenido de c es: %i", c);
	printf("\nEl contenido del puntero a 'c' es: %d", *dc);
	printf("\nLa dirección de memoria de 'c' es: %p", &c);
	printf("\nLa dirección de memoria del puntero es: %p", &dc);

	printf("\n");
	++*dc;
	printf("\nEl contenido de c es: %i", c);
	printf("\nEl contenido del puntero a 'c' es: %d", *dc);
	
	printf("\n");
	++c;
	printf("\nEl contenido de c es: %i", c);
	printf("\nEl contenido del puntero a 'c' es: %d", *dc);

	printf("\n");
	++dc;
	printf("\nEl contenido de c es: %i", c);
	printf("\nLa dirección de memoria del puntero es: %p", &dc);
	printf("\nEl contenido del puntero a 'c' es: %d", *dc);
	

	char a[SIZE] = "ABC";
}
```

```

El contenido de c es: 2
El contenido del puntero a 'c' es: 2
La dirección de memoria de 'c' es: 0x7fff79054c24
La dirección de memoria del puntero es: 0x7fff79054c28

El contenido de c es: 3
El contenido del puntero a 'c' es: 3

El contenido de c es: 4
El contenido del puntero a 'c' es: 4

El contenido de c es: 4
La dirección de memoria del puntero es: 0x7fff79054c28
El contenido del puntero a 'c' es: 2030390312
```
