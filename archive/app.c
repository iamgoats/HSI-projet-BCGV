#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h> 
#include "drv_api.h"
#include "decodage.h"
#include "encodage.h"

#define FRAME_SIZE DRV_UDP_100MS_FRAME_SIZE

void display_udp_frame(const uint8_t *frame) {
    printf("Trame UDP reçue : ");
    for (int i = 0; i < FRAME_SIZE; i++) {
        printf("%02X ", frame[i]);
    }
    printf("\n");
}


int main(void) {
    int32_t drvFd;              // Descripteur de fichier du driver
    uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE];    // Buffer pour stocker la trame UDP
    uint8_t previousFrameNumber = 0x00;   // Numéro de trame précédent (initialisé à une valeur hors limites)
    int32_t retUdp;                     // Code de retour des fonctions API
    int32_t retSer;                 // Code de retour des fonctions API
    app_data_t udpData;            // Structure applicative pour stocker les données de la trame
    serial_frame_t serialData[SER_MAX_FRAME_SIZE];   // Structure applicative pour stocker les données de la trame
    uint32_t serialDataLen = SER_MAX_FRAME_SIZE;
    

    printf("Ouverture du driver...\n");
    drvFd = drv_open();
    if (drvFd < 0) {
        printf("Erreur : impossible d'ouvrir le driver.\n");
        return -1;
    }

    printf("Lecture des trames UDP (Ctrl+C pour quitter)...\n");
    while (true) {
        retUdp = drv_read_udp_100ms(drvFd, udpFrame);
        if (retUdp == DRV_SUCCESS) {
            if (udpFrame[0] != previousFrameNumber + 1) {
                printf("Attention : trame manquée. Numéro attendu : %u, reçu : %u\n", previousFrameNumber + 1, udpFrame[0]);
            }

            // Décodage de la trame
            decode_frame_udp(udpFrame, &udpData);

            // Stockage du numéro de trame actuel avec gestion du débordement
            if (udpData.frame_number < 100) {
                previousFrameNumber = udpData.frame_number;
            } else {
                previousFrameNumber = 0x00;
            }

            printf("Trame UDP décodée : %d\n", udpData.frame_number);
        } else {
            printf("Erreur : échec de lecture de la trame UDP (code %d).\n", retUdp);
        }

        //TODO: Finir lecture et décodage de la trame série
        // retSer = drv_read_ser(drvFd, serialData, serialDataLen);
        // if (retSer == DRV_SUCCESS) {
        //     printf("Trame série reçue : %d\n", serialData->serNum);
        // } else {
        //     printf("Erreur : échec de lecture de la trame série (code %d).\n", retSer);
        // }
        
    }
    drv_close(drvFd);
    return 0;
}


/*
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h> 
#include "drv_api.h"
#include "decodage.h"
#include "encodage.h"

#define FRAME_SIZE DRV_UDP_100MS_FRAME_SIZE

void display_udp_frame(const uint8_t *frame) {
    printf("Trame UDP reçue : ");
    for (int i = 0; i < FRAME_SIZE; i++) {
        printf("%02X ", frame[i]);
    }
    printf("\n");
}

int main(void) {
    int32_t drvFd;                     // Descripteur de fichier du driver
    uint8_t udpFrame[FRAME_SIZE];      // Buffer pour stocker la trame UDP
    uint8_t previous_frame_number = 0xFF; // Numéro de trame précédent (initialisé à une valeur invalide)
    int32_t ret;                       // Code de retour des fonctions API
    app_data_t data;                   // Structure applicative pour stocker les données de la trame
    
    printf("Ouverture du driver...\n");
    drvFd = drv_open();
    if (drvFd < 0) {
        printf("Erreur : impossible d'ouvrir le driver.\n");
        return -1;
    }

    printf("Lecture des trames UDP (Ctrl+C pour quitter)...\n");
    while (true) {
        //Attente de la trame UDP (100ms)
        ret = drv_read_udp_100ms(drvFd, udpFrame);
        if (ret != DRV_SUCCESS) {
            printf("Erreur : échec de lecture de la trame UDP (code %d).\n", ret);
            continue; // Passer à la prochaine itération
        }

        //Vérification du numéro de trame
        if (udpFrame[0] != previous_frame_number + 1) {
            printf("Attention : trame manquée. Numéro attendu : %u, reçu : %u\n", previous_frame_number + 1, udpFrame[0]);
        } else {
            printf("Numéro de trame correct : %u\n", udpFrame[0]);
        }

        previous_frame_number = udpFrame[0]; // Mettre à jour le numéro de trame précédent

        //Décodage de la trame UDP
        decode_frame_udp(udpFrame, &data);

        //Lecture ligne série si nécessaire
        if (data.frame_number % 2 == 0) { // Exemple : condition arbitraire pour simuler la lecture série
            printf("Lecture de la ligne série...\n");
            // Simuler une lecture série ici
        }

        //Encodage et écriture UDP
        printf("Encodage et écriture UDP...\n");
        encode_frame_udp(&data, udpFrame);
        drv_write_udp(drvFd, udpFrame);

        //Encodage et écriture Ligne Série
        printf("Encodage et écriture Ligne Série...\n");
        drv_write_serial(drvFd, udpFrame); 
    }

    drv_close(drvFd);
    return 0;
}

*/