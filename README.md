# READ ME

## Projet JOinParis

### Aperçu
Le projet JOinParis est une application en C conçue pour aider à suivre et gérer les données de performance des athlètes en préparation pour les prochains Jeux Olympiques. Cette application permet aux entraîneurs de stocker, mettre à jour et analyser les performances des athlètes lors des sessions d'entraînement.

### Développeurs
- **Sayed Sanem**
- **Achour Hajar**
- **Choudhury Dimittri**

### Prérequis
Avant d'exécuter le programme, vous devez installer certains packages essentiels sur votre système. Utilisez les commandes suivantes dans le terminal :

```bash
sudo apt-get update
sudo apt-get install -y build-essential gnuplot
```

### Compilation et Exécution
Pour compiler et exécuter le programme, utilisez les commandes suivantes :

1. **Compiler le programme :**
   ```bash
   gcc -o main main_JOinParis.c functions_JOinParis.c imports_and_variables_JOinParis.c
   ```

2. **Exécuter le programme :**
   ```bash
   ./main
   ```

### Structure du Projet
Le projet se compose de plusieurs fichiers sources et en-tête :

- **main_JOinParis.c :** Le fichier principal qui contient la logique de base et l'interface utilisateur.
- **functions_JOinParis.c :** Contient l'implémentation de diverses fonctions utilisées dans le programme.
- **imports_and_variables_JOinParis.c :** Contient les imports nécessaires et les déclarations de variables globales.
- **functions_JOinParis.h :** Fichier en-tête pour les déclarations de fonctions.
- **imports_and_variables_JOinParis.h :** Fichier en-tête pour les imports et les déclarations de variables.
- **structures_JOinParis.h :** Fichier en-tête pour les définitions de structures.

### Fonctionnalités
Le programme offre les fonctionnalités suivantes :

1. **Ajouter une nouvelle performance :**
   - Entrer le nom de l'athlète, la date, l'événement, le temps et la position (si applicable).
   - Stocker les données de performance dans un fichier nommé d'après l'athlète.

2. **Afficher l'historique des performances :**
   - Voir les données de performance historiques d'un athlète.

3. **Afficher les statistiques de performance :**
   - Voir des statistiques telles que le meilleur, le pire et le temps moyen pour un athlète dans un événement spécifique.

4. **Afficher la tendance des performances de l'athlète :**
   - Choisir entre afficher la progression entre deux dates ou une régression linéaire des tendances de performance.

5. **Trouver les 3 meilleurs athlètes pour un événement :**
   - Déterminer et afficher les 3 meilleurs athlètes pour un événement donné en fonction de leurs performances.

6. **Quitter le programme :**
   - Quitter l'application en toute sécurité, en veillant à ce que toute la mémoire allouée soit libérée.

### Instructions d'Utilisation
Lorsque vous exécutez le programme, suivez ces étapes pour utiliser ses fonctionnalités :

1. **Entrer le nom de l'athlète :**
   - Saisissez le nom de l'athlète dont vous souhaitez gérer les données. Si l'athlète n'a pas de fichier existant, le programme en créera un.

2. **Sélectionner une option :**
   - Le programme vous demandera de choisir une option dans le menu pour ajouter une performance, voir l'historique, voir les statistiques, analyser les tendances de performance, trouver les meilleurs athlètes ou quitter.

3. **Suivre les instructions :**
   - Selon votre choix, suivez les instructions pour entrer les données nécessaires telles que la date, l'événement et les temps de performance.

### Stockage des Données
- Les données de performance de chaque athlète sont stockées dans un fichier séparé nommé d'après l'athlète (par exemple, `athlete_name.txt`).
- Pour les événements de relais, le programme garantit qu'une seule performance de relais est enregistrée par jour.

### Gestion des Erreurs
Le programme inclut une gestion des erreurs pour gérer les entrées invalides et les opérations de fichiers. Assurez-vous de suivre correctement les instructions pour éviter les interruptions.

### Informations Supplémentaires
Pour plus de détails et d'améliorations, consultez le rapport du projet et la documentation fournis avec les fichiers sources. Cela inclut :

- Des explications détaillées sur les fonctions et les structures.
- Des fonctionnalités supplémentaires et des améliorations.
- Des détails sur l'implémentation de la régression linéaire pour les tendances de performance.

Profitez de l'utilisation de l'application JOinParis et bonne chance pour le suivi des performances de vos athlètes !
