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
## ⚙️ Compilation

Pour compiler :  

```bash
make
```

Cela génère l’exécutable :

./minishell

Pour compiler avec valgrind:

valgrind --suppressions=.val.supp --leak-check=full ./minishell
