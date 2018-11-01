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
  - iterate through input one character at a time
    - a word begins on the first alphanumeric character
    - the word ends when a non-alnum char is reached
    - from the first letter to the last, the word will be built character by character into a chararray
    - the chararray will be terminated with a `'\0'`

- each word entered will be a "noise word"

- a pointer in memory will be made to each word entered

- each pointer will be stored in a pointer array

- the array to put it into will be provided when function is called

***

## is_noise

- called for every word found when traversing the file, it will take the word and compare it to each entry in the list of noise words, if it is in the list, it will return true, else it will retrun false

***

## traverse_file alg

- create line counter, that will increase for every newline

- input comes in through console as words separated by spaces
  - iterate through input one character at a time
    - a word begins on the first alphanumeric character
    - the word ends when a non-alnum char is reached

- when a word is created, test if is_noise
  - if is_noise returns true, the word is ignored and we move to the next one
  - else, proceed with alg

- if the word is not noise
  - test if the word exists somewhere in the binary tree
    - if so, add line_number to the array of lines_appeared of that word
    - else, create a new node for that word in the tree