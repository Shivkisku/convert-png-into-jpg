from PIL import Image

# Open the PNG image file
with Image.open('image.png') as png_image:

    # Convert the image to RGB mode (if it is not already in RGB mode)
    rgb_image = png_image.convert('RGB')

    # Save the converted image as a JPEG image
    rgb_image.save('image.jpg')
