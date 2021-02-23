int main(void)
{
	int lower, upper, step;
	char c, line[1000];

	/* a variable may also be initialized in its declaration */
	char esc = '\\';
	int i = 0;
	int limit = MAXLINE + 1;
	float eps = 1.0e-5;

	/* the qualifier const can be applied to the declaration of
         * any variable to specify that its value will not be changed.
         * For an array, the const qualifier says that the elements will
         * not be altered.
         */
         const double e = 2.71828182845905;
         const char msg[] = "warning: ";

         /* the const declaration can also be used with array arguments,
          * to indicate that the function does not change that array.
          * The result is implementation defined if an attempt is made
          * to change a const
          */
          int strlen(const char[]);
}
