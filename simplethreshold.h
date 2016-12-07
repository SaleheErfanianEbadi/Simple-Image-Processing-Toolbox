//Simple Thresholding- Finding Mean and Standard Deviation ---> To be modified!
void MyFrame::OnSimpleThresholdImage(wxCommandEvent & event){

    printf("Simple Thresholding...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());
	
	double RHist[256];	int Rv;		double normalHistR[256];
	double GHist[256];	int Gv;		double normalHistG[256];
	double BHist[256];	int Bv;		double normalHistB[256];

	for(int i=0;i<256;i++)
	{
	RHist[i]=0;
	GHist[i]=0;
	BHist[i]=0;
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
	normalHistR[m]=( (double) RHist[m])/(imgWidth*imgHeight);
	normalHistG[m]=( (double) GHist[m])/(imgWidth*imgHeight);
	normalHistB[m]=( (double) BHist[m])/(imgWidth*imgHeight);
	}

//find mean of each channel in image
	double MeanR;
	double MeanG;
	double MeanB;

	for(int k=0;k<256;k++)
	{	
	MeanR += normalHistR[k]*k;
	MeanG += normalHistG[k]*k;
	MeanB += normalHistB[k]*k;
	}

//find Standard Deviation for each channel in image
	double SDR=0;
	double SDG=0;
	double SDB=0;

	for(int k=0;k<imgWidth;k++)
	{	
		for(int l=0;l<imgHeight;l++)
		{
		SDR = SDR + abs(loadedImage->GetRed(k,l) - MeanR);
		SDG = SDG + abs(loadedImage->GetGreen(k,l) - MeanG);
		SDB = SDB + abs(loadedImage->GetBlue(k,l) - MeanB);
		}
	}

//Simple Thresholding
	double TR = MeanR;
	double TG = MeanG;
	double TB = MeanB;
	for(int k=0;k<imgWidth;k++)
	{	
		for(int l=0;l<imgHeight;l++)
		{
			if(loadedImage->GetRed(k,l) < TR)
			{
			loadedImage->SetRGB(k,l,0,loadedImage->GetGreen(k,l),loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetRed(k,l) > TR)
			{
			loadedImage->SetRGB(k,l,255,loadedImage->GetGreen(k,l),loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetGreen(k,l) < TG)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),0,loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetGreen(k,l) > TG)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),255,loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetBlue(k,l) < TB)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),loadedImage->GetGreen(k,l),0);
			}
			if(loadedImage->GetBlue(k,l) > TB)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),loadedImage->GetGreen(k,l),255);
			}
		}
	}

    printf(" Finished Simple Thresholding.\n");
    Refresh();
}
