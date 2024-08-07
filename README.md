# interview_codes
Codes asked in interviews and in skills tests
I started writing them as I encountered them.  Some are
kind of stupid.  Like all the anagrams of a word (i.e.,
for smile it could be limes, miles, slime).  It's an 
interesting problem, but writing it would take a while since
you need to provide a way of storing the basic words.  See
below for my solution to that based on "are two words anagrams".

So, did I write these?  Yes, I did.  Could I do them in 30 or 45
minutes on some skills test?  I doubt it.  To do them in the time
those goofy tests give you, I'd have to go here and copy the one
from here into the answer.

And I don't remember every little thing about every language
feature.  I've usually found it is enough to know that a
capability exists within a language and then look it up.

There are some CSharp variants of some of the programs.  Bear in
mind that I am relatively new to CSharp and I am using these
to learn the language.  But, for what they are, you are free to
use them/steal them.

## anagrams of a string
```
smile
sort to eilms, all in the anagram list will sort to the same thing.
eilms (key) -> smile, limes, miles, slime
See anagram.c
```
## detect a linked list cycle
```
AKA, tortoise and hare algorithm
Traverse the linked list with 2 "followers"
One moves 1 node at a time
One moves 2 nodes at a time
If either one hits NULL, there is no cycle
If there is a cycle, eventually both followers will
point at the same node

See show_cycle.c, function showacycle()
```
## break a linked list cycle
The difference between breaking a cycle and detecting a cycle
is simple enough.  To detect a cycle, the nodes can become 
equal to each other anywhere in the cycle.  To break the cycle,
you need to know WHERE tail that should be null is rejoining the
list so you can make it null.  It needs to be done that way so
you don't lose any parts from the middle of the linked list.  The
visited approach is a far more specific locater than the tortoise
and hare for the sake of breaking the cycle.
```
I would use a "visited" marker
Or track the base address of each node you visit
As you go through the node, set visited to 1 (from 0)
Or save the node address somewhere (slower, but works)
If, at any point, visited is already 1, you found where the
cycle is.  Set the "next" value to NULL
Or see if you all ready have that address (like I said, slower).
Though with "visited", you'll need to reset to zero or remember
it's been set to one for later cycle tests.
The deal with this is you need to know which node actually ends
the list and begins the cycle.  "visited" does that.

Let's be realistic.  If you have to do this, you've got a bug and
you're trying to figure it out.  Using visited is probably the
easiest way to find the issue.  If someone says do it all the time,
tell them your skills are such that you avoid creating the cycle
in the first place.  :)

see break_cycle.c
```

## Python
caesar.py:
```
caesar's cypher
python3
translate and maketrans
```
caesar2.py:
```
caesar's cypher
BUT, with a longer encrypt/decrypt alphabet to
show it can be done that way.
python3
translate and maketrans
```
repeaters.py
```
Count the number of times a character occurs within a
string.  A variant of sortastring.py with different
outputs.
Also done, in a limited fashion, with map().  So
contains two ways to do the counts.
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
fibonacci_recur2.py
```
Fibonacci sequence using recursion
Slow version.  Still works.  But
noticably slower.
python3
```
fibonacci_recur3.py
```
Fibonacci sequence using recursion
Done to remover the counter that is
present in fibonacci_recur.py.  Still
better than fibonacci_recur2.py in 
terms of performance.
python3
```
vowel_cons.py
```
Count the vowels and consonants in a string
Of course, in python, this one is pretty easy.
At least relative to something like C.
python3
```
vowel_count.py
```
Count the individual vowels in a string
Uses map()
python3
```
sum_list.py
```
Sum a list of values 2 ways
one with a for loop
one with the sum() function
   also computes the average of the list
python3
```
count_digits.py
```
Count the digits in a string
one with a for loop (more traditional)
one with the sum(map()) functions, very python3
python3
```
num_bits.py
```
Count the 1 bits in an integer
2 methods
Using division by 2 and modulo 2
using mask and shift
python3
```
merge_sort.py
```
Do a merge and sort of two lists in a number of
ways.  One way is known broken.  It is here
so folks can "recognize" it when they see it.
The broken part is explained in code comments.
It came from a popular training site so folks
will probably see it eventually.
python3
```
sortastring.py
```
A python version of sortastring.c.  Just to
see what it would look like.  Yes, python
has easier methods of doing sorts.  But this
has uses other than sorts (character counts, etc).
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
Since this treats a string like a character array, this
would also work to reverse an array.  Though you may have
to supply the array length.  If the array is in scope (I.E.,
in the function where it was declared) you can do something 
like this to get the array length:
   array_size = sizeof(myarray) / sizeof(myarray[0]);
   (see maxelem.c for a working example of this)
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
link_list_mrg.c
```
Merge two sorted linked lists.
2 ways.  One destructive, one not.
```
break_cycle.c
```
Create a linked list
put in a cycle
demo the cycle
break the cycle
```
show_cycle.c
```
Create a linked list
put in a cycle
demo the cycle
detect the cycle (tortoise and hare)
break the cycle
```
maxelem.c
```
Find the largest element in an array.  Nothing fancy about this.
```
sortastring.c
```
Sort a string in a quick, but unusual, way.
Notes in the program comments.
Also, added in the smile, limes, slime example from
the anagram problem posed up at the top so you can
see that type of output.
```
repeaters.c
```
Count the number of times a character occurs within a
string.  A variant of sortastring.c with different
outputs.
```
anagram.c
```
Show if two strings are anagrams of each other.
A variant of sortastring.c.
```
swap2.c
```
Swap 2 numbers without a third variable(in place, sort of)
```
circle_area.c
```
Calculate the area of a circle.
Bonehead easy one.  I was bored.
```
rotate.c
```
Rotate an array x positions to the right.
So shift of 2.
Array of 1 2 3 4 5
becomes  4 5 1 2 3

2 methods.  Transfer one array into another and
in place.
```
array_bin_srch.c
```
Binary search of a sorted array.
Seems to comply with expected time complexity in
terms of look ups.  Other than that, I have not
compared it to anything that may exist.  So, it
is what it is.
```
power.c
```
Do the power of a number without pow().
```
sqrt.c
```
Get the square root of number without sqrt().
sqrt() is called, but only to compare its result 
with the programatic result.  The multiply the results
to see how close we get to the original number.
Once I made the results double instead of float, my
results are the same as the sqrt() function.
Uses a combination of subtract the odds and guessing.
Subtract the odds works as follows (using 100 as example):
1    100 - 1 = 99
2    99 - 3 = 96
3    96 - 5 = 91
4    91 - 7 = 84
5    84 - 9 = 75
6    75 - 11 = 64
7    64 - 13 = 51
8    51 - 15 = 36
9    36 - 17 = 19
10   19 - 19 = 0
So, the square root of 100 is 10.  Works for whole
square root values only(i.e., 25, 16, 36, etc).  
But it gets you close if it is 
not a whole number so you can guess the rest to get the
decimal if the square root is not whole.  See the code
for how the guessing is done.
```
## Go
tprimes.go:
```
Find if a number is prime or not.
First one here.  There will be others.
I want to refresh my Go skills.
```
odd_or_even.go:
```
Is a number odd or even
```
factorial.go
```
Factorial of a number
```
swap2.go
```
swap two numbers without a temp variable (in place)
```
circle_area.go
```
Calculate the area of a circle.
```
fibonacci.go and fibonacci2.go
```
Fibonacci sequence
They work the same.  But each illustrates a different means of
variable initialization
```
vowel_cons.go
```
Count vowels and consonants in a string.
```

More coming
            
