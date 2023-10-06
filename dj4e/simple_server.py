import socket as so
import time
def createServer():
  server_sock = so.socket(so.AF_INET, so.SOCK_STREAM)

  try:
    server_sock.bind(('localhost', 9000))
    server_sock.listen(5)
    while 1:
      time.sleep(4)
      print('waiting...')
  except KeyboardInterrupt:
    print('interrupt detected...')
  
  print('\nshutting down...\n')  
  server_sock.close()

print('starting server on localhost:9000\n')
createServer()