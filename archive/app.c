#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h> // Pour sleep (si nécessaire pour des pauses simulées)
#include "drv_api.h"

#define FRAME_SIZE DRV_UDP_100MS_FRAME_SIZE

void display_udp_frame(const uint8_t *frame) {
    printf("Trame UDP reçue : ");
    for (int i = 0; i < FRAME_SIZE; i++) {
        printf("%02X ", frame[i]);
    }
    printf("\n");
}


int main(void) {
    int32_t drvFd;                   // Descripteur de fichier du driver
    uint8_t udpFrame[FRAME_SIZE];    // Buffer pour stocker la trame UDP
    int32_t ret;                     // Code de retour des fonctions API

    printf("Ouverture du driver...\n");
    drvFd = drv_open();
    if (drvFd < 0) {
        printf("Erreur : impossible d'ouvrir le driver.\n");
        return -1;
    }

    printf("Lecture des trames UDP (Ctrl+C pour quitter)...\n");
    while (true) {
        ret = drv_read_udp_100ms(drvFd, udpFrame);
        if (ret == DRV_SUCCESS) {
            display_udp_frame(udpFrame);
        } else {
            printf("Erreur : échec de lecture de la trame UDP (code %d).\n", ret);
        }
    }

    // Fermeture du driver (normalement non atteint avec une boucle infinie)
    drv_close(drvFd);
    return 0;
}
