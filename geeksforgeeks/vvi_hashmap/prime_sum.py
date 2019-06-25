'''
Given a positive number N. The task is to find sum of all the primes upto N(inclusive).

Input:
First line of input contains number of testcases T. For each testcase, there will be only single line containing N.

Output:
For each testcase, output the sum.

Constraints:
1 <= T <= 100
1 <= N <= 106

Example:
Input:
1
23

Output:
100

Explanation:
Testcase 1: Sum of primes till 23 is 100, i.e, 2+3+5+7+11+13+17+19+23 = 100.
'''

from math import floor,sqrt
N=1000000+5
sieve=[1]*N
sieve[0],sieve[1]=0,0
def update(i):
    for j in range(i*i,N,i):
        sieve[j]=0
for i in range(2,floor(sqrt(N))+1):
    if(sieve[i]==1):
        update(i)
        
sum=0
for i in range(2,N,1):
    if(sieve[i]==1):
        sum+=i
    sieve[i]=sum
    
t=int(input())
while t:
    t-=1
    n=int(input())
    print(sieve[n])
    