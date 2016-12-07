//Image Convolution by 5x5 Mask ---> To be modified!
void MyFrame::OnConvolve5x5Image(wxCommandEvent & event){

    printf("Convolving5x5...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

//mask5 matrix formation	
	int mask5[5][5];
	int weight;

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		mask5[i][j]= 1;
		}
	}
	
//declare mask matrix values and mask weight here
	mask5[0][0]=1;	mask5[0][1]=1;	mask5[0][2]=1;	mask5[0][3]=1;	mask5[0][4]=1;
	mask5[1][0]=1;	mask5[1][1]=1;	mask5[1][2]=1;	mask5[1][3]=1;	mask5[1][4]=1;
	mask5[2][0]=1;	mask5[2][1]=1;	mask5[2][2]=1;	mask5[2][3]=1;	mask5[2][4]=1;
	mask5[3][0]=1;	mask5[3][1]=1;	mask5[3][2]=1;	mask5[3][3]=1;	mask5[3][4]=1;
	mask5[4][0]=1;	mask5[4][1]=1;	mask5[4][2]=1;	mask5[4][3]=1;	mask5[4][4]=1;


	weight=25;
//mask5 values declared

//making a new image to put masked values in
	double RedMaskImage[imgWidth][imgHeight];
	double GreenMaskImage[imgWidth][imgHeight];
	double BlueMaskImage[imgWidth][imgHeight];


for(int i= 0;i< imgWidth;i++)
{
      	for(int j=0;j<imgHeight;j++)
      	{

        int sumRed =0; int sumGreen =0; int sumBlue= 0;
	

sumRed=sumRed+(
mask5[0][0]*loadedImage->GetRed(i-2,j-2)+mask5[0][1]*loadedImage->GetRed(i-2,j-1)+mask5[0][2]*loadedImage->GetRed(i-2,j+1)+mask5[0][3]*loadedImage->GetRed(i-2,j-1)+mask5[0][4]*loadedImage->GetRed(i-2,j-1)

+mask5[1][0]*loadedImage->GetRed(i-1,j-2)+mask5[1][1]*loadedImage->GetRed(i-1,j-1)+mask5[1][2]*loadedImage->GetRed(i-1,j)+mask5[1][3]*loadedImage->GetRed(i-1,j+1)+mask5[1][4]*loadedImage->GetRed(i-1,j+2)

+mask5[2][0]*loadedImage->GetRed(i,j-2)+mask5[2][1]*loadedImage->GetRed(i,j-1)+mask5[2][2]*loadedImage->GetRed(i,j)+mask5[2][3]*loadedImage->GetRed(i,j+1)+mask5[2][4]*loadedImage->GetRed(i,j+2)

+mask5[3][0]*loadedImage->GetRed(i+1,j-2)+mask5[3][1]*loadedImage->GetRed(i+1,j-2)+mask5[3][2]*loadedImage->GetRed(i+1,j)+mask5[3][3]*loadedImage->GetRed(i+1,j+1)+mask5[3][4]*loadedImage->GetRed(i+1,j+2)

+mask5[4][0]*loadedImage->GetRed(i+2,j-2)+mask5[4][1]*loadedImage->GetRed(i+2,j-1)+mask5[4][2]*loadedImage->GetRed(i+2,j)+mask5[4][3]*loadedImage->GetRed(i+2,j+1)+mask5[4][4]*loadedImage->GetRed(i+2,j+2)
	);

sumGreen=sumGreen+(
mask5[0][0]*loadedImage->GetGreen(i-2,j-2)+mask5[0][1]*loadedImage->GetGreen(i-2,j-1)+mask5[0][2]*loadedImage->GetGreen(i-2,j+1)+mask5[0][3]*loadedImage->GetGreen(i-2,j-1)+mask5[0][4]*loadedImage->GetGreen(i-2,j-1)

+mask5[1][0]*loadedImage->GetGreen(i-1,j-2)+mask5[1][1]*loadedImage->GetGreen(i-1,j-1)+mask5[1][2]*loadedImage->GetGreen(i-1,j)+mask5[1][3]*loadedImage->GetGreen(i-1,j+1)+mask5[1][4]*loadedImage->GetGreen(i-1,j+2)

+mask5[2][0]*loadedImage->GetGreen(i,j-2)+mask5[2][1]*loadedImage->GetGreen(i,j-1)+mask5[2][2]*loadedImage->GetGreen(i,j)+mask5[2][3]*loadedImage->GetGreen(i,j+1)+mask5[2][4]*loadedImage->GetGreen(i,j+2)

+mask5[3][0]*loadedImage->GetRed(i+1,j-2)+mask5[3][1]*loadedImage->GetRed(i+1,j-2)+mask5[3][2]*loadedImage->GetRed(i+1,j)+mask5[3][3]*loadedImage->GetRed(i+1,j+1)+mask5[3][4]*loadedImage->GetRed(i+1,j+2)

+mask5[4][0]*loadedImage->GetGreen(i+2,j-2)+mask5[4][1]*loadedImage->GetGreen(i+2,j-1)+mask5[4][2]*loadedImage->GetGreen(i+2,j)+mask5[4][3]*loadedImage->GetGreen(i+2,j+1)+mask5[4][4]*loadedImage->GetGreen(i+2,j+2)
	);

sumBlue=sumBlue+(  
mask5[0][0]*loadedImage->GetBlue(i-2,j-2)+mask5[0][1]*loadedImage->GetBlue(i-2,j-1)+mask5[0][2]*loadedImage->GetBlue(i-2,j+1)+mask5[0][3]*loadedImage->GetBlue(i-2,j-1)+mask5[0][4]*loadedImage->GetBlue(i-2,j-1)

+mask5[1][0]*loadedImage->GetBlue(i-1,j-2)+mask5[1][1]*loadedImage->GetBlue(i-1,j-1)+mask5[1][2]*loadedImage->GetBlue(i-1,j)+mask5[1][3]*loadedImage->GetBlue(i-1,j+1)+mask5[1][4]*loadedImage->GetBlue(i-1,j+2)

+mask5[2][0]*loadedImage->GetBlue(i,j-2)+mask5[2][1]*loadedImage->GetBlue(i,j-1)+mask5[2][2]*loadedImage->GetBlue(i,j)+mask5[2][3]*loadedImage->GetBlue(i,j+1)+mask5[2][4]*loadedImage->GetBlue(i,j+2)

+mask5[3][0]*loadedImage->GetBlue(i+1,j-2)+mask5[3][1]*loadedImage->GetBlue(i+1,j-2)+mask5[3][2]*loadedImage->GetBlue(i+1,j)+mask5[3][3]*loadedImage->GetBlue(i+1,j+1)+mask5[3][4]*loadedImage->GetBlue(i+1,j+2)

+mask5[4][0]*loadedImage->GetBlue(i+2,j-2)+mask5[4][1]*loadedImage->GetBlue(i+2,j-1)+mask5[4][2]*loadedImage->GetBlue(i+2,j)+mask5[4][3]*loadedImage->GetBlue(i+2,j+1)+mask5[4][4]*loadedImage->GetBlue(i+2,j+2)
	);

          
         //int averageRed = abs(round(sumRed/weight));
	double averageRed = (sumRed/weight);

         //int averageGreen = abs(round(sumGreen/weight));
	double averageGreen = (sumGreen/weight);

         //int averageBlue = abs(round(sumBlue/weight));
	double averageBlue = (sumBlue/weight);


	//loadedImage->SetRGB(i,j,averageRed,averageGreen,averageBlue);  
	RedMaskImage[i][j] = averageRed;
	GreenMaskImage[i][j] = averageGreen;
	BlueMaskImage[i][j] = averageBlue;        
      
//Making sure all the pixel values lie between 0-255
/*   if(loadedImage->GetRed(i,j) <0){loadedImage->SetRGB(i,j,0,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetRed(i,j)> 255){loadedImage->SetRGB(i,j,255,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),0,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)>255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),255,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetBlue(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),0);}

   if(loadedImage->GetBlue(i,j) >255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),255);}*/
//End of making 0-255

     	
	}
}


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

	
    printf(" Finished Convolving5x5\n");
    Refresh();
}

