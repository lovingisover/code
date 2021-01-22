/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
_Bool isSub(struct TreeNode* A, struct TreeNode* B){
	return B ? (!A || B->val != A->val) ? 0 : isSub(A->left, B->left) && isSub(A->right, B->right) : 1;
}
//遍历A，与B进行比较
_Bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
	if (!B || !A) return 0;
	_Bool result = 0;
	if (A){
		if (A->val == B->val) result = isSub(A->left, B->left) && isSub(A->right, B->right);
		result = result || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	return result;
}