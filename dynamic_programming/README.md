Global scope array max size    : int * 10^8

Function scope array max size  : int * 10^6

## DP

save values of states that overlap

**state**: set of parameters that give a unique answer

## Framework 

- Decide Form 
- Decide State and meaning
- Decide Transition 
- Complexity Cost

### general code form

```cpp
// pruning

// base case

// cache check

// compute / transition

// save and return
```

### Form 1

dp(index, ..) -> Y
Y for [index..N] if previsouly calculated X

Go item by item, and build incremental solutions

for e.g., if problem uses subset

- Level: Way to iterate over all solution space efficiently, current position

- Choice: For each level, what moves we can make to go to next level

- Check: For each choice, check if the current partial solution is valid as per problem

- Move: If it is a valid choice, evaluate that branch using recursion

### Form 2

dp(index, ..) -> Y

best Y starting/ending at index

can be used for path / sequence / subarray dependencies

- Figure out the config, which is the state we want the best answer at

- Best (asked in problem) ending at configuration

- Transition

### Form 3

multi sequence DP

A: [ . . . . i . . . . .]

B: [ . . . . . . . j . .]

dp(i, j, ..) -> best answer in A[i..N] and B[j..M]

e.g. LCS

matching on multiple sequences

### Form 4

dp(L, R, _) = best way to cut Xl to Xr

for rod cutting problem

for all L <= P <= R

dp(L, R) = Xr - Xl + dp(L, P) + dp(P, R)

think of what is deleted, and how it affects the rest

### Form 5

game based dp

dp(config) -> W/C

## Time Complexity

#states: #different possibilities for each parameter 

Estimate: #states * transition time for each state

Exact: total transition time for all the states

OR

TC: #states * (1 + avg. transition cost per state)
    #states * (1 + avg. #transitions per state) ( most of the time ) 

- Always use recurrence function directly when trying to print solutions, as its possible not all dp array states are populated

## Space Complexity

#states * space required for each state

## climbing stair problem

level -> current stair

choice -> 1,2,3 steps

check -> check if in [1..n]

move -> move to stair ( level + 1/2/3 )

## n queens

level -> row

choice -> which column

check -> is being attacked from previous spots

move -> place queen, go to next row

## bricks coloring https://www.learning.algozenith.com/problems/Bricks-Colouring-170

level -> which brick

choice -> to paint same as prev color or not

check -> not more than K distint left paints

move -> paint brick, move

