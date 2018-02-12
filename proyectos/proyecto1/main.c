#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sentence.h"
#include "hashTable.h"

#define MAX_STRING_LENGTH 100
#define SIZE 65536
#define LANG "en"

hashtable_t* defineHashArrayOfCards(char** sentences);

int main(){
    // Gather sentences to print depending on the specified language.
    char **sentences;
    if(!strcmp(LANG, "en")){
        sentences = sentence_EN;
    }
    else if(!strcmp(LANG, "es")){
        sentences = sentence_ES;
    }
    // --------------------------------------------------------------
    printf("%s\n", sentences[0]); // Printing string requisition.
    // Convert string of sequence into an array of cards.
    char sequence[MAX_STRING_LENGTH];
    scanf ("%[^\n]%*c", sequence);
    int nSpaces = 0;
    for(int i = 0; i < strlen(sequence); i++){
        if(sequence[i] == ' '){
            nSpaces++;
        }
    }
    int nCards = nSpaces + 1;
    int j = 0;
    char *p = strtok(sequence, " ");
    char **cards = malloc(sizeof(p) * nCards);
    while(p != NULL){
        cards[j++] = p;
        p = strtok(NULL, " ");
    }
    // If the number of cards is more than 16 print No already.
    if(nCards > 16){
        printf("%s\n", sentences[1]);
        return 0;
    }
    // -------------------------------------------------------------
    // Define a hash table of our 53 different types of cards.
    hashtable_t *deck = defineHashArrayOfCards(sentences);
    // Gather laid up card.
    char laidUpCard[MAX_STRING_LENGTH];
    scanf("%s", laidUpCard);
    // -------------------------------------------------------------
    // Get last card value, and suit.
    char lastCardValue;
    if(laidUpCard[0] != '*'){
        lastCardValue = laidUpCard[0];
    }
    else{
        lastCardValue = laidUpCard[1];
    }
    char lastCardSuit = laidUpCard[(strlen(laidUpCard)-1)];
    // Seach for not halting cards.
    int nNotHaltingCards = 0;
    for(int i = 0; i < nCards; i++){
        if(!strcmp(ht_get(deck, cards[i]), sentences[4])){
            nNotHaltingCards++;
        }
    }
    if(nNotHaltingCards > 1){
        printf("%s\n", sentences[1]);
        return 0;
    }
    // -------------------------------------------------------------
    hashtable_t *acceptedCards = ht_create(SIZE);
    int nAcceptedCards = 0;
    int foundOne = 0;
    for(int i = 0; i < nCards; i++){
        foundOne = 0;
        if(lastCardValue == 'A'|| lastCardValue == '6' || lastCardValue == '7' || (lastCardValue == 'K' && lastCardSuit != 'S')){
            for(int j = 0; j < nCards; j++){
                if(cards[j][0] == lastCardValue && ht_get(acceptedCards, cards[j]) != NULL && !strcmp(ht_get(deck, cards[j]), sentences[3])){
                    lastCardSuit = cards[j][1];
                    char counter[12];
                    sprintf(counter, "%d", i);
                    ht_set(acceptedCards, cards[j], counter);
                    nAcceptedCards++;
                    foundOne = 1;
                    break;
                }
            }
            if(foundOne != 1){
                for(int j = 0; j < nCards; j++){
                    if(cards[j][1] == lastCardSuit && ht_get(acceptedCards, cards[j]) != NULL && !strcmp(ht_get(deck, cards[j]), sentences[3])){
                        lastCardValue = cards[j][0];
                        char counter[12];
                        sprintf(counter, "%d", i);
                        ht_set(acceptedCards, cards[j], counter);
                        nAcceptedCards++;
                        foundOne = 1;
                        break;
                    }
                }
            }
        }
        else{
            for(int j = 0; j < nCards; j++){
                if(cards[j][1] == lastCardSuit && ht_get(acceptedCards, cards[j]) != NULL && !strcmp(ht_get(deck, cards[j]), sentences[3])){
                    lastCardValue = cards[j][0];
                    char counter[12];
                    sprintf(counter, "%d", i);
                    ht_set(acceptedCards, cards[j], counter);
                    nAcceptedCards++;
                    foundOne = 1;
                    break;
                }
            }
            if(foundOne != 1){
                for(int j = 0; j < nCards; j++){
                    if(cards[j][0] == lastCardValue && ht_get(acceptedCards, cards[j]) != NULL && !strcmp(ht_get(deck, cards[j]), sentences[3])){
                        lastCardSuit = cards[j][1];
                        char counter[12];
                        sprintf(counter, "%d", i);
                        ht_set(acceptedCards, cards[j], counter);
                        nAcceptedCards++;
                        foundOne = 1;
                        break;
                    }
                }
            }
        }
    }

    if(nAcceptedCards == nCards){
        printf("%s\n", sentences[2]);
        for(int i = 0; i < nAcceptedCards; i++){
            char counter[12];
            sprintf(counter, "%d", i);
            for(int j = 0; i < nCards; j++){
                if(!strcmp(ht_get(acceptedCards, cards[j]), counter)){
                    printf("%s ", cards[j]);
                }
            }
        }
        printf("\n");
    }
    else{
        printf("%s\n", sentences[1]);
    }
    return 0;
}

hashtable_t* defineHashArrayOfCards(char** sentences){
    hashtable_t *deck = ht_create(SIZE);

    ht_set(deck, "AS", sentences[3]);
    ht_set(deck, "AD", sentences[3]);
    ht_set(deck, "AH", sentences[3]);
    ht_set(deck, "AC", sentences[3]);
    ht_set(deck, "2S", sentences[4]);
    ht_set(deck, "2D", sentences[4]);
    ht_set(deck, "2H", sentences[4]);
    ht_set(deck, "2C", sentences[4]);
    ht_set(deck, "3S", sentences[4]);
    ht_set(deck, "3D", sentences[4]);
    ht_set(deck, "3H", sentences[4]);
    ht_set(deck, "3C", sentences[4]);
    ht_set(deck, "4S", sentences[4]);
    ht_set(deck, "4D", sentences[4]);
    ht_set(deck, "4H", sentences[4]);
    ht_set(deck, "4C", sentences[4]);
    ht_set(deck, "5S", sentences[4]);
    ht_set(deck, "5D", sentences[4]);
    ht_set(deck, "5H", sentences[4]);
    ht_set(deck, "5C", sentences[4]);
    ht_set(deck, "6S", sentences[3]);
    ht_set(deck, "6D", sentences[3]);
    ht_set(deck, "6H", sentences[3]);
    ht_set(deck, "6C", sentences[3]);
    ht_set(deck, "7S", sentences[3]);
    ht_set(deck, "7D", sentences[3]);
    ht_set(deck, "7H", sentences[3]);
    ht_set(deck, "7C", sentences[3]);
    ht_set(deck, "8S", sentences[4]);
    ht_set(deck, "8D", sentences[4]);
    ht_set(deck, "8H", sentences[4]);
    ht_set(deck, "8C", sentences[4]);
    ht_set(deck, "9S", sentences[4]);
    ht_set(deck, "9D", sentences[4]);
    ht_set(deck, "9H", sentences[4]);
    ht_set(deck, "9C", sentences[4]);
    ht_set(deck, "TS", sentences[4]);
    ht_set(deck, "TD", sentences[4]);
    ht_set(deck, "TH", sentences[4]);
    ht_set(deck, "TC", sentences[4]);
    ht_set(deck, "JS", sentences[4]);
    ht_set(deck, "JD", sentences[4]);
    ht_set(deck, "JH", sentences[4]);
    ht_set(deck, "JC", sentences[4]);
    ht_set(deck, "QS", sentences[4]);
    ht_set(deck, "QD", sentences[4]);
    ht_set(deck, "QH", sentences[4]);
    ht_set(deck, "QC", sentences[4]);
    ht_set(deck, "KS", sentences[3]);
    ht_set(deck, "KD", sentences[4]);
    ht_set(deck, "KH", sentences[4]);
    ht_set(deck, "KC", sentences[4]);
    ht_set(deck, "*", sentences[3]);

    return deck;
}