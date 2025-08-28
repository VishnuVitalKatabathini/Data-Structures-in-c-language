a=['','','','','','','','','','',]
b=[1,2,1,3,24,4,34,5,56,65]
def hashing(key):
    for i in range(10):
        id=(key%10+i)%10
        if a[id]=='':
            a[id]=key
            return 1
        

for i in range(len(b)):
    x=hashing(b[i])
    

print(a)