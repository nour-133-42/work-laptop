#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*target;
	int				to_top_cost;
	int				price;
	int				chepest_node;
	// 1 for rotate 2 for revers rotate
	int				chepest_rotation;
}					t_list;

t_list				*ft_lstnew(void *data);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				swap_last_two(t_list **lst);
void				push_last_to_last(t_list **lst1, t_list **lst2);
void				rotate_list(t_list **lst);
t_list				*fill_list(int argc, char *argv[]);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					if_sorted_1(t_list *lst);
t_list				*find_min(t_list *lst);
t_list				*find_max(t_list *lst);
void				assien_the_target_node(t_list **current_a,
						t_list **current_b, t_list *max);
void				assien_targets(t_list **a, t_list **b);
int					ft_lstlen(t_list *lst);
void				assien_to_top_cost(t_list **lst);
void				assien_price(t_list **lst);
t_list				*assien_chepest_node(t_list **lst);
int					ra(t_list **lst);
int					rb(t_list **lst);
int					rr(t_list **lst1, t_list **lst2);
int					rra(t_list **lst);
int					rrb(t_list **lst);
int					rrr(t_list **lst1, t_list **lst2);
int					pa(t_list **lst1, t_list **lst2);
int					pb(t_list **lst1, t_list **lst2);
int					sa(t_list **lst);
int					sb(t_list **lst);
int					ss(t_list **lst1, t_list **lst2);
int					preform_different_rotation(t_list **a, t_list **b,
						t_list *chepestnode);
int					execute_operations(t_list **a, t_list **b);
