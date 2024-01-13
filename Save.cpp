#include "Save.h"

const std::string SaveYams::FILENAME = "save.txt";
bool SaveYams::cleaned = false;
bool SaveYams::loading = false;
std::ofstream SaveYams::file;

std::vector<std::string> SaveYams::split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void SaveYams::savePlayer(Player player, int difficulty){
    if(loading) return;
    if(!cleaned){
        file = std::ofstream(FILENAME, std::ofstream::out | std::ofstream::trunc);
        cleaned = true;
    }
    if (file.is_open()) {
        file << "player " << player.name << " " << difficulty <<std::endl;
        
    } else std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
}
void SaveYams::saveHardcoreOrder(FigureManagement* fm){
    if(loading) return;
    if(!cleaned){ // SavePlayer s'active après le saveHardcoreOrder (s'il y en a un)
        file = std::ofstream(FILENAME, std::ofstream::out | std::ofstream::trunc);
        cleaned = true;
    }
    if (file.is_open()){
        file << fm->getOrder() << std::endl;
    }else std::cerr << "/!\\Error file " + FILENAME + " is not open.\n";

    //faire un constr dans le hardcore, pour pouvoir instancier en fonction du nom
}

void SaveYams::saveFigure(const int* dices, const int& nbFigure){
    std::cout << "saveFigure here";
    if(loading) return;
    if (file.is_open()) {
        file << "figure";
        for(int i = 0 ; i < 6 ; i++)
            file << " " << dices[i];
        file << " " << nbFigure <<std::endl;
        
    } else std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    delete[](dices);
}

std::list<Player> SaveYams::load(int* turns){
    loading = true;
    std::ifstream file(FILENAME);
    std::list<Player> players;
    std::list<Player>::iterator it;

    std::string s = "", hardcore = "";
    bool b = false; // pourpas comparer les strings à chaque fois
    // lit les if de gauche à droite ?
    // si on est rentrés une fois dans figure, il n'y aura plus
    // d'ajout de joueur
    while(std::getline(file, s)){
        std::vector<std::string> args = split(s, " ");
        if(!b && args[0] == "player"){ // vérifiera le bool avant de comparer les strings ?
            int difficulty=stoi(args[2]);

            Player p(args[1], difficulty);
            if(difficulty == 4){
                delete p.figureManagement;
                p.figureManagement = new HardcoreFigure(hardcore);
            }
            players.push_back(p);
        }else if(args[0] == "figure"){
            if(b){
                b=true;
                it = players.begin();
            }
            int* dices = new int[6];
            for (int i = 0; i < 6; ++i) {
                dices[i] = stoi(args[i+1]);
            }
            Player p = *it;
            p.figureManagement->playFigure(dices, stoi(args[7]));
        }
        else hardcore = s; // sinon on a un ordre de figures qu'on mettra au prochain
    }

    file.close();
    loading = false;
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

    // remise en place de la difficulté (si difficulté = hardcore)

    // boucle sur l'ajout de figure
    

   Player p("test", 4);
   int* dices;
   p.figureManagement->playFigure(dices, 5);*/

}

SaveYams::~SaveYams(){
    if(cleaned /*&& file.is_open()*/) file.close();
}