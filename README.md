# C++ Array Based Implementation of a 3-Ary Heap

This code utilizes array based implementation to create a heap, and allows the user to perform three  basic heap operations ( insert, extract min, and decrease key).
The program reads commands an inputFile, inputFile.txt,  for operations to be performed on the heap.

## Commands

* Command IN:   Inserts a element into the 3-ary heap

* Command EM:   Extracts the minimum element from the 3-ary heap

* Command DK:   Decrease the key of the element at a given position to the given value


## Sample Output 

```python

IN 10   # [ 10 ]

IN 15   # [ 10 15 ]

IN 27   # [ 10 15 27 ]

EM      # Minimum: 10 
        # [ 15 27 ]

IN 13   # [ 13 27 15 ]

IN 11   # [ 11 27 15 13]

IN 5    # [ 5 11 15 13 27 ]

IN 6    # [ 5 6 15 13 27 11 ] 

DK 5 4  # [ 4 5 15 13 27 6]

IN 3    # [ 3 4 15 13 27 6 5 ]

EM      # Minimum: 3 
        # [ 4 5 15 13 27 6 ]

```


