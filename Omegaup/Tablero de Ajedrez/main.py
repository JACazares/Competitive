_r, _c = input().split()
c = int(_c)
r = ord(_r) - ord('a')

if (r+c)%2 == 0:
  print("BLANCO")
else:
  print("NEGRO")
