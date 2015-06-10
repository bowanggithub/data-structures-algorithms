//Insert "it" at current position
void insert(const E& it)
{
    curr->next = curr->next->prev =
        new Link<E>(it, curr, curr->next);
    cnt++;
}

//append "it" to the end of the list
void append(const E& it)
{
    tail->prev = tail->prev->next =
        new Link<E>(it,tail->prev,tail);
    cnt++;
}

//remove and return current element
E remove()
{
    if (curr->next == tail)
	return NULL;
    E it = curr->next->element;
    Link<E>* ltemp = curr->next;
    curr->next->next=>prev = curr;
    curr->next = curr->next->next;
    delete ltemp;
    cnt--;
    return it;
}

//move fence one step left; no change if left is empty
void prev()
{
    if (curr != head)
	curr = curr->prev;
}
