//print all points within distance "rad" of "coord"
void regionhelp(BinNode<E>* root, int* coord,
		int rad, int discrim) const
{
    if (root == NULL) return;		//empty tree
    //check if record at root is in circle
    if (Incircle((root->val())->coord(), coord, rad))
	cout << root->val() << endl;
    int* currcoord = (root->val())->coord();
    if (currcoord[discrim] > (coord[discrim]-rad))
	regionhelp(root->left(), coord, rad, (discrim+1)%D);
    if (currcoord[discrim] < (coord[discrim]+rad))
	regionhelp(root->right(), coord, rad, (discrim+1)%D);
}
    
