# Pointers, Strings, Arrays, and String Arrays in C
***


## Pointers 

```C
int x = 5;
```
- assume that the variable x is stored in memory address 1004
- so, the value of 5 is currently stored in memory address 1004
***

```C
int *num;
```
- creates a pointer to an integer, called num, explicitly telling the computer "this variable will hold an address to an integer"
- lets assume that the value of num is to be stored in memory address 12008 
***

**NOW**

```C
num = &x;
```
- sets the value of num to the address of x
- the address of x is 1004,
- so, the value stored in num is 1004,
- *so,* the value stored in the address of num- 12008, is **1004**
***

**SO**

- if I reference 'num',
    I am referencing the value inside of num, which is x's address, **1004**

- if I reference '&num',
    I am referencing the address of 'num', which is **12008**

- if I reference '*num',
    I am referencing the value that num is pointing to, which is the value at x's address, **5**

***
***

## Strings and Arrays

- in C, there is no innate String datatype, instead, we need to use a **Character Array**, i.e., an **array of characters**.

```C
char chararray[64];
```
- ^this^ initializes an array of characters, 64 spaces wide, each element is currently just garbage data until changed

- assume that the first byte of the character array is located at memory address 4000 

- to reference the memory address of `chararray`'s first element, **4000**, we can say `&chararray[0]`

- `&chararray[0]` can be explicitly read as "the address of the first element of `chararray`, with no offset"

- `&chararray[4]` would be explicitly read as "the address of the first element of `chararray`, offset by four spaces"

***

**NOTE**
- `chararray` and `&chararray[0]` are effectively equivalent when referenced, **however**, keep in mind:

-  `chararray` is **not** a variable, and it **cannot** be treated or referenced as one; `(chararray += 10);` will do nothing but cause error marks to appear in your IDE 

- `chararray` is **not** a variable, it is also **not** a pointer, `chararray` **is** a **lable** that we can use to reference the address of it's first element

- more plainly: in this case, whenever your computer sees "`chararray`", it will immediately translate it to "memory address 4000"

- ^this^ is actually true for any kind of variable name, whenever you reference `my_variable_x`, your computer will immediately translate it to "the value at memory address `address_of_my_variable_x`"

***

***

## String Arrays