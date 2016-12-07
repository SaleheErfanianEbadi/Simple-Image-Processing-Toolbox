//Min Filtering ---> To be modified!
void MyFrame::OnMinFilterImage(wxCommandEvent & event){

    printf("Min Filtering...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

	int minR[9];	int minVR;
	int minG[9];	int minVG;
	int minB[9];	int minVB;

for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{	
		 minR[0]=loadedImage->GetRed(i-1,j-1);		minR[1]=loadedImage->GetRed(i-1,j);		minR[2]=loadedImage->GetRed(i-1,j+1);
		 minR[3]=loadedImage->GetRed(i,j-1);		minR[4]=loadedImage->GetRed(i,j);		minR[5]=loadedImage->GetRed(i,j+1);
		 minR[6]=loadedImage->GetRed(i+1,j-1);		minR[7]=loadedImage->GetRed(i+1,j);		minR[8]=loadedImage->GetRed(i+1,j+1);
			minVR=minR[0];

		 minG[0]=loadedImage->GetGreen(i-1,j-1);	minG[1]=loadedImage->GetGreen(i-1,j);		minG[2]=loadedImage->GetGreen(i-1,j+1);
		 minG[3]=loadedImage->GetGreen(i,j-1);		minG[4]=loadedImage->GetGreen(i,j);		minG[5]=loadedImage->GetGreen(i,j+1);
		 minG[6]=loadedImage->GetGreen(i+1,j-1);	minG[7]=loadedImage->GetGreen(i+1,j);		minG[8]=loadedImage->GetGreen(i+1,j+1);
			minVG=minG[0];

		 minB[0]=loadedImage->GetBlue(i-1,j-1);		minB[1]=loadedImage->GetBlue(i-1,j);		minB[2]=loadedImage->GetBlue(i-1,j+1);
		 minB[3]=loadedImage->GetBlue(i,j-1);		minB[4]=loadedImage->GetBlue(i,j);		minB[5]=loadedImage->GetBlue(i,j+1);
		 minB[6]=loadedImage->GetBlue(i+1,j-1);		minB[7]=loadedImage->GetBlue(i+1,j);		minB[8]=loadedImage->GetBlue(i+1,j+1);
			minVB=minB[0];

		for(int k=1;k<9;k++)
		{
			if(minR[k] < minR[k-1])
			{
			minVR=minR[k];
			}

			if(minG[k] < minG[k-1])
			{
			minVG=minG[k];
			}

			if(minB[k] < minB[k-1])
			{
			minVB=minB[k];
			}
		}

		loadedImage->SetRGB(i,j,minVR,minVG,minVB);

	}

}


	
    printf(" Finished Min Filtering.\n");
    Refresh();
}
