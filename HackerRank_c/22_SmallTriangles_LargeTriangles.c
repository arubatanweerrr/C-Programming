#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            double s1 = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
            double area1 = sqrt(s1 * (s1 - tr[i].a) * (s1 - tr[i].b) * (s1 - tr[i].c));

            double s2 = (tr[j].a + tr[j].b + tr[j].c) / 2.0;
            double area2 = sqrt(s2 * (s2 - tr[j].a) * (s2 - tr[j].b) * (s2 - tr[j].c));

            if (area1 > area2) {
                triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}