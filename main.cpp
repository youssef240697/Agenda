#include <iostream>
#include <string>
#include "Agendas.h"
#include <windows.h>
using namespace std;

int menu()  
{
	int rep = 0;
	cout << "\n\n\n";
	cout << "                             ------------------------\n";
	cout << "                           | GESTION D'AGENDA |\n";
	cout << "                              -----------------------\n";
	cout << "                                       |\n";
	cout << "  ---------------------------------------------------------------------- \n";
	cout << " |  ->1) creer agenda personne..                                                  |\n";
	cout << " |  ->2) Ajouter evenement.                                                       |\n";
	cout << " |  ->3) Annuler un evenement.                                                    |\n";
	cout << " |  ->4) info agenda (nom personne et son agenda).                                |\n";
	cout << " |  ->0) Quitter.                                                                 |\n";
	cout << " ------------------------------------------------------------------------- \n";
	cout << "                                                   |Choix : ";
	cin >> rep;
	return rep;
}
int main()
{
	bool flag = false;
	AgendaPersonne agenda;
	while (flag != true)
	{
		if (agenda.GetNom() != "")
			cout << " \n\t\t\t\tAGENDA DE : ";
			cout << agenda.GetNom() << " " << agenda.GetPrenom();
		switch (menu())
		{
		case 1:
		{
			system("cls");
			string nom, prenom;
			cout << "[+]entrez le nom : ";
			cin >> nom;
			cout << endl;
			cout << "[+]entrez le prenom : ";
			cin >> prenom;
			cout << endl;
			agenda.SetNom(nom);
			agenda.SetPrenom(prenom);
			getchar(); break;
		}
		case 2:
		{
			system("cls");
			string titre;
			string type;
			string lieu;
			int numjour;
			int numois;
			cout << "[+]entrez le titre de l'evenement : ";
			cin >> titre;
			cout << endl;
			cout << "[+]entrez le lieu de l'evenement : ";
			cin >> lieu;
			cout << endl;
			cout << "[+]entrez le jour de l'evenement : ";
			cin >> numjour;
			cout << endl;
			cout << "[+]entrez le mois de l'evenement : ";
			cin >> numois;
			cout << endl;
			//get type
			while (1)
			{
				cout << "[+]entrez le type de l'evenement : (ponctuel ou repetitive) ou bien rien (non) : ";
				cin >> type;
				cout << endl;
				if (type != "ponctuel" && type != "repetitive" && type != "non")
				{
					cout << "[-]type inexistant " << endl;
				}
				else{ break; }
			}
			//type ponctuel
			if (type == "ponctuel")
			{
				EvenementPonctuel* evenement = new EvenementPonctuel();
				int heuredebut;
				int heurefin;
				cout << "[+]entrez l'heure debut de l'evenement (HHmm) " << type << ": ";
				cin >> heuredebut;
				cout << endl;
				cout << "[+]entrez l'heure fin de l'evenement(HHmm) " << type << ": ";
				cin >> heurefin;
				cout << endl;
				//config evenement
				evenement->SetTitre(titre);
				evenement->setHeureDebut(heuredebut);
				evenement->setHeureFin(heurefin);
				evenement->SetLieuEven(lieu);
				//ajoute a l'agenda
				agenda.EnregistrerEvt(numjour, numois, evenement);
				cout << "[+]ajouter a l'agenda personnelle avec succes" << endl;
				getchar(); break;
				
			
			}
			if (type == "repetitive")
			{
				EvenementRepetitive* evenement = new EvenementRepetitive();
				int nbjours;
				int periodicite;
				cout << "[+]entrez le nb de jours pour l'evenement " << type << ": ";
				cin >> nbjours;
				cout << endl;
				cout << "[+]entrez la periodicite de l'evenement " << type << "( cb de fois ):";
				cin >> periodicite;
				cout << endl;
				evenement->SetTitre(titre);
				evenement->SetLieuEven(lieu);
				evenement->SetPeriodicite(periodicite);
				evenement->setNbJours(nbjours);
				agenda.EnregistrerEvt(numjour, numois, evenement);
				cout << "[+]ajouter avec succes" << endl;
				getchar(); break;
			}
			
			
			if(type == "non")
			{
				Evenement* evenement = new Evenement;
				evenement->SetLieuEven(lieu);
				evenement->SetTitre(titre);
				agenda.EnregistrerEvt(numjour, numois, evenement);
				cout << "[+]ajouter avec succes";
				cout << endl;
				getchar(); break;
			}
		}
		case 3:
		{
			system("cls");
			string titre;
			string lieu;
			int numjour;
			int numois;
			cout << "[+]entrez le titre de l'evenement : ";
			cin >> titre;
			cout << endl;
			cout << "[+]entrez le lieu de l'evenement : ";
			cin >> lieu;
			cout << endl;
			cout << "[+]entrez le jour de l'evenement : ";
			cin >> numjour;
			cout << endl;
			cout << "[+]entrez le mois de l'evenement : ";
			cin >> numois;
			cout << endl;
			agenda.AnnulerEvt(numjour, numois, titre);
			getchar(); break;
		}
		case 4:
		{
			system("cls");
			agenda.AffichInfo();
			getchar(); break;
		}
		case 0:
		{
			flag = true;
			getchar(); break;
		}
		}
	}
}