//Add salt noise to Image ---> To be modified!
void MyFrame::OnSaltNoiseImage(wxCommandEvent & event){

    printf("Adding salt noise...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage2 = new wxImage(bitmap.ConvertToImage());

	for(int i=0;i<100;i++)
	{
	for(int j=0;j<100;j++)
	{
	loadedImage->SetRGB((rand()%(512-0)+0),(rand()%(512-0)+0),255,255,255);
	}
	}
	
    printf(" Finished adding salt noise.\n");
    Refresh();
}
