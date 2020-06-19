<b>NAME</b>
	
<code>ft_printf</code>
	
<b>LIBRARY</b>
	
Standart C library from 42 curriculum (libft, -lft)
	
<b>SYNOPSIS</b>
```
#include	<stdarg.h>
#include	<unistd.h>
 
int
ft_printf(const char *, ...);
```
<b>DESCRIPTION</b>

	The ft_printf() function produces output according to a format as
	described below to stdout, the standard output stream.

	These functions write the output under the control of a format string
	that specifies how subsequent arguments (or arguments accessed via the
	variable-length argument facilities of stdarg(3)) are converted for output.

	The format string is composed of zero or more directives: ordinary characters (not %),
	which are copied unchanged to the output stream; and conversion specifications,
	each of which results in fetching zero or more subsequent arguments.
	Each conversion specification is introduced by the % character.
	The arguments must correspond properly (after type promotion) with the conversion specifier.
	After the %, the following appear in sequence:
	
<b>RETURN VALUES</b>

     These functions return the number of characters printed (not including
     the trailing `\0' used to end output to strings).
	  The functions return a negative value if an error occurs.
