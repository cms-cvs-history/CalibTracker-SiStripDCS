
#include "FWCore/Framework/interface/MakerMacros.h"

#include "CalibTracker/SiStripDCS/test/SiStripModuleHVBuilder.h"
#include "CalibTracker/SiStripDCS/test/SiStripModuleHVReader.h"

using cms::SiStripModuleHVBuilder;
using cms::SiStripModuleHVReader;

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(SiStripModuleHVBuilder);
DEFINE_ANOTHER_FWK_MODULE(SiStripModuleHVReader);

