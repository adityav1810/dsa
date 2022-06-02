import sys 

def find_closest_pair(arr1,arr2,k):
    
    n = len(arr2)
    m = len(arr1)
    l = 0
    r = m-1
    diff = sys.maxsize
    

    
    while(l<n and r >=0):
        
        if(abs(arr1[l] + arr2[r] - k) < diff):
            
            
            diff = abs(arr1[l] + arr2[r] - k ) 
            print(arr1[l] , arr2[r])
            
        if(arr1[l] + arr2[r] > k):
            r=r-1
        else:
            l=l+1
            
    return diff
            
            
        
        
            
    
    
    
    
    
def main():
    ar1 = [1, 4, 5, 7]
    ar2 = [10, 20, 30, 40]
    x = 38

    print(find_closest_pair(ar1,ar2,x))

if __name__ == "__main__":
    main()