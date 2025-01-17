# HSI-projet-BCGV

# Question 1 : 

Dans cette question, il nous a été demandé de concevoir et de documenter les données applicatives utilisées dans notre  calculateur. Nous avons ainsi créé deux tableaux, un pour les types de données et un pour les données applicatives afin d'avoir une structure claire 

# Question  2 : 

Création d'une bibliothèque statique en C, contenant :

    - Les définitions des types 
    - Une structure applicative (app_data_t) avec ses getters et setters 
    - Une fonction d'initialisation et des outils pour le décodage et la validation de trames UDP
Pour cela,  on analyse les fichiers CSV de la Q1 afin de définir les types et les champs puis on génère automatiquement les app_data à l'aide du script

# Question 3   

L'objectif ici est de développer une application qui lit et affiche les trames UDP envoyées toutes les 100 ms par le calculateur MUX à l'aide des fonctions de l'API drv_api.a.
Pour cela, on a implémenté donc une fonction main nous permettant d'avoir les trames UDP sous forme hexadécimale toutes les 100 ms

# Question 4 : 

Il nous est demandé ici d'adapter une machine à états finis pour gérer différents comportements du système, en s'appuyant sur des événements périodiques. Il est nécessaire ici de remplacer les états et événements génériques par ceux de l'application et d'adapter le main.

# Question 5 : 

Nous devons créé un environnement de compilation pour l'application, la librairie statique, ainsi qu'un script permettant de lancer simultanément le driver et l'application d'où la création de trois makefiles. A la fin, nous avons l'application qui est compilée et liée à la librairie et le script bash qui lance le driver et l'application

# Question 6 : 

Ici nous avons créé une fonction de décodage qui met à jour la structure applicative en fonction des trames reçues (COMODO et MUX) du driver.

# Question 7 

# Question 8 
