#include <wx/wx.h>
#include "window.h"
#include <wx/image.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dc.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <math.h>
#include "invert.h"	
#include "scale.h"	
#include "conv3.h"	
#include "conv5.h"	
#include "shift.h"	
#include "rraw.h"	
#include "saltnoise.h"
#include "peppernoise.h"
#include "minfilter.h"
#include "maxfilter.h"
#include "midpointfilter.h"
#include "medianfilter.h"
#include "histogram.h"
#include "disphist.h"
#include "simplethreshold.h"
#include "automatedthreshold.h"
#include "adaptivethreshold.h"
#include "roi.h"
#include "undo.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

using namespace std; 

static const wxChar *FILETYPES = _T("All files (*.*)|*.*");

IMPLEMENT_APP(BasicApplication)

bool BasicApplication::OnInit()
{
  wxInitAllImageHandlers();
  MyFrame *frame = new MyFrame(_("Basic Frame"), 50, 50, 700, 700); //700 by 400
  frame->Show(TRUE);
  SetTopWindow(frame);
  return TRUE;	
}

MyFrame::MyFrame(const wxString title, int xpos, int ypos, int width, int height): wxFrame((wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height)){

  fileMenu = new wxMenu;
  fileMenu->Append(LOAD_FILE_ID, _T("&Open file")); 
  fileMenu->Append(READ_RAW_IMAGE_ID, _T("&Read RAW image")); //--->To be modified! 
  fileMenu->AppendSeparator();

//###########################################################//
//----------------------START MY MENU -----------------------//
//###########################################################// 
  
  fileMenu->Append(INVERT_IMAGE_ID, _T("&Invert image"));
  fileMenu->Append(SCALE_IMAGE_ID, _T("&Scale image"));
  fileMenu->Append(SHIFT_IMAGE_ID, _T("&Shift image")); //--->To be modified!
  fileMenu->Append(SALT_NOISE_IMAGE_ID, _T("&Add salt noise")); //--->To be modified!
  fileMenu->Append(PEPPER_NOISE_IMAGE_ID, _T("&Add pepper noise")); //--->To be modified!
  fileMenu->Append(CONVOLVE3X3_IMAGE_ID, _T("&Convolve3x3 image")); //--->To be modified!
  fileMenu->Append(CONVOLVE5X5_IMAGE_ID, _T("&Convolve5x5 image")); //--->To be modified!
  fileMenu->Append(MIN_FILTER_IMAGE_ID, _T("&MIN filter")); //--->To be modified!
  fileMenu->Append(MAX_FILTER_IMAGE_ID, _T("&MAX filter")); //--->To be modified!
  fileMenu->Append(MIDPOINT_FILTER_IMAGE_ID, _T("&Midpoint filter")); //--->To be modified!
  fileMenu->Append(MEDIAN_FILTER_IMAGE_ID, _T("&Median filter")); //--->To be modified!
  fileMenu->Append(HISTOGRAM_IMAGE_ID, _T("&Histogram")); //--->To be modified!
  fileMenu->Append(DISP_HIST_IMAGE_ID, _T("&Display Histogram")); //--->To be modified!
  fileMenu->Append(SIMPLE_THRESHOLD_IMAGE_ID, _T("&Simple Thresholding")); //--->To be modified!
  fileMenu->Append(AUTOMATED_THRESHOLD_IMAGE_ID, _T("&Automated Thresholding")); //--->To be modified!
  fileMenu->Append(ADAPTIVE_THRESHOLD_IMAGE_ID, _T("&Adaptive Thresholding")); //--->To be modified!
  fileMenu->Append(ROICONVOLVE3X3_IMAGE_ID, _T("&ROI Convolve3x3 image")); //--->To be modified!
  fileMenu->Append(UNDO_IMAGE_ID, _T("&Undo")); //--->To be modified!
  fileMenu->Append(MY_IMAGE_ID, _T("&My function")); //--->To be modified!
 
//###########################################################//
//----------------------END MY MENU -------------------------//
//###########################################################// 

  fileMenu->AppendSeparator();
  fileMenu->Append(SAVE_IMAGE_ID, _T("&Save image"));
  fileMenu->Append(EXIT_ID, _T("E&xit"));

  menuBar = new wxMenuBar;
  menuBar->Append(fileMenu, _T("&File"));

  
  SetMenuBar(menuBar);


  CreateStatusBar(3); 
  oldWidth = 0;
  oldHeight = 0;
  loadedImage = 0;

/* initialise the variables that we added */
  imgWidth = imgHeight = 0;
  stuffToDraw = 0;

}

MyFrame::~MyFrame(){
/* release resources */
  if(loadedImage){
    loadedImage->Destroy();
    loadedImage = 0;
  }

}

void MyFrame::OnOpenFile(wxCommandEvent & event){
  wxFileDialog *openFileDialog = new wxFileDialog ( this, _T("Open file"), _T(""), _T(""), FILETYPES, wxOPEN, wxDefaultPosition);  
  if(openFileDialog->ShowModal() == wxID_OK){
    wxString filename = openFileDialog->GetFilename();
    wxString path = openFileDialog->GetDirectory() + wxString(_T("/"));
    printf("Loading image form file...");    
    loadedImage = new wxImage(path + filename); //Image Loaded form file 
    if(loadedImage->Ok()){
      stuffToDraw = ORIGINAL_IMG;    // set the display flag
      printf("Done! \n");    
    }
    else {
      loadedImage->Destroy();
      loadedImage = 0;
    }
    Refresh();
  }    
}


//###########################################################//
//-----------------------------------------------------------//
//---------- DO NOT MODIFY THE CODE ABOVE--------------------//
//-----------------------------------------------------------//
//###########################################################//



//###########################################################//
//-----------------------------------------------------------//
//--------------------- EMPTY FUNCTION-----------------------//
//-----------------------------------------------------------//
//###########################################################//
//My Function ---> To be modified!
void MyFrame::OnMyFunctionImage(wxCommandEvent & event){

    printf("My function...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());

    unsigned char r,g,b;

    for( int i=0;i<imgWidth;i++)
       for(int j=0;j<imgHeight;j++){
	// GET THE RGB VALUES 	
        r = loadedImage->GetRed(i,j);   // red pixel value
        g = loadedImage->GetGreen(i,j); // green pixel value
	b = loadedImage->GetBlue(i,j); // blue pixel value

	//printf("(%d,%d) [r = %x  | g = %x | b = %x] \n",i,j,r,g,b);        
        
	// SAVE THE RGB VALUES
	loadedImage->SetRGB(i,j,r,g,b); 
    }
	
    printf(" Finished My function.\n");
    Refresh();
}


//###########################################################//
//-----------------------------------------------------------//
//---------- DO NOT MODIFY THE CODE BELOW--------------------//
//-----------------------------------------------------------//
//###########################################################//


//IMAGE SAVING
void MyFrame::OnSaveImage(wxCommandEvent & event){

    printf("Saving image...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());

    loadedImage->SaveFile(wxT("Saved_Image.bmp"), wxBITMAP_TYPE_BMP);

    printf("Finished Saving.\n");
}


void MyFrame::OnExit (wxCommandEvent & event){
  Close(TRUE);
}


void MyFrame::OnPaint(wxPaintEvent & event){
  wxPaintDC dc(this);
  int cWidth, cHeight;  
  GetSize(&cWidth, &cHeight);
  if ((back_bitmap == NULL) || (oldWidth != cWidth) || (oldHeight != cHeight)) {
    if (back_bitmap != NULL)
      delete back_bitmap;
    back_bitmap = new wxBitmap(cWidth, cHeight);
    oldWidth = cWidth;
    oldHeight = cHeight;
  }
  wxMemoryDC *temp_dc = new wxMemoryDC(&dc);
  temp_dc->SelectObject(*back_bitmap);
  // We can now draw into the offscreen DC...
  temp_dc->Clear();
  if(loadedImage)
    temp_dc->DrawBitmap(wxBitmap(*loadedImage), 0, 0, false);//given bitmap xcoord y coord and transparency
       
  switch(stuffToDraw){
     case NOTHING:
        break;
     case ORIGINAL_IMG:
       bitmap.CleanUpHandlers; // clean the actual image header
       bitmap = wxBitmap(*loadedImage); // Update the edited/loaded image
       break;
  }

// update image size
imgWidth  = (bitmap.ConvertToImage()).GetWidth();
imgHeight = (bitmap.ConvertToImage()).GetHeight();



 temp_dc->SelectObject(bitmap);//given bitmap 

  //end draw all the things
  // Copy from this DC to another DC.
  dc.Blit(0, 0, cWidth, cHeight, temp_dc, 0, 0);
  delete temp_dc; // get rid of the memory DC  
}

BEGIN_EVENT_TABLE (MyFrame, wxFrame)
  EVT_MENU ( LOAD_FILE_ID,  MyFrame::OnOpenFile)
  EVT_MENU ( EXIT_ID,  MyFrame::OnExit)

//###########################################################//
//----------------------START MY EVENTS ---------------------//
//###########################################################// 

  EVT_MENU ( INVERT_IMAGE_ID,  MyFrame::OnInvertImage)
  EVT_MENU ( SCALE_IMAGE_ID,  MyFrame::OnScaleImage)
  EVT_MENU ( SAVE_IMAGE_ID,  MyFrame::OnSaveImage)
  EVT_MENU ( MY_IMAGE_ID,  MyFrame::OnMyFunctionImage)//--->To be modified!
  EVT_MENU ( SHIFT_IMAGE_ID,  MyFrame::OnShiftImage)//--->To be modified!
  EVT_MENU ( READ_RAW_IMAGE_ID,  MyFrame::OnReadRAWImage)//--->To be modified!
  EVT_MENU ( CONVOLVE3X3_IMAGE_ID,  MyFrame::OnConvolve3x3Image)//--->To be modified!
  EVT_MENU ( CONVOLVE5X5_IMAGE_ID,  MyFrame::OnConvolve5x5Image)//--->To be modified!
  EVT_MENU ( SALT_NOISE_IMAGE_ID,  MyFrame::OnSaltNoiseImage)//--->To be modified!
  EVT_MENU ( PEPPER_NOISE_IMAGE_ID,  MyFrame::OnPepperNoiseImage)//--->To be modified!
  EVT_MENU ( MIN_FILTER_IMAGE_ID,  MyFrame::OnMinFilterImage)//--->To be modified!
  EVT_MENU ( MAX_FILTER_IMAGE_ID,  MyFrame::OnMaxFilterImage)//--->To be modified!
  EVT_MENU ( MIDPOINT_FILTER_IMAGE_ID,  MyFrame::OnMidpointFilterImage)//--->To be modified!
  EVT_MENU ( MEDIAN_FILTER_IMAGE_ID,  MyFrame::OnMedianFilterImage)//--->To be modified!
  EVT_MENU ( HISTOGRAM_IMAGE_ID,  MyFrame::OnHistogramImage)//--->To be modified!
  EVT_MENU ( DISP_HIST_IMAGE_ID,  MyFrame::OnDispHistImage)//--->To be modified!
  EVT_MENU ( SIMPLE_THRESHOLD_IMAGE_ID,  MyFrame::OnSimpleThresholdImage)//--->To be modified!
  EVT_MENU ( AUTOMATED_THRESHOLD_IMAGE_ID,  MyFrame::OnAutomatedThresholdImage)//--->To be modified!
  EVT_MENU ( ADAPTIVE_THRESHOLD_IMAGE_ID,  MyFrame::OnAdaptiveThresholdImage)//--->To be modified!
  EVT_MENU ( ROICONVOLVE3X3_IMAGE_ID,  MyFrame::OnROIConvolve3x3Image)//--->To be modified!
  EVT_MENU ( UNDO_IMAGE_ID,  MyFrame::OnUndoImage)//--->To be modified!

//###########################################################//
//----------------------END MY EVENTS -----------------------//
//###########################################################// 

  EVT_PAINT (MyFrame::OnPaint)
END_EVENT_TABLE()
