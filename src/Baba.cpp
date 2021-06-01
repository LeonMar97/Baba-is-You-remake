#include "Baba.h" 

Baba& Baba::instance() {
	static Baba baba;
	return baba;
}

Baba::Baba()
:BaseObject(Textures::instance().get_Textures(babas_t), BABAIMGCOUNT)
{
}
