# interview_codes
Codes asked in interviews and in stupid skills tests
I started writing them as I encountered them.  Some are
kind of stupid.  Like all the anagrams of a word (i.e.,
for smile it could be limes, miles, slime).  It's an 
interesting problem, but writing it would take a while since
you need to provide a way of storing the basic words.  Just FYI,
I would lower case all of the letters and sort the letters.  Then
I'd use that sorted string as a sort of key to the word list. I.e.,
```
smile
sort to eilms, all in the anagram list will sort to the same thing.
eilms (key) -> smile, limes, miles, slime
```

## Python
caesar.py:
```
caesar's cypher
python3
translate and maketrans
```
prime.py
```
Tell if number is prime
python3
```
powerset.py
```
All the subsets in a set
python3
```
factorial.py
```
Factorial of a number
python3
```
fibonacci.py
```
Fibonacci sequence
python3
```
fibonacci_recur.py
```
Fibonacci sequence using recursion
python3
```
vowel_cons.py
```
Count the vowels and consonants in a string
Of course, in python, this one is pretty easy.
At least relative to something like C.
python3
```

## C
prime
```
prime is a directory with 4 ways of doing a prime
```
powerset
```
Also a directory with 3 variants of powerset
(all the subsets of a set)
```
endian.c
```
Is the machine big endian or little endian
```
factorial.c
```
again, get the factorial of a number
```
function_pointer.c
```
A few ways of using function pointers
```
numbits.c
```
Count the bits (1) in a value.  5 or 6 different methods.
Get values from a table.
logical and
modulo 2
```
odd_or_even.c
```
is a number odd or even
```
sentence_reverse.c
```
reverse a sentence, words are still proper words
```
soduku.c
```
validate a soduku puzzle
```
str_reverse.c
```
reverse a string
```
whatisi.c
```
This one is the oddest one.
Varying ways of using a variable, must of which are umdefined.
Show what the value would be.  However, it will change
depending on the compiler or platform you use because
these are, as stated, UNDEFINED.
```
word_boundary.c
```
is a variable word on a word boundary
```     
tree.c
```
a basic binary tree program
balanced tree counterpart is coming
```
linked_list.c
```
a basic linked list program
```
sortastring.c
```
Sort a string in a quick, but unusual, way.
Notes in the program comments.
```

More coming
            
