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
