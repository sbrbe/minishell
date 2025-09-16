# Minishell

Minishell est un projet de l’école 42 qui consiste à recréer un shell basique en C, inspiré de **bash**.  
Il permet de mieux comprendre le fonctionnement interne des shells Unix (lecture des commandes, parsing, gestion des processus, redirections…).

---

## 📖 Fonctionnalités

- **Affichage d’un prompt** interactif et attente de commandes.  
- **Exécution de commandes simples** via `execve`.  
- **Gestion du PATH** pour retrouver les binaires.  
- **Arguments et options** passés aux programmes.  
- **Redirections** :
  - `>` sortie vers un fichier (écrasement)
  - `>>` sortie vers un fichier (ajout)
  - `<` entrée depuis un fichier
  - `<<` heredoc
- **Pipes** (`|`) pour chaîner plusieurs commandes.  
- **Variables d’environnement** (lecture, modification, export).  
- **Signaux** :
  - `Ctrl-C` → interrompt la commande en cours
  - `Ctrl-\` → ignoré
  - `Ctrl-D` → quitte le shell  
- **Builtins** implémentés :  
  - `echo` (avec `-n`)
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`

---
## 📂 Organisation

- **includes** : définitions, includes et structures.  
- **srcs/parsing/** : analyse des commandes, gestion des tokens et redirections.  
- **srcs/ft_ex/ && srcs/pipex** : exécution des commandes, pipes, forks, dup2.  
- **srcs/builtins/** : fonctions internes au shell (`cd`, `echo`, etc.).  
- **srcs/utiles/** : librairie perso réutilisée.  
- **srcs/add_signal/** : signaux `Ctrl-C`, `Ctrl-\`, `Ctrl-D`.  
- **srcs/get_pwd/** :  Le shell affiche le chemin courant (`PWD`) en couleur, afin de mieux repérer dans quel dossier on se trouve.  
- **.val.supp** : fichier de suppression utilisé par **Valgrind** pour ignorer les faux positifs de fuites mémoire liés à la lib `readline` et autres fonctions système.  

---
## ⚙️ Compilation

Pour compiler :  

```bash
make
```

Cela génère l’exécutable :
```bash
./minishell
```
Pour compiler avec valgrind:
```bash
valgrind --suppressions=.val.supp --leak-check=full ./minishell
```
