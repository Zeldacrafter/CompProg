import random
import subprocess

iterations = 1000000;
maxbits = 50000
minbits = 1

p = subprocess.Popen(["./a.out"], stdout=subprocess.PIPE,
                     stdin=subprocess.PIPE,
                     stderr=subprocess.PIPE)
i = 1
while 1:
    if (i % 10000 == 0):
        print(i)
    a = random.getrandbits(random.randrange(minbits, maxbits + 1))
    b = random.getrandbits(random.randrange(minbits, maxbits + 1))
    if bool(random.getrandbits(1)):
        a *= -1
    if bool(random.getrandbits(1)):
        b *= -1
    op = random.choice(['+', '-', '*'])
    erg = 0
    if op == '+':
        erg = a + b
    elif op == '-':
        erg = a - b
    else:
        erg = a * b

    p.stdin.write(f'{op} {a} {b}\n'.encode())
    p.stdin.flush()
    outs = p.stdout.readline().decode().rstrip()
    if outs != str(erg):
        print(a)
        print(op)
        print(b)
        print('=')
        print(erg)
        print("false:")
        print(outs)
        f = open("wrong.in", "w")
        f.write(f"{op}\n{a}\n{b}\n")
        f.close()
        f = open("wrong.out", "w")
        f.write(str(erg) + '\n')
        f.close()
    i += 1

p.stdin.write('q'.encode())
p.stdin.flush()
p.wait();

print("100/100")
