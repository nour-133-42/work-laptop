/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:26:29 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 08:26:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int ft_isspace(char c) {
    if (c == 32  ||  c == 9   ||  c == 10  ||  c == 11 || c == 12  ||  c == 13)
    return (1);a
    else
        return (0);
}

size_t count(char const *s, char c)
{
    size_t i;
    size_t n;
    i = 0;
    n = 0;
    while(s[i])
    {
        if(s[i]==c)
            n++;
        i++;
    }
    return (n);
}

char **ft_split(char const *s, char c)
{
    unsigned char *p;
    unsigned char **r;
    size_t i;
    size_t j;
    size_t n;
    
    i = 0;
    j = 0;
    p = malloc(strlen(s)*2+1);
    r = malloc(strlen(s) * 2 +1);
    
    while(s[i])
    {
        
        while(s[i] != c && s[i])
        {
            p[n] = s[i];
            i++;
            n++;
        }
        r[j] = p;
        // free(p);
        p = malloc(strlen(s)*2+1);
        j++;
        i++;
        n = 0;
    }
    return ((char **)r);
}

int main(void)
{
    char **c;
    int i;
    int j;
    
    i =0 ;
    j =0 ;
    c = ft_split("hel   lo,mtrdjgvr,youghvuyg",'l');
    while(c[i])
    {
        printf("%s\n",c[i]);
        i++;
    }
        c = split("hel   lo,mtrdjgvr,youghvuyg",'l');
    while(c[i])
    {
        printf("%s\n",c[i]);
        i++;
    }
}

