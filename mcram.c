#include <stdio.h>
#include <string.h>

#define RAM_SIZE 16

#define X 105
#define Y 56
#define Z 146

void writeBit(FILE *fp, int x, int y, int z, int value) {

	fprintf(fp, "setblock %i %i %i minecraft:repeater[locked=true,powered=%s]\n", x, y, z, value ? "true" : "false");

}

int main(int argc, char *argv[]) {

	if (argc < 3) {
		printf("Usage: %s [raw data file] [mcfunction file]\n", argv[0]);
		return -1;
	}

	FILE *datafp;
	FILE *fp;

	if ((datafp = fopen(argv[1], "r")) == NULL) {
		perror("Error opening input file");
		return -1;
	}

	if ((fp = fopen(argv[2], "w")) == NULL) {
		perror("Error opening output file");
		return -1;
	}

	unsigned char data[RAM_SIZE];

	if ((fread(data, 1, RAM_SIZE, datafp)) != RAM_SIZE) {
		fprintf(stderr, "Error: read error (input file must be %i bytes)\n", RAM_SIZE);
		return -1;
	}


	for (int i=0; i<RAM_SIZE; i++) {
		for (int j=0; j<8; j++) {
			if (i < 2) { // The RAM is a little uneven
				writeBit(fp, X+(j*8), Y, Z+(i*8), (data[i] >> j) & 1);
			} else {
				writeBit(fp, X+(j*8), Y, Z+8+((i-1)*7), (data[i] >> j) & 1);
			}
		}
	}

	printf("Successfully wrote %i bytes to mcfunction file\n", RAM_SIZE);

	fclose(fp);
	fclose(datafp);
	return 0;
}
