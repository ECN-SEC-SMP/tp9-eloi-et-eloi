/**
 * @file csv.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 5 LECTURE/ÉCRITURE DE FICHIER CSV
 * @version 0.1
 * @date 13-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "csv.hpp"

/**
 * @brief Construct a new CSV::CSV object
 * 
 */
CSV::CSV()
{
}

/**
 * @brief Destroy the CSV::CSV object
 * 
 */
CSV::~CSV()
{
}

/**
 * @brief Ajoute un événement à la map
 * 
 * @param year Année de l'événement
 * @param event Description de l'événement
 */
void CSV::ajoute_evenement(int year, string event)
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
 */
void CSV::affiche_evenements()
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
 * @brief Sauvegarde les événements dans un fichier CSV
 * 
 * @param filename Nom du fichier de sauvegarde
 */
void CSV::save(string filename)
{
    // On ouvre le fichier en écriture
    ofstream file(filename);

    // On vérifie si le fichier est ouvert
    if (file.is_open())
    {
        // On parcourt la map
        for (auto &event : events)
        {
            // On écrit l'année
            file << event.first << ";";

            // On parcourt la liste d'événements
            for (auto &description : event.second)
            {
                // On écrit la description
                file << description << ";";
            }

            // On écrit un retour à la ligne
            file << endl;
        }

        // On ferme le fichier
        file.close();
    }
    else
    {
        // Si le fichier n'est pas ouvert, on affiche un message d'erreur
        cout << "Erreur lors de l'ouverture du fichier " << filename << endl;
    }
}

/**
 * @brief Charge les événements depuis un fichier CSV
 * 
 * @param filename Nom du fichier à charger
 */
void CSV::load(string filename)
{
    // On ouvre le fichier en lecture
    ifstream file(filename);

    // On vérifie si le fichier est ouvert
    if (file.is_open())
    {
        // On lit le fichier ligne par ligne
        string line;
        while (getline(file, line))
        {
            // On crée un stringstream à partir de la ligne
            stringstream ss(line);

            // On crée une variable pour l'année
            int year;

            // On lit l'année
            ss >> year;

            // On ignore the first token (year)
            ss.ignore(numeric_limits<streamsize>::max(), ';');

            // On crée une variable pour la description
            string description;

            // On lit la description
            while (getline(ss, description, ';'))
            {
                // On vérifie si la description n'est pas vide
                if (!description.empty())
                {
                    // On ajoute l'événement à la map
                    ajoute_evenement(year, description);
                }
            }
        }

        // On ferme le fichier
        file.close();
    }
    else
    {
        // Si le fichier n'est pas ouvert, on affiche un message d'erreur
        cout << "Erreur lors de l'ouverture du fichier " << filename << endl;
    }
}