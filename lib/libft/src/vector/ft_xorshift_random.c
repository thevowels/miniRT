#include "libft.h"

/* XOR-Shift Random Number Generator */
int	ft_xorshift_random(int seed)
{
	seed ^= seed >> 17;
	seed ^= seed << 5;
	seed ^= seed << 13;
	return seed;
}
