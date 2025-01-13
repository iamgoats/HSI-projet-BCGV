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
    uint8_t udpFrame[FRAME_SIZE];    // Buffer pour stocker la trame UDP
    uint8_t previous_frame_number = 0x00;   // Numéro de trame précédent (initialisé à une valeur hors limites)
    int32_t ret;                     // Code de retour des fonctions API
    app_data_t data;            // Structure applicative pour stocker les données de la trame
    
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
            if (udpFrame[0] != previous_frame_number + 1) {
                printf("Attention : trame manquée. Numéro attendu : %u, reçu : %u\n", previous_frame_number + 1, udpFrame[0]);
            }

            // Décodage de la trame
            decode_frame_udp(udpFrame, &data);

            // Stockage du numéro de trame actuel avec gestion du débordement
            if (data.frame_number < 100) {
                previous_frame_number = data.frame_number;
            } else {
                previous_frame_number = 0x00;
            }

            printf("Trame UDP décodée : %d\n", data.frame_number);
        } else {
            printf("Erreur : échec de lecture de la trame UDP (code %d).\n", ret);
        }
    }
    drv_close(drvFd);
    return 0;
}

/*
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h> // Pour sleep (si nécessaire pour des pauses simulées)
#include "drv_api.h"

#define FRAME_SIZE DRV_UDP_100MS_FRAME_SIZE

// Fonction pour afficher le contenu d'une trame UDP
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
    uint8_t previous_frame_number = 0xFF; // Numéro de trame précédent (initialisé à une valeur hors limites)
    bool first_frame = true;         // Indicateur pour la première trame

    printf("Ouverture du driver...\n");
    drvFd = drv_open();
    if (drvFd < 0) {
        printf("Erreur : impossible d'ouvrir le driver.\n");
        return -1;
    }

    printf("Lecture des trames UDP (Ctrl+C pour quitter)...\n");
    while (true) {
        // Lecture d'une trame UDP
        ret = drv_read_udp_100ms(drvFd, udpFrame);
        if (ret == DRV_SUCCESS) {
            uint8_t current_frame_number = udpFrame[0]; // Premier octet : numéro de trame
            
            // Vérification du numéro de trame
            if (!first_frame) {
                uint8_t expected_frame_number = (previous_frame_number + 1) % 256; // Gestion du débordement
                if (current_frame_number != expected_frame_number) {
                    printf("Attention : trame manquée. Numéro attendu : %u, reçu : %u.\n", 
                           expected_frame_number, current_frame_number);
                }
            } else {
                first_frame = false; // La première trame n'a pas de trame précédente à comparer
            }

            // Affichage de la trame
            display_udp_frame(udpFrame);

            // Mise à jour du numéro de trame précédent
            previous_frame_number = current_frame_number;
        } else {
            printf("Erreur : échec de lecture de la trame UDP (code %d).\n", ret);
        }
    }

    // Fermeture du driver (normalement non atteint avec une boucle infinie)
    drv_close(drvFd);
    return 0;
}

*/