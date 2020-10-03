#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>

int main()
{
	std::vector<std::string> imiona =
	{"Jose", "Mark", "Maria", "Antonio", "Lorenzo", "Anna",
	 "Mark", "Anna", "Carol", "Jose", "Maria", "Anna", "Hans"};

	std::vector<std::string> kraje =
	 {"Hiszpania", "Holandia", "Portugalia", "Włochy", "Włochy",
	 "Czechy", "Szwecja", "Hiszpania", "Niemcy", "Hiszpania", 
	 "Portugalia", "Niemcy", "Norwegia"};

	std::vector<std::string> kierunki =
	{"Socjologia", "Ekonomia", "Psychologia", "Ekonomia",
	"Fizyka", "Biotechnologia", "Psychologia", "Socjologia",
	"Psychologia", "Medycyna", "Ekonomia", "Psychologia", "Fizyka"};

	std::vector<std::string> urodziny = 
	{"Maj", "Kwiecien", "Styczen", "Marzec", "Listopad",
	"Grudzien", "Maj", "Kwiecien", "Wrzesien", "Grudzien",
	"Styczen", "Marzec", "Sierpien"};

	std::map<std::string, std::set<std::string> > dane;
	dane["Imiona"] = std::set<std::string>(imiona.begin(), imiona.end());
	dane["Kraje"] = std::set<std::string>(kraje.begin(), kraje.end());
	dane["Kierunki"] = std::set<std::string>(kierunki.begin(), kierunki.end());
	dane["Urodziny"] = std::set<std::string>(urodziny.begin(), urodziny.end());

	for(auto it = dane.begin(); it!=dane.end(); ++it)
	{
		std::cout << it ->first << " : ";
		for(auto it2 = (it->second).begin(); it2!=(it->second).end(); ++it2)
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}