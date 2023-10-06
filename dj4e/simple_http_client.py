import urllib.request as request

resp = request.urlopen('http://localhost:9000/romeo.txt')

for line in resp:
  print(line.decode().strip())
