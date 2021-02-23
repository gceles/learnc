int main(void)
{
	int c;
	for (int i = 0; i != -1; i++) {
		if ((c=getchar()) != '\n') {
			if (c != EOF) {
				s[i] = c;
			} else {
				i = -1;
			}
		} else {
			i = -1;
		}
	}
}
