//Image Shift ---> To be modified!
void MyFrame::OnShiftImage(wxCommandEvent & event){

    printf("Shifting...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

    unsigned char r,g,b;

    for( int i=0;i<imgWidth;i++)
       for(int j=0;j<imgHeight;j++){
	// GET THE RGB VALUES 	
        r = loadedImage->GetRed(i,j);   // red pixel value
        g = loadedImage->GetGreen(i,j); // green pixel value
	b = loadedImage->GetBlue(i,j); // blue pixel value

	//printf("(%d,%d) [r = %x  | g = %x | b = %x] \n",i,j,r,g,b);        
        
	// SAVE THE RGB VALUES
	loadedImage->SetRGB(i,j,r+80,g+200,b+20);

//Making sure all the pixel values lie between 0-255
   if(loadedImage->GetRed(i,j) <0){loadedImage->SetRGB(i,j,0,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetRed(i,j)> 255){loadedImage->SetRGB(i,j,255,loadedImage->GetGreen(i,j),loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),0,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetGreen(i,j)>255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),255,loadedImage->GetBlue(i,j));}

   if(loadedImage->GetBlue(i,j)<0){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),0);}

   if(loadedImage->GetBlue(i,j) >255){loadedImage->SetRGB(i,j,loadedImage->GetRed(i,j),loadedImage->GetGreen(i,j),255);}
//End of making 0-255
 
    }
	
    printf(" Finished Shifting.\n");
    Refresh();
}
