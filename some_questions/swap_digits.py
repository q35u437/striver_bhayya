#JP morgan swap the adjacent digits so that the resulting number is bigger

string = list(input())
index, length = 0, len(string)
while index < length-1:
    if string[index] >= string[index+1]:
        index+=1
        continue
    elif string[index] < string[index+1]:
        if int(string[index]) % 2 == int(string[index+1]) % 2:
            string[index], string[index+1] = string[index+1], string[index]
            if index==0:
                index+=1
                continue
            index-=1
        else:
            index+=1
print(string)
