#include <stdio.h>

struct cricket_player {
    char name[50];
    int runs;
};

int main() {

    int n;
    printf("Enter the number of player:");
    scanf("%d/n",&n);
    struct cricket_player players[n];
    int index;
    int total_runs = 0;
    printf("Enter the batting information :\n");
    
    for (index = 0; index < n; index++) {
        printf("Player %d\n", index + 1);
        printf("Enter name: ");
        scanf("%s", players[index].name);
        printf("Enter runs scored: ");
        scanf("%d", &players[index].runs);
        total_runs=total_runs + players[index].runs;
    }
    
    for (index = 0; index < n; index++) {
	    printf("player name:%s\n", players[index].name);
            printf("runs scored:%d\n", players[index].runs);
    }
    printf("\nThe total team runs is  %d\n", total_runs);
    
    return 0;
}

