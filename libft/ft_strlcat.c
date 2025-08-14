/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:49:06 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/13 23:20:18 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	j;

	n = 0;
	i = 0;
	j = 0;
	if (size < ft_strlen(dst))
		n = ft_strlen(src) + size;
	else
		n = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
		i++;
	if (size != 0)
	{
		while (i < size - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (n);
}

/*#include <bsd/string.h>
int main()
{
	char *s = "hhhhhhhhhhh";
	char *c = "llllllllllllllll";
	int x = ft_strlcat(s,c,-1);
	printf("%d",x);
}*/

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char dst[100];
//     size_t result;

//     printf("Testing strlcat...\n\n");

//     // Test 1: Empty strings, size = 42
//     printf("Test 1: Empty dst, empty src, size=42\n");
//     memset(dst, 'X', sizeof(dst)); // Fill with 'X' to detect overwrites
//     dst[42] = '\0'; // Ensure it's null-terminated at size
//     result = ft_strlcat(dst, "", 42);
//     printf("  Result: %zu, dst[0]='%c', dst[1]='%c'\n", result, dst[0],
//	dst[1]);
//     if (dst[0] == '\0' && dst[1] == 'X') {
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     // Test 2: Destination string is empty
//     printf("\nTest 2: Empty dst, src=\"hello\", size=10\n");
//     memset(dst, 'X', sizeof(dst));
//     result = ft_strlcat(dst, "hello", 10);
//     printf("  Result: %zu, dst=\"%s\"\n", result, dst);
//     if (strcmp(dst, "hello") == 0 && result == 5) {
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     // Test 3: Source string is empty
//     printf("\nTest 3: dst=\"world\", empty src, size=10\n");
//     strcpy(dst, "world");
//     result = ft_strlcat(dst, "", 10);
//     printf("  Result: %zu, dst=\"%s\"\n", result, dst);
//     if (strcmp(dst, "world") == 0 && result == 5) {
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     // Test 4: Size is zero
//     printf("\nTest 4: dst=\"test\", src=\"ing\", size=0\n");
//     strcpy(dst, "test");
//     result = ft_strlcat(dst, "ing", 0);
//     printf("  Result: %zu, dst=\"%s\"\n", result, dst);
//     if (strcmp(dst, "test") == 0 && result == 3) { // 3 is len of "ing"
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     // Test 5: Size is 1
//     printf("\nTest 5: dst=\"test\", src=\"ing\", size=1\n");
//     strcpy(dst, "test");
//     result = ft_strlcat(dst, "ing", 1);
//     printf("  Result: %zu, dst[0]='%c'\n", result, dst[0]);
//     if (dst[0] == '\0' && result == 7) { // 4 (len "test") + 3 (len "ing")
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     // Test 6: Destination is already full (size-1 chars)
//     printf("\nTest 6: dst=\"abc\", size=4 (full), src=\"def\"\n");
//     strcpy(dst, "abc"); // 3 chars + null = 4, so full
//     result = ft_strlcat(dst, "def", 4);
//     printf("  Result: %zu, dst=\"%s\"\n", result, dst);
//     if (strcmp(dst, "abc") == 0 && result == 6) { // 3 + 3
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//         // Test 7: Destination is not null-terminated within size (continued)
//     printf("\nTest 7: dst not null-terminated within size=3\n");
//     dst[0] = 'a'; dst[1] = 'b'; dst[2] = 'c';
// No null terminator in first 3 bytes
//     result = ft_strlcat(dst, "def", 3);
//     printf("  Result: %zu, dst[0]='%c', dst[1]='%c', dst[2]='%c'\n", result,
//	dst[0], dst[1], dst[2]);
//     if (result == 3 && dst[0] == 'a' && dst[1] == 'b' && dst[2] == 'c') {
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     // Test 8: Buffer overflow prevention (src longer than available space)
//     printf("\nTest 8: Buffer overflow prevention\n");
//     strcpy(dst, "Hi"); // dst has "Hi" (2 chars)
//     result = ft_strlcat(dst, " there!", 6); // size=6: "Hi"
//	+ space for 4 more incl. null
//     printf("  Result: %zu, dst=\"%s\"\n", result, dst);
//     if (strcmp(dst, "Hi th") == 0 && result == 8) { // 2 + 6 = 8
//         printf("  PASS\n");
//     } else {
//         printf("  FAIL\n");
//     }

//     printf("\nAll tests completed.\n");
//     return (0);
// }

// int main()
// {
//     char first[] = "This is ";
//     char last[] = "a potentially long string";
//     int r;
//     int size = 16;
//     char buffer[size];

//     strcpy(buffer,first);
//     r = ft_strlcat(first,last,size);

//     printf("%s\n",first);
//     printf("Value returned: %d\n",r);
//     if( r > size )
//         puts("String truncated");
//     else
//         puts("String was fully copied");

//     return(0);
// }
