#ifndef JSONOPRATION_H
#define JSONOPRATION_H

#include "Common/commontest.h"

class JsonOpration
{
public:
    JsonOpration();
    int ReadJson(ConfigData &p_data);
    int WriteJson(const ConfigData &p_data);

private:
    int openJson();
};

#endif // JSONOPRATION_H
