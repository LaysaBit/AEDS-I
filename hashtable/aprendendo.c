#include <stdio.h>
#include <stdlib.h>
// Hash Table is a data structure.
// You`re going to pass the key to the hash function and it`ll  spit out the index where the key`s value is located in the array.

// The hash function is a calculation used to transform the key into adress.

// When using numeric keys, you can divide it by the number of elements in the list and take the remainder.  

// For phone numbers you can use the folding method:
    // divide the number into equal parts, add them and divide them by a constant taking the remainder of it.

//Open Adressing, Collision technique - Linear probing:
    // before doing chaining: when a place is occupied, verify if the next space isn`t until you find a free space to put it.
    // If you still can`t find free space, the linear probing will go back to the beginning of the array and keeps searching from there.

// A way to avoid chaining is making the hash table bigger than is needed to be. In a way that only 70% of the table is occupied. 
// Also known as Load Factor = (total number of items stored)/(size of the array)
    //In Open Adressing with Linear Probing if load factor is low, Linear probing is gonna work well.

//When load factor is low is more efficient to use linear probing.

// Perfect hash function should: Minimize collisions, Uniform distribution of hash values, easy to calculate, resolve any collisions.
//Hashing is widely used in database indexing, compilers, caching, password authentication and more.





int main (){
    //m=10 size of hash table;
    //Time Complexity O(1);
    // Methods to calculate de hash function: division method, fourlier method, mid squared method
    // Collision is when you`re calculating key % m (hash function) and different keys get the same result, resulting in a collision
    // because they can`t be stored in the same adress.
    
    //To Open Hashing, you can solve collision through chaining method.
    //To Closed Hashing, you have 3 techniques: linear probing, quadratic probing, double hashing.

    //You can`t solve collision, but you can minimize collision
    //Key Values = 3,2,9,6,11,13,7,12



    return 0;
}