#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	node *right;
	node *left;
};

node *root = NULL;

void BST(int value)
{
	node *p = (node *) malloc(sizeof(node));

	if(root == NULL)
	{
		p->info = value;
		p->right = NULL;
		p->left = NULL;
		root = p;
	}

	else
	{
		node *q = root;
		p->info = value;
		p->right = NULL;
		p->left = NULL;

		while(q->right != p || q->left != p)
		{
			if(p->info > q->info)
			{
				if(q->right == NULL)
				{
					q->right = p;
					break;
				}

				else
				{
					q = q->right;
				}
			}

			else if(p->info < q->info)
			{
				if(q->left == NULL)
				{
					q->left = p;
					break;
				}

				else
				{
					q = q->left;
				}
			}

			else
			{
				free(p);
				break;
			}
		}
	}
}

void traversalPRE(node *root)
{
    node *q = root;

        if(q == NULL)
                return;

        else
        {
            printf("\n%d", q->info);
            traversalPRE(q->left);
            traversalPRE(q->right);
        }
}

void traversalPOST(node *root)
{
    node *q = root;

        if(q == NULL)
                return;

        else
        {
            traversalPRE(q->left);
            traversalPRE(q->right);
            printf("\n%d", q->info);
        }
}

void traversalIN(node *root)
{
    node *q = root;

        if(q == NULL)
                return;

        else
        {
            traversalPRE(q->left);
            printf("\n%d", q->info);
            traversalPRE(q->right);
        }
}

int main()
{
    int val, c, n=0;

	do{

        printf("\n1. To insert value in BST ");
        printf("\n2. To display PRE-order ");
        printf("\n3. To display POST-order ");
        printf("\n4. To display IN-order ");
        printf("\n5. To exit ");

        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &val);
                BST(val);
                printf("\n");
                break;

            case 2:
                printf("\nPre-order: ");
                traversalPRE(root);
                printf("\n\n");
                break;

            case 3:
                printf("\nPost-order: ");
                traversalPOST(root);
                printf("\n\n");
                break;

            case 4:
                printf("\nIn-order: ");
                traversalIN(root);
                printf("\n\n");
                break;

            case 5:
                n = 1;
                break;

            default:
                printf("\nERROR!");
                break;
        }

	}while(n != 1);

	return 0;
}
