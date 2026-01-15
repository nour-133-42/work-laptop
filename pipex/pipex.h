/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:50:38 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/12 15:27:56 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd1[2];
	int		true_flag;
	pid_t	first_child;
	pid_t	second_child;
	char	**envp;
}			t_pipex;

int			free_all(char **arr, char *arg, int res);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
int			exec_command(char **paths, char **argv, char **envp, int flag);
char		**get_paths(char **envp);
int			create_children(t_pipex *pipex, char **argv, char **envp, int *pid);
void		child_two(t_pipex *pipex, char **argv, char **envp);
void		child_one(t_pipex *pipex, char **argv, char **envp);
void		ending(int *pid);
int			search_path(char **paths, char **args, char **envp);

#endif
