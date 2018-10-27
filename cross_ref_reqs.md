# Goal

- Write a cross referencer that prints a list of all words in a document, and, for each word a list of the line numbers on which it occurs.

- Remove noise words like "the", "and", etc.

## Routines/items needed

- function that prompts the user to define what will be considered "noise words"    **[DONE]**
  - array to put the noise words into **[DONE]**

- loop through file comparing each word to the noise list, if not, update 'lines found'

- check if noise
  - for each word, will loop through predefined array of 'noise words' and ignore if found in the array

- line number incrementer for every '\n' **[DONE]**

- word struct with properties (the_word, appeared_lines)
  - appeared_lines will be a pointer to an array of ints **[DONE]**

- array to store pointers to every word object
  - array will be sorted alphabetically by word property
    - array will be a binary tree

***
***
***

## define_noise alg

- input comes in through console as words separated by spaces

- each word entered will be a "noise word"

- a pointer in memory will be made to each word entered

- each pointer will be stored in a pointer array

- the array to put it into will be provided when function is called

- return type will be int, will return 0 if all works properly, else it will return an error code

- use a separate calling function to test for error