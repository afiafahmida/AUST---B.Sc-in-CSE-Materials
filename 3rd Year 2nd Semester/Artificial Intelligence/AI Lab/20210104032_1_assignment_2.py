gtp= [(1,1,1), (2,1,2), (3,1,3), (4,2,3), (5,3,3), (6,3,2), (7,3,1), (8,2,1)]

tp=[(1,1,2), (2,1,3), (3,2,1), (4,2,3), (5,3,3), (6,2,2), (7,3,2), (8,1,1)]


i=0
j=0
js=0
k=0
ks=0
h=0

while i<=7:
    if(gtp[i][1] != tp[i][1]) or (gtp[i][2] != tp[i][2]):

           if(tp[i][1] > gtp[i][1]):
               js = ((tp[i][1] - gtp[i][1]))
           else:
               js = (gtp[i][1] - tp[i][1])


           if (tp[i][2] > gtp[i][2]):
               ks = ((tp[i][2] - gtp[i][2]))
           else:
               ks = (gtp[i][2] - tp[i][2])


           h = h + (js + ks)
    print(i+1 ," ", h)
    i=i+1


print("Heuristic: ",h)
