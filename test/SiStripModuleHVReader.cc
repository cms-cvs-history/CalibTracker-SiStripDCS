#include "CondFormats/SiStripObjects/interface/SiStripModuleHV.h"
#include "CondFormats/DataRecord/interface/SiStripModuleHVRcd.h"

#include "CalibTracker/SiStripDCS/test/SiStripModuleHVReader.h"

#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"


#include "CondFormats/SiStripObjects/interface/SiStripModuleHV.h"


#include <iostream>
#include <stdio.h>
#include <sys/time.h>



using namespace cms;

SiStripModuleHVReader::SiStripModuleHVReader( const edm::ParameterSet& iConfig ):
  printdebug_(iConfig.getUntrackedParameter<bool>("printDebug",true)){}


SiStripModuleHVReader::~SiStripModuleHVReader(){}


void SiStripModuleHVReader::analyze( const edm::Event& e, const edm::EventSetup& iSetup){

  edm::ESHandle<SiStripModuleHV> SiStripModuleHV_;
  iSetup.get<SiStripModuleHVRcd>().get(SiStripModuleHV_);
  edm::LogInfo("SiStripModuleHVReader") << "[SiStripModuleHVReader::analyze] End Reading SiStripModuleHV" << std::endl;
  
  std::vector <uint32_t> detid;
  SiStripModuleHV_->GetAllDetIds(detid);
  
  if (printdebug_){
    for (uint32_t  id=0;id<=detid.size();id++)
      {
	bool hvflag=SiStripModuleHV_->IsModuleHVOff(detid[id]);
	if(hvflag==true){std::cout << "detid: " << detid[id] << "HV\t OFF\n";}  
	if(hvflag==false){std::cout << "detid: " << detid[id] << "HV\t ON\n";}  
      } 
  }

}
