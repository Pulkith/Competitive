## Math Tips & Tricks

## General Math
- **Proizvolov's identity**
> Split a permutation of 2N into arbitrary subsets of size N labeled *A*, and *B*. <br> If you sort *A* in increasing order, and *B* in increasing order then <br>
![](https://latex.codecogs.com/gif.latex?N^2&space;=&space;\sum_{i=1}^{N}&space;|A_i&space;-&space;B_i|)

- **Median Trick**<br>
Given a set of *N* integers, *s*, the absolute sum of all distances to one point, *p* will be minimized at the median, *M*. <br>Formally, given the following *f(x)*, *f(x)* is minimized when *x* = *M*
    > ![](https://latex.codecogs.com/gif.latex?f(x)&space;=&space;\sum_{i=1}^{N}&space;|s_i&space;-&space;x|)<br><br>
    - Implementation-wise, if |*s*| is odd, the sole Median can act as *x*, and if |*s*| is even, either Median can act as *x*. (set[(set.size() + 1) / 2 - 1) and (set[(set.size() + 2) / 2 - 1) are the medians. If the size of the set is odd, they return the same element.
    - On a 2D grid, the point that minimize the distances across both *x* and *y* axis is the point, *p*, whre *px* is the median <br>of the set of *x* coordinates, and *py* is the median of the set of *y* coordinates. Multiple points can satisify the minimum <br> distance property when either set has an even size. The number of points *n* that minimize the distance in the above <br> scenario can be described as: 
        > ![](https://latex.codecogs.com/gif.latex?(1&space;-&space;|s_x|%2&space;&plus;&space;1)&space;&plus;&space;(1&space;-&space;|s_y|%2&space;&plus;&space;1))<br>

        Where *sx* and *sy* represent the sets of the *x* and *y* components of the coordinates on the grid.

## Misc
- **If you need to maximize the product of an array, but must decrease 1 or more elements, it is always optimal to reduce the largest elements** 
- **Given a Permutation of *N*, find the largest subsequence product that is 1 when modded with *N*.**
    > All numbers must be coprime with *N*, or its product will not be coprime with *N*, and product%*N* != 1(gcd(N, product) != 1). If you multiply all numbers that are coprime<br>
       with *N*, and the product%*N* is 1, you are good. Otherwise, you must remove the element that is product%*N*, and the product will be 1 modulo *N*

## Graphs
- **Euler's Formula for Planar Graphs**:	
> ![](https://latex.codecogs.com/gif.latex?V&space;-&space;E&space;&plus;&space;F&space;=&space;1&space;&plus;&space;C) <br>
where *V*, is the number of vertices, *E* is the number of edges,  *F* is the name of faces, and *C* is the <br>number of connected components


## Bitwise

### Implementation Tricks
- **Highest Power of 2 some number, *x* is divisible by can be calculated by**
> (x & -x)
