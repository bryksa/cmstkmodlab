
#ifndef _DEFOCONFIGREADER_H
#define _DEFOCONFIGREADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class DefoConfigReader {

 public:
  DefoConfigReader( const char* );
  ~DefoConfigReader();

  ///
  ///
  ///
  template <class aType> aType getValue( std::string const& key ) const {

    std::ifstream file( inputFileName_.c_str(), std::ios::in );
    if( !file.good() ) {
      std::cerr << " [DefoConfigReader::openAndCheckFile] ** ERROR: failed to open file: " << inputFileName_ << "." << std::endl;
      throw;
    }

    bool isFound = false;
    aType returnValue = 0;
    std::string buffer;

    while (std::getline(file, buffer)) {
      while (buffer[0]==' ') buffer = buffer.substr(1, buffer.length());
      if (buffer[0]=='\0') continue;
      if (buffer[0]=='#') continue;

      std::istringstream iss(buffer.c_str(), std::istringstream::in);
      iss >> buffer;
      if( key == buffer ) { 
	iss >> returnValue; isFound = true;
      }
    }
    
    file.close();
    if( !isFound ) issueKeyError( key );
    return returnValue;    
  }

 private:
  void issueKeyError( const std::string& ) const;
  std::string inputFileName_;

};

#endif