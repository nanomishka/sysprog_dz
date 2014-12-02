#include <stdio.h>

struct Ttime {
	int year;
	int month;
	int day;
};

struct Trip {
	struct Ttime start;
	struct Ttime finish;
};

int greater(struct Ttime tr1, struct Ttime tr2) {
	return tr1.year > tr2.year ||
		tr1.year == tr2.year && tr1.month > tr2.month ||
		tr1.year == tr2.year && tr1.month == tr2.month && tr1.day > tr2.day;
}

void selSort(struct Trip *array, int n) {
	int i;
	for ( i = 0 ; i < ( n - 1 ) ; i++ ) {
		int pos = i;
		int d;
		for ( d = i + 1 ; d < n ; d++ )
			if (greater(array[pos].start, array[d].start)) pos = d;
		if ( pos != i ) {
			struct Trip swap = array[i];
			array[i] = array[pos];
			array[pos] = swap;
		}
	}
}

void print(struct Trip data) {
	printf("%d-",data.start.year);
	printf("%02d-",data.start.month);
	printf("%02d ",data.start.day);
	printf("%d-",data.finish.year);
	printf("%02d-",data.finish.month);
	printf("%02d\n",data.finish.day);
}

int main() {
	int size = 2;
	struct Trip *trips = (struct Trip *) calloc(size, sizeof(struct Trip));
	FILE *file;
	file = fopen("data","rt");
	char m[256];
	int i = 0;
	while (fscanf(file,"%d-%d-%d %d-%d-%d", 
		&trips[i].start.year, &trips[i].start.month, &trips[i].start.day,
		&trips[i].finish.year, &trips[i].finish.month, &trips[i].finish.day) != EOF) {
		i++;
		if ( i == size - 1) {
			size *= 2;
			trips = (struct Trip *) realloc (trips, size* sizeof(struct Trip));
		}
	}
	int n = i;

	selSort(&trips[0],n);

	for (i = 0; i < n; i++) {
		print(trips[i]);
	}
	printf("%d\n", n);

	struct Trip current = trips[0];
	for (i = 1; i < n; i++) {
		if (!greater(trips[i].start, current.finish)) {
			if (greater(trips[i].finish, current.finish))
				current.finish = trips[i].finish;
		} else {
			print(current);
			current = trips[i];
		}	
	}
	print(current);

	fclose(file);
	return 0;
}