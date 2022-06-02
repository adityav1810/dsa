def find_triplet_sum(arr,k):
    n = len(arr)-1
    arr = sorted(arr)
    
    
    for i in range(n):
        l = i+1
        r = n
        while(l!=r):
            if(arr[i]+arr[l] + arr[r] == k):
                return (arr[i],arr[l] ,arr[r])
            elif(arr[i]+arr[l] + arr[r] < k):
                l+=1
            elif(arr[i]+arr[l] + arr[r]>k):
                r-=1
                
            
    
    
    
    
    
def main():
    arr=[12,3,4,1,6,9]
    k = 24
    print(find_triplet_sum(arr,k))

if __name__ == "__main__":
    main()