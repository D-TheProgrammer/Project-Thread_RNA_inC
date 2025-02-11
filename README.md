## Projet : Simulation de Portes Logiques avec Threads et Réseau de Neurones Artificiels (RNA) en C
## Project: Logic Gate Simulation with Threads and Artificial Neural Network (ANN) in C

[French] Application permettant de simuler des portes logiques avec des threads, un réseau de neurones artificiels et un système client-serveur via sockets.  
[English] An application to simulate logic gates using threads, an artificial neural network, and a client-server system via sockets.


## SOMMAIRE / SUMMARY  
- [Présentation en français / Presentation in French](#français)  
- [Présentation en anglais / Presentation in English](#english)  


## __[FRANÇAIS]__  
### Présentation  
Ce projet est divisé en plusieurs parties :
- **Gestion des threads** : Utilisation des threads pour paralléliser les calculs.
- **Simulation de portes logiques** : Réalisation d'opérations logiques (ET, OU, XOR) à l’aide de threads.
- **Réseau de Neurones Artificiels (RNA)** : Entraînement d’un modèle pour apprendre les portes logiques.
- **Système client-serveur** : Communication via sockets pour envoyer/recevoir des données, y compris des images et vidéos.


## Fonctionnalités

### Communication client-serveur :
- Ensemble de fichier basé sur la créaton de thread et sockets

### Gestion des Threads :
- Exécution parallèle des opérations **AND, OR, XOR**.
- Synchronisation et gestion efficace des threads.

### Réseau de Neurones Artificiels (RNA) :
- **Apprentissage des portes logiques** grâce à un réseau neuronal.
- **Algorithme de rétropropagation** pour ajuster les poids du modèle.
- **Prédiction des résultats logiques** après entraînement.


## Comment exécuter le projet ?

### Compilation et exécution des programmes de gestion de threads :
```sh
gcc -g -pthread tp1_applicatif_1.c -o tp1_applicatif_1
./tp1_applicatif_1.exe

gcc -g -pthread tp1_applicatif_2.c -o tp1_applicatif_2
./tp1_applicatif_2.exe

gcc -g -pthread tp1_applicatif_3_1.c -o tp1_applicatif_3_1
./tp1_applicatif_3_1.exe

gcc -g -pthread tp1_applicatif_3_2.c -o tp1_applicatif_3_2
./tp1_applicatif_3_2.exe

gcc -g -pthread tp1_applicatif_3_3.c -o tp1_applicatif_3_3
./tp1_applicatif_3_3.exe
```

### Exécuter le programme des portes logiques avec threads :
```sh
gcc -g -pthread Thread_porteLogique.c -o Thread_porteLogique
./Thread_porteLogique.exe
```

### Exécuter le programme des portes logiques avec threads :
```sh
gcc -g -pthread Projet_RNA.c -o Projet_RNA
./Projet_RNA.exe
```


## Comment exécuter le projet ?
### Lancement du serveur :
```sh
gcc -o serveur serveur.c
./serveur
```

### Lancement du client :
```sh
gcc -o client client.c
./client
```

### Lancement du client :
```sh
RNA      # Entraînement et test du réseau de neurones
IMAGE    # Envoi d’une image au serveur
VIDEO    # Envoi d’une vidéo au serveur
COMPTER  # Comptage des mots dans un message
QUITTER  # Fermeture de la connexion
```

## Détails Techniques
- Sockets : Communication TCP entre client et serveur.
- Threads : Gestion parallèle des calculs.
- RNA : Algorithme d’apprentissage supervisé pour ajuster les poids neuronaux.
- Transmission de fichiers : Gestion de l’envoi et réception d’images et vidéos via sockets.



---
---
## __[ENGLISH]__  
### Presentation  

This project is divided into several parts:
- **Thread Management**: Using threads to parallelize calculations.
- **Logic Gate Simulation**: Performing logical operations (AND, OR, XOR) using threads.
- **Artificial Neural Network (ANN)**: Training a model to learn logic gates.
- **Client-Server System**: Communication via sockets to send/receive data, including images and videos.


## Features

### Client-Server Communication:
- Set of files based on the creation of threads and sockets

### Thread Management:
- Parallel execution of **AND, OR, XOR** operations.
- Synchronization and efficient thread management.

### Artificial Neural Network (ANN):
- **Logic gate learning** using a neural network.
- **Backpropagation algorithm** to adjust the model weights.
- **Logic outcome prediction** after training.
- 

## How to run the project?

### Compiling and running thread management programs:
```sh
gcc -g -pthread tp1_applicatif_1.c -o tp1_applicatif_1
./tp1_applicatif_1.exe

gcc -g -pthread tp1_applicatif_2.c -o tp1_applicatif_2
./tp1_applicatif_2.exe

gcc -g -pthread tp1_applicatif_3_1.c -o tp1_applicatif_3_1
./tp1_applicatif_3_1.exe

gcc -g -pthread tp1_applicatif_3_2.c -o tp1_applicatif_3_2
./tp1_applicatif_3_2.exe

gcc -g -pthread tp1_applicatif_3_3.c -o tp1_applicatif_3_3
./tp1_applicatif_3_3.exe
```

### Run the logic gate program with threads:
```sh
gcc -g -pthread Thread_porteLogique.c -o Thread_porteLogique
./Thread_porteLogique.exe
```

### Run the logic gate program with threads:
```sh
gcc -g -pthread Projet_RNA.c -o Projet_RNA
./Projet_RNA.exe
```

## How to run the project?
### Server launch:
```sh
gcc -o server server.c
./server
```

### Client launch:
```sh
gcc -o client client.c
./client
```

### Client launch:
```sh
RNA # Training and testing the neural network
IMAGE # Sending an image to the server
VIDEO # Sending a video to the server
COUNT # Counting words in a message
QUIT # Closing the connection
```

## Technical details
- Sockets: TCP communication between client and server.
- Threads: Parallel management of calculations.
- RNA: Supervised learning algorithm to adjust neural weights.
- File transmission: Management of sending and receiving images and videos via sockets.

