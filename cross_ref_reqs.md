## Goal

- Write a cross referencer that prints a lits of all words in a document, 
and, for each word a list of the line numbers on which it occurs.

- Remove noise words like "the", "and", etc.



## Routines/items needed:

- function that prompts the user to define what will be considered "noise words"

- loop through file comparing each word to the noise list, if not, update 'lines found'

- check if noise
    - for each word, will loop through predefined array of 'noise words' and ignore if found in the array

- line number incrementer for every '\n'

- word struct with properties (the_word, appeared_lines)
    - appeared_lines will be a pointer to an array of ints

- array to store pointers to every word object
    - array will be sorted alphabetically 
                - array will be a binary tree
