# Occurrence_of_words_in_C

Write a program able to identify in a text file words that contain a given sequence of characters. So
called "words" in the text contain only alphanumeric characters (they can be identified by the isal
num function from ctype.h) and are separated by spaces or punctuation marks (respectively iden
tified by the isspace and ispunct functions). 

The program should receive in input:

• The file sequences.txt. The file reports in the first line an integer value representing the total 
  number of given sequences (no more than 20), and in the following lines, one per line, the 
  sequences to be identified. Each sequence is no more than 5 characters long. You should not 
  differentiate between uppercase and lowercase characters. 

• The file text.txt. The file contains a generic text, of unknown number of lines. You can assume 
  that each line is no more than 200 characters long and that each word is no more than 25 characters 
  long. 

The program should print on the screen, per each of the given sequences, the list of words in the text 
that contain such sequence, with their respective position in the file. The position should be computed 
in terms of number of words from the beginning of the file (that is: 1 for the first word of the text, 2 
for the second, etc.) For the sake of this exercise, you should identify and visualize only a maximum 
of 10 words per each given sequence.

Example 
file sequences.txt:  

4 

no 

Al 

per 

s 


file text.txt:  
Non sempre si capisce un esercizio alla prima lettura, ma prestando 
attenzione al testo e all’esempio non dovrebbe essere impossibile 
scrivere codice funzionante nonostante i dubbi iniziali. Se ancora non 
si capisce, allora basta chiedere all’esercitatore di turno. 


Sequence no is contained in:  
Non (position 1) 

non (position 18) 

nonostante (position 25) 

non (position 31)  

turno (position 40).
.
.
.
