// Create a new Image object
const img = new Image();

// Set the source of the image
img.src = 'path/to/image.png';

// Wait for the image to load
img.onload = () => {
  // Create a canvas element
  const canvas = document.createElement('canvas');

  // Set the canvas dimensions to match the image dimensions
  canvas.width = img.width;
  canvas.height = img.height;

  // Draw the image on the canvas
  const ctx = canvas.getContext('2d');
  ctx.drawImage(img, 0, 0);

  // Convert the canvas to a JPG image
  const dataURL = canvas.toDataURL('image/jpeg', 1.0);

  // Create a new Image object with the data URL as the source
  const newImg = new Image();
  newImg.src = dataURL;

  // Use the new image however you like (e.g. display it on the page, download it, etc.)
  document.body.appendChild(newImg);
};
