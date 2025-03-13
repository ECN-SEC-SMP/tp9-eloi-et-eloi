/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 5 LECTURE/ÉCRITURE DE FICHIER CSV
 *        Écrire une classe csv qui permet de lire et écrire un fichier (date; descriptions) au format CSV
 *        (Comma-SeparatedValueshttps://fr.wikipedia.org/wiki/Comma-separated_values).
 *        La lecture stockera le résultat dans une map comme définit précédemment. L’écriture sauvera
 *        la liste des dates/descriptions que vous aviez créé dans la map dans un fichier .csv. Vous com-
 *        pléterez votre classe CSV des fonctions affiche et ajoute_evenement comme définies précédem-
 *        ment.
 * 
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

#include "csv.hpp"

using namespace std;

/**
 * @brief main
 *
 * @return int
 */
int main()
{
    // On crée une instance de la classe CSV
    CSV myCSV;

    // On charge le fichier dates.csv
    myCSV.load("dates.csv");

    // On affiche les événements
    myCSV.affiche_evenements();

    // On ajoute nos évènements
    myCSV.ajoute_evenement(0, "Naissance de JC");
    myCSV.ajoute_evenement(2025, "TP9 de SMP");
    myCSV.ajoute_evenement(2025, "Voyage à l'étranger");
    myCSV.ajoute_evenement(2004, "Naissance de Eloi");
    myCSV.ajoute_evenement(2000, "Passage en l'an 2000");
    
    // On exporte les évènements
    myCSV.save("myEvents.csv");

    return 0;
}