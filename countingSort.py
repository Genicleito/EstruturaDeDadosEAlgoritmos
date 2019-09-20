# counting-sort function
# complexity is: theta(n + m)
def countingSort(l):
  n = len(l)
  m = max(l)
  count, result = [0] * m + [0], [0] * n

  # counting elements
  for x in l:
    count[x] += 1
  
  # modify each element of 'count' with sum of previous elements
  for i in range(1, len(count)):
    count[i] += count[i - 1]

  # sort elements
  for i in range(len(l)):
    result[ count[ l[i] ] - 1 ] = l[i]
    count[ l[i] ] -= 1
  
  return result
  
# # Example:
# a = [2, 3, 4, 1, 2, 1, 8, 1]
# countingSort(a)
