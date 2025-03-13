/**
 * @file csv.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 5 LECTURE/ÉCRITURE DE FICHIER CSV
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
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief Classe qui permet de lire et écrire des fichiers CSV
 * 
 */
class CSV
{
    private:
        map<int, list<string>> events;

    public:
        CSV();
        ~CSV();

        void ajoute_evenement(int year, string event);
        void affiche_evenements();
        void save(string filename);
        void load(string filename);
};