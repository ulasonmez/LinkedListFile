#include <stdio.h>
#include <stdlib.h>


struct node{
	int x;
	struct node *next;
};
 void printList(struct node *head){
	printf("%d\t",head->x);
	while(head->next!=NULL){
		head = head->next;
		printf("%d\t",head->x);
	}
}
void addToLinkedList(FILE *file,struct node *root){
	int num,i=0;
	while(!feof(file)){
		if(i==0){
			fscanf(file,"%d",&num);
			root->x=num;			
			root->next = NULL;
		}
		else{
			fscanf(file,"%d",&num);
			sonaEkle(root,num);
		}
		i++;
	}
}
void addListToList(struct node *bas, struct node *son){
	while(bas->next!=NULL){
 		bas=bas->next;
	}
	bas->next=son;
}
void sort(struct node *head){
	struct node *tmp = head;
	struct node *tmp2 = head;
	for(tmp = head ; tmp!= NULL ; tmp = tmp->next){
		for(tmp2 = tmp->next ; tmp2 != NULL ; tmp2 = tmp2->next){
			if(tmp->x > tmp2->x){
				int temp = tmp->x;
				tmp->x = tmp2->x;
				tmp2->x = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	struct node *root1 = (struct node*)malloc(sizeof(struct node));
	struct node *root2 = (struct node*)malloc(sizeof(struct node));
	FILE *sayilar1,*sayilar2;
	sayilar1=fopen("sayilar1.txt","r");
	sayilar2=fopen("sayilar2.txt","r");
	
	addToLinkedList(sayilar1,root1);
	addToLinkedList(sayilar2,root2);
	
	addListToList(root1,root2);
	
	sort(root1);
	printList(root1);
	

	return 0;
}