//Finding Histogram ---> To be modified!
void MyFrame::OnHistogramImage(wxCommandEvent & event){

    printf("Finding Histogram...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

						//double
	double RHist[256];	int Rv;		double normalHistR[256];		double eqR[256]={0};	double cumulativeDistR[256];
	double GHist[256];	int Gv;		double normalHistG[256];		double eqG[256]={0};	double cumulativeDistG[256];
	double BHist[256];	int Bv;		double normalHistB[256];		double eqB[256]={0};	double cumulativeDistB[256];

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
	normalHistR[m]=RHist[m]/(imgWidth*imgHeight);
	normalHistG[m]=GHist[m]/(imgWidth*imgHeight);
	normalHistB[m]=BHist[m]/(imgWidth*imgHeight);
	}
	
//equalize, add each pixel value with its previous values
	eqR[0]=normalHistR[0];
	eqG[0]=normalHistG[0];
	eqB[0]=normalHistB[0];

	for(int o=1;o<256;o++)
	{
		for(int p=o;p>=0;p--)
		{
		eqR[o]=eqR[o]+normalHistR[p];
		eqG[o]=eqG[o]+normalHistG[p];
		eqB[o]=eqB[o]+normalHistB[p];
		}
	}

//multiply by the highest gray-level value (L-1) 255
	for(int q=0;q<256;q++)
	{
	cumulativeDistR[q]=eqR[q]*255;
	cumulativeDistG[q]=eqG[q]*255;
	cumulativeDistB[q]=eqB[q]*255;
	}


	int newRed; int newGreen; int newBlue;

	for(int k=0;k<imgWidth;k++)
        {
		for(int l=0;l<imgHeight;l++)
		{
                newRed = loadedImage->GetRed(k,l);
		newGreen = loadedImage->GetGreen(k,l);
		newBlue = loadedImage->GetBlue(k,l);

		loadedImage->SetRGB(k,l,cumulativeDistR[newRed],cumulativeDistG[newGreen],cumulativeDistB[newBlue]);
		}
	}




    printf(" Finished Finding Histogram.\n");
    Refresh();
}
