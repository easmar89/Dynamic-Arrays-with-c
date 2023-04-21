# Dynamic Array in C

One of my favorite exercises. In this one, I tried implementing a dynamic array in C. As we know, arrays that are used on a daily basis in higher level languages are not "real" arrays, so the primary goal of this exercise is to provide a deeper understanding of how these dynamic array types in languages like JavaScript and Python work under the hood.

> Dynamic arrays are built in data structures capable of storing elements of any data type and dynamically adjusting their size as needed. In contrast, traditional C arrays are defined as contiguous memory blocks with a fixed size, designed to store elements of a single data type.

<br>

## API

The dynamic array implementation in this exercise provides the following functions for manipulating the array:

- `DA* DA_new(void)`: Creates a new dynamic array and returns a pointer to the `DA` struct.
- `int DA_size(DA *da)`: Returns the current size of the dynamic array.
- `void DA_push(DA* da, void *x)`: Adds an element to the end of the dynamic array.
- `void* DA_pop(DA *da)`: Removes and returns the last element of the dynamic array. If the array is empty, returns `NULL`.
- `void DA_set(DA *da, void* val, int idx)`: Sets the value at the specified index in the dynamic array, as long as the index is within the bounds of the array's current size.
- `void *DA_get(DA *da, int idx)`: Returns the value at the specified index in the dynamic array if the index is within the bounds of the array's current size; otherwise, returns `NULL`.
- `void DA_free(DA *da)`: Frees the memory allocated for the array and the `DA` struct itself.

<br>

## Learning outcome

- Understanding how arrays work in C.
- Understanding how dynamic arrays are implemented in higher level languages, and how the memory is managed.
- Understanding pointers, void pointers and structs in C.

<br>

> This is one exercise in a series of exercises aiming to learn how things work under the hood, as well as get some practice working with the C language.
