#include "CalibTracker/SiStripDCS/test/plugins/testSiStripDcuDetIdMap.h"
#include "CalibTracker/SiStripDCS/interface/SiStripPsuDetIdMap.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "OnlineDB/SiStripConfigDb/interface/SiStripConfigDb.h"
#include "DataFormats/SiStripCommon/interface/SiStripConstants.h"
#include "DataFormats/SiStripCommon/interface/SiStripEnumsAndStrings.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
using namespace sistrip;

testSiStripDcuDetIdMap::testSiStripDcuDetIdMap(const edm::ParameterSet&) {
  LogTrace("testSiStripDcuDetIdMap") << "[Constructor]  entered constructor";
}

void testSiStripDcuDetIdMap::beginRun( const edm::Run& run, const edm::EventSetup& setup ) {
  LogTrace("testSiStripDcuDetIdMap") <<"[beginRun]  entered beginRun";
  SiStripPsuDetIdMap map_;
  LogTrace("testSiStripDcuDetIdMap") <<"[beginRun]  Map object instantiated!";
  map_.BuildMap();
  LogTrace("testSiStripDcuDetIdMap") <<"[beginRun]  Map built!";
}

