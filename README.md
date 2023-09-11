### Yo! 🤖

We were asked in one instance to develop a method in which we can extract the maximum values for n and k by calculating under $((n)/(k))$ respectively, with 2 methods being:

- $((n)/(k)) = n!/(((n-k)!) * k!$

- $((n)/(k)) = ((n-1)/(k-1)) + ((n-1)/(k))$

### Updates from the explanation

it should be noted that we were asked to use the second method without recursion as well as to use a relevant change of base at the time of execution.

### Execution

All this was under a linux environment system so follow these commands:
 - locate your file on your's documents with cd respectively.
 - gcc namefile.c -o namefile -lm.
 - ./namefile (method = 1 | 0 respectively) n k base.
    
