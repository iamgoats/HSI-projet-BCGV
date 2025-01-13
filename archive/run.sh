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

# Vérification des permissions d'exécution
if [ ! -x "./driver" ]; then
    echo "Erreur : l'exécutable 'driver' n'a pas les permissions d'exécution."
    chmod +x ./driver
    echo "Permissions d'exécution ajoutées au 'driver'."
fi

if [ ! -x "./app" ]; then
    echo "Erreur : l'exécutable 'app' n'a pas les permissions d'exécution."
    chmod +x ./app
    echo "Permissions d'exécution ajoutées à 'app'."
fi

# Lancer le driver en arrière-plan
echo "Lancement du driver..."
./driver &

# Stocker le PID du driver
DRIVER_PID=$!

# Vérifier si le driver s'est lancé correctement
sleep 2 # Attente pour s'assurer que le driver a eu le temps de se lancer
if ! kill -0 $DRIVER_PID 2>/dev/null; then
    echo "Erreur : le driver n'a pas démarré correctement."
    exit 1
fi

echo "Driver lancé avec succès (PID: $DRIVER_PID)."

# Lancer l'application
echo "Lancement de l'application..."
./app
APP_EXIT_CODE=$?

# Arrêter le driver après que l'application se termine
echo "Arrêt du driver..."
kill $DRIVER_PID 2>/dev/null
if [ $? -eq 0 ]; then
    echo "Driver arrêté avec succès."
else
    echo "Erreur : impossible d'arrêter le driver (PID: $DRIVER_PID)."
fi

# Vérification du statut de sortie de l'application
if [ $APP_EXIT_CODE -ne 0 ]; then
    echo "Erreur : l'application a rencontré un problème (code de sortie: $APP_EXIT_CODE)."
    exit $APP_EXIT_CODE
fi

echo "Exécution terminée avec succès."
