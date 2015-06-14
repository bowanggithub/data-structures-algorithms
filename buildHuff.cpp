//build a Huffman tree from a collection of frequencies
template <typename E> HuffTree<E>*
buildHuff(HuffTree<E>** TreeArray, int count)
{
    heap<HuffTree<E>*, minTreeComp>* forest =
        new heap<HuffTree<E>*, minTreeComp>(TreeArray, count, count);

    HuffTree<char> *temp1, *temp2, *temp3 = NULL;
    while (forest->size() >1) 
    {
	temp1 = forest->removefirst();
	temp2 = forest->removefirst();
	temp3 = new HuffTree<E>(temp1, temp2);
	forest->insert(temp3);
	delete temp1;
	delete temp2;
    }
    return temp3;
}
