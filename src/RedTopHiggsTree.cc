#include "TopHiggsAnalysis/include/RedTopHiggsTree.h"

// C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

// Root
#include "TFile.h"
#include "TTree.h"

RedTopHiggsTree::RedTopHiggsTree(const char * filename) {

  myFile = new TFile(filename,"RECREATE");
  myTree = new TTree("latino","latino tree");

  // GENERAL block
  myTree->Branch("puweight",            &myPUWeight,            "puweight/F");
  myTree->Branch("hlt",                 &myHLT,                 "hlt/O");
  myTree->Branch("met",                 &myMet,                 "met/F");  
  myTree->Branch("pfMet",               &myPFMet,               "pfMet/F");  
  myTree->Branch("caloMet",             &myCaloMet,             "caloMet/F");  
  myTree->Branch("projMet",             &myProjectedMet,        "projMet/F");
  myTree->Branch("deltaPhi",            &myDeltaPhi,            "deltaPhi/F");  
  myTree->Branch("deltaR",              &myDeltaR,              "deltaR/F");  
  myTree->Branch("transvMass",          &myTransvMass,          "transvMass/F");  
  myTree->Branch("eleInvMass",          &myEleInvMass,          "eleInvMass/F");  
  myTree->Branch("maxPtEle",            &maxPtEle,              "maxPtEle/F");  
  myTree->Branch("minPtEle",            &minPtEle,              "minPtEle/F");  
  myTree->Branch("maxEtaEle",           &maxEtaEle,             "maxEtaEle/F");  
  myTree->Branch("minEtaEle",           &minEtaEle,             "minEtaEle/F");  
  myTree->Branch("detaLeptons",         &myDetaLeptons,         "detaLeptons/F");  
  myTree->Branch("nVtx",                &myNVtx,                "nVtx/I");
  myTree->Branch("finalLeptons",        &myFinalLeptons,        "finalLeptons/O");
  myTree->Branch("jetVeto",             &myJetVeto,             "jetVeto/O");
  myTree->Branch("uncorrJetVeto",       &myUncorrJetVeto,       "uncorrJetVeto/O");
  myTree->Branch("preDeltaPhi",         &myPreDeltaPhi,         "preDeltaPhi/O");
  myTree->Branch("finalSelection",      &myFinalSelection,      "finalSelection/O");

}

RedTopHiggsTree::~RedTopHiggsTree() 
{
  delete myFile;
}

void RedTopHiggsTree::addMLVars() {

  myTree->Branch("njets",               &myNjets,               "njets/I");
  myTree->Branch("ncbIDjets",           &mycbIDNjets,           "ncbIDjets/I");
  myTree->Branch("nuncorrjets",         &myNuncorrjets,         "nuncorrjets/I");
  myTree->Branch("dxyEVT",              &myDxyEVT,              "dxyEVT/F");
  myTree->Branch("dszEVT",              &myDszEVT,              "dszEVT/F");
  myTree->Branch("softtche",            &mySoftBdisc,           "softtcche/F");
  myTree->Branch("hardbjpb",            &myHardBdisc,           "hardbjbp/F");
  myTree->Branch("bTagSecVertex",       &myBTagSecVertex,       "bTagSecVertex/F");
  myTree->Branch("nSoftMu",             &myNSoftMu,             "nSoftMu/I");
  myTree->Branch("nSoftMuNoJets",       &myNSoftMuNoJets,       "nSoftMuNoJets/I");
  myTree->Branch("leadingJetBTagTrackCount", &myLeadingJetBTagTrackCount,    "leadingJetBTagTrackCount/F");
  myTree->Branch("subleadingJetBTagTrackCount", &mySubleadingJetBTagTrackCount,    "subleadingJetBTagTrackCount/F");    
  myTree->Branch("subleadingJetsMaxBTagTrackCount", &mySubleadingJetsMaxBTagTrackCount,    "subleadingJetsMaxBTagTrackCount/F");    
  myTree->Branch("leadingJetBTagJetBProb", &myLeadingJetBTagJetBProb,    "leadingJetBTagJetBProb/F");
  myTree->Branch("subleadingJetBTagJetBProb", &mySubleadingJetBTagJetBProb,    "subleadingJetBTagJetBProb/F");    
  myTree->Branch("subleadingJetsMaxBTagJetBProb", &mySubleadingJetsMaxBTagJetBProb,    "subleadingJetsMaxBTagJetBProb/F");    
  myTree->Branch("numExtraLep", &myNumExtraLep, "numExtraLep/I");   
  myTree->Branch("nsoftjet"   , &myNumSoftJets, "nsoftjet/I");
  myTree->Branch("nsoftbjet"  , &myNumSoftBJets, "nsoftbjet/I");

  //! cut based id jets
  myTree->Branch("numbtagCSVLcbIDaccepjets", &myNumbtagCSVLcbIDaccepjets, "numbtagCSVLcbIDaccepjets/I");
  myTree->Branch("numbtagCSVMcbIDaccepjets", &myNumbtagCSVMcbIDaccepjets, "numbtagCSVMcbIDaccepjets/I");
  myTree->Branch("numbtagCSVTcbIDaccepjets", &myNumbtagCSVTcbIDaccepjets, "numbtagCSVTcbIDaccepjets/I");
  
  myTree->Branch("numcbIDcentralLjets"     , &myNumcbIDcentralLjets     , "numcbIDcentralLjets/I");
  myTree->Branch("numcbIDforwardLjets"     , &myNumcbIDforwardLjets     , "numcbIDforwardLjets/I");

  myTree->Branch("numcbIDcentralMjets"     , &myNumcbIDcentralMjets     , "numcbIDcentralMjets/I");
  myTree->Branch("numcbIDforwardMjets"     , &myNumcbIDforwardMjets     , "numcbIDforwardMjets/I");

  //! mva based id jets
  myTree->Branch("numbtagCSVLmvaIDaccepjets", &myNumbtagCSVLmvaIDaccepjets, "numbtagCSVLmvaIDaccepjets/I");
  myTree->Branch("numbtagCSVMmvaIDaccepjets", &myNumbtagCSVMmvaIDaccepjets, "numbtagCSVMmvaIDaccepjets/I");
  myTree->Branch("numbtagCSVTmvaIDaccepjets", &myNumbtagCSVTmvaIDaccepjets, "numbtagCSVTmvaIDaccepjets/I");

  myTree->Branch("numbtagCSVLmvaIDcentraljets", &myNumbtagCSVLmvaIDcentraljets, "numbtagCSVLmvaIDcentraljets/I");
  myTree->Branch("numbtagCSVMmvaIDcentraljets", &myNumbtagCSVMmvaIDcentraljets, "numbtagCSVMmvaIDcentraljets/I");
  myTree->Branch("numbtagCSVTmvaIDcentraljets", &myNumbtagCSVTmvaIDcentraljets, "numbtagCSVTmvaIDcentraljets/I");

  myTree->Branch("nummvaIDcentraljets"        , &myNummvaIDcentraljets        , "nummvaIDcentraljets/I");
  myTree->Branch("nummvaIDforwardjets"        , &myNummvaIDforwardjets        , "nummvaIDforwardjets/I");
  
  myTree->Branch("nummvaIDaccepINjets"       , &myNummvaIDaccepINjets        , "nummvaIDaccepINjets/I");
  myTree->Branch("nummvaIDaccepOUTjets"      , &myNummvaIDaccepOUTjets       , "nummvaIDaccepOUTjets/I");

}

void RedTopHiggsTree::addJetsVars() {

  myTree->Branch("leadJetPt",          &myLeadJetPt,          "leadJetPt/F");
  myTree->Branch("leadJetEta",         &myLeadJetEta,         "leadJetEta/F");
  myTree->Branch("leadJetLooseId",     &myLeadJetLooseId,     "leadJetLooseId/I");
  myTree->Branch("leadJetGenMatch",    &myLeadJetGenMatch,    "leadJetGenMatch/I");
  myTree->Branch("jetmva1",            &myLeadJetIdMva,       "jetmva1/F");
  myTree->Branch("jetid1",             &myLeadJetPassLooseId, "jetid1/I");
  myTree->Branch("subleadJetPt",       &mySubleadJetPt,       "subleadJetPt/F");
  myTree->Branch("subleadJetEta",      &mySubleadJetEta,      "subleadJetEta/F");
  myTree->Branch("subleadJetLooseId",  &mySubleadJetLooseId,  "subleadJetLooseId/I");
  myTree->Branch("subleadJetGenMatch", &mySubleadJetGenMatch, "subleadJetGenMatch/I");
  myTree->Branch("jetmva2",            &mySubleadJetIdMva,    "jetmva2/F");
  myTree->Branch("jetid2",             &mySubleadJetPassLooseId,  "jetid2/I");
}

void RedTopHiggsTree::add2013IDJetsVars() {

  myTree->Branch("jetPuId_eta",          &myJetPuId_eta,         "jetPuId_eta[20]/F");
  myTree->Branch("jetPuId_phi",          &myJetPuId_phi,         "jetPuId_phi[20]/F");
  myTree->Branch("jetPuId_energy",       &myJetPuId_energy,      "jetPuId_energy[20]/F");
  myTree->Branch("jetPuId_pt",           &myJetPuId_pt,          "jetPuId_pt[20]/F");
  myTree->Branch("jetPuId_csv",          &myJetPuId_csv,         "jetPuId_csv[20]/F");
  myTree->Branch("jetPuId_betastar",     &myJetPuId_betastar,    "jetPuId_betastar[20]/F");
  myTree->Branch("jetPuId_rms",          &myJetPuId_rms,         "jetPuId_rms[20]/F");
  myTree->Branch("jetPuId_cutBased",     &myJetPuId_cutBased,    "jetPuId_cutBased[20]/I");
  myTree->Branch("jetPuId_mvaBased",     &myJetPuId_mvaBased,    "jetPuId_mvaBased[20]/F");
  myTree->Branch("jetPuId_associated",   &myJetPuId_associated,  "jetPuId_associated[20]/I");
}


void RedTopHiggsTree::addMoreJetsVars() {
  
  myTree->Branch("ptCVStaggedL" , &myptCVStaggedL , "ptCVStaggedL[5]/F");
  myTree->Branch("etaCVStaggedL", &myetaCVStaggedL, "etaCVStaggedL[5]/F");
  myTree->Branch("phiCVStaggedL", &myphiCVStaggedL, "phiCVStaggedL[5]/F");
  myTree->Branch("eneCVStaggedL", &myeneCVStaggedL, "eneCVStaggedL[5]/F");
  myTree->Branch("cvsCVStaggedL", &mycvsCVStaggedL, "cvsCVStaggedL[5]/F");

  myTree->Branch("ptForwardL" , &myptForwardL,  "ptForwardL[5]/F");
  myTree->Branch("etaForwardL", &myetaForwardL, "etaForwardL[5]/F");
  myTree->Branch("phiForwardL", &myphiForwardL, "phiForwardL[5]/F");  
  myTree->Branch("eneForwardL", &myeneForwardL, "eneForwardL[5]/F");
  myTree->Branch("cvsForwardL", &mycvsForwardL, "cvsForwardL[5]/F");

  myTree->Branch("ptCentralL" , &myptCentralL,  "ptCentralL[5]/F");
  myTree->Branch("etaCentralL", &myetaCentralL, "etaCentralL[5]/F");
  myTree->Branch("phiCentralL", &myphiCentralL, "phiCentralL[5]/F");
  myTree->Branch("eneCentralL", &myeneCentralL, "eneCentralL[5]/F");
  myTree->Branch("cvsCentralL", &mycvsCentralL, "cvsCentralL[5]/F");

  myTree->Branch("ptCVStaggedM" , &myptCVStaggedM , "ptCVStaggedM[5]/F");
  myTree->Branch("etaCVStaggedM", &myetaCVStaggedM, "etaCVStaggedM[5]/F");
  myTree->Branch("phiCVStaggedM", &myphiCVStaggedM, "phiCVStaggedM[5]/F");
  myTree->Branch("eneCVStaggedM", &myeneCVStaggedM, "eneCVStaggedM[5]/F");
  myTree->Branch("cvsCVStaggedM", &mycvsCVStaggedM, "cvsCVStaggedM[5]/F");

  myTree->Branch("ptForwardM" , &myptForwardM,  "ptForwardM[5]/F");
  myTree->Branch("etaForwardM", &myetaForwardM, "etaForwardM[5]/F");
  myTree->Branch("phiForwardM", &myphiForwardM, "phiForwardM[5]/F");
  myTree->Branch("eneForwardM", &myeneForwardM, "eneForwardM[5]/F");
  myTree->Branch("cvsForwardM", &mycvsForwardM, "cvsForwardM[5]/F");

  myTree->Branch("ptCentralM" , &myptCentralM,  "ptCentralM[5]/F");
  myTree->Branch("etaCentralM", &myetaCentralM, "etaCentralM[5]/F");
  myTree->Branch("phiCentralM", &myphiCentralM, "phiCentralM[5]/F");
  myTree->Branch("eneCentralM", &myeneCentralM, "eneCentralM[5]/F");
  myTree->Branch("cvsCentralM", &mycvsCentralM, "cvsCentralM[5]/F");

}

void RedTopHiggsTree::addSystematics() {
  
  myTree->Branch("scEnergy", myScEnergy, "scEnergy[3]/F");
  myTree->Branch("R9", myR9, "R9[3]/F");
  myTree->Branch("eneL1",  &myEneL1,  "eneL1/F");
  myTree->Branch("eneL2",  &myEneL2, " eneL2/F");
  myTree->Branch("eneL3",  &myEneL3, " eneL3/F");
  myTree->Branch("typeL1", &myTypeL1, "typeL1/I");
  myTree->Branch("typeL2", &myTypeL2, "typeL2/I");
  myTree->Branch("typeL3", &myTypeL3, "typeL3/I");
  myMetFromJets = 0;
  myPfMetUp = 0;
  myPfMetDown = 0;
  myTree->Branch("metFromJets", "TVector3", &myMetFromJets);
  myTree->Branch("pfMetUp", "TVector3", &myPfMetUp);
  myTree->Branch("pfMetDown", "TVector3", &myPfMetDown);
  myTree->Branch("transvMassUp", &myMtUp, "transvMassUp/F");
  myTree->Branch("transvMassDown", &myMtDown, "transvMassDown/F");

}

void RedTopHiggsTree::addLeptonInfos() {
  myTree->Branch("pt",      myPt,      "pt[3]/F");
  myTree->Branch("eta",     myEta,     "eta[3]/F");
  myTree->Branch("phi",     myPhi,     "phi[3]/F");
  myTree->Branch("flavour", myLepFlav, "flavour[3]/I"); // electron == 0, muon == 1
  myTree->Branch("lepid",   myLepId,   "lepid[3]/F"); 
  myTree->Branch("lepiso",  myLepIso,  "lepiso[3]/F"); 
  myTree->Branch("lepconv", myLepConv, "lepconv[3]/F"); 
}

void RedTopHiggsTree::addCSA07Infos() {

  myTree->Branch("CSA07weight",              &myWeight,              "CSA07weight/D");
  myTree->Branch("CSA07processId",           &myProcesId,            "CSA07processId/D");
  myTree->Branch("CSA07lumi",                &myLumi,                "CSA07lumi/F");
}

void RedTopHiggsTree::addLatinos() {

  myTree->Branch("step",              mySteps,              "step[29]/O"); 
}

void RedTopHiggsTree::addPDFs() {
  myTree->Branch("cteq66W", myCTEQ66, "cteq66W[45]/D");
  myTree->Branch("mstwW",   myMSTW,   "mstwW[31]/D");
  myTree->Branch("nnpdfW",  myNNPDF,  "nnpdfW[101]/D");
}

void RedTopHiggsTree::addRazor() {

  myTree->Branch("mtr",  &myMTR,  "mtr/F");
  myTree->Branch("mr",  &myMR,  "mr/F");
  myTree->Branch("gammamr", &myGammaMR, "gammamr/F");
}

void RedTopHiggsTree::addFake() {
  
  myTree->Branch("tight",        &myTight,        "tight/I");
  myTree->Branch("weightFP",     &myWeightFP,     "weightFP/F");
  myTree->Branch("weightStatFP", &myWeightStatFP, "weightStatFP/F");

  myTree->Branch("weightFP15",     &myWeightFP15,     "weightFP15/F");
  myTree->Branch("weightStatFP15", &myWeightStatFP15, "weightStatFP15/F");
  myTree->Branch("weightFF15",     &myWeightFF15,     "weightFF15/F");
  myTree->Branch("weightStatFF15", &myWeightStatFF15, "weightStatFF15/F");
  myTree->Branch("weightPP15",     &myWeightPP15,     "weightPP15/F");
  myTree->Branch("weightStatPP15", &myWeightStatPP15, "weightStatPP15/F");

  myTree->Branch("weightFP35",     &myWeightFP35,     "weightFP35/F");
  myTree->Branch("weightStatFP35", &myWeightStatFP35, "weightStatFP35/F");
  myTree->Branch("weightFF35",     &myWeightFF35,     "weightFF35/F");
  myTree->Branch("weightStatFF35", &myWeightStatFF35, "weightStatFF35/F");
  myTree->Branch("weightPP35",     &myWeightPP35,     "weightPP35/F");
  myTree->Branch("weightStatPP35", &myWeightStatPP35, "weightStatPP35/F");

  myTree->Branch("weightFP50",     &myWeightFP50,     "weightFP50/F");
  myTree->Branch("weightStatFP50", &myWeightStatFP50, "weightStatFP50/F");
  myTree->Branch("weightFF50",     &myWeightFF50,     "weightFF50/F");
  myTree->Branch("weightStatFF50", &myWeightStatFF50, "weightStatFF50/F");
  myTree->Branch("weightPP50",     &myWeightPP50,     "weightPP50/F");
  myTree->Branch("weightStatPP50", &myWeightStatPP50, "weightStatPP50/F");

  myTree->Branch("weightFPQCD",     &myWeightFPQCD,     "weightFPQCD/F");
  myTree->Branch("weightStatFPQCD", &myWeightStatFPQCD, "weightStatFPQCD/F");
  myTree->Branch("weightFFQCD",     &myWeightFFQCD,     "weightFFQCD/F");
  myTree->Branch("weightStatFFQCD", &myWeightStatFFQCD, "weightStatFFQCD/F");
  myTree->Branch("weightPPQCD",     &myWeightPPQCD,     "weightPPQCD/F");
  myTree->Branch("weightStatPPQCD", &myWeightStatPPQCD, "weightStatPPQCD/F");
}


void RedTopHiggsTree::addKinematics() {

  myTree->Branch("pxChMet", &myPxTkMet, "pxChMet/F");
  myTree->Branch("pyChMet", &myPyTkMet, "pyChMet/F");
  myTree->Branch("pzChMet", &myPzTkMet, "pzChMet/F");
  myTree->Branch("pxLeadJet", myPxLeadJet, "pxLeadJet[3]/F"); // 0th is nominal JEC, 1st=+1sigma JES, 2nd=-1sigma JES   
  myTree->Branch("pyLeadJet", myPyLeadJet, "pyLeadJet[3]/F");
  myTree->Branch("pzLeadJet", myPzLeadJet, "pzLeadJet[3]/F");
  myTree->Branch("pxSecondJet", myPxSecondJet, "pxSecondJet[3]/F");
  myTree->Branch("pySecondJet", myPySecondJet, "pySecondJet[3]/F");
  myTree->Branch("pzSecondJet", myPzSecondJet, "pzSecondJet[3]/F");
  myTree->Branch("pxL1", &myPxL1, "pxL1/F");
  myTree->Branch("pyL1", &myPyL1, "pyL1/F");
  myTree->Branch("pzL1", &myPzL1, "pzL1/F");
  myTree->Branch("pxL2", &myPxL2, "pxL2/F");
  myTree->Branch("pyL2", &myPyL2, "pyL2/F");
  myTree->Branch("pzL2", &myPzL2, "pzL2/F");
  myTree->Branch("pxL3", &myPxL3, "pxL3/F");
  myTree->Branch("pyL3", &myPyL3, "pyL3/F");
  myTree->Branch("pzL3", &myPzL3, "pzL3/F");
  myTree->Branch("ch"  , myLepCharge, "ch[3]/I");
  myTree->Branch("bdt" , myLepBDT   , "bdt[3]/F");

  myJetsSum = 0;
  myUncorrJetsSum = 0;
  myPfMet = 0;
  myTree->Branch("sumJetsV4", "TLorentzVector", &myJetsSum);
  myTree->Branch("uncorrSumJetsV4", "TLorentzVector", &myUncorrJetsSum);
  myTree->Branch("pfmetV", "TVector3", &myPfMet);
}

void RedTopHiggsTree::addKFactor() {
  
  myTree->Branch("KFactor",       &myKFactor,      "KFactor/F");
  myTree->Branch("GenHPt",        &myGenHPt,       "GenHPt/F");
  myTree->Branch("leadingJetPt",  &myLeadingJetPt, "leadingJetPt/F");
}

void RedTopHiggsTree::addMcTruthInfos() {
  myTree->Branch("promptDecay",         &myPromptDecay,         "promptDecay/O");
  myTree->Branch("genmll",              &myGenmll,              "genmll/F");
  myTree->Branch("genptll",             &myGenptll,             "genptll/F");
  myTree->Branch("genyll",              &myGenyll,              "genyll/F");
}

void RedTopHiggsTree::addHLTElectronsInfos() {

  myTree->Branch("HLTSingleElectron",        &myHLTSingleElectron,        "HLTSingleElectron/O");
  myTree->Branch("HLTSingleElectronRelaxed", &myHLTSingleElectronRelaxed, "HLTSingleElectronRelaxed/O");
  myTree->Branch("HLTSingleElectronOR",      &myHLTSingleElectronOR,      "HLTSingleElectronOR/O");
}

void RedTopHiggsTree::addHLTMuonsInfos() {

  myTree->Branch("HLTSingleMuon",        &myHLTSingleMuon,        "HLTSingleMuon/O");
  myTree->Branch("HLTSingleMuonRelaxed", &myHLTSingleMuonRelaxed, "HLTSingleMuonRelaxed/O");
  myTree->Branch("HLTSingleMuonOR",      &myHLTSingleMuonOR,      "HLTSingleMuonOR/O");
}

void RedTopHiggsTree::addRunInfos() {
  myTree->Branch("run", &myRun,     "run/I");
  myTree->Branch("lumi", &myLS,     "lumi/I");
  myTree->Branch("event", &myEvent, "event/l");
  myTree->Branch("npu", myNpu, "npu[3]/F");
}

void RedTopHiggsTree::addMetStudies() {

  myTree->Branch("projPFMet",        &myProjPFMet,        "projPFMet/F");
  myTree->Branch("projPFChargedMet", &myProjPFChargedMet, "projPFChargedMet/F");
  myTree->Branch("signPFMet",        &mySignPFMet,        "signPFMet/F");
  myTree->Branch("signPFChargedMet", &mySignPFChargedMet, "signPFChargedMet/F");
  myTree->Branch("mtrchargedMet",    &myMTRchargedMet,    "mtrchargedMet/F");
  myTree->Branch("dymva1",           &myDYMVA,            "dymva1/F");
  myTree->Branch("rho",              &myRho,              "rho/F"); 
  myTree->Branch("rhoJet",           &myRhoJet,           "rhoJet/F"); 
}

void RedTopHiggsTree::addtHMcTruthInfos(){
  
  myTree->Branch("genHiggsPt" , &myGenHiggsPt , "genHiggsPt/F");
  myTree->Branch("genHiggsEta", &myGenHiggsEta, "genHiggsEta/F");

  myTree->Branch("genTopPt" , &myGenTopPt , "genTopPt/F");
  myTree->Branch("genTopEta", &myGenTopEta, "genTopEta/F");

  myTree->Branch("genWpfromH_Pt" , &myGenWpfromH_Pt , "genWpfromH_Pt/F");
  myTree->Branch("genWpfromH_Eta", &myGenWpfromH_Eta, "genWpfromH_Eta/F");

  myTree->Branch("genWmfromH_Pt" , &myGenWmfromH_Pt , "genWmfromH_Pt/F");
  myTree->Branch("genWmfromH_Eta", &myGenWmfromH_Eta, "genWmfromH_Eta/F");

  myTree->Branch("genWfromT_Pt" , &myGenWfromT_Pt , "genWfromT_Pt/F");
  myTree->Branch("genWfromT_Eta", &myGenWfromT_Eta, "genWfromT_Eta/F");

  myTree->Branch("genLeptonPlusfromWfromH_Pt" , &myGenLeptonPlusfromWfromH_Pt , "genLeptonPlusfromWfromH_Pt/F");
  myTree->Branch("genLeptonPlusfromWfromH_Eta", &myGenLeptonPlusfromWfromH_Eta, "genLeptonPlusfromWfromH_Eta/F");

  myTree->Branch("genLeptonMinusfromWfromH_Pt" , &myGenLeptonMinusfromWfromH_Pt , "genLeptonMinusfromWfromH_Pt/F");
  myTree->Branch("genLeptonMinusfromWfromH_Eta", &myGenLeptonMinusfromWfromH_Eta, "genLeptonMinusfromWfromH_Eta/F");

  myTree->Branch("genLeptonfromWfromT_Pt" , &myGenLeptonfromWfromT_Pt , "genLeptonfromWfromT_Pt/F");
  myTree->Branch("genLeptonfromWfromT_Eta", &myGenLeptonfromWfromT_Eta, "genLeptonfromWfromT_Eta/F");

  myTree->Branch("genNeutrinoPlusfromWfromH_Pt" , &myGenNeutrinoPlusfromWfromH_Pt , "genNeutrinoPlusfromWfromH_Pt/F");
  myTree->Branch("genNeutrinoPlusfromWfromH_Eta", &myGenNeutrinoPlusfromWfromH_Eta, "genNeutrinoPlusfromWfromH_Eta/F");

  myTree->Branch("genNeutrinoMinusfromWfromH_Pt" , &myGenNeutrinoMinusfromWfromH_Pt , "genNeutrinoMinusfromWfromH_Pt/F");
  myTree->Branch("genNeutrinoMinusfromWfromH_Eta", &myGenNeutrinoMinusfromWfromH_Eta, "genNeutrinoMinusfromWfromH_Eta/F");

  myTree->Branch("genNeutrinofromWfromT_Pt" , &myGenNeutrinofromWfromT_Pt , "genNeutrinofromWfromT_Pt/F");
  myTree->Branch("genNeutrinofromWfromT_Eta", &myGenNeutrinofromWfromT_Eta, "genNeutrinofromWfromT_Eta/F");

  myTree->Branch("genForwardQuark_Pt" , &myGenForwardQuark_Pt , "genForwardQuark_Pt/F");
  myTree->Branch("genForwardQuark_Eta", &myGenForwardQuark_Eta, "genForwardQuark_Eta/F");

  myTree->Branch("genbQuark_Pt" , &myGenbQuark_Pt , "genbQuark_Pt/F");
  myTree->Branch("genbQuark_Eta", &myGenbQuark_Eta, "genbQuark_Eta/F");
  
}

void  RedTopHiggsTree::addLeptonMVAidVariables(){

  myTree->Branch("leptPt" , &myleptPt, "leptPt[3]/F"); 
  myTree->Branch("leptEta", &myleptEta, "leptEta[3]/F"); 
  myTree->Branch("neuRelIs", &myneuRelIs, "neuRelIs[3]/F"); 
  myTree->Branch("chRelIso", &mychRelIso, "chRelIso[3]/F"); 
  myTree->Branch("jetDR_in", &myjetDR_in, "jetDR_in[3]/F"); 
  myTree->Branch("jetPtRatio_in", &myjetPtRatio_in, "jetPtRatio_in[3]/F"); 
  myTree->Branch("jetBTagCSV_in", &myjetBTagCSV_in, "jetBTagCSV_in[3]/F"); 
  myTree->Branch("sip3d", &mysip3d, "sip3d[3]/F"); 
  myTree->Branch("mvaId",&mymvaId, "mvaId[3]/F"); 
  myTree->Branch("innerHits", &myinnerHits, "innerHits[3]/I"); 
  myTree->Branch("logdxy", &mylogdxy, "logdxy[3]/F"); 
  myTree->Branch("logdz", &mylogdz, "logdz[3]/F"); 

}

void RedTopHiggsTree::store()
{
  myTree->Fill();
}


void RedTopHiggsTree::save() 
{
  myFile->cd();
  myTree->Write();
  myFile->Close();
}


void RedTopHiggsTree::fillAll(float met, float pfmet, float cmet, float projmet, 
			   float dphi, float derre, float tmass, float mee, float max, float min, float deta, int nvtx,
			   bool finalLeptons, bool jetVeto, bool uncorrjetVeto, bool preDeltaPhi, bool finalSelection)
{

  myMet         = met;
  myPFMet       = pfmet;
  myCaloMet     = cmet;
  myProjectedMet = projmet;
  myDeltaPhi    = dphi;
  myDeltaR      = derre;
  myTransvMass  = tmass;
  myEleInvMass  = mee;
  maxPtEle      = max;
  minPtEle      = min;
  myDetaLeptons = deta;
  myNVtx        = nvtx;
  myFinalLeptons = finalLeptons;
  myJetVeto       = jetVeto;
  myUncorrJetVeto = uncorrjetVeto;
  myPreDeltaPhi = preDeltaPhi;
  myFinalSelection = finalSelection;
}

void RedTopHiggsTree::fillAll(float met, float pfmet, float cmet, float projmet, 
			   float dphi, float derre, float tmass, float mee, 
			   float max, float min, float maxEta, float minEta, float deta, int nvtx,
			   bool finalLeptons, bool jetVeto, bool uncorrjetVeto, bool preDeltaPhi, bool finalSelection)
{

  myMet         = met;
  myPFMet       = pfmet;
  myCaloMet     = cmet;
  myProjectedMet = projmet;
  myDeltaPhi    = dphi;
  myDeltaR      = derre;
  myTransvMass  = tmass;
  myEleInvMass  = mee;
  maxPtEle      = max;
  minPtEle      = min;
  maxEtaEle     = maxEta;
  minEtaEle     = minEta;
  myDetaLeptons = deta;
  myNVtx        = nvtx;
  myFinalLeptons = finalLeptons;
  myJetVeto       = jetVeto;
  myUncorrJetVeto = uncorrjetVeto;
  myPreDeltaPhi = preDeltaPhi;
  myFinalSelection = finalSelection;
}
 
void RedTopHiggsTree::fillMLVars(int   njets, 
				 int   ncbIDjets, 
				 int   nuncorrjets, 
				 float dxyEVT, 
				 float dszEVT, 
				 float softbdisc, 
				 float hardbdisc, 
				 float bTagSecVertex, 
				 int   nsoftmu, 
				 float leadJetBTagTrackCount, 
				 float subleadJetBTagTrackCount, 
				 float subleadJetsMaxBTagTrackCount, 
				 float leadJetBTagJetBProb, 
				 float subleadJetBTagJetBProb, 
				 float subleadJetsMaxBTagJetBProb,
				 int   numExtraLep, 
				 int   nsoftmunojets, 
				 int   nSoftBJets, 
				 int   nSoftJets,

				 // cb
				 int   numbtagCSVLcbIDaccepjets,
				 int   numbtagCSVMcbIDaccepjets,
				 int   numbtagCSVTcbIDaccepjets,

				 int   numcbIDcentralLjets,
				 int   numcbIDforwardLjets,

				 int   numcbIDcentralMjets,
				 int   numcbIDforwardMjets,

				 // mva
				 int   numbtagCSVLmvaIDaccepjets,
				 int   numbtagCSVMmvaIDaccepjets,
				 int   numbtagCSVTmvaIDaccepjets,

				 int   numbtagCSVLmvaIDcentraljets,
				 int   numbtagCSVMmvaIDcentraljets,
				 int   numbtagCSVTmvaIDcentraljets,

				 int   nummvaIDcentraljets,
				 int   nummvaIDforwardjets,

				 int   nummvaIDaccepINjets ,
				 int   nummvaIDaccepOUTjets				 
) {
 
  myNjets   = njets;
  mycbIDNjets   = ncbIDjets;
  myNuncorrjets = nuncorrjets;
  myDxyEVT = dxyEVT;
  myDszEVT = dszEVT;
  mySoftBdisc = softbdisc;
  myHardBdisc = hardbdisc;
  myBTagSecVertex = bTagSecVertex;
  myNSoftMu = nsoftmu;
  myNSoftMuNoJets = nsoftmunojets;
  myLeadingJetBTagTrackCount = leadJetBTagTrackCount;
  mySubleadingJetBTagTrackCount = subleadJetBTagTrackCount;
  mySubleadingJetsMaxBTagTrackCount = subleadJetsMaxBTagTrackCount;
  myLeadingJetBTagJetBProb = leadJetBTagJetBProb;
  mySubleadingJetBTagJetBProb = subleadJetBTagJetBProb;
  mySubleadingJetsMaxBTagJetBProb = subleadJetsMaxBTagJetBProb;
  myNumExtraLep = numExtraLep;
  myNumSoftBJets = nSoftBJets;
  myNumSoftJets = nSoftJets;

  // cb
  myNumbtagCSVLcbIDaccepjets = numbtagCSVLcbIDaccepjets;
  myNumbtagCSVMcbIDaccepjets = numbtagCSVMcbIDaccepjets;
  myNumbtagCSVTcbIDaccepjets = numbtagCSVTcbIDaccepjets;

  myNumcbIDcentralLjets = numcbIDcentralLjets;
  myNumcbIDforwardLjets = numcbIDforwardLjets;

  myNumcbIDcentralMjets = numcbIDcentralMjets;
  myNumcbIDforwardMjets = numcbIDforwardMjets;

  // mva
  myNumbtagCSVLmvaIDaccepjets = numbtagCSVLmvaIDaccepjets;
  myNumbtagCSVMmvaIDaccepjets = numbtagCSVMmvaIDaccepjets;
  myNumbtagCSVTmvaIDaccepjets = numbtagCSVTmvaIDaccepjets;

  myNumbtagCSVLmvaIDcentraljets = numbtagCSVLmvaIDcentraljets;
  myNumbtagCSVMmvaIDcentraljets = numbtagCSVMmvaIDcentraljets;
  myNumbtagCSVTmvaIDcentraljets = numbtagCSVTmvaIDcentraljets;

  myNummvaIDcentraljets = nummvaIDcentraljets;
  myNummvaIDforwardjets = nummvaIDforwardjets;

  myNummvaIDaccepINjets  = nummvaIDaccepINjets;
  myNummvaIDaccepOUTjets = nummvaIDaccepOUTjets;

 }

void RedTopHiggsTree::fillJetsVars(float ljpt, float ljeta, int ljpfid, int ljmatch, float ljmva, int ljl, float sljpt, float sljeta, int sljpfid, int sljmatch, float sljmva, int sljl) {

  myLeadJetPt             = ljpt;
  myLeadJetEta            = ljeta;
  myLeadJetLooseId        = ljpfid;
  myLeadJetGenMatch       = ljmatch;
  myLeadJetIdMva          = ljmva;
  myLeadJetPassLooseId    = ljl;
  mySubleadJetPt          = sljpt;
  mySubleadJetEta         = sljeta;
  mySubleadJetLooseId     = sljpfid;
  mySubleadJetGenMatch    = sljmatch;
  mySubleadJetIdMva       = sljmva;
  mySubleadJetPassLooseId = sljl;
}

void RedTopHiggsTree::fill2013ExtraJetsVars(float jetPuId_eta[20], float jetPuId_phi[20], float jetPuId_energy[20], float jetPuId_pt[20],
                                            float jetPuId_csv[20], float jetPuId_betastar[20], float jetPuId_rms[20],
                                            int jetPuId_cutBased[20],
                                            float jetPuId_mvaBased[20],
                                            int jetPuId_associated[20]) {

  for(int k=0;k<20;k++){
    myJetPuId_eta[k] = jetPuId_eta[k];
    myJetPuId_phi[k] = jetPuId_phi[k];
    myJetPuId_energy[k] = jetPuId_energy[k];
    myJetPuId_pt[k] = jetPuId_pt[k];
    myJetPuId_csv[k] = jetPuId_csv[k];
    myJetPuId_betastar[k] = jetPuId_betastar[k];
    myJetPuId_rms[k] = jetPuId_rms[k];
    myJetPuId_cutBased[k] = jetPuId_cutBased[k];
    myJetPuId_mvaBased[k] = jetPuId_mvaBased[k];
    myJetPuId_associated[k] = jetPuId_associated[k];
  }
}

void RedTopHiggsTree::fillMoreJetsVars(float ptCVStaggedM[5], float etaCVStaggedM[5], float phiCVStaggedM[5], float eneCVStaggedM[5], float cvsCVStaggedM[5],
				       float   ptForwardM[5], float   etaForwardM[5], float   phiForwardM[5], float   eneForwardM[5], float cvsForwardM[5],
				       float   ptCentralM[5], float   etaCentralM[5], float   phiCentralM[5], float   eneCentralM[5], float cvsCentralM[5],
				       
				       float ptCVStaggedL[5], float etaCVStaggedL[5], float phiCVStaggedL[5], float eneCVStaggedL[5], float cvsCVStaggedL[5],
				       float   ptForwardL[5], float   etaForwardL[5], float   phiForwardL[5], float   eneForwardL[5], float   cvsForwardL[5],
				       float   ptCentralL[5], float   etaCentralL[5], float   phiCentralL[5], float   eneCentralL[5], float   cvsCentralL[5]){
  
  for(int k=0;k<5;k++){
    
    myptCVStaggedM [k] = ptCVStaggedM[k];
    myetaCVStaggedM[k] = etaCVStaggedM[k];
    myphiCVStaggedM[k] = phiCVStaggedM[k];
    myeneCVStaggedM[k] = eneCVStaggedM[k];
    mycvsCVStaggedM[k] = cvsCVStaggedM[k];
    
    myptForwardM [k] = ptForwardM[k];
    myetaForwardM[k] = etaForwardM[k];
    myphiForwardM[k] = phiForwardM[k];
    myeneForwardM[k] = eneForwardM[k];
    mycvsForwardM[k] = cvsForwardM[k];
    
    myptCentralM [k] = ptCentralM[k];
    myetaCentralM[k] = etaCentralM[k];
    myphiCentralM[k] = phiCentralM[k];
    myeneCentralM[k] = eneCentralM[k];
    mycvsCentralM[k] = cvsCentralM[k];
    
    myptCVStaggedL [k] = ptCVStaggedL[k];
    myetaCVStaggedL[k] = etaCVStaggedL[k];
    myphiCVStaggedL[k] = phiCVStaggedL[k];
    myeneCVStaggedL[k] = eneCVStaggedL[k];
    mycvsCVStaggedL[k] = cvsCVStaggedL[k];
    
    myptForwardL [k] = ptForwardL[k];
    myetaForwardL[k] = etaForwardL[k];
    myphiForwardL[k] = phiForwardL[k];
    myeneForwardL[k] = eneForwardL[k];
    mycvsForwardL[k] = cvsForwardL[k];
    
    myptCentralL [k] = ptCentralL[k];
    myetaCentralL[k] = etaCentralL[k];
    myphiCentralL[k] = phiCentralL[k];
    myeneCentralL[k] = eneCentralL[k];
    mycvsCentralL[k] = cvsCentralL[k];
    
  }

}

void RedTopHiggsTree::fillLatinos(bool s0, bool s1) {

  mySteps[0]  = s0;
  mySteps[1]  = s1;

}

void RedTopHiggsTree::fillPDFs(double cteq66[45], double mstw[31], double nnpdf[101]) {
  for(int i=0;i<45;++i)  myCTEQ66[i] = cteq66[i];
  for(int i=0;i<31;++i)  myMSTW  [i] = mstw  [i];
  for(int i=0;i<101;++i) myNNPDF [i] = nnpdf [i];
}

void RedTopHiggsTree::fillRazor(float MTR, float mR, float gammaMR) {

  myMTR = MTR;
  myMR = mR;
  myGammaMR = gammaMR;
}

void RedTopHiggsTree::fillFake(int ntigh, float wfp, float wsfp, 
			    float wfp15, float wsfp15, float wff15, float wsff15, float wpp15, float wspp15,
			    float wfp35, float wsfp35, float wff35, float wsff35, float wpp35, float wspp35,
			    float wfp50, float wsfp50, float wff50, float wsff50, float wpp50, float wspp50,
			    float wfpQCD, float wsfpQCD, float wffQCD, float wsffQCD, float wppQCD, float wsppQCD) {
  
  myTight        = ntigh;
  myWeightFP     = wfp;
  myWeightStatFP = wsfp;
  //
  myWeightFP15     = wfp15;
  myWeightStatFP15 = wsfp15;
  myWeightFF15     = wff15;
  myWeightStatFF15 = wsff15;
  myWeightPP15     = wpp15;
  myWeightStatPP15 = wspp15;
  //
  myWeightFP35     = wfp35;
  myWeightStatFP35 = wsfp35;
  myWeightFF35     = wff35;
  myWeightStatFF35 = wsff35;
  myWeightPP35     = wpp35;
  myWeightStatPP35 = wspp35;
  //
  myWeightFP50     = wfp50;
  myWeightStatFP50 = wsfp50;
  myWeightFF50     = wff50;
  myWeightStatFF50 = wsff50;
  myWeightPP50     = wpp50;
  myWeightStatPP50 = wspp50;
  // 
  myWeightFPQCD     = wfpQCD;
  myWeightStatFPQCD = wsfpQCD;
  myWeightFFQCD     = wffQCD;
  myWeightStatFFQCD = wsffQCD;
  myWeightPPQCD     = wppQCD;
  myWeightStatPPQCD = wsppQCD;
}


void RedTopHiggsTree::fillKinematics(float pxTkMet, float pyTkMet, float pzTkMet,
                                  float pxLeadJet[3], float pyLeadJet[3], float pzLeadJet[3], 
                                  float pxSecJet[3], float pySecJet[3], float pzSecJet[3],    
                                  float pxL1, float pyL1, float pzL1,
                                  float pxL2, float pyL2, float pzL2,
                                  float pxL3, float pyL3, float pzL3,
                                  int ch[3], 
                                  float bdt[3], 
                                  TLorentzVector *jetSum, TLorentzVector *uncorrJetSum, TVector3 *pfmet) {

  myPxTkMet = pxTkMet;
  myPyTkMet = pyTkMet;
  myPzTkMet = pzTkMet;

  for(int jes=0; jes<3; jes++) {
    myPxLeadJet[jes] = pxLeadJet[jes];
    myPyLeadJet[jes] = pyLeadJet[jes];
    myPzLeadJet[jes] = pzLeadJet[jes];
    myPxSecondJet[jes] = pxSecJet[jes];
    myPySecondJet[jes] = pySecJet[jes];
    myPzSecondJet[jes] = pzSecJet[jes];
  }

  myPxL1 = pxL1;
  myPyL1 = pyL1;
  myPzL1 = pzL1;
  myPxL2 = pxL2;
  myPyL2 = pyL2;
  myPzL2 = pzL2;
  myPxL3 = pxL3;
  myPyL3 = pyL3;
  myPzL3 = pzL3;

  myJetsSum = jetSum;
  myUncorrJetsSum = uncorrJetSum;
  myPfMet = pfmet;
  for(int i=0; i<3; i++) {
    myLepCharge[i] = ch[i];
    myLepBDT   [i] = bdt[i];
  }
}

void RedTopHiggsTree::fillSystematics(float scE[3], float r9[3], float ene1, float ene2, float ene3, 
				      int ty1, int ty2, int ty3, TVector3 *metFromJets, TVector3 *pfMetUp, 
				      TVector3 *pfMetDown, float mtUp, float mtDown) {

  for(int i=0; i<3; i++) {
    myScEnergy[i] = scE[i];
    myR9[i] = r9[i];
  }

  myEneL1  = ene1;
  myEneL2  = ene2;
  myEneL3  = ene3;
  myTypeL1 = ty1;
  myTypeL2 = ty2;
  myTypeL3 = ty3;
  myMetFromJets = metFromJets;
  myPfMetUp = pfMetUp;
  myPfMetDown = pfMetDown;  
  myMtUp = mtUp;
  myMtDown = mtDown;
}


void RedTopHiggsTree::fillLeptons(float pt[3], float eta[3], float phi[3], int flavour[3],
				  float lepid[3], float lepiso[3], float lepconv[3]) {
  for(int i=0; i<3; i++) {
    myPt[i] = pt[i];
    myEta[i] = eta[i];
    myPhi[i] = phi[i];
    myLepFlav[i] = flavour[i];
    myLepId[i] = lepid[i];
    myLepIso[i] = lepiso[i];
    myLepConv[i] = lepconv[i];
  }
}

void RedTopHiggsTree::fillCSA07(double weight, double processId, float lumi) 
{

  myWeight = weight;
  myProcesId = processId;
  myLumi = lumi;
}

void RedTopHiggsTree::fillKFactor(float kfactor, float genh, float ptlj ) {

  myKFactor      = kfactor;
  myGenHPt       = genh;
  myLeadingJetPt = ptlj;
}

void RedTopHiggsTree::fillMcTruth(bool prompt, float genmll, float genptll, float genyll) {
  myPromptDecay = prompt;
  myGenptll = genptll;
  myGenyll = genyll;
  myGenmll = genmll;
}

void RedTopHiggsTree::fillHLTElectrons(bool singleEle, bool singleEleRelaxed, bool singleEleOR) {

  myHLTSingleElectron = singleEle;
  myHLTSingleElectronRelaxed = singleEleRelaxed;
  myHLTSingleElectronOR = singleEleOR;
}

void RedTopHiggsTree::fillHLTMuons(bool singleMuon, bool singleMuonRelaxed, bool singleMuonOR) {

  myHLTSingleMuon = singleMuon;
  myHLTSingleMuonRelaxed = singleMuonRelaxed;
  myHLTSingleMuonOR = singleMuonOR;
}

void RedTopHiggsTree::fillRunInfos(int run, int lumi, long event, float puweight, bool HLT, float npu[3]) {

  myRun = run;
  myLS = lumi;
  myEvent = event;
  myPUWeight = puweight;
  myHLT = HLT;
  for(int i=0; i<3; i++) myNpu[i] = npu[i];
}

void RedTopHiggsTree::fillMetStudies(float projPF, float projTk, float signPFMet, float signChMet, float m_MTRcha, float DYMVA, float rho, float rhojet) {
  
  myProjPFMet        = projPF;  
  myProjPFChargedMet = projTk;  
  mySignPFMet        = signPFMet;
  mySignPFChargedMet = signChMet;
  myMTRchargedMet    = m_MTRcha;
  myDYMVA  = DYMVA;
  myRho    = rho; 
  myRhoJet = rhojet; 
}

void RedTopHiggsTree::filltHMcTruthInfos(float genHiggsPt,
					 float genHiggsEta,
					 
					 float genTopPt, 
					 float genTopEta,
					 
					 float genWpfromH_Pt, 
					 float genWpfromH_Eta,
					 
					 float genWmfromH_Pt,
					 float genWmfromH_Eta,
					 
					 float genWfromT_Pt,
					 float genWfromT_Eta,
					 
					 float genLeptonPlusfromWfromH_Pt,
					 float genLeptonPlusfromWfromH_Eta,
					 
					 float genLeptonMinusfromWfromH_Pt,
					 float genLeptonMinusfromWfromH_Eta,
					 
					 float genLeptonfromWfromT_Pt,
					 float genLeptonfromWfromT_Eta,
					 
					 float genNeutrinoPlusfromWfromH_Pt,
					 float genNeutrinoPlusfromWfromH_Eta,
					 
					 float genNeutrinoMinusfromWfromH_Pt,
					 float genNeutrinoMinusfromWfromH_Eta,
					 
					 float genNeutrinofromWfromT_Pt,
					 float genNeutrinofromWfromT_Eta,

					 float genForwardQuark_Pt,
					 float genForwardQuark_Eta,

					 float genbQuark_Pt,
					 float genbQuark_Eta){
  
  myGenHiggsPt = genHiggsPt;
  myGenHiggsEta = genHiggsEta;
  
  myGenTopPt = genTopPt; 
  myGenTopEta = genTopEta;
  
  myGenWpfromH_Pt = genWpfromH_Pt; 
  myGenWpfromH_Eta = genWpfromH_Eta;
  
  myGenWmfromH_Pt = genWmfromH_Pt;
  myGenWmfromH_Eta = genWmfromH_Eta;
  
  myGenWfromT_Pt = genWfromT_Pt;
  myGenWfromT_Eta = genWfromT_Eta;
  
  myGenLeptonPlusfromWfromH_Pt = genLeptonPlusfromWfromH_Pt;
  myGenLeptonPlusfromWfromH_Eta = genLeptonPlusfromWfromH_Eta;
  
  myGenLeptonMinusfromWfromH_Pt = genLeptonMinusfromWfromH_Pt;
  myGenLeptonMinusfromWfromH_Eta = genLeptonMinusfromWfromH_Eta;
  
  myGenLeptonfromWfromT_Pt = genLeptonfromWfromT_Pt;
  myGenLeptonfromWfromT_Eta = genLeptonfromWfromT_Eta;
  
  myGenNeutrinoPlusfromWfromH_Pt = genNeutrinoPlusfromWfromH_Pt;
  myGenNeutrinoPlusfromWfromH_Eta = genNeutrinoPlusfromWfromH_Eta;
  
  myGenNeutrinoMinusfromWfromH_Pt = genNeutrinoMinusfromWfromH_Pt;
  myGenNeutrinoMinusfromWfromH_Eta = genNeutrinoMinusfromWfromH_Eta;
  
  myGenNeutrinofromWfromT_Pt = genNeutrinofromWfromT_Pt;  
  myGenNeutrinofromWfromT_Eta = genNeutrinofromWfromT_Eta;

  myGenForwardQuark_Pt = genForwardQuark_Pt;  
  myGenForwardQuark_Eta = genForwardQuark_Eta;

  myGenbQuark_Pt = genbQuark_Pt;  
  myGenbQuark_Eta = genbQuark_Eta;

}

//! add lepton mva variables
void RedTopHiggsTree::fillLeptonMVAidVariables(float leptPt[3],
					       float leptEta[3],
					       float neuRelIs[3],
					       float chRelIso[3],
					       float jetDR_in[3],
					       float jetPtRatio_in[3],
					       float jetBTagCSV_in[3],
					       float sip3d[3],
					       float mvaId[3],
					       int   innerHits[3],
					       float logdxy[3],
					       float logdz[3]){
  
  for (int i=0; i<3; i++){
    
    myleptPt[i]  = leptPt[i];
    myleptEta[i] = leptEta[i];
    myneuRelIs[i] = neuRelIs[i];
    mychRelIso[i] = chRelIso[i];
    myjetDR_in[i] = jetDR_in[i];
    myjetPtRatio_in[i] = jetPtRatio_in[i];
    myjetBTagCSV_in[i] = jetBTagCSV_in[i];
    mysip3d[i] = sip3d[i];
    mymvaId[i] = mvaId[i];
    myinnerHits[i] = innerHits[i];
    mylogdxy[i] = logdxy[i];
    mylogdz[i] = logdz[i];

  }

}
