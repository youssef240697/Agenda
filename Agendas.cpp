#include "Agendas.h"
#include <iostream>
#include <iomanip>
using namespace std;
//agenda journee

AgendaJournee::AgendaJournee()
{
}


AgendaJournee::~AgendaJournee()
{
	for (int i = 0; i < m_lesEvtsDuJour.size(); i++)
	{
		delete m_lesEvtsDuJour[i];
	}
}

int AgendaJournee::RechercherEvt(std::string titre)
{
	for (int i = 0; i < m_lesEvtsDuJour.size(); i++)
	{
		if (m_lesEvtsDuJour[i]->GetTitre() == titre) return i;
	}
	return -1;
}

void AgendaJournee::AjouterEvt(Evenement * evenement)
{
	if (RechercherEvt(evenement->GetTitre()) != -1) //si evenement deja dans tableau
	{
		cout << "[-]deja dans l agenda de la journee .." << endl;
		}
	else
	{
		m_lesEvtsDuJour.push_back(evenement);
		cout << "[+]ajoutee a l'agenda journaliere avec succes " << endl;
	}
}

void AgendaJournee::SupprimerEvt(int indiceEvenement)
{
	m_lesEvtsDuJour.erase(m_lesEvtsDuJour.begin()+indiceEvenement);
}

void AgendaJournee::AffichInfo() const
{
	cout << "[+]jour : " << m_numjours << endl;
	cout << "[+]mois : " << m_nummois << endl;
	cout << "[+] tous les evenements du jour : " << endl;
	cout << endl;
	cout <<left << "TITRE " << setw(10) << left << "\t" << " lieu" << setw(10) << left << "\t" << " heure debut" << setw(10) << left << "\t" << " heure fin" << setw(10) << left << "\t" << " nb jours" << setw(10) << left << "\t" << " periode" << endl;

	for (int i = 0; i < m_lesEvtsDuJour.size(); i++)
	{
		cout << fixed;
		cout << left << m_lesEvtsDuJour[i]->GetTitre() << setw(10) << left << "\t" << m_lesEvtsDuJour[i]->GetLieuEven();
		if (m_lesEvtsDuJour[i]->GetType() == "ponctuel")
		{
			EvenementPonctuel* evenement = (EvenementPonctuel*)m_lesEvtsDuJour[i];
			cout << setw(10) << left << "\t" << evenement->GetHeureDebut() << setw(10) << left << "\t" << evenement->GetHeureFin() << endl;
		}
		if (m_lesEvtsDuJour[i]->GetType() == "repetitive")
		{
			EvenementRepetitive* evenement = (EvenementRepetitive*)m_lesEvtsDuJour[i];
			cout << setw(10) << left << "\t" << evenement->GetNbJours() << setw(10) << left << "\t" << evenement->GetPeriodicite() << endl;
		}
		else {
			cout << endl;
		}
		cout << endl;

	}
	
}

int AgendaJournee::GetNumJour() const
{
	return m_numjours;
}

void AgendaJournee::SetNumJour(int numjour)
{
	m_numjours = numjour;
}

int AgendaJournee::GetNumMois() const
{
	return m_nummois;
}

void AgendaJournee::SetNumMois(int numMois)
{
	m_nummois = numMois;
}

//agenda personne 

AgendaPersonne::AgendaPersonne()
{
}

AgendaPersonne::~AgendaPersonne()
{
}

int AgendaPersonne::RechercheJour(int jour, int mois)
{ //renvois l'indice de lagenda journalier
	for (int i = 0; i < m_agendaAnnee.size(); i++)
	{
		if (m_agendaAnnee[i]->GetNumJour() == jour && m_agendaAnnee[i]->GetNumMois() == mois)
		{
			return i;
		}
	}
	return -1;
}

void AgendaPersonne::EnregistrerEvt(int jour, int mois,Evenement * evenement)
{
	int i = RechercheJour(jour, mois);
	if (i != -1) // si il existe une agenda journaliere avec le meme jour et mois on ajoute leven dans l'agenda journaliere
	{
		m_agendaAnnee[i]->AjouterEvt(evenement);
	}
	else // si il nexiste pas on cree une nouvelle agenda JOURNALIERE
	{
		AgendaJournee* agendajournee = new AgendaJournee();
		agendajournee->AjouterEvt(evenement);
		agendajournee->SetNumJour(jour);
		agendajournee->SetNumMois(mois);
		m_agendaAnnee.push_back(agendajournee); //enter
	}
}

void AgendaPersonne::AnnulerEvt(int jour, int mois, std::string titre)
{
	int j = RechercheJour(jour, mois); //on trouve l'agenda journaliere correspondante
	if (j == -1)
	{
		cout << "[-]pas d agenda journaliere correspondante .." << endl;
		return;
	}
	int indice_even = m_agendaAnnee[j]->RechercherEvt(titre); //on trouve l'even correspondant
	if (indice_even == -1)
	{
		cout << "[+]pas devenement pour cette date .." << endl;
		return;
	}
	else
	{
		m_agendaAnnee[j]->SupprimerEvt(indice_even); //supprime l'evenement
		cout << "[-]supprime avec succes" << endl;
	}
}
void AgendaPersonne::AffichInfo() const
{
	cout << endl;
	if (m_agendaAnnee.size() == 0) cout << "[-]pas d'evenement pour le moment ..";
	else 
	{
		for (int i = 0; i < m_agendaAnnee.size(); i++)
		{

			m_agendaAnnee[i]->AffichInfo();
			cout << endl;
			cout << endl;
		}
	}
}

string AgendaPersonne::GetNom() const
{
	return m_nom;
}

void AgendaPersonne::SetNom(std::string nom)
{
	m_nom = nom;
}

string AgendaPersonne::GetPrenom() const
{
	return m_prenom;
}

void AgendaPersonne::SetPrenom(std::string prenom)
{
	m_prenom = prenom;
}
