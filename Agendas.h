#pragma once
#include <vector>
#include <string>
#include "Evenements.h"
//journee particuliere

class AgendaJournee
{
public:
	AgendaJournee();
	virtual ~AgendaJournee();
	int RechercherEvt(std::string titre);
	void AjouterEvt(Evenement * evenement);
	void SupprimerEvt(int indiceEvenement);
	virtual void AffichInfo() const;
	//num jours
	int GetNumJour() const;
	void SetNumJour(int numjour);
	//num mois
	int GetNumMois() const;
	void SetNumMois(int numMois);

protected:
	int m_numjours;
	int m_nummois;
	std::vector<Evenement*> m_lesEvtsDuJour;


};

//aganda personne

class AgendaPersonne
{
public:
	AgendaPersonne();
	virtual ~AgendaPersonne();
	int RechercheJour(int jour, int mois);
	void EnregistrerEvt(int jour, int mois,Evenement* evenement);
	void AnnulerEvt(int jour, int mois,std::string titre);
	void AffichInfo() const;
	//nom
	std::string GetNom() const;
	void SetNom(std::string nom);
	//prenom
	std::string GetPrenom() const;
	void SetPrenom(std::string prenom);
private:
	std::string m_nom;
	std::string m_prenom;
	std::vector<AgendaJournee*> m_agendaAnnee;
};
