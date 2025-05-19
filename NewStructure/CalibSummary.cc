#include "CalibSummary.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"

ClassImp(CalibSummary);

bool CalibSummary::Fill(const TileCalib& tc){
  hLGped        .Fill(tc.PedestalMeanL);
  hLGpedwidth   .Fill(tc.PedestalSigL);
  hHGped        .Fill(tc.PedestalMeanH);
  hHGpedwidth   .Fill(tc.PedestalSigH);
  hLGscale      .Fill(tc.ScaleL);
  if (tc.LGHGCorr != 0. ) hLGscaleCalc  .Fill(tc.ScaleH/tc.LGHGCorr);
  else hLGscaleCalc  .Fill(-1000);
  hLGscalewidth .Fill(tc.ScaleWidthL);
  hHGscale      .Fill(tc.ScaleH);
  hHGscalewidth .Fill(tc.ScaleWidthH);
  hHGLGcorr     .Fill(tc.HGLGCorr);
  hLGHGcorr     .Fill(tc.LGHGCorr);
  return true;
}

bool CalibSummary::Write(TFile* f){
  f->cd();
  hLGped          .Write();
  hLGpedwidth     .Write();
  hHGped          .Write();
  hHGpedwidth     .Write();
  hLGscale        .Write();
  hLGscaleCalc    .Write();
  hLGscalewidth   .Write();
  hHGscale        .Write();
  hHGscalewidth   .Write();
  hHGLGcorr       .Write();
  hLGHGcorr       .Write();
  return true;
}

bool CalibSummary::Analyse(){
  std::cout << "***********************************************************************************************************************" << std::endl;
  std::cout << "Run Nr.: "<< RunNr << "\t total entries: "<< hLGped.GetEntries() << std::endl;
  std::cout << Form("\t --> LG pedestal:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hLGped.GetMean(), hLGped.GetRMS(), 
                    hLGped.GetBinContent(0)+hLGped.GetBinContent(hLGped.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> LG pedestal sigma:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hLGpedwidth.GetMean(), hLGpedwidth.GetRMS(), 
                    hLGpedwidth.GetBinContent(0)+hLGpedwidth.GetBinContent(hLGpedwidth.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> HG pedestal:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hHGped.GetMean(), hHGped.GetRMS(), 
                    hHGped.GetBinContent(0)+hHGped.GetBinContent(hHGped.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> HG pedestal sigma:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hHGpedwidth.GetMean(), hHGpedwidth.GetRMS(), 
                    hHGpedwidth.GetBinContent(0)+hHGpedwidth.GetBinContent(hHGpedwidth.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> LG scale:\t\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hLGscale.GetMean(), hLGscale.GetRMS(), 
                    hLGscale.GetBinContent(0)+hLGscale.GetBinContent(hLGscale.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> LG scale calc:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hLGscaleCalc.GetMean(), hLGscaleCalc.GetRMS(), 
                    hLGscaleCalc.GetBinContent(0)+hLGscaleCalc.GetBinContent(hLGscaleCalc.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> LG scale width:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hLGscalewidth.GetMean(), hLGscalewidth.GetRMS(), 
                    hLGscalewidth.GetBinContent(0)+hLGscalewidth.GetBinContent(hLGscalewidth.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> HG scale:\t\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hHGscale.GetMean(), hHGscale.GetRMS(), 
                    hHGscale.GetBinContent(0)+hHGscale.GetBinContent(hHGscale.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> HG scale width:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hHGscalewidth.GetMean(), hHGscalewidth.GetRMS(), 
                    hHGscalewidth.GetBinContent(0)+hHGscalewidth.GetBinContent(hHGscalewidth.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> LG-HG corr:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hLGHGcorr.GetMean(), hLGHGcorr.GetRMS(), 
                    hLGHGcorr.GetBinContent(0)+hLGHGcorr.GetBinContent(hLGHGcorr.GetNbinsX()+1)  )
            << std::endl;
  std::cout << Form("\t --> HG-LG corr:\t mean:\t%3.3f\t\tRMS:\t%3.3f\t\t%.0f\t out of bounds", 
                    hHGLGcorr.GetMean(), hHGLGcorr.GetRMS(), 
                    hHGLGcorr.GetBinContent(0)+hHGLGcorr.GetBinContent(hHGLGcorr.GetNbinsX()+1)  )
            << std::endl;
  std::cout << "***********************************************************************************************************************" << std::endl;
  return true;
}
