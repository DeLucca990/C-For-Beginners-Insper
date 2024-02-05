int process_pixel(int level, int level2) {
    int new_level;

    new_level = level*level2;

    if (new_level > 255) {
        new_level = 255;
    } else if (new_level < 0){
        new_level = 0;
    }

    return new_level;
}
