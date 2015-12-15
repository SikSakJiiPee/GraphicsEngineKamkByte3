#pragma once

#include <string>

extern void fatalError(std::string errorString);

/*
--Bugeja--

Kierto, zoomaus ja ylöspäin liikkuminen toimii yhtäaikaa vain:
-Myötäpäivään kierrättäessä ja sisäänpäin zoomatessa.
-Muuten ylös liikkuminen ei toimi.
-Muut suunnat toimii
*/