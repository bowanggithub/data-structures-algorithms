//print using a preorder traversal
void printhelp(GTNode<E>* root)
{
    if (root->isLeaf()) cout << "Leaf: ";
    else cout << "Internal: ";
    cout << root->value() << "\n";
    //now process the children of "root"
    for (GTNode<E>* temp = root->leftmostChild();
    	temp!= NULL; temp = temp->rightSibling())
	printhelp(temp);
}
