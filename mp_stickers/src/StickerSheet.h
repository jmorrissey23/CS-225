#include "cs225/PNG.h"
#include <cmath>
#include "Image.h"
#include <vector>
#include <map>

class StickerSheet {
    public:
        StickerSheet(const Image &picture, unsigned max);
        ~StickerSheet();
        StickerSheet(const StickerSheet &other);
        const StickerSheet& operator=(const StickerSheet &other);
        void changeMaxStickers(unsigned max);
        int addSticker(Image &sticker, unsigned x, unsigned y);
        bool translate(unsigned index, unsigned x, unsigned y);
        void removeSticker(unsigned index);
        Image* getSticker(unsigned index);
        Image render() const;
    
    private:
        Image base_image;
        // cs225::PNG og_image;
        void _copy(const StickerSheet &other);
        std::vector<Image*> stickers;  //array of pointers 
        unsigned int max_stickers;
        std::map<Image*, std::pair<int, int>> coordinates; //maps an image to its coordinates
        void clear();

};
#pragma once