
class BasicApplication : public wxApp {
 public:
    virtual bool OnInit();
};


class MyFrame : public wxFrame {    
 protected:
    wxMenuBar  *menuBar;//main menu bar
    wxMenu     *fileMenu;//file menu
    wxBitmap *back_bitmap; // offscreen memory buffer for drawing
    wxToolBar *toolbar;//tollbar not necessary to use
    int oldWidth, oldHeight; // save old dimensions

    wxBitmap bitmap;  //structure for the edited image
    wxImage *loadedImage; // image loaded from file
    wxImage *loadedImage2;
    int imgWidth, imgHeight; // image dimensions
    int stuffToDraw; 

   /* declear message handler */
    void OnInvertImage(wxCommandEvent & event);
    void OnScaleImage(wxCommandEvent & event);
    void OnSaveImage(wxCommandEvent & event);
    void OnMyFunctionImage(wxCommandEvent & event); //---> To be modified!
    void OnShiftImage(wxCommandEvent & event); //---> To be modified!
    void OnReadRAWImage(wxCommandEvent & event); //---> To be modified!
    void OnConvolve3x3Image(wxCommandEvent & event); //---> To be modified!
    void OnConvolve5x5Image(wxCommandEvent & event); //---> To be modified!
    void OnSaltNoiseImage(wxCommandEvent & event); //---> To be modified!
    void OnPepperNoiseImage(wxCommandEvent & event); //---> To be modified!
    void OnMinFilterImage(wxCommandEvent & event); //---> To be modified!
    void OnMaxFilterImage(wxCommandEvent & event); //---> To be modified!
    void OnMidpointFilterImage(wxCommandEvent & event); //---> To be modified!
    void OnMedianFilterImage(wxCommandEvent & event); //---> To be modified!
    void OnHistogramImage(wxCommandEvent & event); //---> To be modified!
    void OnDispHistImage(wxCommandEvent & event); //---> To be modified!
    void OnSimpleThresholdImage(wxCommandEvent & event); //---> To be modified!
    void OnAutomatedThresholdImage(wxCommandEvent & event); //---> To be modified!
    void OnAdaptiveThresholdImage(wxCommandEvent & event); //---> To be modified!
    void OnROIConvolve3x3Image(wxCommandEvent & event); //---> To be modified!
    void OnUndoImage(wxCommandEvent & event); //---> To be modified!
    
 public:
    MyFrame(const wxString title, int xpos, int ypos, int width, int height);
    virtual ~MyFrame();
    
    void OnExit(wxCommandEvent & event);       
    void OnOpenFile(wxCommandEvent & event);       
    void OnPaint(wxPaintEvent & event);	
    
    DECLARE_EVENT_TABLE()
	
};

enum { NOTHING = 0,
       ORIGINAL_IMG,
};

enum { EXIT_ID = wxID_HIGHEST + 1,      
       LOAD_FILE_ID,
       INVERT_IMAGE_ID,
       SCALE_IMAGE_ID,
       SAVE_IMAGE_ID,
       MY_IMAGE_ID, //--->To be modified!
       SHIFT_IMAGE_ID, //--->To be modified!
       CONVOLVE3X3_IMAGE_ID, //--->To be modified!
       CONVOLVE5X5_IMAGE_ID, //--->To be modified!
       SALT_NOISE_IMAGE_ID, //--->To be modified!
       PEPPER_NOISE_IMAGE_ID, //--->To be modified!
       MIN_FILTER_IMAGE_ID, //--->To be modified!
       MAX_FILTER_IMAGE_ID, //--->To be modified!
       MIDPOINT_FILTER_IMAGE_ID, //--->To be modified!
       MEDIAN_FILTER_IMAGE_ID, //--->To be modified!
       HISTOGRAM_IMAGE_ID, //--->To be modified!
       DISP_HIST_IMAGE_ID, //--->To be modified!
       SIMPLE_THRESHOLD_IMAGE_ID, //--->To be modified!
       AUTOMATED_THRESHOLD_IMAGE_ID, //--->To be modified!
       ADAPTIVE_THRESHOLD_IMAGE_ID, //--->To be modified!
       ROICONVOLVE3X3_IMAGE_ID, //--->To be modified!
       UNDO_IMAGE_ID, //--->To be modified!
       READ_RAW_IMAGE_ID,
};
