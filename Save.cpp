#include "Save.h"

const std::string SaveYams::FILENAME = "save.txt";
bool SaveYams::cleaned = false;
std::ofstream SaveYams::file;

void SaveYams::savePlayer(Player player, int difficulty){
    if(!cleaned){
        file = std::ofstream(FILENAME, std::ofstream::out | std::ofstream::trunc);
        cleaned = true;
    }  
    
    if (file.is_open()) {
        file << "player " << player.name << " " << difficulty <<std::endl;
        
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}
void SaveYams::saveHardcoreOrder(){
    
}

void SaveYams::saveFigure(const int* dices, const int& nbFigure){

}

std::list<Player> SaveYams::load(){
    // ne peut être lancé si on a sauvegardé
    /*
    dans Yams.cpp
    si au début le joueur charge une partie,
    on appelle la fonction load qui nous retourne une liste de joueurs

    while getline args[0] == player
    // on récupère les joueurs dans le fichier
    list<Player> loadedPlayers;
    //boucle sur l'ajout des joueurs
        Player p(pName, difficulty);
        loadedPlayers.push_back(p);
    // boucle sur l'ajout de figure

    // remise en place de la difficulté

    */

   Player p("test", 4);
   int* dices;
   p.figureManagement->playFigure(dices, 5);

}

SaveYams::~SaveYams(){
    if(cleaned) file.close();
}