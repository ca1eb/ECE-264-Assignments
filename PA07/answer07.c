#include "answer07.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>

#define MAGIC 0x21343632

#define FALSE 0
#define TRUE 1

Image * Image_load(const char * filename)
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

//  if(!err) 
//    { // Allocate Image struct
  //    tmp = malloc(sizeof(Image));
    //  
     // if(tmp == NULL) 
//	{
//	  fprintf(stderr, "Failed to allocate im structure\n");
//	  err = TRUE;
//	}
  //  }

  

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


  if(!err) 
    { // Init the Image struct
      tmp = malloc(sizeof(Image));

      if(tmp == NULL)
        {
          fprintf(stderr, "Failed to allocate im structure\n");
          err = TRUE;
        }
	     
 
      tmp -> width = header.width;
      tmp -> height = header.height;
      tmp -> comment = NULL;
      tmp -> data = NULL;     
 
      // Handle the comment
      size_t n_bytes = sizeof(char) * (header.comment_len);
      tmp -> comment = malloc(n_bytes);
      
      if (tmp -> comment == NULL)
	{
	  err = TRUE;
	}
      
	//if(tmp -> comment[header.comment_len - 1] != '\0') 
	//{
	//err = TRUE;
	//} 

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
      read = fread(tmp -> comment,sizeof(char),header.comment_len,fp); 

      if (header.comment_len != read || tmp -> comment[header.comment_len - 1] != '\0')
	    {
	      err = TRUE;
	    } 
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
	  
	  if (read != n_bytes)
	    {
	      err = TRUE;
	    }
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

void linearNormalization(int width, int height, uint8_t * intensity)
{
  //LOCAL DECLARATIONS
  int min = 255;
  int max = 0;
  int ind;

  //EXECUTABLE STATEMENTS
  for (ind = 0; ind < (width * height); ind++)
    {
      if (intensity[ind] > max)
	{
	  max = intensity[ind];
	}
      
      if (intensity[ind] < min)
	{
	  min = intensity[ind];
	}
    }

  for (ind = 0; ind < (width * height); ind++)
    {
      intensity[ind] = (intensity[ind] - min) * 255.0 / (max - min);
    }

  return;
}

int Image_save(const char * filename, Image * image)
{
  //LOCAL DECLARATIONS
  int err = FALSE; 
  FILE * fp = NULL;
  //uint8_t * buffer = NULL;    
  //size_t written = 0;
  //int ind;

  //EXECUTABLE STATEMENTS
  fp = fopen(filename, "wb");
  if (fp == NULL)
    {
      fprintf(stderr, "Failed to open %s for writing\n", filename);
      fclose(fp);

      return FALSE;
    }

  ImageHeader header;
  header.magic_number = MAGIC;
  header.width = image -> width;
  header.height = image -> height;
  header.comment_len = strlen(image -> comment) + 1;

  if (fwrite(&header, sizeof(ImageHeader), 1, fp) != 1)
    {
      err = TRUE; 
    }

  if (fwrite(image -> comment, sizeof(char), header.comment_len,fp) != header.comment_len)
    {
      err = TRUE;
    }

  if (fwrite(image->data, sizeof(uint8_t), (image -> width * image -> height), fp) != (image -> width * image -> height))
    {
      err = TRUE;
    }

  fclose(fp);

  return !err;
}

void Image_free(Image * image)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  free(image -> comment);
  free(image -> data);
  free(image);

  return;
}

/*
int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  Image * image = Image_loadbmp(argv[1]);
  
  printf("%s\n", image -> comment);
  printf("%d\n", image -> width);
  printf("%d\n", image -> height);
  Image_save(argv[2], image);
  Image_free(image);	
 
  //EXECUTABLE STATEMENTS

  return EXIT_SUCCESS;
}*/
