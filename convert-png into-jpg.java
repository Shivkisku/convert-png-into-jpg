import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class PNGtoJPGConverter {
   public static void main(String[] args) throws IOException {
      // input PNG file path
      File input = new File("input.png");
      
      // output JPG file path
      File output = new File("output.jpg");
      
      // read input PNG file
      BufferedImage image = ImageIO.read(input);
      
      // convert PNG to JPG
      BufferedImage result = new BufferedImage(
         image.getWidth(), image.getHeight(), BufferedImage.TYPE_INT_RGB);
      result.createGraphics().drawImage(image, 0, 0, java.awt.Color.WHITE, null);
      
      // write JPG to output file
      ImageIO.write(result, "jpg", output);
   }
}
