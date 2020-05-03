#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <random>

using namespace std;

class Student{
    private:
        char name[100], surname[100];
        unsigned albumNo;
        vector<double>* marks;
    public:
        Student(){
            strcpy(name, "");
            strcpy(surname, "");
            albumNo = 0;
            marks = new vector<double>;
            }
        ~Student(){
            if(marks){delete marks;}
        }
        Student(const char* name, const char* surname, unsigned albumNo){
            strcpy(this->name, name);
            strcpy(this->surname, surname);
            this->albumNo = albumNo;
            marks = new vector<double>;
        }
        Student(const Student &osoba){
            strcpy(this->name, osoba.name);
            strcpy(this->surname, osoba.surname);
            this->albumNo = osoba.albumNo;
            marks = osoba.marks;
        }
        void wypiszDane();
        const char* getName(){return name;}
        const char* getSurname(){return surname;}
        unsigned getAlbumNumber(){return albumNo;}
        double getMark(int n){return (this->marks)->at(n);}
        void setName(const char* givenName){strcpy(this->name, givenName);}
        void setSurname(const char* givenSurname){strcpy(this->surname, givenSurname);}
        void setAlbumNo(unsigned albumNumber){this->albumNo = albumNumber;}
        //void addMark(double m);
        //void printMarks();
        //inline void getAllMarks();
};

void Student::wypiszDane(){
    printf("Imie: %s, Nazwisko: %s, Nr Albumu: %d\n", getName(), getSurname(), getAlbumNumber());
}
/*
void Student::addMark(double m){
    (this->marks)->push_back(m);
}


void Student::printMarks(){
    for (auto j=marks->begin(); j!=marks->end(); j++){
            cout << "dupa ";
        }
}
*/
/*
inline void Student::getAllMarks(){
    for(auto iter = marks.begin(); iter!= marks.end();iter++){
        cout << iter->getMark() << " ";
    }
}
*/
int main(){

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine e (seed);
    uniform_real_distribution<> dist(2,5);
    vector<Student> uczniowie{{"Boleslaw", "Chroby", 17061025, {13.0}}, {"Jan", "Matejko", 24061838}, {}, {"Mikolaj", "Kopernik", 19021473}, {}};

    uczniowie[4].setName("Stanislaw");
    uczniowie[4].setSurname("Lem");
    uczniowie[4].setAlbumNo(12091921);

    for(auto iter = uczniowie.begin(); iter!=uczniowie.end(); iter++){
        iter -> wypiszDane();
    }
    /*
    for(auto iter = uczniowie.begin(); iter!=uczniowie.end(); iter++){
        for (int i=0; i<3; i++){
            double x = dist(e);
            cout << x << endl;
            iter -> addMark(x);
        }
    }
    */
    for(int j = 0; j<3; j++){
        cout << uczniowie[0].getMark(j) << endl;
    }
return 0;
}
