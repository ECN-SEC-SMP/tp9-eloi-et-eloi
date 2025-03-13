/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 4 LES MAPS
 *        — Créez un code qui contient une std::map qui, pour chaque année, associe une liste
 *        d’évènements (sous la forme d’une std::list). Chaque évènement étant stocké dans une
 *        std::string. La map sera ordonnée dans l’ordre chronologique, mais les évènements as-
 *        sociés à une date donnée seront ordonnés suivant leur ordre d’entrée dans la structure.
 *        — Construisez une fonction ajoute_evenement qui ajoute un événement (date, intitulé)
 *        dans votre structure que vous passerez en paramètre.
 *        Remarque :
 *        — Il faut séparer les cas où l’on ajoute un événement dans une liste déjà existante, du
 *        cas où il faut ajouter une nouvelle liste dans la map.
 *        — Il est possible d’ajouter une entrée dans une map sous différentes formes :
 *        M[clé]=valeur ou M.insert(std::make_pair(clé,valeur))
 *        — Faites une fonction qui affiche l’ensemble des dates et des événements associés.
 *        — Faites des jeux d’essais en choisissant par exemple des dates historiques et des des-
 *        criptions associées. Pour vous inspirer, vous pouvez utiliser les données de dates.csv
 *        fourni.
 * @version 0.1
 * @date 13-03-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

/**
 * @brief Fonction qui ajoute un événement à la map
 *
 * @param events Map des événements
 * @param year   Année de l'événement
 * @param event  Description de l'événement
 */
void ajoute_evenement(map<int, list<string>> &events, int year, string event)
{
    // On vérifie si l'année existe déjà
    if (events.find(year) == events.end())
    {
        // Si l'année n'existe pas, on crée une nouvelle liste
        events[year] = list<string>();
    }

    // On ajoute l'événement à la liste
    events[year].push_back(event);
}

/**
 * @brief Affiche les événements de la map
 *
 * @param events Map des événements
 */
void affiche_evenements(map<int, list<string>> &events)
{
    // Affichage de la map
    for (auto &event : events) // On parcourt la map avec un itérateur auto
    {
        cout << "Événements de l'année " << event.first << " : " << endl; // On affiche l'année de l'événement
        for (auto &description : event.second)                            // On parcourt la liste d'événements avec un itérateur auto
        {
            cout << "  - " << description << endl; // On affiche la description de l'événement
        }
    }
}

/**
 * @brief main
 *
 * @return int
 */
int main()
{
    // Création de la map
    map<int, list<string>> events;

    // Ajout d'un événement
    events[2025].push_back("TP9 de SMP");
    events[2025].push_back("Voyage à l'étranger");
    events[2004].push_back("Naissance de Eloi");
    events[2000].push_back("Passage en l'an 2000");

    // Affichage de la map
    for (auto &event : events) // On parcourt la map avec un itérateur auto
    {
        cout << "Événements de l'année " << event.first << " : " << endl; // On affiche l'année de l'événement
        for (auto &description : event.second)                            // On parcourt la liste d'événements avec un itérateur auto
        {
            cout << "  - " << description << endl; // On affiche la description de l'événement
        }
    }

    // Construction de la map avec la fonction ajoute_evenement
    // Création d'une nouvelle map
    map<int, list<string>> events2;

    // Ajout d'événements
    ajoute_evenement(events2, 2025, "TP9 de SMP");
    ajoute_evenement(events2, 2025, "Voyage à l'étranger");
    ajoute_evenement(events2, 2004, "Naissance de Eloi");
    ajoute_evenement(events2, 2000, "Passage en l'an 2000");

    // Affichage de la map
    cout << endl
         << "Affichage de la map avec la fonction ajoute_evenement : " << endl
         << endl;
    affiche_evenements(events2);

    // Ajout des événements historiques
    ajoute_evenement(events2, -753, "Fondation de Rome");
    ajoute_evenement(events2, -509, "Fondation de la république");
    ajoute_evenement(events2, -479, "Début de l’époque classique et apogée d’Athènes");
    ajoute_evenement(events2, -334, "Début de l’expédition d’Alexandre le Grand");
    ajoute_evenement(events2, -300, "Début des conquêtes romaines");
    ajoute_evenement(events2, -168, "Début de la conquête romaine");
    ajoute_evenement(events2, -52, "Guerre des Gaules et victoire romaine à Alésia");
    ajoute_evenement(events2, -27, "Début de l’Empire et fin des conquêtes romaines");
    ajoute_evenement(events2, 64, "Incendie de Rome");
    ajoute_evenement(events2, 64, "Début des persécutions contre les chrétiens");
    ajoute_evenement(events2, 313, "Edit de Constantin autorisant la religion chrétienne");
    ajoute_evenement(events2, 392, "Edit de Théodose autorisant seulement la religion chrétienne dans l’Empire romain");
    ajoute_evenement(events2, 395, "Partage de l’Empire (Empire romain d’occident et Empire romain d’orient)");
    ajoute_evenement(events2, 410, "Prise de Rome par les Goths");
    ajoute_evenement(events2, 476, "Chute de l’Empire romain d’occident");
    ajoute_evenement(events2, 476, "Fin de l’Antiquité");

    // Affichage des événements historiques
    cout << endl
         << "Affichage des événements historiques : " << endl
         << endl;
    affiche_evenements(events2);
    return 0;
}