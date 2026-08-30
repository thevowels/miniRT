#include "libft.h"

/* Combined Random Number Generator using XOR-Shift and LCG */
int	ft_xslcg_random(unsigned int seed)
{
	return ft_xorshift_random(seed) ^ ft_lcg_random(seed);
}
