#!/bin/bash

# Vérification que les binaires existent
if [ ! -f "./driver" ]; then
    echo "Erreur : l'exécutable 'driver' est introuvable."
    exit 1
fi

if [ ! -f "./app" ]; then
    echo "Erreur : l'exécutable 'app' est introuvable."
    exit 1
fi

# Lancer le driver en arrière-plan
echo "Lancement du driver..."
./driver &

# Stocker le PID du driver
DRIVER_PID=$!

# Lancer l'application
echo "Lancement de l'application..."
./app

# Arrêter le driver après que l'application se termine
echo "Arrêt du driver..."
kill $DRIVER_PID
