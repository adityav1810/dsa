import time


def equilibrium_sum(arr):
    x=-1
    for i in range(1,len(arr)-1):
        if(sum(arr[0:i])==sum(arr[i+1:])):
            x = i
    return x
    

def equilibrium(arr):
    leftsum = 0
    arr_sum = sum(arr)

    x = -1
    for i in range(len(arr)-1):
        
        arr_sum = arr_sum - arr[i]
        if leftsum == arr_sum:
            x = i 
        leftsum = leftsum + arr[i]
    return x


# driver code
arr=[-7,1,5,2,-4,3,0]


# current_time = time.time()
# print(equilibrium_sum(arr))
# print("Exection Time : ",time.time() - current_time)



current_time = time.time()
print (equilibrium(arr))
print("Exection Time : ",time.time() - current_time) 


