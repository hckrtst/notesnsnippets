import socket
 
my_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_sock.connect(('localhost', 9000))
cmd = 'GET localhost/romeo.txt HTTP/1.0/\r\n\r\n'.encode()
my_sock.send(cmd)

while True:
  data = my_sock.recv(512)
  if len(data) < 1:
    break
  print(data.decode(), end='')

my_sock.close()