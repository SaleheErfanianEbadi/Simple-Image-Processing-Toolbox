//Display Histogram ---> To be modified!
void MyFrame::OnDispHistImage(wxCommandEvent & event){
     
    
    printf("Displaying Histogram...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());


	int RHist[256];	int Rv;	double normalHistR[256];
	int GHist[256];	int Gv;	double normalHistG[256];
	int BHist[256];	int Bv;	double normalHistB[256];

        for (int k = 0; k < 256 ; k++)
        {
          RHist[k] = 0;
        }

        //find # of each color in image
	for(int k=0;k<imgWidth;k++)
	{	
		for(int l=0;l<imgHeight;l++)
		{
		Rv=loadedImage->GetRed(k,l);
		RHist[Rv]=RHist[Rv]+1;

		Gv=loadedImage->GetGreen(k,l);
		GHist[Gv]=GHist[Gv]+1;

		Bv=loadedImage->GetBlue(k,l);
		BHist[Bv]=BHist[Bv]+1;
		}
	}
	
	//normalize image for example divide by 512*512
	for(int m=0;m<256;m++)
	{
	normalHistR[m]= ((double) RHist[m]) / (imgWidth*imgHeight);
	normalHistG[m]=GHist[m]/(imgWidth*imgHeight);
	normalHistB[m]=BHist[m]/(imgWidth*imgHeight);
	}
	
    
    //Image properties
    int width = 256;
    int height = 256;

    //Freeing the previous image 
    free(loadedImage);
    //Loading a new image to loadedImage
    loadedImage = new wxImage(width,height);

    //Paint every pixel white.
    for (int h = 0; h < height; h++)
    {
      for (int w = 0; w < width; w++)
      {
        loadedImage->SetRGB(w,h,255,255,255);
      }
    }


//Draw Histogram
    double max_value = 0;
    for (int x = 0; x < width ; x++)
    {
      max_value = (max_value > normalHistR[x]) ? max_value : normalHistR[x];
    }
    //printf("max_value = %f.\n",max_value);

    double scale = (200 / max_value);
    for (int x = 0; x < width ; x++)
    {
      int value = (int) (scale * normalHistR[x]);
      //printf("%d - %f - %d.\n",RHist[x],normalHistR[x],value);
      for (int y = 255; y > (255 - value) ; y--)
      {
        loadedImage->SetRGB(x,y,0,0,0);
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

    printf("Finished Displaying Histogram.\n");
    Refresh();
}
