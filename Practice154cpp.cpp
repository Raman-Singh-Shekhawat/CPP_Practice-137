/*

155. Second Largest Element In Tree: Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.

*/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

class Pair
{
public:
    TreeNode<int> *largest;
    TreeNode<int> *secondLargest;
};

Pair helper(TreeNode<int> *root)
{
    Pair ans;
    ans.largest = root;
    ans.secondLargest = NULL;

    for (int i = 0; i < root->children.size(); i++)
    {
        Pair smallAns = helper(root->children[i]);
        if (smallAns.largest->data > ans.largest->data)
        {
            if (smallAns.secondLargest == NULL)
            {
                ans.secondLargest = ans.largest;
                ans.largest = smallAns.largest;
            }
            else
            {
                if (smallAns.secondLargest->data > ans.largest->data)
                {
                    ans.secondLargest = smallAns.secondLargest;
                    ans.largest = smallAns.largest;
                }
                else
                {
                    ans.secondLargest = ans.largest;
                    ans.largest = smallAns.largest;
                }
            }
        }
        else
        {
            if ((ans.largest->data != smallAns.largest->data) &&
                (ans.secondLargest == NULL || smallAns.largest->data > ans.secondLargest->data))
            {
                ans.secondLargest = smallAns.largest;
            }
        }
    }
    return ans;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    return helper(root).secondLargest;
}