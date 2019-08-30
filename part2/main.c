#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ENTER_CREDIT 0
#define PLACE_WAGER 1
#define DICE_ROLL 2
#define REPLAY 3
#define END 4

int enter_credits(int*);
int place_wager(int, int*);
int roll_dice(int*, int);
int replay(int);
void end();

int main()
{
    srand(time(NULL));
    int state = ENTER_CREDIT;
    int cred = 0, currentWager = 0;

    while (state != END) {
        switch (state) {
        case ENTER_CREDIT:
            state = enter_credits(&cred);
            break;
        case PLACE_WAGER:
            state = place_wager(cred, &currentWager);
            break;
        case DICE_ROLL:
            printf("%d\n\n", currentWager);
            state = roll_dice(&cred, currentWager);
            break;
        case REPLAY:
            state = replay(cred);
            break;
        default:
            break;
        }
    }

    return 0;
}

int enter_credits(int *cred) {
    printf("welcome to the dice roll game\n enter credits: ");
    scanf("%d",cred);

    if (cred <= 0) {
        printf("Credit amount entered is invalid.\n");
        return ENTER_CREDIT;
    }
    else {
        return PLACE_WAGER;
    }
}

int place_wager(int cred, int *currentWager)
{
    printf("Place a bet with available credits (%d)\n", cred);
    scanf("%d", currentWager);

    while ((getchar()) != '\n');
    if (*currentWager > cred) {
        printf("Bet cannot be more than available credits.\n");
        return PLACE_WAGER;
    }
    else if (*currentWager < 0) {
        printf("Bet must not be negative.\n");
        return PLACE_WAGER;
    }
    return DICE_ROLL;
}

int roll_dice(int *cred, int currentWager) {
    int player = rand() % 6;
    int cpu = rand() % 6;

    printf("You rolled a %d\nCPU rolled a %d\n", player, cpu);

    if (player > cpu) {
        printf("You won.\n");
        *cred += currentWager;
    } else if (player < cpu) {
        printf("You lost.\n");
        *cred -= currentWager;
    } else {
        printf("You tied.\n");
    }
    return REPLAY;
}

int replay(int cred) {
    char response;

    if (cred <= 0) {
        printf("You have ran out of credits.\n");
        end();
        return END;
    }

    printf("Your current credit is at %d\nPlay again? (y/n)\n", cred);
    scanf("%c", &response);

    while ((getchar()) != '\n');
    if (response == 'y' || response == 'Y') {
        return PLACE_WAGER;
    }
    else if (response == 'n' || response == 'N') {
        end();
        return END;
    }
    else {
        printf("Input invalid.\n");
        return REPLAY;
    }
}

void end() {
    printf("Goodbye.\n");
}
