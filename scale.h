//IMAGE SCALEING- Values can be 0-2
void MyFrame::OnScaleImage(wxCommandEvent & event){

    printf("Scaling...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

    for( int i=0;i<imgWidth;i++)
       for(int j=0;j<imgHeight;j++){
 	loadedImage->SetRGB(i,j,0.5* loadedImage->GetRed(i,j), 
				0.5* loadedImage->GetGreen(i,j),
				0.5* loadedImage->GetBlue(i,j));


//Making sure all the pixel values lie between 0-255
   if(loadedImage->GetRed(i,j) <0){loadedImage->SetRGB(i,j,0,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetRed(i,j)> 255){loadedImage->SetRGB(i,j,255,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),0,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)>255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),255,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetBlue(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),0);}

   if(loadedImage->GetBlue(i,j) >255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),255);}
//End of making 0-255

    }	
    printf(" Finished scaling.\n");
    Refresh();
}
