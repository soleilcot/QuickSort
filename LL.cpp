void quickSort(struct node **headRef) {
    node* p = partition(headRef, NULL);
    node** tmp = &(p->next);
    
    QuickSort(headRef, p);
    QuickSort(tmp, NULL);
    
    p->next = *tmp;
}

void QuickSort(struct node** headRef, node* end)
{
    if(end == *headRef)
    {
        return;
    }
    end = partition(headRef, end);
    QuickSort(headRef, end);
    QuickSort(&(end->next), NULL);

    
}

node* partition(struct node **headRef,struct node* end)
{
    node* current = *headRef;
    node* prev = NULL;
    node* pivot = current;
    node* tmp = NULL;
    node* newHead = NULL;
    
    while(pivot->next != end)
    {
        pivot=pivot->next;
    }
    
    node* tail = pivot;
    node* temp = tail->next;
    
    tail->next = NULL;
    
    while(current != pivot)
    {
        if(current->data < pivot->data)
        {
            if(!newHead)
            {
                newHead = current;
                *headRef = newHead;
            }
            prev = current;
            current = current->next;
        }
        else
        {
            tmp = current->next;
            tail->next = current;
            
            if(prev)
            {
                prev->next = tmp;
            }
            else
            {
                *headRef = tmp;
            }
            
            current->next = NULL;
            tail =  current;
            current=tmp;
            
        }
    }
    
    tail->next = temp;
    
    return pivot;
}
