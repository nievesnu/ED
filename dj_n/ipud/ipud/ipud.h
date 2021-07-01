//Nieves Núñez Ugena
//A52

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <map>

using cancion = std::string;
using artista = std::string;


class iPud {
	struct infoSong {
		artista autor;
		int duracion;
		std::list<cancion>::iterator enPlaylist;
		std::list<cancion>::iterator enRecientes;
	};
	std::unordered_map<cancion, infoSong> canciones;

	std::list<cancion> playlist;
	int duracionPlaylist;

	std::list<cancion>recientes; //oreden de mas creciente a menos

public:
	iPud() : duracionPlaylist(0) {} //inicializamos a 0

	//a la clave s se le insertan a y d si second es false da error de que ya se ha insertado antes la cancion
	void addSong(cancion S, artista A, int D) { //0(1)
		if (!canciones.insert({ S, { A, D, playlist.end(), recientes.end()} }).second)
			throw std::invalid_argument("addSong");
	}

	void addToPlaylist(cancion S) {//0(1)
		auto itS = canciones.find(S);
		if (itS == canciones.end())
			throw std::invalid_argument("addToPlaylist");
		infoSong& info = itS->second;
		if (info.enPlaylist == playlist.end()) {
			info.enPlaylist = playlist.insert(playlist.end(), S);
			duracionPlaylist += info.duracion;
		}
	}

	cancion current() const {//0(1)
		if (playlist.empty())
			throw std::invalid_argument("current");
		return playlist.front();
	}

	cancion play() {//0(1)
		std::string tocando;
		if (!playlist.empty()) {
			std::string tocando = playlist.front();
			playlist.pop_front();
			infoSong& info = canciones[tocando];
			info.enPlaylist = playlist.end();
			duracionPlaylist -= info.duracion;
			if (info.enRecientes != recientes.end()) {
				recientes.erase(info.enRecientes);
			}
			info.enRecientes = recientes.insert(recientes.begin(), tocando);
		}
		return tocando;
	}

	int totalTime() { //0(1){
		return duracionPlaylist;
	}

	std::list<cancion> recent(int N) {
		std::list<cancion> res;
		for (cancion const& c : recientes) {
			res.push_back(c);
			if (res.size() == N) break;
		}
		return res;
	}

	void deleteSong(cancion S) {
		auto itS = canciones.find(S);
		if (itS != canciones.end()) {
			infoSong& info = itS->second;
			if (info.enPlaylist != playlist.end()) {
				playlist.erase(info.enPlaylist);
				duracionPlaylist -= info.duracion;
			}
			canciones.erase(itS);
		}
	}
};