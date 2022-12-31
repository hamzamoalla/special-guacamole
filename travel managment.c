//(hamza moalla + mohamed ali dhuib II1c)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Trip {
  char name[100];
  char destination[100];
  int date_debut;
  int date_fin;
  int price;
  struct Trip *next;
};

struct Trip *first_trip = NULL;

// Ajoute un voyage a la liste chainee
void ajout_voy(struct Trip trip) {
  struct Trip *new_trip;
  new_trip = (struct Trip*)malloc(sizeof(struct Trip));
  *new_trip = trip;
  new_trip->next = first_trip;
  first_trip = new_trip;
}

// Affiche la description d'un voyage
void affiche_voy(char *name) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (strcmp(current_trip->name, name) == 0) {
      printf("Nom : %s\n", current_trip->name);
      printf("Destination : %s\n", current_trip->destination);
      printf("Dates : %d - %d\n", current_trip->date_debut, current_trip->date_fin);
      printf("Prix : %d\n", current_trip->price);
      break;
    }
    current_trip = current_trip->next;
  }
}

// Supprime un voyage de la liste cha�n�e
void supp_voy(char *name) {
  struct Trip *current_trip;
  struct Trip *prev_trip;
  current_trip = first_trip;
  prev_trip = NULL;
  while (current_trip != NULL) {
    if (strcmp(current_trip->name, name) == 0) {
      if (prev_trip == NULL) {
        first_trip = current_trip->next;
      } else {
        prev_trip->next = current_trip->next;
      }
      free(current_trip);
      break;
    }
    prev_trip = current_trip;
    current_trip = current_trip->next;
  }
}

// Modifie un voyage de la liste cha�n�e
void modif_voy(char *name) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (strcmp(current_trip->name, name) == 0) {
      printf("Entrez les nouvelles informations sur le voyage :\n");
      printf("Nom : ");
      scanf("%s", current_trip->name);
      printf("Destination : ");
      scanf("%s", current_trip->destination);

  printf("Date de debut (jjmmaaaa) : ");
  scanf("%d", &current_trip->date_debut);
  printf("Date de fin (jjmmaaaa) : ");
  scanf("%d", &current_trip->date_fin);
  printf("Prix : ");
  scanf("%d", &current_trip->price);
  break;
}
current_trip = current_trip->next;
}
}

// Recherche les voyages disponibles entre deux dates
void rechercher_voy(int date_debut, int date_fin) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (current_trip->date_debut >= date_debut && current_trip->date_fin <= date_fin) {
      printf("Nom : %s\n", current_trip->name);
      printf("Destination : %s\n", current_trip->destination);
      printf("Dates : %d - %d\n", current_trip->date_debut, current_trip->date_fin);
      printf("Prix : %d\n", current_trip->price);
    }
    current_trip = current_trip->next;
  }
}

// Affiche la liste de tous les voyages de la liste cha�n�e
void affiche_tout_voy() {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    printf("Nom : %s\n", current_trip->name);
    printf("Destination : %s\n", current_trip->destination);
    printf("Dates : %d - %d\n", current_trip->date_debut, current_trip->date_fin);
    printf("Prix : %d\n", current_trip->price);
    current_trip = current_trip->next;
  }
}

int main() {
  int choice;
  do {
    printf("Menu :\n");
    printf("1. Ajouter un voyage\n");
    printf("2. Afficher la description d'un voyage\n");
    printf("3. Supprimer un voyage\n");
    printf("4. Modifier un voyage\n");
    printf("5. Rechercher des voyages disponibles entre deux dates\n");
    printf("6. Afficher la liste de tous les voyages\n");
    printf("7. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        struct Trip trip;
        printf("Entrez les informations sur le voyage a ajouter :\n");
        printf("Nom : ");
        scanf("%s", trip.name);
        printf("Destination : ");
        scanf("%s", trip.destination);
        printf("Date de debut (jjmmaaaa) : ");
        scanf("%d", &trip.date_debut);
        printf("Date de fin (jjmmaaaa) : ");
        scanf("%d", &trip.date_fin);
        printf("Prix : ");
        scanf("%d", &trip.price);
        ajout_voy(trip);
        break;
      }
      case 2: {
        char name[100];
                printf("Entrez le nom du voyage a afficher : ");
        scanf("%s", name);
        affiche_voy(name);
        break;
      }
      case 3: {
        char name[100];
        printf("Entrez le nom du voyage a supprimer : ");
        scanf("%s", name);
        supp_voy(name);
        break;
      }
      case 4: {
        char name[100];
        printf("Entrez le nom du voyage a modifier : ");
        scanf("%s", name);
        modif_voy(name);
        break;
      }
      case 5: {
        int date_debut, date_fin;
        printf("Entrez la date de debut (jjmmaaaa) : ");
        scanf("%d", &date_debut);
        printf("Entrez la date de fin (jjmmaaaa) : ");
        scanf("%d", &date_fin);
        rechercher_voy(date_debut, date_fin);
        break;
      }
      case 6: {
        affiche_tout_voy();
        break;
      }
      case 7: {
        printf("Au revoir !\n");
        break;
      }
      default: {
        printf("Choix incorrect.\n");
        break;
      }
    }
  } while (choice != 7);
  return 0;
}


