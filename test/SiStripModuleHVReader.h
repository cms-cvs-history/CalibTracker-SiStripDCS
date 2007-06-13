#ifndef SiStripModuleHVReader_H
#define SiStripModuleHVReader_H

// system include files
//#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ServiceRegistry/interface/Service.h"


//
//
// class decleration
//
namespace cms{
  class SiStripModuleHVReader : public edm::EDAnalyzer {

  public:
    explicit SiStripModuleHVReader( const edm::ParameterSet& );
    ~SiStripModuleHVReader();
    
    void analyze( const edm::Event&, const edm::EventSetup& );

  private:
    bool printdebug_;
    std::vector<uint32_t> detids;
     };
}
#endif

/*  LocalWords:  ifndef
 */
