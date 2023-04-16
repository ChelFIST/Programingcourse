#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

#define SIZE_MAX 500000

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

bool isEmpty(Vector *v);

bool isFull(Vector *v);

int getVectorValue(Vector *v, size_t i);

void pushBack(Vector *v, int x);

void popBack(Vector *v);

int *atVector(Vector *v, size_t index);

int *back(Vector *v);

int *front(Vector *v);

#endif//UNTITLED_VECTOR_H



