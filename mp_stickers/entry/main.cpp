#include "Image.h"
#include "StickerSheet.h"

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image image;
  image.readFromFile("../alma.png");

  StickerSheet sheet = StickerSheet(image, 4);
  Image sticker;
  sticker.readFromFile("../i.png");


  sheet.addSticker(sticker ,20,200);
  sheet.addSticker(sticker ,100,200);
  sheet.addSticker(sticker ,69,150);
  
  Image final = sheet.render();
  final.writeToFile("../myImage.png");
  return 0;
}
