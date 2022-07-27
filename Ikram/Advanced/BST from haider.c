#include<Stdio.h>
#include<malloc.h>
struct binary *inorder(struct binary *pt);
struct binary* insert(struct binary* pt,int info);
struct binary{
int data;
struct binary *left;
struct binary *right;
};
typedef struct binary b;
typedef b *ptr;
ptr start=NULL,newptr,crnt;
ptr *current = NULL, *del_node = NULL, *child = NULL;
ptr *parent = NULL, *x = NULL;
int main()
{
    start=NULL;
    start=insert(start,50);
    start=insert(start,30);
    start=insert(start,20);
    start=insert(start,40);
    inorder(start);
}
struct binary* newn(int info)
{
    newptr=malloc(sizeof(ptr));
    newptr->data=info;
    newptr->left=NULL;
    newptr->right=NULL;
    return newptr;
}
struct binary* insert(struct binary *pt,int info)
{
    if(pt==NULL){
            printf("l1\n");
        printf("\n");
        return newn(info);}
    else
    {
        if(info<pt->data){
                printf("l2\n");
            pt->left=insert(pt->left,info);}
        else if(info>pt->data){
                printf("l3\n");
            pt->right=insert(pt->right,info);}
    }    printf("\n\n");
}
struct binary *inorder(struct binary *pt)
{
    if(pt!=NULL)
    {
        inorder(pt->left);
        printf(" %d\n",pt->data);
        inorder(pt->right);
    }
}
int minValue(struct binary *root) {
  crnt = root;
  while (crnt->left != NULL) {
    crnt = crnt->left;
  }
  return(crnt->data);
}
int maxValue(struct binary *root) {
  crnt = root;
  while (crnt->right != NULL) {
    crnt = crnt->right;
  }
  return(crnt->data);
}
void delete_node(struct binary *node, int value)
{
	current = node;
	while (current != NULL) {
		if (value == current->data) {
		del_node = current;
			if ((del_node->left == NULL) && (del_node->right == NULL)) {
				if (parent->left == del_node) {
					parent->left = NULL;
					free(del_node);
					printf("Node deleted\n");
					break;
				}
				else if (parent->right == del_node) {
					parent->right = NULL;
					free(del_node);
					printf("Node deleted\n");
					break;
				}
			}
			else if ((del_node->left == NULL) || (del_node->right == NULL)) {
				printf("Node has one child\n");
				if (parent->left == del_node) {
					if (del_node->left != NULL) {
						child = del_node->left;
						parent->left = child;
						free(del_node);
						break;
					}
					else if (del_node->right != NULL) {
						child = del_node->right;
						parent->left = child;
						free(del_node);
						break;
					}
				}
				else if (parent->right == del_node) {
					if (del_node->left != NULL) {
						child = del_node->left;
						parent->right = child;
						free(del_node);
						break;
					}
					else if (del_node->right != NULL) {
						child = del_node->right;
						parent->right = child;
						free(del_node);
						break;
					}
				}
			}
			else if ((del_node->left != NULL) && (del_node->right != NULL)) {
				printf("Node has two children\n");
				x = del_node;
				if (parent == NULL) {
					child = del_node->right;
					if (child->left == NULL) {
						child->left = del_node->left;
						free(del_node);
						break;
					}
					else {
						while (child->left != NULL) {
								parent = child;
								child = parent->left;
						}
						x->data = child->data;
						parent->left = child->right;
						del_node = child;
						free(del_node);
						break;
					}
				}
				else if (parent->left == del_node) {
					child = del_node->right;
					if (child->left == NULL) {
						parent->left = child;
						child->left = del_node->left;
						free(del_node);
						break;
					}
					else {
						while (child->left != NULL) {
								parent = child;
								child = parent->left;
						}
						x->data = child->data;
						parent->left = child->right;
						del_node = child;
						free(del_node);
						break;
					}
				}
				else if (parent->right == del_node) {
					child = del_node->right;
					if (child->left == NULL) {
						parent->right = child;
						child->left = del_node->left;
						free(del_node);
						break;
					}
					else {
						while (child->left != NULL) {
								parent = child;
								child = parent->left;
						}
						x->data = child->data;
						parent->left = child->right;
						del_node = child;
						free(del_node);
						break;
					}
				}
			}
		}
		else if (value < current->data) {
			parent = current;
			current = current->left;
		}
		else {
			parent = current;
			current = current->right;
		}
	}
}
