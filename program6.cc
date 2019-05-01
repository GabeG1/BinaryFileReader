#include <fstream>
#include <iostream>
#include "binaryFileHeader.h"
#include "binaryFileRecord.h"
#include "cdk.h"
#include <string>
#include <sstream>

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"


using namespace std;

int main(int agrc, char* argv[])
{
  WINDOW        *window;
  CDKSCREEN     *cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix                                                                                                                                                   

  // const char                *rowTitles[MATRIX_HEIGHT+1] = {"", "a", "b", "c", "d","e"};                                                                                                                     
    const char                *rowTitles[MATRIX_HEIGHT+1] = {"", "a", "b", "c"};
    const char            *columnTitles[MATRIX_WIDTH+1] = {"", "a", "b", "c", "d", "e"};
  int           boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int           boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*                                                                                                                                                                                                        
   * Initialize the Cdk screen.                                                                                                                                                                             
   *                                                                                                                                                                                                        
   * Make sure the putty terminal is large enough                                                                                                                                                           
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*                                                                                                                                                                                                        
   * Create the matrix.  Need to manually cast (const char**) to (char **)                                                                                                                                  
   */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
                          MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);


  /* so we can see results */






ifstream binaryFile ("binaryFile.bin", ios::in | ios::binary);
 if(binaryFile.is_open())
   {
 BinaryFileHeader *myHeader = new BinaryFileHeader();
 binaryFile.read((char*) myHeader, sizeof(BinaryFileHeader));
 stringstream ss;
 ss << hex << showbase << uppercase <<  myHeader->magicNumber;
 string hexStr(ss.str());
 string str = "Magic: ";
 str+= hexStr; 
 setCDKMatrixCell(myMatrix, 1, 1, str.c_str());
 str = "Version: " + to_string(myHeader->versionNumber);
 setCDKMatrixCell(myMatrix, 1, 2, str.c_str());
 str = "NumRecords: " + to_string(myHeader->numRecords); 
 setCDKMatrixCell(myMatrix, 1, 3, str.c_str());
 BinaryFileRecord *myRecord = new BinaryFileRecord();
 for(int i = 0; i < 4; i++)
   {
     binaryFile.read((char *) myRecord, sizeof(BinaryFileRecord));
     str = "strlen: " + to_string(myRecord->strLength);
     setCDKMatrixCell(myMatrix, i + 2, 1, str.c_str());
     str = myRecord->stringBuffer;
     setCDKMatrixCell(myMatrix, i + 2, 2, str.c_str());

}
 binaryFile.close();
 drawCDKMatrix(myMatrix, true);

 sleep (10);

 endCDK();

   }
 return 0;

}
