#ifndef CalibTracker_SiStripDCS_test_testSiStripDcuDetIdMap_H
#define CalibTracker_SiStripDCS_test_testSiStripDcuDetIdMap_H

#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class SiStripConfigDb;
class SiStripPsuDetIdMap;

class testSiStripDcuDetIdMap : public edm::EDAnalyzer {
public:
  testSiStripDcuDetIdMap(const edm::ParameterSet&);
  virtual ~testSiStripDcuDetIdMap() {;}
  
private:
  void beginRun(const edm::Run&, const edm::EventSetup& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
};

#endif // CalibTracker_SiStripDCS_testDcuPsuMap_H

