#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>
#include <QString>
#include <fstream>
#include <iostream>

using namespace std;

class Configuration
{
public :
    QString *m_listeCodes;
    int m_nbNiveau;
    int m_niveauALancer;

public:
    Configuration();
    ~Configuration();
};

#endif // CONFIGURATION_H
