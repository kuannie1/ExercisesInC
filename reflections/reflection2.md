# Reflection 2: Focusing on the Project

This sprint was vastly different from the ones before in that my team and I had a completely different focus from the past sprints. We decided to split up our work in 2: the web server wrapper and the structs to handle the incoming HTTP requests. I was going to help with making the structs to handle the HTTP requests. I personally did not feel ready to jump into learning about web servers, but this fear of unpreparedness might have held me back from contributing to the team as much as I could. I think that this held-back feeling of mine may explain why I'm behind where I thought I would be at the end of this sprint. I really did try to combat this fear by studying this topic as much as possible. 

To get myself up to speed with the rest of my Happy Hedgehogs group, I also took notes and read through the first few sections of an "Introduction to TCP/IP Networking" textbook to understand how to handle incoming HTTP requests. Although the book was informative in explaning the layers and terms behind these concepts, it (the book) did not help me understand how to attempt the daunting task of structuring structs to handle these requests. This book made me even more confused because I started to think these HTTP terms were data types. How do I make these data types when I only know about character arrays in C? I only knew about strings, so am I supposed to use a new library, libmcurl, to help us handle http data types? How do I use a new library? How is it possible for a single string to hold so much information -- enough to direct HTTP requests? Although I had a slightly better, high-level understanding of how HTTP servers work, I still felt confused and angry. 

In addition to studying the textbook, I read through chapters 4 and 5. I'm glad I read through chapter 5 because knowing them proved extremely useful for handling incoming HTTP requests. I was able to write [very basic structs](https://github.com/kuannie1/SoftSysHappyHedgehogs/commit/c8fc3f25b199635afe6d02f23abf31e3807d5b09) that Bill and I were able to build on later. This first step is something I thought went well with this sprint. 

#Links to Head First C Exercises
[Chapter 1 - It turns out I didn't finish this last time](https://github.com/kuannie1/ExercisesInC/tree/master/exercises/ex01)
[Chapter 3](https://github.com/kuannie1/ExercisesInC/tree/master/exercises/ex03)

I haven't done exercises 4 or 5 but I have read through them and implemented those concepts into our web server project. I'm still running into compilation issues with the trout files, so I'm in the process of resolving those.

#Links ThinkOS Answers
I decided not to focus on ThinkOS this sprint, because I felt that it does not cover the topics we needed for this project. 

#Possible Exam Questions
Q: Why doesn't C support binary literals? What does C use instead?
A: Binary literals take up a lot of space. C uses hex values, because they are more efficient. 