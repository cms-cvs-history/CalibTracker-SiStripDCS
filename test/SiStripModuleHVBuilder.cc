// system include files
#include <memory>

// user include files

#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"


#include "CondFormats/SiStripObjects/interface/SiStripModuleHV.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h" 
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"
#include "Geometry/CommonDetUnit/interface/GeomDetType.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetType.h"
#include "DataFormats/FEDRawData/interface/FEDNumbering.h"


#include "CLHEP/Random/RandFlat.h"
#include "CLHEP/Random/RandGauss.h"



#include "CalibTracker/SiStripDCS/test/SiStripModuleHVBuilder.h"

using namespace std;
using namespace cms;

SiStripModuleHVBuilder::SiStripModuleHVBuilder( const edm::ParameterSet& iConfig ):
  printdebug_(iConfig.getUntrackedParameter<bool>("printDebug",false)){}

SiStripModuleHVBuilder::~SiStripModuleHVBuilder(){}


void SiStripModuleHVBuilder::beginJob( const edm::EventSetup& iSetup ) {

  edm::ESHandle<TrackerGeometry> pDD;
  iSetup.get<TrackerDigiGeometryRecord>().get( pDD );     
  edm::LogInfo("SiStripModuleHVBuilder") <<" There are "<<pDD->detUnits().size() <<" detectors"<<std::endl;
  
  for(TrackerGeometry::DetUnitContainer::const_iterator it = pDD->detUnits().begin(); it != pDD->detUnits().end(); it++){
  
    if( dynamic_cast<StripGeomDetUnit*>((*it))!=0){
      uint32_t detid=((*it)->geographicalId()).rawId();            
      const StripTopology& p = dynamic_cast<StripGeomDetUnit*>((*it))->specificTopology();
      unsigned short Nstrips = p.nstrips();
      if(Nstrips<1 || Nstrips>768 ) {
	edm::LogError("SiStripModuleHVBuilder")<<" Problem with Number of strips in detector.. "<< p.nstrips() <<" Exiting program"<<endl;
	exit(1);
      }
      detids.push_back(detid);
      if (printdebug_)
	edm::LogInfo("SiStripModuleHVBuilder")<< "detid " << detid;
    }
  }
}

void SiStripModuleHVBuilder::analyze(const edm::Event& evt, const edm::EventSetup& iSetup){

  unsigned int run=evt.id().run();

  edm::LogInfo("SiStripModuleHVBuilder") << "... creating dummy SiStripModuleHV Data for Run " << run << "\n " << std::endl;



  SiStripModuleHV* SiStripModuleHV_ = new SiStripModuleHV();

   std::vector<uint32_t> TheDetIdHVVector;

    for(std::vector<uint32_t>::const_iterator it = detids.begin(); it != detids.end(); it++){
       
    //Generate HV for each channel, if HV is off fill Vector
    int hv=rand() % 20;
    if(hv<=2){TheDetIdHVVector.push_back(*it);
	  edm::LogInfo("SiStripModuleHVBuilder") << "detid with HV off" <<  *it
						 << std::endl;
    }
  }

  

  SiStripModuleHV_->put(TheDetIdHVVector);

  


  //End now write ModuleHV data in DB
  edm::Service<cond::service::PoolDBOutputService> mydbservice;
  
  if( mydbservice.isAvailable() ){
    try{
      if( mydbservice->isNewTagRequest("SiStripModuleHVRcd") ){
	mydbservice->createNewIOV<SiStripModuleHV>(SiStripModuleHV_,mydbservice->endOfTime(),"SiStripModuleHVRcd");      
      } else {
	mydbservice->appendSinceTime<SiStripModuleHV>(SiStripModuleHV_,mydbservice->currentTime(),"SiStripModuleHVRcd");      
      }
    }catch(const cond::Exception& er){
      edm::LogError("SiStripModuleHVBuilder")<<er.what()<<std::endl;
    }catch(const std::exception& er){
      edm::LogError("SiStripModuleHVBuilder")<<"caught std::exception "<<er.what()<<std::endl;
    }catch(...){
      edm::LogError("SiStripModuleHVBuilder")<<"Funny error"<<std::endl;
    }
  }else{
    edm::LogError("SiStripModuleHVBuilder")<<"Service is unavailable"<<std::endl;
  }
}
