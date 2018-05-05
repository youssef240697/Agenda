#pragma once
#include <string>
//evenement
class Evenement
{
public:
	Evenement();
	virtual ~Evenement();
	virtual std::string GetType();
	//titre
	std::string GetTitre() const;
	void SetTitre(std::string titre);
	//lieu evenement
	std::string GetLieuEven() const;
	void SetLieuEven(std::string lieuevenement);
protected:
	std::string m_titre;
	std::string m_lieuEven;
};
//evenment ponctuel

class EvenementPonctuel : public Evenement
{
public:
	EvenementPonctuel();
	~EvenementPonctuel();
	std::string GetType();
	//heure debut
	float GetHeureDebut() const;
	void setHeureDebut(float heuredebut);
	//heure fin
	float GetHeureFin() const;
	void setHeureFin(float heurefin);
private:
	float m_hDebut;
	float m_hFin;
};

//evenement repetitif

class EvenementRepetitive : public Evenement
{
public:
	EvenementRepetitive();
	~EvenementRepetitive();
	std::string GetType();
	//nb jours
	int GetNbJours() const;
	void setNbJours(int nbjours);
	//periodicite
	int GetPeriodicite() const;
	void SetPeriodicite(int periodicite);
private:
	int m_nbjours;
	int m_periodicite;
};
