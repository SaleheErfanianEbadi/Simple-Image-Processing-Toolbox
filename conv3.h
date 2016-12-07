//Image Convolution by 3x3 Mask ---> To be modified!
void MyFrame::OnConvolve3x3Image(wxCommandEvent & event){

    printf("Convolving3x3...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

        //mask3 matrix formation	
    	int mask3[3][3];
	int weight;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
		mask3[i][j]= 1;
		}
	}
	
//declare mask matrix values and mask weight here
	mask3[0][0]=-1;	mask3[0][1]=-2;	mask3[0][2]=-1;
	mask3[1][0]=0;	mask3[1][1]=0;	mask3[1][2]=0;
	mask3[2][0]=1;	mask3[2][1]=2;	mask3[2][2]=1;

	weight=1;
//mask3 values declared

//making a new image to put masked values in
	double RedMaskImage[imgWidth][imgHeight];
	double GreenMaskImage[imgWidth][imgHeight];
	double BlueMaskImage[imgWidth][imgHeight];


for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{

        double sumRed =0; double sumGreen =0; double sumBlue= 0;
	

	sumRed = sumRed + ( 	mask3[0][0]*loadedImage->GetRed(i-1,j-1)	+mask3[0][1]*loadedImage->GetRed(i-1,j)		+mask3[0][2]*loadedImage->GetRed(i-1,j+1)
				+mask3[1][0]*loadedImage->GetRed(i,j-1)		+mask3[1][1]*loadedImage->GetRed(i,j)		+mask3[1][2]*loadedImage->GetRed(i,j+1)
				+mask3[2][0]*loadedImage->GetRed(i+1,j-1)	+mask3[2][1]*loadedImage->GetRed(i+1,j)		+mask3[2][2]*loadedImage->GetRed(i+1,j+1)	);

        sumGreen = sumGreen + ( mask3[0][0]*loadedImage->GetGreen(i-1,j-1)	+mask3[0][1]*loadedImage->GetGreen(i-1,j)	+mask3[0][2]*loadedImage->GetGreen(i-1,j+1)
				+mask3[1][0]*loadedImage->GetGreen(i,j-1)	+mask3[1][1]*loadedImage->GetGreen(i,j)		+mask3[1][2]*loadedImage->GetGreen(i,j+1)
				+mask3[2][0]*loadedImage->GetGreen(i+1,j-1)	+mask3[2][1]*loadedImage->GetGreen(i+1,j)	+mask3[2][2]*loadedImage->GetGreen(i+1,j+1)	);

        sumBlue = sumBlue + ( 	mask3[0][0]*loadedImage->GetBlue(i-1,j-1)	+mask3[0][1]*loadedImage->GetBlue(i-1,j)	+mask3[0][2]*loadedImage->GetBlue(i-1,j+1)
				+mask3[1][0]*loadedImage->GetBlue(i,j-1)	+mask3[1][1]*loadedImage->GetBlue(i,j)		+mask3[1][2]*loadedImage->GetBlue(i,j+1)
				+mask3[2][0]*loadedImage->GetBlue(i+1,j-1)	+mask3[2][1]*loadedImage->GetBlue(i+1,j)	+mask3[2][2]*loadedImage->GetBlue(i+1,j+1)	);

          
        //int averageRed = abs(round(sumRed/weight));
	//int averageRed = round(sumRed/weight);
	double averageRed = (sumRed/weight);

        //int averageGreen = abs(round(sumGreen/weight));
	//int averageGreen = round(sumGreen/weight);
	double averageGreen = (sumGreen/weight);

        //int averageBlue = abs(round(sumBlue/weight));
	//int averageBlue = round(sumBlue/weight);
	double averageBlue = (sumBlue/weight);


	//loadedImage->SetRGB(i,j,averageRed,averageGreen,averageBlue);       
	RedMaskImage[i][j] = averageRed;
	GreenMaskImage[i][j] = averageGreen;
	BlueMaskImage[i][j] = averageBlue;
	}
}

	
      
//Making sure all the pixel values lie between 0-255
/*   if(loadedImage->GetRed(i,j) <0){loadedImage->SetRGB(i,j,0,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetRed(i,j)> 255){loadedImage->SetRGB(i,j,255,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),0,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)>255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),255,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetBlue(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),0);}

   if(loadedImage->GetBlue(i,j) >255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),255);}
//End of making 0-255
*/

//finding min and max of image for absolute value conversion

	double minIMGR=RedMaskImage[0][0];		double maxIMGR=RedMaskImage[0][0];
	double minIMGG=GreenMaskImage[0][0];		double maxIMGG=GreenMaskImage[0][0];
	double minIMGB=BlueMaskImage[0][0];		double maxIMGB=BlueMaskImage[0][0];


	for(int i=0;i<imgWidth;i++)
	{
		for(int j=0;j<imgHeight;j++)
		{
			if(RedMaskImage[i][j] < minIMGR)
			{
			minIMGR=RedMaskImage[i][j];
			}
			if(RedMaskImage[i][j] > maxIMGR)
			{
			maxIMGR=RedMaskImage[i][j];
			}

			if(GreenMaskImage[i][j] < minIMGG)
			{
			minIMGG=GreenMaskImage[i][j];
			}
			if(GreenMaskImage[i][j] > maxIMGG)
			{
			maxIMGG=GreenMaskImage[i][j];
			}

			if(BlueMaskImage[i][j] < minIMGB)
			{
			minIMGB=BlueMaskImage[i][j];
			}
			if(BlueMaskImage[i][j] > maxIMGB)
			{
			maxIMGB=BlueMaskImage[i][j];
			}
		}
	}


	for(int i=0;i<imgWidth;i++)
	{
		for(int j=0;j<imgHeight;j++)
		{
		RedMaskImage[i][j] = round((RedMaskImage[i][j] - minIMGR) * (255) / (maxIMGR - minIMGR));
		GreenMaskImage[i][j] = round((GreenMaskImage[i][j] - minIMGG) * (255) / (maxIMGG - minIMGG));
		BlueMaskImage[i][j] = round((BlueMaskImage[i][j] - minIMGB) * (255) / (maxIMGB - minIMGB));
		}
	}

for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{
	loadedImage->SetRGB(i,j,RedMaskImage[i][j],GreenMaskImage[i][j],BlueMaskImage[i][j]);
	}
}

	
    printf(" Finished Convolving3x3\n");
    Refresh();
} //END

