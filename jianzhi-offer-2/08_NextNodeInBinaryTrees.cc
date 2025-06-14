// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
    if (!pNode)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;
    if (pNode->m_pRight) {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while (pRight->m_pLeft)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    } else if (pNode->m_pParent) {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while (pParent && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }

    return pNext;
}
