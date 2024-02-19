#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    buffer->capacity = capacity;
    buffer->buffer = malloc(capacity * sizeof(buffer_value_t));
    buffer->size = 0;
    buffer->head = 0;
    buffer->tail = 0;
    return buffer;
}
int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (!buffer)
    {
        errno = EINVAL;
        return EXIT_FAILURE;
    }
    if (buffer->size == buffer->capacity)
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    buffer->buffer[buffer->head] = value;
    buffer->head = (buffer->head + 1) % buffer->capacity;
    buffer->size++;
    return EXIT_SUCCESS;
}
int16_t read(circular_buffer_t *buffer, buffer_value_t *value)
{
    if (!buffer)
    {
        errno = EINVAL;
        return EXIT_FAILURE;
    }
    if (buffer->size == 0)
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = buffer->buffer[buffer->tail];
    buffer->buffer[buffer->tail] = 0;
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->size--;
    return EXIT_SUCCESS;
}
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    buffer->buffer[buffer->head] = value;
    buffer->head = (buffer->head + 1) % buffer->capacity;
    if (buffer->size != buffer->capacity)
    {
        buffer->size++;
    }
    else
    {
        buffer->tail = (buffer->tail + 1) % buffer->capacity;
    }
    return EXIT_SUCCESS;
}
void clear_buffer(circular_buffer_t *buffer)
{
    for (size_t i = 0; i < buffer->capacity; ++i)
    {
        buffer->buffer[i] = 0;
    }
    buffer->size = 0;
    buffer->head = 0;
    buffer->tail = 0;
}

void delete_buffer(circular_buffer_t *buffer)
{
    free(buffer->buffer);
    free(buffer);
}