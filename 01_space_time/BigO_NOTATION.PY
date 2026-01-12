'''very basics of Big O notation in computer science'''

# O = order of 1,2,3,n...etc..


'''it describes the performance of an algorithm as the amount of data increases or changes'''
'''it is machine independed, what we count is number of steps taken.'''

'''smaller operations and constants are ignored in big O 

eg- O(n+1) -> O(n)
O(n/2) -> O(n)'''

''''''






#O(1) -> constant time
'''regardless of the data size, the time required to run the program is same. constant in time'''

'''examples of O(1)
random access of an element in an array. 
inserting at the beginning of a linked list'''

#O(log n) = logarithmic time 

'''examples - binary search'''
'''by looking the the graph we can say that, as the data size increases, the algorithm will take less and less time in execute the program. ie- with large datasets using this is efficient'''

#O(n) = linear time 

'''examples - linear search
as the amount of data increases, the time it takes to execute the algorithm increases propotionally'''
'''example- looping through elements in an array'''

# O(n log n) = quasilinear time 
#between linear and quadratic scales better than O(n^2).
#quick sort
#merge sort
#heap sort

'''it is very similar to linear time, unless we are working with a large dataset.
as the dataset increases in size, o (n log n) will slow down'''


#O(n^2) = quadratic time 
#insertion sort 
#selection sort 
#bubble sort 
'''eg- nested loops as the amount of data increases, more and more time will be taken to run the program. for runtime complexity of o(n^2). but with small dataset, it could be very fast, as seen in the graph. '''

# O(n!) = factorial time 
#extremely slow with large dataset
'''travelling salesman problem'''
 
 

