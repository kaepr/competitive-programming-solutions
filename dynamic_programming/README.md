Global scope array max size    : int * 10^8

Function scope array max size  : int * 10^6

## DP

save values of states that overlap

**state**: set of parameters that give a unique answer

## Framework 

- Look for the form
- Decide state and meaning
- Decide transition

### Form 1

Go item by item, and build incremental solutions

- Level: Way to iterate over all solution space efficiently, current position

- Choice: For each level, what moves we can make to go to next level

- Check: For each choice, check if the current partial solution is valid as per problem

- Move: If it is a valid choice, evaluate that branch using recursion

## Time Complexity

#states: #different possibilities for each parameter 

Estimate: #states * transition time for each state

Exact: total transition time for all the states

OR

TC: #states * (1 + avg. transition cost per state)
    #states * (1 + avg. #transitions per state) ( most of the time ) 

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

### general code form

```cpp
// pruning

// base case

// cache check

// compute / transition

// save and return
```

