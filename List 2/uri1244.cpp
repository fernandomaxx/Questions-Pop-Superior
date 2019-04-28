n = int(input())

while (n):
    
    text = input()
    out = ""
    lista = [[] for _ in range(51)]
    result = text.split(" ")
    
    for item in result:
        lista[len(item)].append(item)
    
    for i in range(50, 0, -1):
        for string in lista[i]:
            out += string + " "
    
    for i in range(0, len(out)-1):
        print(out[i], end="")
    print ("")
    n = n -1