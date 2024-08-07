# barbershop_tcp
Test program to work with local network based on tcp connection:
  1. **server.c** illustrates barber sleeping without clients and working with them.
  2. **client.c** illustrates cliets visiting barbershop.
  3. **log.c** illustrates logger program that outputs all actions in local network.

Rules:
  1. Working server must be one.
  2. May be more then one client.
  3. Clients work independently of each other.
  4. May be more then one logger.
  5. Loggers work independently of each other.
  6. Running order: server -> loggers -> clients.
