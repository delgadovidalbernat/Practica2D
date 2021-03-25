#pragma once
#include "Enemigo.h"
class EnemigoBasico :
    public Enemigo
{

public:

	void setPosTarget(glm::ivec2) override;
	string typeOf() override;
};

