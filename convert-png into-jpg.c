#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

int main(void) {

  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE *infile, *outfile;
  JSAMPROW row_pointer[1];
  int row_stride, width, height, pixel_size;

  // Open the PNG image file
  if ((infile = fopen("image.png", "rb")) == NULL) {
    fprintf(stderr, "can't open %s\n", "image.png");
    exit(1);
  }

  // Initialize the libjpeg structures
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);

  // Open the output JPG image file
  if ((outfile = fopen("image.jpg", "wb")) == NULL) {
    fprintf(stderr, "can't open %s\n", "image.jpg");
    exit(1);
  }
  jpeg_stdio_dest(&cinfo, outfile);

  // Set the image information
  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  png_infop info_ptr = png_create_info_struct(png_ptr);
  png_init_io(png_ptr, infile);
  png_read_info(png_ptr, info_ptr);
  width = png_get_image_width(png_ptr, info_ptr);
  height = png_get_image_height(png_ptr, info_ptr);
  pixel_size = png_get_channels(png_ptr, info_ptr) * png_get_bit_depth(png_ptr, info_ptr);
  row_stride = width * pixel_size;

  // Set the compression parameters
  cinfo.image_width = width;
  cinfo.image_height = height;
  cinfo.input_components = pixel_size / 8;
  cinfo.in_color_space = JCS_RGB;
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, 90, TRUE);

  // Start the compression process
  jpeg_start_compress(&cinfo, TRUE);

  // Read and compress each row of the image
  while (cinfo.next_scanline < cinfo.image_height) {
    png_read_row(png_ptr, row_pointer[0], NULL);
    row_pointer[0] = &png_ptr->row_pointers[cinfo.next_scanline][0];
    jpeg_write_scanlines(&cinfo, row_pointer, 1);
  }

  // Finish the compression process
  jpeg_finish_compress(&cinfo);

  // Close the input and output files
  fclose(infile);
  fclose(outfile);

  return 0;
}
