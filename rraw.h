//Read Raw Images ---> To be modified!
void MyFrame::OnReadRAWImage(wxCommandEvent & event){
     
    
    printf("INSIDE READ RAW IMAGE!.\n");
    int width, height;
    int h,w;
	
    
    //Image properties
    width = 512;
    height = 512;

    //Freeing the previous image 
    free(loadedImage);
    //Loading a new image to loadedImage
    loadedImage = new wxImage(width,height);

    //Paint every pixel white.
    for (h = 0; h < height; h++)
    {
      for (w = 0; w < width; w++)
      {
        loadedImage->SetRGB(w,h,255,255,255);
      }
    }
    

    //Signal that the image is loaded
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
