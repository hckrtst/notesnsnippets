import socket as so
import time
def createServer():
  server_sock = so.socket(so.AF_INET, so.SOCK_STREAM)

  try:
    server_sock.bind(('localhost', 9000))
    server_sock.listen(5)
    while 1:
      client_sock, address = server_sock.accept()
      print(f'accepted from {client_sock}')
  except KeyboardInterrupt:
    print('interrupt detected...')
  
  print('\nshutting down...\n')  
  server_sock.close()

print('starting server on localhost:9000\n')
createServer()