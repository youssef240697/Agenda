#include "Evenements.h"
#include <iostream>

//evenement
Evenement::Evenement()
{
}


Evenement::~Evenement()
{
}

std::string Evenement::GetType()
{
	return "evenement";
}

std::string Evenement::GetTitre() const
{
	return m_titre;
}

void Evenement::SetTitre(std::string titre)
{
	m_titre = titre;
}

std::string Evenement::GetLieuEven() const
{
	return m_lieuEven;
}

void Evenement::SetLieuEven(std::string lieuevenement)
{
	m_lieuEven = lieuevenement;
}

//even ponctuel


EvenementPonctuel::EvenementPonctuel()
{
}

EvenementPonctuel::~EvenementPonctuel()
{
}

std::string EvenementPonctuel::GetType()
{
	return "ponctuel";
}

float EvenementPonctuel::GetHeureDebut() const
{
	return m_hDebut;
}

void EvenementPonctuel::setHeureDebut(float heuredebut)
{
	m_hDebut = heuredebut;
}

float EvenementPonctuel::GetHeureFin() const
{
	return m_hFin;
}

void EvenementPonctuel::setHeureFin(float heurefin)
{
	m_hFin = heurefin;
}

//even repetitif

EvenementRepetitive::EvenementRepetitive()
{
}

EvenementRepetitive::~EvenementRepetitive()
{
}

std::string EvenementRepetitive::GetType()
{
	return "repetitive";
}

int EvenementRepetitive::GetNbJours() const
{
	return m_nbjours;
}

void EvenementRepetitive::setNbJours(int nbjours)
{
}

int EvenementRepetitive::GetPeriodicite() const
{
	return m_periodicite;
}

void EvenementRepetitive::SetPeriodicite(int periodicite)
{
	m_periodicite = periodicite;
}
