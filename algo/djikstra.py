
import math

def min_element(pq,isvisted):
    
    min_value = math.inf
    min_index=0
    for i in range(len(pq)):
        if pq[i] < min_value and pq[i] != 0 and not isvisted[i]:
            min_value=pq[i]
            min_index=i
    return (min_value,min_index)


def djisktra(a_mat,source,n):
    
    pq=a_mat[source][:]
    
    isvisted=[0]*n
    while 1:
        
        item,index=min_element(pq,isvisted)
    
        if item==math.inf:
            break
        
        isvisted[index] = 1

        
        for i in range(n):
            

            if item + a_mat[index][i] <  pq[i]:
                
                pq[i] = item + a_mat[index][i]
                
    
    print(pq)
    
    


a_mat=list()
n=int(input())
for i in range(n):
    node=list(map(int,input().split()))
    for i in range(len(node)):
        if node[i]==-1:
            node[i]=math.inf
    a_mat.append(node)
    
djisktra(a_mat,0,n)
