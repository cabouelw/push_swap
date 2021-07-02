import os, random
def gen(mi, ma, num):
    l = []
    for i in range(num):
        r = random.randint(mi, ma)
        while(r in l) :
            r = random.randint(mi, ma)
        l.append(r)
    return " ".join( (str(i) for i in l) )
def pR(l):
    for el in l: print(el,end=" ")
i = 0
mi = 100000
ma = 0
avg = 0
n = 50
OK = 0
while (i < n):
    ran = gen(-2147483648, 2147483647, 100)
    valid = os.popen(f"./push_swap {ran} | ./checker_Mac {ran} | tail -1").read()[:-1]
    num = os.popen(f"./push_swap {ran} | wc -l").read()[:-1]
    tem = int(num)
    if valid == "OK":
        OK += 1
        avg += tem
        if tem < mi:
            mi = tem
        if tem > ma:
            ma = tem
    else:
        print("KO")
        print(ran)
        break
    zero = "0" if (tem < 10) else ""
    print(f"{valid} - {zero}{tem} | min: {mi} - max: {ma}")
    # print(" - - - - - - - - - - - - -")
    i += 1
print(f"min: {mi}  max: {ma}  avg: {avg/OK}")