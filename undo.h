//Undo ---> To be modified!
void MyFrame::OnUndoImage(wxCommandEvent & event){

    printf("Undoing...");
    free(loadedImage);
    loadedImage = new wxImage(bitmap.ConvertToImage());
    loadedImage = loadedImage2;
	
    printf(" Finished Undoing.\n");
    Refresh();
}
