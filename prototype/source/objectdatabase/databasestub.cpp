#include "databasestub.h" 


  DatabaseStub::DatabaseStub(){
	 // data("test");
  }
//modify to use your code
   vector<Mat>* DatabaseStub::loadFeatures(){
	  return &feats;
  }
  //modify to use your code
   vector<Mat>* DatabaseStub::loadHistograms(){
	  return &hists;
  }
   
  void DatabaseStub::saveImage(string file,Mat img){
   
    imwrite(file,img);
  }