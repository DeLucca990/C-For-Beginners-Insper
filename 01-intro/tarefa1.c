int process_pixel(int level) {
	int new_level;

	// Nagtiviza a imagem
	new_level = 255 - level;

	return new_level;
}
