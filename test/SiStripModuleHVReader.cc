#include "CondFormats/SiStripObjects/interface/SiStripModuleHV.h"
#include "CondFormats/DataRecord/interface/SiStripModuleHVRcd.h"

#include "CalibTracker/SiStripDCS/test/SiStripModuleHVReader.h"





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
  

  // put here a vector of DetIds to compare 
  // Here we just take the vector with all modules that have HV OFF
  
  // replace this code, with Your own detids
  std::vector <uint32_t> detid;
  SiStripModuleHV_->getDetIds(detid);
  //


  if (printdebug_){
    for (uint32_t  id=0;id<=detid.size();id++)
      {
	bool hvflag=SiStripModuleHV_->IsModuleHVOff(detid[id]);
	if(hvflag==true){std::cout << "detid: " << detid[id] << "HV\t OFF\n";}  
	if(hvflag==false){std::cout << "detid: " << detid[id] << "HV\t ON\n";}  
      } 
  }

}
