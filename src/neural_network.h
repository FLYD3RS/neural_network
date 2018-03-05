#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H


typedef struct layer {
    char *name;
    int size;
    struct neurone *neurones;
    struct layer *nextLayer;
} layer;


typedef struct neurone {
    short enable;
    struct synapse *synapses;
} neurone;


typedef struct synapse {
    double weight;
    struct neurone *nextNeurone;
} synapse;


// ACTION: return a ptr layer with 'size' neurones inside
layer * create_layer(int size);


// append a layer to an existing layer with 'size' neurones inside
// this function return a ptr layer of the added layer
layer * add_layer(layer *model, int size);


// create each link beetwen neurones of the layer n and the the layer n+1
void generateLink(layer *model);


// free layers, neurones, and synapses of one model
void clear_model(layer *model);


#endif