//celebrity
// A celebrity is defined as someone who:

// Is known by everyone else.

// Does not know any other person in the party.
//mat[x][y]---> x knows y (or not)

//n-1 person will be knowing the celebrity, celebrity will know 0 person

//brute____________________________________

//use two arrays...to compute both the values anc check condition for every person
//knowme arr and Iknow arr
//ans is the ind where knowme=n-1 and Iknow=0

//there is always 1 celebrity or no celebrity at all

//tc=O(N^2)
//sc=O(2n)


//_______________________________________________________________________

//optimised

//kind of two pointers for 2d matrix