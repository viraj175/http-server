#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        printf("Socket Failed!\n");
        return -1;
    }

    struct sockaddr_in serveraddr = {0};
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8080);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    bind(socket_fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    listen(socket_fd, 10);
    int client_fd = accept(socket_fd, NULL, NULL);

    char buffer[1024] = {0};
    read(client_fd, buffer, sizeof(buffer));

    printf("%s\n", buffer);

    return 0;
}
