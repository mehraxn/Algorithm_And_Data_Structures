# Algorithms and Data Structures
## Laboratory number 01
--------------------

### Exercise 01 (A and B)

In
Exercise 01 of Laboratory 00
given a list of words (stored in a file), it is required
to print out the number of times each word appears in a
text (stored in a second file).

Extend this program with dynamic allocation, i.e.
dynamically allocate an array of structures to store
the list of words read from file and their absolute
frequency.

The number of words stored in the second file is specified
on the first row of the file itself, for example:

3
watch
words
become

Write two versions of this program:

- Version A
  Define the C structure as

  ```
  typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
  } index_t;
  ```

- Version B
  Define the C structure as

  ```
  typedef struct {
    char *word;
    int occurrences;
  } index_t;
  ```

### Exercise 02

In
Exercise 02 of Laboratory 00
it is requested to order a list of rectangles read from file.

Extend this program with dynamic allocation, i.e.
dynamically allocate an array of structures to store
information on all rectangles.

The number of rectangles stored in the input file is specified on the
first row of the file itself, for example:

5
rct2  1.5 3.5
xxyy  -0.5 3.0
xxyy  1.5 2.0
abcd  1.0 4.5
ktkr  -2.5 1.5
abcd  2.0 2.0
rct2  3.5 -2.0
trya  2.5 -1.0
ktkr  1.5 3.5
trya  4.0 4.0

### Exercise 03

During a training session each athlete of a group of professional
cyclists is checked during each lap.
For each athlete all lap times are stored in a file with the following
format.
The first line of the file stores the number of cyclists in the group.
Then, for each cyclist, the file stores:
- On the first line, his/her name (string of 30 characters at most),
  identifier (integer value), and number of laps performed.
- On the second line, all lap times,
  time_1 time_2 ... time_N, stored as real values.

Write a program that, after reading the file and storing its content
in a proper data structure, is able to reply to the following menu
inquiry:
- list: the program prints-out the number of athletes, their names,
  identifiers, and number of laps performed.
- detail name: given an athlete name, the program prints-out
  his/her identifier, and all lap times.
- best: the program prints-out the name, identifier, all lap times
  and the average lap time for the athlete whose average lap time is
  smaller.
- stop: end the program.

Notice that all operations can be performed more than once till the
stop command is issued.

#### Example

Let the following be the input file:

4
Rossi 100 3
1.30 1.38 1.29
Bianchi 101 5
1.46 1.43 1.42 1.51 1.28
Neri 117 2 
1.26 1.34
Verdi 89 4
2.01 1.45 1.43 1.38

The following is a run example of the program:

Input file name: cyclist.txt
Command? list
Number of athletes : 4
Name: Rossi #Id:100 #Laps:3
Name: Bianchi #Id:101 #Laps:5
Name: Neri #Id:117 #Laps:2
Name: Verdi #Id:89 #Laps:4
Command? best
Name:Neri #Id number:117 Laps:2 Times: 1.26 1.34 (Average:1.30)
Command? details Bianchi
#Id:101 #Laps:5 Times: 1.46 1.43 1.42 1.51 1.28
Command? stop
Program ended.              

------
Tips on command acquisition:
```
char cmd[256];
fprintf(stdout,"Command? ");
scanf("%s", cmd);
```