#include "todo.h"

task_t *task_new(int state, uint8_t *data, size_t size)
{
    task_t *task = malloc(sizeof(task_t));

    if (task != NULL) {
        task->state = state;
        task->next = NULL;

        hbuf_t *buf = hbuf_new(BUF_UNIT);

        if (!buf)
            return NULL;

        if (hbuf_put(buf, data, size) != HBUF_OK)
            return NULL;

        task->data = buf;
    }
    return task;
}

void task_free(task_t *task)
{
    if (task != NULL) {
        if (task->data != NULL)
            hbuf_free(task->data);
        free(task);
    }
}

todo_t *todo_new()
{
    todo_t *todo = malloc(sizeof(todo_t));

    if (todo != NULL) {
        todo->head = NULL;
    }
    return todo;
}
