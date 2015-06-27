//find the record with the given coordinates
bool findhelp(BinNode<E>* root, int* coord,
		E& e, int discrim) const
{
    //member "coord" of a node is an integer array storing
    //the node's coordinates
    if (root == NULL) return false;	//empty tree
    int* currcoord = (root->val())->coord();
    if (EqualCoord(currcoord, coord))	//found it
    {
	e = root->val();
	return true;
    }

    if (currcoord[discrim] < coord[discrim])
	return findhelp(root->left(), coord, e, (discrim+1)%D);
    else
	return findhelp(root->right(), coord, e, (discrim+1)%D);
}

