#choripunk
num, t = map(int, input().split())

p = []
n = []

for i in range(num):
    c, x = input().split()
    x = int(x)
    if c == 'P':
        p.append(x)
    else:
        n.append(x)

p.sort()
n.sort()
tiempo = 0
tmp = 0
tmn = 0

while len(p)>0 or len(n)>0:
    if len(p) > 0 and len(n)>0:
        tp = 0.75 * t / len(p)
        tn = 0.25 * t / len(n)
        tiempo_muerte = min((p[0] - tmp) / tp, (n[0] - tmn) / tn)
        tmp += tiempo_muerte*tp
        tmn += tiempo_muerte*tn
        #print(tmp)

    elif len(p) > 0 and len(n) == 0:
        tp = t / len(p)
        tiempo_muerte = (p[0] - tmp) / tp
        tmp += tiempo_muerte*tp
    else:  
        tn = t / len(n)
        tiempo_muerte = (n[0] - tmn) / tn
        tmn += tiempo_muerte*tn

    tiempo += tiempo_muerte
    #print(tiempo)

    lpi = 0
    for i in range(len(p)):
        p[i] -= tmp
        if p[i] <= 0:
            lpi += 1
        else:
            p[i] += tmp
            break
    if lpi >= len(p):
        p = []
    else:
        p = p[lpi:]
        
    lni = 0
    for i in range(len(n)):
        n[i] -= tmn
        if n[i] <= 0:
            lni += 1
        else:
            n[i] += tmn
            break
    if lni >= len(n):
        n = []
    else:
        n = n[lni:]
    #print(p, n, tmp, tmn)
    
print(tiempo)