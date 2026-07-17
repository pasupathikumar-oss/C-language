//start
//out/in
//if out
  //current floor (p)
  //current floor (lift)
  //up/down
//if in
  //current floor
  //dest.floor
  //no.floors,display
#include <stdio.h>
#include <stdlib.h>
int main() {
    //variables
    int in_out,current_floor_person,destination_floor,up_down;
    int Max=6,Min=0;
    int current_floor_lift=6;
    //loop
    while(1){
	printf("------------------------------\n");
	printf("----------Lift system---------\n");
	printf("------------------------------\n");
    printf("total 7 floor:0 1 2 3 4 5 6 \n");
    printf("Are u in lift or out?(1 -> in,0 -> out):");
    scanf("%d",&in_out);
    //person inside lift
    if(in_out==1){
        
        printf("\ncurrent floor:%d\n",current_floor_lift);
        printf("destination floor?:");
        scanf("%d",&destination_floor);
      if(destination_floor >= Min && destination_floor <= Max){    
        if(current_floor_lift!=destination_floor){
            printf("\nu got %d floors to destination %d\n",abs(destination_floor - current_floor_lift),destination_floor);
            if(current_floor_lift>destination_floor) printf("Lift moving down\n");
            else printf("Lift moving up\n");
            current_floor_lift=destination_floor;
        }else{
            printf("\nu are at ur destination\n");
        }
      }else printf("enter valid destination\n");
    }
    //person outside of lift
    else if(in_out==0){
        
        printf("\nur current floor(out of 0-6):");
        scanf("%d",&current_floor_person);
        printf("\nwanna go up or down?(1 -> up,0 -> down):");
        scanf("%d",&up_down);
        if(current_floor_person < Min || current_floor_person > Max){
            printf("Invalid floor\n");
            continue;
        }
          if (up_down!=0&&up_down!=1){
              printf("Invalid direction choose 0 or 1\n");
              continue;
          }else if((up_down==1 && current_floor_person==Max) ||(up_down==0 && current_floor_person==Min)){
            printf("Cannot move in that direction\n");
          }else{
            printf("lift currently at %d\n", current_floor_lift);
            if(current_floor_lift > current_floor_person)printf("lift moving down\n");
            else if(current_floor_lift < current_floor_person)printf("lift moving up\n");
            else printf("same floor\n");
            current_floor_lift=current_floor_person;
        }
    }
    else {
    printf("Invalid choice. Enter 1 for inside or 0 for outside\n");
    }
      
    }    
return 0;
}

