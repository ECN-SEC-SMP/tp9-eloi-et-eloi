/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 2 VECTEUR DE CHAINES DE CARACTÈRES
 *        Créez un code qui permet de faire les actions suivantes :
 *        — Déclarez un vecteur stockant des std::string.
 *        — Ajoutez cinq std::string dans ce vecteur. Ces std::string contiendront respective-
 *        ment "Bonjour", "comment", "allez", "vous", "?".
 *        — Affichez la taille de votre vecteur
 *        — Affichez sa capacité (capacity). Quelle est la différence avec sa taille? (ajoutez des élé-
 *        ments dans le vecteur et observez les différences entre la taille et la capacité).
 *        — Affichez le contenu du vecteur sur une même ligne (chaque mot étant séparé par un
 *        espace) avec les mêmes trois méthodes différentes que précédemment
 *        — Réalisez un échange entre le contenu de la case d’indice 1 avec le contenu de la case
 *        d’indice 3 de votre vecteur (vérifiez votre résultat en affichant le vecteur modifié). Uti-
 *        lisez swap.
 *        — Insérez la valeur "a tous" après le premier élément dans votre vecteur. Vérifiez votre
 *        résultat.
 *        — Changez le point d’interrogation final par "???". Vérifiez votre résultat.
 *        — Affichez le contenu du vecteur en séparant chaque chaine par une virgule.
 *        — Triez le vecteur en utilisant un algorithme de la STL. L’ordre de tri par défaut est celui
 *        de la comparaison alphabétique sur des std::string. Affichez le résultat obtenu.
 *        — Créez une fonction affiche qui affiche le contenu du vecteur passé en paramètre. Notez
 *        qu’ici, on prendra soin de passer le vecteur sous forme de référence constante car il n’a
 *        pas à être modifié ni copié (std::vector<std::string> const&).
 *        — Créez une fonction concatene qui concatène l’ensemble des éléments du vecteur dans
 *        une seule variable de type std::string. Chaque élément sera espacé d’un espace dans
 *        la std::string de sortie.
 *        — Créez une fonction ajoute_virgule qui ajoute une virgule derrière chaque mot contenu
 *        dans le std::vector. Cette fois, la variable de type std::vector passée en paramètre de
 *        la fonction doit être modifiée. Utilisez for_each et soit une fonction, soit un foncteur.
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

using namespace std;

/**
 * @brief Affiche le contenu du vecteur passé en paramètre
 *
 * @param v vecteur string à afficher
 */
void affiche(const vector<string> &v)
{
    for (string s : v)
    {
        cout << s << " ";
    }
    cout << endl;
}

/**
 * @brief Concatène l'ensemble des éléments du vecteur dans une seule variable de type std::string
 *
 * @param v vecteur string à concaténer
 * @return string
 */
string concatene(const vector<string> &v)
{
    string res = "";
    for (string s : v)
    {
        res += s + " ";
    }
    return res;
}

/**
 * @brief ajoute une virgule derrière chaque mot contenu dans le std::vector
 *
 * @param v vecteur string à modifier
 */
void fonction_ajoute_virgule(vector<string> &v)
{
    for (string &s : v)
    {
        s += ",";
    }
}

/**
 * @brief Foncteur qui ajoute une virgule derrière chaque mot contenu dans le std::vector
 *
 */
class AjouteVirgule
{
public:
    void operator()(string &s)
    {
        s += ",";
    }
};

/**
 * @brief main
 * 
 * @return int 
 */
int main()
{
    // Déclarez un vecteur stockant des std::string.
    vector<string> vec;

    // AJouter 5 string dans ce vecteur
    vec.push_back("Bonjour");
    vec.push_back("comment");
    vec.push_back("allez");
    vec.push_back("vous");
    vec.push_back("?");

    // Afficher la taille du vecteur
    cout << "Taille de vec : " << vec.size() << endl;

    // Afficher la capacité du vecteur
    cout << "Capaci de vec : " << vec.capacity() << endl;

    // Quelle différence entre taille et capacité ?
    vec.push_back("Bonjour");
    vec.push_back("très");
    vec.push_back("bien");
    vec.push_back("et");
    vec.push_back("vous");
    vec.push_back("?");

    cout << "Taille de vec : " << vec.size() << endl;
    cout << "Capaci de vec : " << vec.capacity() << endl
         << endl;

    /* La difference entre capacité et taille est que la capacité est
    la taille maximale que le vecteur peut contenir sans avoir à
    réallouer de mémoire. La taille est le nombre d'éléments actuellement
    dans le vecteur. */

    // Afficher le contenu du vecteur sur une même ligne
    /* Avec des indices */
    cout << "Avec des indices" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl
         << endl;

    /* En exécutant une boucle sur une plage de nombres (C++11 rangebasedloop) */
    cout << "Avec une boucle rangebasedloop" << endl;
    for (string s : vec)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    /* En utilisant un itérateur */
    cout << "Avec un itérateur" << endl;
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl
         << endl;

    // Réaliser un échange entre le contenu de la case 1 avec la 3 (swap)
    vec[1].swap(vec[3]);

    cout << "Après un swap 1 <=> 3" << endl;
    for (string s : vec)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // Insérer "a tous" après le premier élément
    vec.insert(vec.begin() + 1, "a tous");

    cout << "Après un insert \"à tous\"" << endl;
    for (string s : vec)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // Changez le point d’interrogation final par "???"
    vec.pop_back();
    vec.push_back("???");

    cout << "Après un changement ? => ???" << endl;
    for (string s : vec)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // Afficher le contenu du vecteur en séparant chaque chaine par une virgule
    cout << "Avec des virgules" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl
         << endl;

    // Trier le vecteur en utilisant un algorithme de la STL
    sort(vec.begin(), vec.end());

    cout << "Après un tri" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl
         << endl;

    // Créer une fonction affiche qui affiche le contenu du vecteur passé en paramètre
    cout << "Affichage avec la fonction affiche" << endl;
    affiche(vec);
    cout << endl;

    // Créer une fonction concatene qui concatène l’ensemble des éléments du vecteur dans une seule variable de type std::string
    cout << "Concaténation avec la fonction concatene" << endl;
    cout << concatene(vec) << endl << endl;

    // Créer une fonction ajoute_virgule qui ajoute une virgule derrière chaque mot contenu dans le std::vector

    // cout << "Ajout de virgules avec la fonction ajoute_virgule" << endl;
    // fonction_ajoute_virgule(vec);
    // affiche(vec);
    // cout << endl;

    cout << "Ajout de virgules avec un foncteur" << endl;
    for_each(vec.begin(), vec.end(), AjouteVirgule());
    affiche(vec);
    cout << endl;

    return 0;
}