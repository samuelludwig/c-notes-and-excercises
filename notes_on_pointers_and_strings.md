# Pointers, Strings, Arrays, and String Arrays in C



```C
int x = 5;
```
- assume that the variable x is stored in memory address 1004
- so, the value of 5 is currently stored in memory address 1004
***

```C
int *num;
```
- creates a pointer to an integer, called num
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

- If I reference 'num'
    I am referencing the value inside of num, which is x's address, **1004**

- If I reference '&num'
    I am referencing the address of 'num', which is **12008**

- If I reference '*num',
    I am referencing the value that num is pointing to, which is the value at x's address, **5**

