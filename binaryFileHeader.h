/*                                                                              
 *Filename        binaryFileHeader.h
 *Date            Cinco De Mayo!                                          
 *Author          Gabriel Goldstein                                             
 *Email           gjg180000@utdallas.edu                                        
 *Course          CS 3377.502 Spring 2019                                       
 *Version         1.0                                                           
 *Copyright 2019, All Rights Reserved                                           
 *                                                                              
 *Description                                                                   
 *       Basic header file to read in from binary file.                                                
 *      
 */


#ifndef _BinaryFileHeader_
#define _BinaryFileHeader_

#include <iomanip>
#include <stdint.h>

class BinaryFileHeader
{
 public:
  uint32_t magicNumber;         /* Should be 0xFEEDFACE */
  uint32_t versionNumber;
  uint64_t numRecords;
};

#endif //_BinaryFileHeader_
