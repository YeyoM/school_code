#include <arpa/inet.h>
#include <cstring> // Para strlen()
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main() {

  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    perror("socket");
    return 1;
  } else {
    cout << "Socket de cliente creado." << endl;
  }

  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080); // Puerto del servidor
  serverAddress.sin_addr.s_addr =
      inet_addr("172.16.116.188"); // Dirección IP del servidor

  if (connect(clientSocket, reinterpret_cast<struct sockaddr *>(&serverAddress),
              sizeof(serverAddress)) == -1) {
    perror("connect");
    close(clientSocket);
    return 1;
  } else {
    cout << "Conectado al servidor." << endl;
  }

  const char *message = "Hola, servidor!";
  if (send(clientSocket, message, strlen(message), 0) == -1) {
    perror("send");
    close(clientSocket);
    return 1;
  } else {
    cout << "Mensaje enviado al servidor." << endl;
  }

  close(clientSocket);
  cout << "Socket de cliente cerrado." << endl;

  return 0;
}
