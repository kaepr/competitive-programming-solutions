Time Complexity

Estimate: #states * transition time for each state

Exact: total transition time for all the states

Space Complexity

#states * space required for each state

### Climbing Stair Problem

level -> current stair

choice -> 1,2,3 steps

check -> check if in [1..n]

move -> move to stair ( level + 1/2/3 )

### n queens

level -> row

choice -> which column

check -> is being attacked from previous spots

move -> place queen, go to next row
