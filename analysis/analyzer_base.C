#include "analyzer_base.h"
#include <iostream>

//----------------------------analyzer_base
analyzer_base::analyzer_base() 
{
}

//----------------------------~analyzer_base
analyzer_base::~analyzer_base()
{
}

void analyzer_base::Initt()
{
   std::cout<<"in the INITT "<<std::endl;
   nLeptons_=27;
}
