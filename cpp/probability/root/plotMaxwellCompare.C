void
plotMaxwellCompare() { 

  TH1F * h_reject = new TH1F("h_reject","h_reject",100,0,10);
  TH1F * h_metro  = new TH1F("h_metro","h_metro",100,0,10);

  TTree * t = new TTree("t","t"); 
  t->ReadFile("data/maxwell_boltzmann_compare.dat", "index/i:reject/D:metro/D");



  t->Draw("metro>>h_metro","","goff");
  t->Draw("reject>>h_reject","","goff");

  h_reject->SetLineColor(kRed);
  h_metro->SetLineColor(kBlue);  

  TCanvas * c = new TCanvas("c","c",0,0,600,500);
  TH1F * frame = (TH1F*)(c->DrawFrame(0,0,10,1.1*TMath::Max(h_reject->GetMaximum(),h_metro->GetMaximum())));
  h_reject->Draw("sames");
  h_metro->Draw("sames");

  //
  // color the text in the stats boxes
  //
  c->Modified();
  c->Update();
  TPaveStats * s_reject = (TPaveStats*)(h_reject->GetListOfFunctions()->FindObject("stats"));
  s_reject->SetTextColor(kRed);
  TPaveStats * s_metro = (TPaveStats*)(h_metro->GetListOfFunctions()->FindObject("stats"));
  s_metro->SetTextColor(kBlue);
  c->Modified();


}
