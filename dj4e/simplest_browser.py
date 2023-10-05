import socket

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(('data.pr4e.org', 80))
print(f'Raw command looks like: GET http://data.pr4e.org/page1.htm HTTP/1.0\r\n\r\n')
cmd = 'GET http://data.pr4e.org/page1.htm HTTP/1.0\r\n\r\n'.encode()
print(f"My encoded command looks like: {cmd}\n")
mysock.send(cmd)
while 1:
  data = mysock.recv(512)
  if len(data) < 1:
    break
  print(f'Raw data looks like: {data}\n')
  print(f'Decoded data: {data.decode()}', end='')
print('')  
mysock.close()


