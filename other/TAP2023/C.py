#choripunk
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()
b = b[::-1]

c = []

for i in range(N):
    c.append(a[i] + b[i])

print(max(c) - min(c))