# Pointers, Strings, Arrays, and String Arrays in C
***

## Pointers 

```C
int x = 5;
```
- assume that the variable `x` is stored in memory address 1004

- so, the value of 5 is currently stored in memory address 1004
***

```C
int *num;
```
- creates a pointer to an integer, called `num`, explicitly telling the computer "this variable will hold an address to an integer"

- lets assume that the value of `num` is to be stored in memory address 12008 
***

**NOW**

```C
num = &x;
```
- sets the value of `num` to the address of `x`

- the address of `x` is 1004,

- so, the value stored in `num` is 1004,

- *so,* the value stored in the address of `num`; 12008, is **1004**
***

**SO**

- if I reference '`num`',
    I am referencing the value inside of `num`, which is `x`'s address, **1004**

- if I reference '`&num`',
    I am referencing the address of `num`, which is **12008**

- if I reference '`*num`',
    I am referencing the value that `num` is pointing to, which is the value at `x`'s address, **5**

- ^this last one in particular^ is often referred to as **dereferencing** the pointer, i.e. "getting the value of what I'm pointing to"

***
***

## Strings and Arrays

- in C, there is no innate String datatype, instead, we need to use a **Character Array**, i.e., an **array of characters**.

```C
char chararray[64];
```
- ^this^ initializes an array of characters, 64 spaces wide, each element is currently just garbage data until changed
 
- more explicitly, this tells the computer "clear out a block of memory 64 places wide, I'm going to put an array there, and I will use `chararray` to refer to the address of the first element in that array"

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

- ^this idea^ is true for any kind of variable name, whenever you reference `my_variable_x`, your computer will immediately translate it to "the value at memory address `address_of_my_variable_x`"

***

***

## String Arrays and Pointer Arrays
***

- we know how to make a string, and that a string is just a character array

- we know that the beginning of an array can be referenced by its address, just like any other variable

- we know how to make a pointer variable, and how to use it to reference the addresses of other variables

- the same rules and procedures of referencing the addresses of other variables apply to referencing other entities like arrays

- for example:

```C
char my_chararray[64];
char *my_pointer;
```

- ^this^ initializes an empty array of characters `my_chararray` , and declares a pointer variable `my_pointer`, that will point to a character

```C
char my_pointer = &my_chararray[0];
```

- ^this^ stores the address of `my_chararray`'s first character into `my_pointer`

```C
char my_pointer = &my_chararray[4];
```

- ^this^ stores the address of `my_chararray`'s fifth character into `my_pointer`, in other words, it stores the **address of `my_chararray`'s first element, with an offset of four spaces**

***

**SO**

- the next step is understanding how to create an array of strings

- an array of strings can be made in one of two ways, either by creating a multidimensional array, or by creating an array of pointers, each one pointing to a different chararray

- in the interest of staying on topic, we will focus on the latter option

***

**NOW**

```C
char mystring[64];
```

- creates an empty array of characters, 64 spaces wide, assume that the address of the first element is at memory address **4000**

- we can use this to store one string

- we can reference `&mystring` to get the address of this string (the first element of the character array)


```C
char *mystringarray[8];
```
- creates an empty array of **character pointers**, 8 spaces wide, assume the first space of this array is located at memory address **7004**

- in each space of this array, we can store a pointer to another character **or character array**

- this is because every array can be referenced by the address of its first element

```C
mystringarray[0] = mystring;
```

- sets the first element of the array of pointers, `mystringarray`, to the value of the address of `mystring`'s first element, which is **4000**

***

**SO**

- if I reference '`mystringarray[0]`', I am referencing the value stored in `mystringarray`'s address, which is the value of `mystring`'s address, which is **4000**

- if I reference '`&mystringarray[0]`', I am referencing the value of `mystringarray`'s address, which is **7004**

- if I reference '`*mystringarray[0]`', I am referencing the value stored at the address I am pointing to, which is **the first element in the character array `mystring`**

***

***

## **Pointers to *Pointers to Pointers, Oh My!

```C
int x = 5;
```
- creates variable `x` and sets it equal to 5, assume `x`'s address is 5000

- the value of 5 is now stored in memory address 5000

```C
int *mypointer = &x;
```
- creates a pointer variable `mypointer` and sets it equal to `x`'s address, 5000, assume `mypointer`'s address is 7000

- the value of `x`'s address in memory, 5000, is now stored in the address of `mypointer`, 7000
***

**SO**
- if I reference '`mypointer`',
I am referencing the value stored in `mypointer`'s address, which is `x`'s address, **5000**

- if I reference '`&mypointer`',
I am referencing the value of `mypointer`'s address, which is **7000** 

- if I reference '`*mypointer`',
I am referencing the value that `mypointer` is pointing to, which is the value at `x`'s address, **5**
***
**NOW**

```C
int **doublepointer = &mypointer;
```

- creates a new pointer variable called `doublepointer`, and sets it equal to the address of `mypointer`, 7000

- assume the address of `doublepointer` is 14000

- the value of `mypointer`'s address, 7000, is now stored in the address of `doublepointer`, 14000

- the two asterisks "**", in front of the variable indicate to the computer that "this variable is going to be a pointer to another pointer"
***

**SO**

- if I reference '`doublepointer`',
I am referencing the value stored in `doublepointer`'s address, which is `mypointer`'s address, **7000**

- if I reference '`&doublepointer`',
I am referencing the value of `doublepointer`'s address, which is **14000** 

- if I reference '`*doublepointer`',
I am referencing the value that `doublepointer` is pointing to, which is the value stored at `mypointer`'s address, **5000**

- if I reference '`**doublepointer`',
I am referencing the value that `mypointer` is pointing to, which is the value stored in `x`'s address, **5**

***
**NOTE**

- when I reference something using two asterisks, I am telling the computer "look at this thing that I am pointing to, now give me the value that *that* thing is pointing to"

- ^this^ is something that we have done before, albeit using different syntax, when I would reference something like `*pointarray[2]`, I would be telling the computer "see this array of pointers that I am looking at, now look at the address held in the third element, give me what that points to"

***
***

## Further Reading

- for further information on pointers and their usecases, see link: http://www.eskimo.com/~scs/cclass/int/sx8.html 

