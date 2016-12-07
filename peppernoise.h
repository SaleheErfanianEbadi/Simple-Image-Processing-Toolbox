//Add pepper noise to Image ---> To be modified!
void MyFrame::OnPepperNoiseImage(wxCommandEvent & event){

    printf("Adding pepper noise...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

	for(int i=0;i<100;i++)
	{
	for(int j=0;j<100;j++)
	{
	loadedImage->SetRGB((rand()%(512-0)+0),(rand()%(512-0)+0),0,0,0);
	}
	}
	
    printf(" Finished adding pepper noise.\n");
    Refresh();
}
