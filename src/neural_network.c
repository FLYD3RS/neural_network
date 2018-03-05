#include <stdio.h>
#include <stdlib.h>
#include "neural_network.h"


layer * create_layer(int size){
    layer * local = malloc(sizeof(layer));
    local->size = size;
    local->neurones = malloc(sizeof(neurone) * size);
    local->nextLayer = NULL;
    local->name = "DEFAULT VALUE";
    for(int x=0; x < local->size; x++){
        local->neurones[x].enable = 1;
    }

    return local;
}

layer * add_layer(layer *model, int size){
    layer * local = model;
    while(local->nextLayer != NULL){
        local = local->nextLayer;
    }
    local->nextLayer = create_layer(size);
    return local->nextLayer;
}


void generateLink(layer *model){
    layer *local = model;
    int length1, length2;
    while(local->nextLayer != NULL){
        length1 = local->size;
        length2 = local->nextLayer->size;

        for(int x = 0; x < length1; x++){
            local->neurones[x].synapses = malloc(sizeof(struct synapse)  * length2);
            for(int z = 0; z < length2; z++){
                local->neurones[x].synapses[z].weight = 0; // TODO: random value here
                local->neurones[x].synapses[z].nextNeurone = NULL;
            }
        }

        local = local->nextLayer;
    }
    return;
}

void clear_model(layer *model){
    while(model != NULL){
        layer * local = model->nextLayer;
        if (model->nextLayer != NULL){
            for(int i = 0; i < model->size; i++){
                free(model->neurones[i].synapses);
            }            
        }
        free(model->neurones);
        free(model);
        model = local;        
    }
    return;
}



int main(){
    // EXAMPLE
    layer *a = create_layer(8); // INPUT LAYER
    add_layer(a, 10);           // HIDDEN LAYER 1
    add_layer(a, 10);           // HIDDEN LAYER 2
    add_layer(a, 10);           // HIDDEN LAYER 3
    add_layer(a, 4);            // OUTPUT LAYER
    generateLink(a);
    clear_model(a);  
    printf("test");
    return 0;
}
