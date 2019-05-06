/*                                                                              
 *Filename        binaryFileRecord.h
 *Date            5/5/19                                                        
 *Author          Gabriel Goldstein                                             
 *Email           gjg180000@utdallas.edu                                        
 *Course          CS 3377.502 Spring 2019                                       
 *Version         1.0                                                           
 *Copyright 2019, All Rights Reserved                                           
 *                                                                              
 *Description                                                                   
 *       Basic Binary Record File to read in from binary file                                                                       
 *      
 */


#ifndef _BINARYFILERECORD_
#define _BINARYFILERECORD_
/*
 * Records in the file have a fixed length buffer
 * that will hold a C‐Style string. This is the
 * size of the fixed length buffer.
 */
const int maxRecordStringLength = 25;
class BinaryFileRecord
{
 public:
  uint8_t strLength;
  char   stringBuffer[maxRecordStringLength];
};

#endif // _BINARYFILERECORD_
