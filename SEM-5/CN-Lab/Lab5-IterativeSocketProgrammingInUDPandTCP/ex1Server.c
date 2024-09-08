#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#define PORTNO 10250

int isPresent(char ch, char character[], int index) {
    for (int i = 0; i < strlen(character); i++) {
        if (i == index)
            continue;
        else if (ch == character[i])
            return 1;
    }
    return 0;
}

int count(char ch, char buffer[]) {
    int occ = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        if (ch == buffer[i])
            occ++;
    }
    return occ;
}

int main() {
    printf("Server running...\n");
    int socket_id = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddress;
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = inet_addr("192.168.10.10");
    serveraddress.sin_port = htons(PORTNO);

    bind(socket_id, (struct sockaddr *)&serveraddress, sizeof(serveraddress));
    listen(socket_id, 5);

    while (1) {
        char buffer[256], result[256], character[256];
        int unique_count = 0, frequency[256];

        struct sockaddr_in clientaddress;
        socklen_t client_len = sizeof(clientaddress);
        int new_socket_id = accept(socket_id, (struct sockaddr *)&clientaddress, &client_len);
        
        read(new_socket_id, buffer, sizeof(buffer));
        if (strcmp(buffer, "Stop") == 0)
            break;
        
        for (int i = 0; i < 256; i++) {
            frequency[i] = 0;
            character[i] = '\0';
            result[i] = '\0';
        }

        for (int i = 0; i < strlen(buffer); i++) {
            if (isPresent(buffer[i], character, i)) {
                character[i] = '$';
                frequency[i] = -1;
            } else {
                frequency[i] = count(buffer[i], buffer);
                character[i] = buffer[i];
                result[unique_count] = character[i];
                unique_count++;
            }
        }
        write(new_socket_id, result, sizeof(result));
        close(new_socket_id);
    }
    close(socket_id);
    return 0;
}