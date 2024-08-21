#choripunk
n = int(input())
grid = []
for _ in range(n):
    fila = input()
    grid.append(fila)
count = 0
for i in range(n):
    j=0
    while j+1 < n:
        if grid[i][j] == "N" and grid[i][j+1] == "N":
            count +=1
            j+=1
        j+=1
print(count)