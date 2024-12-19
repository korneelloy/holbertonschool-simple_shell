# PRINTF FUNCTION  
## Plan
#### 1 - Description
#### 2 - Compilation
#### 3 - Requirements
#### 4 - Examples
#### 5 - Flowchart

## **Description**
The printf project asks us to recreate the printf function, in particular these conversion specifiers :
* `%c`: Print a char
* `%s`: Print a string
* `%d`: Print an integer
* `%i`: Print an integer base 10
* `%%`: Print %

We also do a man page, we will see it later in the readme. 

## **Compilation command**
The program will be compiled with this function :
```c
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`
```
## **Requirements**
* Allowed editors: vi, vim, emacs
* All the files will be compiled on Ubuntu 20.04 LTS using gcc
* The code should use the Betty style.
* I am not allowed to use global variables
* No more than 5 functions per file (the reason of the 2 slash files)

## **Examples**
Here we can see the printf function print an int :
```#include <main.h>
/**
* main - printf Examples
* Return: 0
*/
int main (void)
{
    int i;

    i = 78;
    _printf("%d", i);
    Return (0);
}
stdout: 78
```
Here there is a string :
```#include <main.h>
/**
* main - printf Examples
* Return: 0
*/
int main (void)
{
    char *s;
    s = "Hello world!";
    _printf("%s", s);
    Return (0);
}
stdout: Hello world!
```
I will show you a last exemple with a %:
```#include <main.h>
/**
* main - printf Examples
* Return: 0
*/
int main (void)
{
    _printf("%%");
    Return (0);
}
stdout: %
```

## **Flowchart**
![flowchart](image/final_flowchart.png)
#### *Authors*
Korneel Loy - Arthur Urbano
