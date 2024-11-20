#!/bin/bash

echo hello

# Message de bienvenue
echo "Hello"

# Chemin du fichier source C
fichier="../CodeC/main.c"

# Nom du fichier binaire généré
binaire="./main"



gcc "$fichier" -o "$binaire"

./$binaire

