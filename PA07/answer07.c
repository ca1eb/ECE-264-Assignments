#include "answer07.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>

#define MAGIC 0x21343632

#define FALSE 0
#define TRUE 1

Image * Image_loadbmp(const char * filename)
{
  //LOCAL DECLARATIONS
  FILE * fp = NULL;
  Image * img = NULL;
  Image * tmp = NULL;
  size_t read;
  ImageHeader header;
  int err = FALSE;

  //EXECUTABLE STATEMENTS
  if(!err) 
    { 
      fp = fopen(filename, "rb");
      if(!fp) 
	{
	  fprintf(stderr, "Failed to open file %s\n", filename);
	  err = TRUE;
	}
    }

  if (!err)
    {
      read = fread(&header, sizeof(ImageHeader), 1, fp);
      if(read != 1) 
	{
	  fprintf(stderr, "Failed to read header from '%s'\n", filename);
	  err = TRUE;
	}
    }

  if(!err) 
    { // Allocate Image struct
      tmp = malloc(sizeof(Image));
      
      if(tmp == NULL) 
	{
	  fprintf(stderr, "Failed to allocate im structure\n");
	  err = TRUE;
	}
    }
  

  if (!err)
    {
      if (header.magic_number != MAGIC)
	{
	  err = TRUE;
	}
    }

  if (!err)
    {
      if (header.width == 0 || header.height == 0)
	{
	  err = TRUE;
	}
    }

  if (!err)
    {
      if (header.comment_len == 0)
	{
	  err = TRUE;
	}
    }

  if (!err) 
    { // Allocate Image struct
      tmp = malloc(sizeof(Image));
      if(tmp == NULL) 
	{
	  fprintf(stderr, "Failed to allocate im structure\n");
	  err = TRUE;
	}
    }

  if(!err) 
    { // Init the Image struct
      tmp -> width = header.width;
      tmp -> height = header.height;
      
      // Handle the comment
      size_t n_bytes = sizeof(char) * (header.comment_len);
      tmp -> comment = malloc(n_bytes);
      if (tmp -> comment == NULL)
	{
	  fprintf(stderr, "Failed to allocate memory for the comment\n");
	  err = TRUE;
	}
      else 
	{
	  read = fread(tmp -> comment,sizeof(char),header.comment_len,fp);
	}

      if(tmp -> comment[header.comment_len] != '\0') 
	{
	  err = TRUE;
	} 

      //printf("comment = %s\n", tmp -> comment);

      /*
      // Handle image data
      n_bytes = sizeof(uint8_t) * header.width * header.height;
      tmp -> data = malloc(n_bytes);
      
      if(tmp -> data == NULL) 
	{
	  fprintf(stderr, "Failed to allocate %zd bytes for image data\n",n_bytes);
	  err = TRUE;
	  }*/
    }
  
  if (!err)
    {
      size_t n_bytes = sizeof(uint8_t) * header.width * header.height;
      tmp -> data = malloc(n_bytes);
      
      if (tmp -> data == NULL)
	{
	  fprintf(stderr, "Data allocation was not successful.\n");
	  err = TRUE;
	}
      else
	{
	  read = fread(tmp -> data, sizeof(uint8_t), n_bytes, fp);
	}
    }
 
  if (!err) 
    { // We should be at the end of the file now
      uint8_t byte;
      read = fread(&byte, sizeof(uint8_t), 1, fp);
      
      if(read != 0) 
	{
	  fprintf(stderr, "Stray bytes at the end of bmp file '%s'\n",filename);
	  err = TRUE;
	}
    }

  if (!err) 
    { // We're winners...
      img = tmp; // bmp will be returned
      tmp = NULL; // and not cleaned up
    }

  if (tmp != NULL) 
    {
      free(tmp -> comment); // Remember, you can always free(NULL)
      free(tmp -> data);
      free(tmp);
    }

  if(fp) 
    {
      fclose(fp);
    }

  
  return img;
}

int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  //int err;

  //EXECUTABLE STATEMENTS
  //err = Image_loadbmp(argv[1]);
  //printf("err = %d\n", err);

  return EXIT_SUCCESS;
}
