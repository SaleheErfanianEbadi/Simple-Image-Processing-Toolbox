//Median Filtering ---> To be modified!
void MyFrame::OnMedianFilterImage(wxCommandEvent & event){

    printf("Median Filtering...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

	int minR[9];	int tempR;
	int minG[9];	int tempG;
	int minB[9];	int tempB;

for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{	
		 minR[0]=loadedImage->GetRed(i-1,j-1);		minR[1]=loadedImage->GetRed(i-1,j);		minR[2]=loadedImage->GetRed(i-1,j+1);
		 minR[3]=loadedImage->GetRed(i,j-1);		minR[4]=loadedImage->GetRed(i,j);		minR[5]=loadedImage->GetRed(i,j+1);
		 minR[6]=loadedImage->GetRed(i+1,j-1);		minR[7]=loadedImage->GetRed(i+1,j);		minR[8]=loadedImage->GetRed(i+1,j+1);


		 minG[0]=loadedImage->GetGreen(i-1,j-1);	minG[1]=loadedImage->GetGreen(i-1,j);		minG[2]=loadedImage->GetGreen(i-1,j+1);
		 minG[3]=loadedImage->GetGreen(i,j-1);		minG[4]=loadedImage->GetGreen(i,j);		minG[5]=loadedImage->GetGreen(i,j+1);
		 minG[6]=loadedImage->GetGreen(i+1,j-1);	minG[7]=loadedImage->GetGreen(i+1,j);		minG[8]=loadedImage->GetGreen(i+1,j+1);


		 minB[0]=loadedImage->GetBlue(i-1,j-1);		minB[1]=loadedImage->GetBlue(i-1,j);		minB[2]=loadedImage->GetBlue(i-1,j+1);
		 minB[3]=loadedImage->GetBlue(i,j-1);		minB[4]=loadedImage->GetBlue(i,j);		minB[5]=loadedImage->GetBlue(i,j+1);
		 minB[6]=loadedImage->GetBlue(i+1,j-1);		minB[7]=loadedImage->GetBlue(i+1,j);		minB[8]=loadedImage->GetBlue(i+1,j+1);


		for(int k=0;k<9;k++)
		{	
			for(int l=k;l<9;l++)
			{
				if(minR[k] > minR[l])
				{
				tempR=minR[k];
				minR[k]=minR[l];
				//minR[l]=minR[k];
				minR[l]=tempR;
				k=l;
				}
			}
		}

		for(int k=0;k<9;k++)
		{	
			for(int l=k;l<9;l++)
			{
				if(minG[k] > minG[l])
				{
				tempG=minG[k];
				minG[k]=minG[l];
				//minR[l]=minR[k];
				minG[l]=tempG;
				k=l;
				}

			}
		}

		for(int k=0;k<9;k++)
		{	
			for(int l=k;l<9;l++)
			{
				if(minB[k] > minB[l])
				{
				tempB=minB[k];
				minB[k]=minB[l];
				//minB[l]=minB[k];
				minB[l]=tempB;
				k=l;
				}
			}
		}

		loadedImage->SetRGB(i,j,minR[4],minG[4],minB[4]);

	}

}


	
    printf(" Finished Median Filtering.\n");
    Refresh();
}
