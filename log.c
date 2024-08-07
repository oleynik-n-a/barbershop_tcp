#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>

#define BACKLOG 10

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("=============\n");
    printf(" Запуск лога \n");
    printf("=============\n\n");

    // Создание сокета
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // Подключение к серверу
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("connect() error");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (1) {
        struct pollfd pfd;
        pfd.fd = sockfd;
        pfd.events = POLLIN;
        poll(&pfd, 1, -1);
        if (read(sockfd, buffer, sizeof(buffer)) == -1) {
            perror("read() error");
            exit(EXIT_FAILURE);
        }

        if (buffer[0] != '*') {
            printf("%s", buffer);
        }
    }

    return 0;
}
