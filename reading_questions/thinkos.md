## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages support dynamic types, which means you don't necessarily know what type a value is. 

2) Name two advantages of static typing over dynamic typing.

First, declaring types at compile time saves space. Second, errors can be found more quickly due to checking before the program runs

3) Give an example of a static semantic error.

A static semantic error happens when the compiler checks the code makes sense, so checking whether variables or values have the right type is an example. 

4) What are two reasons you might want to turn off code optimization?

Less code optimization can make debugging easier, and additional optimizations require longer compilation time. 

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The results of gcc with -S depends on what architecture you're using. 

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

Using an undefined entity returns an error about "linkers", which refers to the "loading" step of the compilation process. I don't think "loading" and "linking" is a very intuitive error message to get.

7) What is a segmentation fault?

A segmentation fault is an error that occurs when you try to read or write an incorrect location in memory.

## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

I think the virtual machine is one type of virtualization. For example, the Linux Virtual Machine allows you to have the experience of running linux but you're actually in the Windows/MacOS environment. 

2) What is the difference between a program and a process?

A process is a software object that represents a running program. It contains the text, data, and state of operations from the program. One process usually runs one program. 
I think the program is the group of code that interacts with the hardware, data, and instructions to carry out a task. 

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

Process abstraction makes a simplified representation of something complicated. This illusion helps programmers use software efficiently by not requiring them to know all the details of its implementation.

4) What is the kernel?

A component of the OS that manages the core capabilities (like running threads). 

5) What is a daemon?

A group of non-evil, background processes that provide operating system services. This is why the end of the "thread" process has the letter "d" at the end. 

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

Since 5 bits can specify up to 32 letters, 6 bits are needed to 
be able to specify a letter. To specify one letter, we need log base 2 of 33 bits. 

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

Since we have 32 bits, we can indicate up to 2^32 values. 

3) What is the difference between "memory" and "storage" as defined in Think OS?

Main memory seems to be volatile, so the memory contents are lost once the computer shuts down. Storage does not get lost as the computer shuts down, so it gets used for long-term storage. 
Memory is also measured in binary units, while storage is measured in decimal units. 

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB is in binary units, and has up 2^30 bytes. GB is in decimal units and has 10^9 bytes. I think this is a 7% difference (from calculating ((2^30)-(10^9))÷(((2^30)+(10^9))÷2). 

5) How does the virtual memory system help isolate processes from each other?

If there is no virtual address pointing to the specified physical address, then there's no way to access that address. So, even if two processes get the same virtual address, they would map to different locations in physical memory. This system makes it hard for processes to be working on the same physical memory location. 

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

Are they? If they are, I think that's due to how the stack grows down toward smaller addresses, and how heaps grows up toward larger addresses. It wouldn't make sense for the heap to grow into the stack, or for the stack to sink towards the heap. 

7) What Python data structure would you use to represent a sparse array?

I think a dictionary would best represent a sparse array, because it contains a key, which could be like the page number, and a value, which could be the additional information about the frame. 

8) What is a context switch?

The process of interrupting a running process, saving its state, and starting another process. The Memory Management Unit make sure each process has its own page table while doing this. 

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

Our results were slightly different but seemed very close (close enough). 

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

There are 32 bytes between them. 

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

Logically, file systems provide a mapping from file names to its contents, and this content is in terms of bytes. But, persistent storage uses block-based implementation and operations. 

2) What information do you imagine is stored in an `OpenFileTableEntry`?

I think this is a table that indicates the status of each file. 

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

The OS stores data in memory when you write a file so if you modify a block several times, the system only has to write it to disk once. It can also load blocks rather than bytes from disk due to the negligible time to load a KiB block. If the OS can predict a process block that is needed, it can load the block before it is requested. 

4) Suppose your program writes a file and prints a message indicating that it is done writing. Then a power cut crashes your computer. After you restore power and reboot the computer, you find that the file you wrote is not there. What happened?

The file you wrote was probably written to memory but not immediately to storage because the buffering process often delays the writing to disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

One advantage of a FAT is that it has faster access to files. Since inodes are smaller, they aren't used much for larger systems. 

6) What is overhead?  What is fragmentation?

Overhead is the data structure's allocated space. Fragmentation is the unused space of blocks. 

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

This is a good idea because programmers would only have to learn 1 API, and programs may be more adaptable to change (due to the various ways it can work from data from different places). It might be a bad idea because this principle might not be true for everything. 

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert it to a 16-bit number and accidentally apply sign extension?

I don't think anything should change. Unsigned numbers are assumed to be positive, and 128 is a positive number. Sign extensions would only add 0s to the number, which wouldn't do much other than format the number to a higher # of bits. 

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. Try it out and confirm that the result is interpreted as -12.

Check out [bitbyte.c](https://github.com/kuannie1/ExercisesInC/blob/master/reading_questions/bitbyte.c).

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a sign bit or two's complement?

I think the biased integers helps us reach a larger range of exponents. 

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

-13 
binary representation: 1101
floating point representation: 1.101 * 2^3

3 sections: 1 bit for sign, an exponent (8 bits) and bias (127 bits (base 10?)) section, and a mantissa/fraction section

fraction = 101

shift binary representation period to the left get 1.101, shift p = 3
exp = bias + p = 127 + 3 = 130
128 = 1000 0000 (in base 2)
130 is just 128 + 2 = 1000 0010 (which is the exponent)


we have to add zeros until we reach our 32 bit mark.
1 1000 0010 10100000000000000000000

I got this step-by-step procedure from [this video](https://youtu.be/yh2m7BSzRRo): 

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit. As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time. This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

Check out [uppercase.c](https://github.com/kuannie1/ExercisesInC/blob/master/reading_questions/uppercase.c).

## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

I would expect malloc and free  to take constant time. I would expect calloc and realloc to take time proportional to the size of the memory chunk. 

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

You may read data that you were not supposed to see.

b) Writing to unallocated memory.

You will be changing data that you may need later. 

c) Reading from a freed chunk.

Reading from the freed chunk will not access the intended memory (since the pointer to the freed chunk is referencing something completely different).

d) Writing to a freed chunk.

You will be writing somewhere else (not to the freed chunk) because the pointer doesn't point there anymore. 

e) Failing to free a chunk that is no longer needed.

The program will use more memory unecessarily.

3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical memory a process has.  Which processes are using the most memory?

According to my results, firefox processes are using the most memory. 

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

The minimum chunk size is 16 bytes, so allocating them isn't very efficient. Arrays may be a better option. 

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

The flow of execution would jump to another location in the program. 

2) What is the fundamental problem caches are meant to solve?

Caches help speed up the time it takes to load content from memory. 

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
