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

node *insert(node *root){
    if(root == NULL){
        printf("====warning not have any node in tree \n ");
        node *temp;
        temp = create();
        printf("enter a data :");
        scanf("%d",&temp->data);
        root = temp;
        printf("    (:  data injected sucessfully\n");
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
    if(root == NULL){
       return 0;
    }

    if(x==root->data){
        return 1;
    }
    search(root->left,x);
    search(root->right,x);

   if(x!=root->data){
      return 0;
   }
    
}


// deletion in binary search tree 
// case : 1 delete leaf node // done
/*
case :2 delete non leaf node 
case :3 delete root node 
case :4 if no node avalible */ // done

int delete (node *root,int x){
    // handle 1  if no node in binary search tree 
    if (root == NULL){
        
        return 0;
    }else {
           
        // delete leaf node 
        node *track;
        node *prev = NULL;
        track = root;
        while(track->data!=x){
            prev = track; // prevoius stored here
            if(x<track->data){
              track = track->left;
            }else {
                track = track->right;
            }
        }

        // disconnect 
        
    if(x<prev->data){
        prev->left = NULL;
    }else {
        prev->right = NULL;
    }
           
    free(track);
        return 1;
    
     

}


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
    int y = delete(root,x);
     if(y==1){
        printf("data deleted sucessfully %d \n",x);
     }else {
        printf("ERROR: data not found %d \n",x);
     }

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
 

