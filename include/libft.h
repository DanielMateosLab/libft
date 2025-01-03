/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damateos <damateos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:06 by damateos          #+#    #+#             */
/*   Updated: 2025/01/01 22:20:08 by damateos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include "ft_printf.h"
# include <limits.h>

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(
					const char *haystack, const char *needle, size_t len);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_free(void **ptr);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_node);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_node);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(
					t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_hm_node
{
	char				*key;
	void				*value;
	struct s_hm_node	*next;
}	t_hm_node;

typedef struct s_hashmap
{
	t_hm_node	**array;
	size_t		size;
}	t_hashmap;

unsigned int	ft_hash(const char *string);
t_hashmap		*ft_hm_create(size_t size);
t_hm_node		*ft_hm_node_insert(
					t_hashmap *map,
					const char *key,
					void *value,
					size_t value_size);
void			ft_hm_node_remove(t_hashmap *hm, const char *key);
void			*ft_hm_get(t_hashmap *hm, const char *key);
void			ft_hm_remove(t_hashmap *hm);
/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads the next line from the file descriptor specified by `fd`.
 * It uses a static buffer to store the contents read from the file descriptor.
 * The buffer size is defined by `BUFFER_SIZE`.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the next line read from the file descriptor,
 * or NULL if an error occurs or the end of file is reached.
 */
char			*get_next_line(int fd);
int				ft_char_any_of(char target, int num_args, ...);

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void			*str_array_clear(char **table);
char			**str_array_copy(char **map);
char			**str_array_resize(char **arr, size_t len, size_t new_len);
size_t			str_array_len(char **arr);
void			str_array_loop_char(char **arr,
					void (*fn)(char **arr, t_point pos, int *stop, void *param),
					void *param);
char			**str_array_copy_n(char **arr, size_t n);
void			ft_quick_sort(int *arr, int low, int high);
void			ft_reverse_order(int *arr, int low, int high);
int				*ft_int_arr_copy(int *arr, size_t len);
void			ft_int_arr_print(int *arr, size_t len);
void			ft_int_arr_reverse(int *arr, size_t len);
char			*ft_strjoin_mut(char **s1, char *s2);

#endif
