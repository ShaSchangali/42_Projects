/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:19:03 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/16 22:20:34 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(b + i) = (char)c;
		i++;
	}
	return (b);
}

/*
int main() {
    int arr_len = 10; 
	char arr[arr_len];
	int i;

	printf("before memset: \n");
	for(i=0; i<arr_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	//filling all blocks with 0
	ft_memset(arr,0,arr_len);
	printf("Set zeros with ft_memset: \n");
	for(i=0; i<arr_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	//filling first 3 blocks with -1
	//and second 3 blocks with -2
	//and then 3 blocks with -3
	ft_memset(arr,-1,3);
	ft_memset(arr+3,-2,3);
	ft_memset(arr+6,-3,3);
	printf("After ft_memset: \n");
	for(i=0; i<arr_len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
*/