#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data ; 
    struct node *left;
    struct node *right;
}node;

node *root = NULL;

node *create(){
    node *temp ;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int count = 0;
node *insert(node *root){
    if(root == NULL){
        printf("====warning not have any node in tree \n ");
        node *temp;
        temp = create();
        printf("enter a data :");
        scanf("%d",&temp->data);
        root = temp;
        printf("    (:  data injected sucessfully\n");
        count++;
        return root;

    }
    else {
        int x ;
        printf("enter your data :");
        scanf("%d",&x);
        node *track = root;
        node *prev = NULL;
        while(track!=NULL){
             prev = track;
        if(x == track->data){
            printf("duplicasy not allowed\n");
            return NULL;  
        }else if (x < track->data){
            track = track->left;
        }
        else {
            track = track->right;
        }

       
            
        }


    // connect the node 
    node *newnode;
    newnode = create();
    newnode->data = x;
    if(x < prev->data){   
        prev->left = newnode;     
    }else{
        prev->right= newnode;  
    }
       count++;
         printf("    (:  data injected sucessfully\n");
         return root;
    }

}


void display(node *root){
    
    if(root == NULL){
        return ; // exit
    }
    else {
       
        display(root->left);
         printf("%d ",root->data);
        display(root->right);
         
        
        
        }
    }

    
   void infix(node *root){
    if(root == NULL){
        return;
    }
    else {
        infix(root->left);
        printf("%d ",root->data);
        infix(root->right);
    }
   }
   

 void postfix(node *root){
    if(root == NULL){
        return;
    }else {
        postfix(root->left);
        postfix(root->right);
        printf("%d ",root->data);
    }
 }    

 void prefix(node *root){
    if(root == NULL){
        return ;
    }
    else {
        printf("%d ",root->data);
        prefix(root->left);
        prefix(root->right);
    }
 }

 

int search(node*root,int x){
    
    
    node *temp; // local declared 
    temp = root;
    while(temp != NULL){
       if (x == temp->data){
        return 1;
       }
   else if(x < temp->data){
   temp = temp->left;
   }else {
    temp = temp->right;
   }

}


   
    
}

   



// deletion in binary search tree 
// case : 1 delete leaf node // done
// case :2 delete non leaf node  -- done 
// case :3 delete root node  --- done
// case :4 if no node avalible */ // done

int minval(node *root){
    if (root==NULL){
        return 0;
    }
    if(root->left == NULL){
        return root->data;
    }
  
       return minval(root->left);
}


node *delete (node *copy,int x){
    // base case 
    if(copy == NULL){
        return copy;
    }
    if(copy->data==x){
       // case of deletion 
        // 0 child 
        if(copy->left==NULL&&copy->right==NULL){  
            count--;
            free(copy);
            return NULL;
        }// 1 child ---> left child , --->right child 
        else if (copy->left!=NULL&&copy->right==NULL){
            count--;
         node *temp = copy->left;
         free(copy);
         return temp;
         
        }else if (copy->left == NULL && copy->right!=NULL){
           node *temp= copy->right;
           count--;
           free(copy);
           return temp;
           

        }else if (copy->left!=NULL&&copy->right!=NULL){
            
            int min = minval(copy->right);
            copy->data = min;
            copy->right = delete(copy->right,min);
            count--;
            return copy;

        }

    }else if (copy->data>x){
        copy->left = delete(copy->left,x);
    }else {
        copy->right = delete(copy->right,x);
    }

    return copy;

    }


 



  


int main (){




    while(1){
printf("\n1==insert a data into binary search tree \n");
printf("2==delete a data into binary search tree\n");// locked
printf("3==search a node into a tree \n");// locked
printf("4==display\n");
printf("5==prefix , postfix , infix display \n");
printf("6==exit\n \n ");

int select; 
printf("enter a option :");
scanf("%d",&select);

if(select == 1){
     root = insert(root);
}else if(select == 2){
     int x;
    printf("\nwhat do you want to delete:");
    scanf("%d",&x);
  

   
    root = delete(root,x);

    
     

} else if (select == 3){
     node *track ; 
    track = root;
      int x;
    
    printf("enter a data you want to search ");
    scanf("%d",&x);
    int temp = search(root,x);
    if(temp ==1){
        printf("data found %d ",x);
    }else {
        printf("data not found %d",x);
    }
   printf("\n");
}else if(select == 4){
    display(root);
    printf("\n");
    printf("total %d node in tree",count);
    printf("\n");
}else if(select == 5){
    printf("prefix notation of a binary search tree \n");
    prefix(root);
    printf("\n");
    printf("infix notation of a binary search tree\n");
    infix(root);
      printf("\n");
    printf("postfix notation of a binary search tree\n");
    postfix(root);
    printf("\n");

    
}else if (select == 6){
    printf("exited\n");
    return 0;
}else {
    printf("ERROR: enter a correct option ");
}


    }
    return 0;
}
 

// now code ready to push on git hub cyber angels --sunny