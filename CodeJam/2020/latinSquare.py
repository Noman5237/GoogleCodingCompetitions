

def printLatin(n):  
  
    # A variable to control the  
    # rotation point.  
    k = n + 1
  
    # Loop to prrows  
    for i in range(1, n + 1, 1):  
      
        # This loops runs only after first  
        # iteration of outer loop. It prints  
        # numbers from n to k  
        temp = k  
        while (temp <= n) : 
            print(temp, end = " ") 
            temp += 1
          
        # This loop prints numbers 
        # from 1 to k-1.  
        for j in range(1, k): 
            print(j, end = " ")  
  
        k -= 1
        print()


printLatin()

