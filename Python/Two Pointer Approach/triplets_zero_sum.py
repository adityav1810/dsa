def triplets_zero_sum(arr):
    n = len(arr)-1
    for i in range(n):
        l = i+1
        r = n
        
        while (l!=r):
            if(arr[i]+arr[l]+arr[r]==0):
                print ("array index",i,l,r)
                l=l+1
            elif(arr[i]+arr[l]+arr[r]<0):
                l=l+1
            else:
                r=r-1
        
            
        
    
    
    
def main():
    ar1 = [0, -1, 2, -3, 1]


    print(triplets_zero_sum(ar1))

if __name__ == "__main__":
    main()