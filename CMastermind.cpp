#include "CMastermind.h"
#include <cstddef>
#include <cmath>
#include <ctime>
#include <cstdlib>

CMastermind::CMastermind()
{
    nc = 0;
    coup = 0;
    srand(time(NULL));
}

CMastermind::~CMastermind()
{
}

void CMastermind::initialiserJeu(unsigned short nbCoul, unsigned nbCoup)
{
    nc = nbCoul;
    coup = nbCoup;
    nbEssai = 0;

    for (short i = 0; i < 4; i++)
    {
        combinaison[i] = rand() %8;
    }
}

void CMastermind::analyser()
{
    nbBienPlacee = 0;
    nbBonneCouleur = 0;
    nbEssai++;
    for(short i = 0; i < 4; i++)
    {
        if(combinaison[i] == proposition[i])
        {
            nbBienPlacee++;
        }
        else
        {
            for(short k = 0; k < 4; k++)
            {
                if( proposition[k] == combinaison[i])
                {
                    nbBonneCouleur++;
                }
            }
        }
    }
}

unsigned short CMastermind::getNc()
{
    return nc;
}

void CMastermind::setNc(unsigned short nbCoul)
{
    nc = nbCoul;
}

unsigned short CMastermind::getCoup()
{
    return coup;
}

void CMastermind::setCoup(unsigned short nbCoup)
{
    coup = nbCoup;
}

unsigned short CMastermind::getNbEssai()
{
    return nbEssai;
}

unsigned short * CMastermind::getCombinaison()
{
        return combinaison;
}

unsigned short * CMastermind::getProposition()
{
        return proposition;
}

void CMastermind::setProposition(unsigned short tab[4])
{
    for(short i = 0; i < 4; i++)
       {
           proposition[i] = tab[i];
       }
}

unsigned short CMastermind::getNbBienPlacee()
{
    return nbBienPlacee;
}

unsigned short CMastermind::getNbBonneCouleur()
{
    return nbBonneCouleur;
}
