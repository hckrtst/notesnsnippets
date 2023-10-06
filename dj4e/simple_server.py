import socket as so
import time
def createServer():
  server_sock = so.socket(so.AF_INET, so.SOCK_STREAM)
  # makes sure we can re-use same port right away after shutting down
  server_sock.setsockopt(so.SOL_SOCKET, so.SO_REUSEADDR, 1)

  try:
    server_sock.bind(('localhost', 9000))
    server_sock.listen(5)
    hits = 0
    while 1:
      client_sock, address = server_sock.accept()
      rd = client_sock.recv(5000).decode()
      hits += 1
      pieces = rd.split('\n')
      if len(pieces) > 0: print(pieces[0])
      data = "HTTP/1.1 200 OK\r\n"
      data += 'Content-Type: text/html; charset=utf-8\r\n\r\n'
      data += "<html><body>Hello from server</body></html>\r\n\r\n"
      print(data)
      client_sock.sendall(data.encode())
      client_sock.shutdown(so.SHUT_WR)
  except KeyboardInterrupt:
    print('interrupt detected...')
  
  print('\nshutting down...\n')  
  server_sock.close()

print('starting server on localhost:9000\n')
createServer()