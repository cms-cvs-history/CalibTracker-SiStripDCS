# Import configurations
import FWCore.ParameterSet.Config as cms

process = cms.Process("testSiStripDcuDetIdMap")

process.load("DQM.SiStripCommon.MessageLogger_cfi")

process.SiStripConfigDb = cms.Service("SiStripConfigDb",
    ConfDb = cms.untracked.string(''),
    TNS_ADMIN = cms.untracked.string(''),
    UsingDb = cms.untracked.bool(True),
    Partitions = cms.untracked.PSet(
        PART1 = cms.untracked.PSet(
            RunNumber = cms.untracked.uint32(0),
            PartitionName = cms.untracked.string('')
        ),
        PART2 = cms.untracked.PSet(
            PartitionName = cms.untracked.string(''),
            ForceVersions = cms.untracked.bool(True),
            DcuPsuMapVersion = cms.untracked.vuint32(0, 0)
        )
    )
)

process.load("IORawData.SiStripInputSources.EmptySource_cff")
process.maxEvents.input = 2

process.test = cms.EDAnalyzer("testSiStripDcuDetIdMap")
process.p = cms.Path(process.test)
