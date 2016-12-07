//Max Filtering ---> To be modified!
void MyFrame::OnMaxFilterImage(wxCommandEvent & event){

    printf("Max Filtering...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

	int maxR[9];	int maxVR;
	int maxG[9];	int maxVG;
	int maxB[9];	int maxVB;

for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{	
		 maxR[0]=loadedImage->GetRed(i-1,j-1);		maxR[1]=loadedImage->GetRed(i-1,j);		maxR[2]=loadedImage->GetRed(i-1,j+1);
		 maxR[3]=loadedImage->GetRed(i,j-1);		maxR[4]=loadedImage->GetRed(i,j);		maxR[5]=loadedImage->GetRed(i,j+1);
		 maxR[6]=loadedImage->GetRed(i+1,j-1);		maxR[7]=loadedImage->GetRed(i+1,j);		maxR[8]=loadedImage->GetRed(i+1,j+1);
			maxVR=maxR[0];

		 maxG[0]=loadedImage->GetGreen(i-1,j-1);	maxG[1]=loadedImage->GetGreen(i-1,j);		maxG[2]=loadedImage->GetGreen(i-1,j+1);
		 maxG[3]=loadedImage->GetGreen(i,j-1);		maxG[4]=loadedImage->GetGreen(i,j);		maxG[5]=loadedImage->GetGreen(i,j+1);
		 maxG[6]=loadedImage->GetGreen(i+1,j-1);	maxG[7]=loadedImage->GetGreen(i+1,j);		maxG[8]=loadedImage->GetGreen(i+1,j+1);
			maxVG=maxG[0];

		 maxB[0]=loadedImage->GetBlue(i-1,j-1);		maxB[1]=loadedImage->GetBlue(i-1,j);		maxB[2]=loadedImage->GetBlue(i-1,j+1);
		 maxB[3]=loadedImage->GetBlue(i,j-1);		maxB[4]=loadedImage->GetBlue(i,j);		maxB[5]=loadedImage->GetBlue(i,j+1);
		 maxB[6]=loadedImage->GetBlue(i+1,j-1);		maxB[7]=loadedImage->GetBlue(i+1,j);		maxB[8]=loadedImage->GetBlue(i+1,j+1);
			maxVB=maxB[0];

		for(int k=1;k<9;k++)
		{
			if(maxR[k] > maxR[k-1])
			{
			maxVR=maxR[k];
			}

			if(maxG[k] > maxG[k-1])
			{
			maxVG=maxG[k];
			}

			if(maxB[k] > maxB[k-1])
			{
			maxVB=maxB[k];
			}
		}

		loadedImage->SetRGB(i,j,maxVR,maxVG,maxVB);

	}
}


	
    printf(" Finished Max Filtering.\n");
    Refresh();
}
