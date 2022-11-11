#include <StickerSheet.h>


void StickerSheet::_copy(const StickerSheet &other) {
    base_image = Image(other.base_image);
    max_stickers = other.max_stickers;
    coordinates.clear();
    for (Image* i : other.stickers) {
        addSticker(*i, other.coordinates.find(i)->second.first, other.coordinates.find(i)->second.second);
    }
}

// Initializes this StickerSheet with a deep copy of the base 
// picture and the ability to hold a max number of stickers (Images)
//  with indices 0 through max - 1.
StickerSheet::StickerSheet(const Image &picture, unsigned max) {
    base_image = Image(picture);
    max_stickers = max;
}

StickerSheet::~StickerSheet() {
    clear();
}

void StickerSheet::clear() {
    for(Image* i : stickers) {
        delete i;
    }
}

StickerSheet::StickerSheet(const StickerSheet &other) {
    clear();
    _copy(other);
}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other) {
    if (this != &other) {
        clear();
        _copy(other);
    }
    return *this;
}

// Modifies the maximum number of stickers that can be stored on this 
// StickerSheet without changing existing stickers' indices.
// If the new maximum number of stickers is smaller than the current 
// number number of stickers, the stickers with indices above max - 1 will be lost.
void StickerSheet::changeMaxStickers(unsigned max) {
    if (max < stickers.size()) {
        stickers.erase(stickers.begin() + max,stickers.end());
    }
    max_stickers = max;
}

// Adds a sticker to the StickerSheet, so that the 
// top-left of the sticker's Image is at (x, y) on the StickerSheet.
// The sticker must be added to the lowest possible layer available.
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
    if (stickers.size() < max_stickers) {
        Image* add = new Image(sticker);
        stickers.push_back(add);
        coordinates.insert({add, std::make_pair(x,y)});
        return stickers.size() - 1;
    }
    return -1;
}

// Changes the x and y coordinates of the Image in the specified layer.
// If the layer is invalid or does not contain a sticker, this function
// must return false. Otherwise, this function returns true.
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
    if (index < 0 || stickers.size() == 0 || index > stickers.size()) {
        return false;
    }
    Image* sticker = stickers.at(index);
    coordinates.find(sticker)-> second = std::make_pair(x,y);
    return true;
}

// Removes the sticker at the given zero-based layer index.
// Make sure that the other stickers don't change order.
void StickerSheet::removeSticker(unsigned index) {
    stickers.erase(stickers.begin() + index);
}

Image* StickerSheet::getSticker(unsigned index) {
    if (index < 0 || index >= stickers.size()) {
        return NULL;
    }
    return stickers.at(index);
}

// Renders the whole StickerSheet on one Image and returns that Image.
// The base picture is drawn first and then each sticker is drawn in order starting 
// with layer zero (0), then layer one (1), and so on. If a pixel's alpha channel in a 
// sticker is zero (0), no pixel is drawn for that sticker at that pixel. If the alpha channel 
// is non-zero, a pixel is drawn. (Alpha blending is awesome, but not required.) The returned Image always 
// includes the full contents of the picture and all stickers. This means that the size of the result image 
// may be larger than the base picture if some stickers go beyond the edge of the picture.
Image StickerSheet::render() const {
    Image copy = Image(base_image);
    for (size_t i = 0; i < stickers.size(); i++) { //access each sticker
        Image* sticker = stickers.at(i);
        unsigned int xCoord = coordinates.find(sticker)-> second.first;
        unsigned int yCoord = coordinates.find(sticker) -> second.second;
        
        
        double factor = 1;
        if ((xCoord + sticker->width()) >= copy.width() || (yCoord + sticker->height()) >= copy.height()) {
            if (copy.width() > copy.height()) {
                factor = (xCoord + sticker->width())/copy.width();
            } else {
                factor = (yCoord + sticker->height())/copy.height();
            }
            copy.scale(factor);
            // if (width_difference >= 0 && height_difference >= 0) {
            //     copy.scale(copy.width() + width_difference, copy.height() + height_difference);
            // } else if (width_difference > 0) {
            //     copy.scale(copy.width() + width_difference, copy.height());
            // } else { // y + sticker->height() >= base_image.height()
            //     copy.scale(copy.width(), copy.height() + height_difference);
            // }
        }
        

        unsigned int y = yCoord;
        unsigned int x = xCoord;
        for (size_t j = 0; j < sticker->width(); j++) {
            y = yCoord;
            for (size_t k = 0; k < sticker->height(); k++) {
                if (sticker -> getPixel(j,k).a > 0) {
                    copy.getPixel(x, y) = sticker -> getPixel(j,k);
                }
                y++;
            }
            x++;
        }

        // std::cout << "END" << std::endl;
    
    }
    return copy;
}

