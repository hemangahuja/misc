from itertools import permutations
s1, op, s2,  s3 = (input() for _ in range(4))

s = set(s1) | set(s2) | set(s3)


for p in permutations(range(10), len(s)):

    inverse = dict(zip(s, p))

    n1, n2, n3 = (''.join(str(inverse[i]) for i in x) for x in (s1, s2, s3))
    try:
        if eval(f'{n1} {op} {n2} == {n3}'):
            print(f'{n1} {op} {n2} = {n3}', inverse)
    except:
        pass
