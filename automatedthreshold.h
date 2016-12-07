//Automated Thresholding ---> To be modified!
void MyFrame::OnAutomatedThresholdImage(wxCommandEvent & event){

    printf("Automated Thresholding...");
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

//Automated Thresholding
	double TR1 = 0;		double TR2 = MeanR;
	double TG1 = 0;		double TG2 = MeanG;
	double TB1 = 0;		double TB2 = MeanB;

	double finishR; double finishG; double finishB;

	//finding mean for Background and object in step 1
	double BGMeanR;		double BGMeanG;		double BGMeanB;
	double OBJMeanR;	double OBJMeanG;	double OBJMeanB;

	int RvBG=0;	int BvBG=0;	int GvBG=0;
	int RvOBJ=0;	int BvOBJ=0;	int GvOBJ=0;

while(finishR>0.0000001 & finishG>0.0000001 & finishB>0.0000001)
{
	for(int k=0;k<imgWidth;k++)
	{	
		for(int l=0;l<imgHeight;l++)
		{
			if(loadedImage->GetRed(k,l) <= TR2)
			{
			BGMeanR += loadedImage->GetRed(k,l);
			RvBG++;
			}
			if(loadedImage->GetRed(k,l) > TR2)
			{
			OBJMeanR += loadedImage->GetRed(k,l);
			RvOBJ++;
			}

			if(loadedImage->GetGreen(k,l) <= TG2)
			{
			BGMeanG += loadedImage->GetGreen(k,l);
			GvBG++;
			}
			if(loadedImage->GetGreen(k,l) > TG2)
			{
			OBJMeanG += loadedImage->GetGreen(k,l);
			GvOBJ++;
			}

			if(loadedImage->GetBlue(k,l) <= TB2)
			{
			BGMeanB += loadedImage->GetBlue(k,l);
			BvBG++;
			}
			if(loadedImage->GetBlue(k,l) > TB2)
			{
			OBJMeanB += loadedImage->GetBlue(k,l);
			BvOBJ++;
			}

		}
	}

	TR2 = ( (BGMeanR/RvBG) + (OBJMeanR/RvOBJ) ) / 2;
	TG2 = ( (BGMeanG/GvBG) + (OBJMeanG/GvOBJ) ) / 2;
	TB2 = ( (BGMeanB/BvBG) + (OBJMeanB/BvOBJ) ) / 2;

	RvBG=0;		BvBG=0;		GvBG=0;		//Reinitialize
	RvOBJ=0;	BvOBJ=0;	GvOBJ=0;

	finishR = abs(TR2 - TR1);
	finishG = abs(TG2 - TG1);
	finishB = abs(TB2 - TB1);

} //for while(finish>1)

//now do the threshold by T2
	for(int k=0;k<imgWidth;k++)
	{	
		for(int l=0;l<imgHeight;l++)
		{
			if(loadedImage->GetRed(k,l) < TR2)
			{
			loadedImage->SetRGB(k,l,0,loadedImage->GetGreen(k,l),loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetRed(k,l) > TR2)
			{
			loadedImage->SetRGB(k,l,255,loadedImage->GetGreen(k,l),loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetGreen(k,l) < TG2)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),0,loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetGreen(k,l) > TG2)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),255,loadedImage->GetBlue(k,l));
			}
			if(loadedImage->GetBlue(k,l) < TB2)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),loadedImage->GetGreen(k,l),0);
			}
			if(loadedImage->GetBlue(k,l) > TB2)
			{
			loadedImage->SetRGB(k,l,loadedImage->GetRed(k,l),loadedImage->GetGreen(k,l),255);
			}
		}
	}

    printf(" Finished Automated Thresholding.\n");
    Refresh();
}
