#ifndef SiStripModuleHV_H
#define SiStripModuleHV_H

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"


namespace cms{
  class SiStripModuleHVBuilder : public edm::EDAnalyzer {

  public:

    explicit SiStripModuleHVBuilder( const edm::ParameterSet& iConfig);

    ~SiStripModuleHVBuilder();

    virtual void beginJob( const edm::EventSetup& );

    virtual void analyze(const edm::Event& , const edm::EventSetup& );

  private:
    bool printdebug_;
    std::vector<uint32_t> detids;
  };
}
#endif

