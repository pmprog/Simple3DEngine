#ifndef COLOR_H
#define COLOR_H

typedef struct COLOUR {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} COLOUR;

static inline COLOUR createColour(unsigned char red, unsigned char green, unsigned char blue) {
    // Create a color given values
    COLOUR temp;
    temp.red = red;
    temp.green = green;
    temp.blue = blue;
    return temp;
}

#endif // COLOR_H
