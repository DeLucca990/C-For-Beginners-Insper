int process_pixel(int level, int level2) {
    int new_level;

    if (level < level2){
        new_level = 0;
    } else {
        new_level = 255;
    }

    return new_level;
}
