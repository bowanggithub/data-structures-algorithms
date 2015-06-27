//return a pointer to the node with the least value in root
//for the selected descriminator
BinNode<E>* findmin(BinNode<E>* root,
			int discrim, int currdis) const
{
    //discrim: discriminator key used for minimum search
    //currdis: current level (mod D)
    if (root == NULL) return NULL;
    BinNode<E>* minnode = findmin(root->left(), discrim,
    					(currdis+1)%D);
    if (discrim != currdis)	//if not at discrim's level
    {				//we must search both subtrees
	BinNode<E>* rightmin = 
		findmin(root->right(), discrim, (currdis+1)%D);
	//check if right side has smaller key value
	minnode = min(minnode, rightmin, discrim);
    }	//now minnode has the smallest value in children
    return min(minnode, root, discrim);
}
