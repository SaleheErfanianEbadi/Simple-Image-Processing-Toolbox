//Midpoint Filtering ---> To be modified!
void MyFrame::OnMidpointFilterImage(wxCommandEvent & event){

    printf("Midpoint Filtering...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

	int minR[9];	int minVR;
	int minG[9];	int minVG;
	int minB[9];	int minVB;

	int maxR[9];	int maxVR;
	int maxG[9];	int maxVG;
	int maxB[9];	int maxVB;

for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{	
		 maxR[0]=minR[0]=loadedImage->GetRed(i-1,j-1);		maxR[1]=minR[1]=loadedImage->GetRed(i-1,j);		maxR[2]=minR[2]=loadedImage->GetRed(i-1,j+1);
		 maxR[3]=minR[3]=loadedImage->GetRed(i,j-1);		maxR[4]=minR[4]=loadedImage->GetRed(i,j);		maxR[5]=minR[5]=loadedImage->GetRed(i,j+1);
		 maxR[6]=minR[6]=loadedImage->GetRed(i+1,j-1);		maxR[7]=minR[7]=loadedImage->GetRed(i+1,j);		maxR[8]=minR[8]=loadedImage->GetRed(i+1,j+1);
			minVR=minR[0];
			maxVR=maxR[0];

		 maxG[0]=minG[0]=loadedImage->GetGreen(i-1,j-1);	maxG[1]=minG[1]=loadedImage->GetGreen(i-1,j);		maxG[2]=minG[2]=loadedImage->GetGreen(i-1,j+1);
		 maxG[3]=minG[3]=loadedImage->GetGreen(i,j-1);		maxG[4]=minG[4]=loadedImage->GetGreen(i,j);		maxG[5]=minG[5]=loadedImage->GetGreen(i,j+1);
		 maxG[6]=minG[6]=loadedImage->GetGreen(i+1,j-1);	maxG[7]=minG[7]=loadedImage->GetGreen(i+1,j);		maxG[8]=minG[8]=loadedImage->GetGreen(i+1,j+1);
			minVG=minG[0];
			maxVG=maxG[0];

		 maxB[0]=minB[0]=loadedImage->GetBlue(i-1,j-1);		maxB[1]=minB[1]=loadedImage->GetBlue(i-1,j);		maxB[2]=minB[2]=loadedImage->GetBlue(i-1,j+1);
		 maxB[3]=minB[3]=loadedImage->GetBlue(i,j-1);		maxB[4]=minB[4]=loadedImage->GetBlue(i,j);		maxB[5]=minB[5]=loadedImage->GetBlue(i,j+1);
		 maxB[6]=minB[6]=loadedImage->GetBlue(i+1,j-1);		maxB[7]=minB[7]=loadedImage->GetBlue(i+1,j);		maxB[8]=minB[8]=loadedImage->GetBlue(i+1,j+1);
			minVB=minB[0];
			maxVB=maxB[0];

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


		loadedImage->SetRGB(i,j,round((maxVR+minVR)/2),round((maxVG+minVG)/2),round((maxVB+minVB)/2));


//Making sure all the pixel values lie between 0-255
   if(loadedImage->GetRed(i,j) <0){loadedImage->SetRGB(i,j,0,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetRed(i,j)> 255){loadedImage->SetRGB(i,j,255,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),0,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)>255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),255,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetBlue(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),0);}

   if(loadedImage->GetBlue(i,j) >255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),255);}
//End of making 0-255


	}
}


	
    printf(" Finished Midpoint Filtering.\n");
    Refresh();
}

