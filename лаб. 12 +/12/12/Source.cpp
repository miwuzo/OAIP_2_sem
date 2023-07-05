#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;

    Node* createNode(int data) {
        Node* node = new Node;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    Node* insertNode(Node* root, int data) {
        if (root == NULL) {
            return createNode(data);
        }
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == NULL) {
            return root;
        }
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    void printNode(Node* node, int level) {
        if (node == NULL) {
            return;
        }
        printNode(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "   ";
        }
        cout << node->data << endl;
        printNode(node->left, level + 1);
    }
    void printTree(Node* root) {
        printNode(root, 0);
    }

    void clearTree(Node* root) {
        if (root != NULL) {
            clearTree(root->left);
            clearTree(root->right);
            delete root;
        }
    }

    int countRightNodes(Node* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->right != NULL) {
            return 1 + countRightNodes(root->right);
        }
        return (countRightNodes(root->left) +1);
    }

    void mixedTraversal(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            mixedTraversal(root->right);
            mixedTraversal(root->left);
        }
    }

    void descendingTraversal(Node* root) {
        if (root != NULL) {
            descendingTraversal(root->right);
            cout << root->data << " ";
            descendingTraversal(root->left);
        }
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(Node* root) {
        if (root == NULL) {
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return (abs(leftHeight - rightHeight) <= 1)
            && isBalanced(root->left)
            && isBalanced(root->right);
    }

public:
    BinaryTree() {
        root = NULL;
    }
    void createTree() {
        int data;
        cout << "������� �������� �������: ";
        cin >> data;
        root = createNode(data);
    }

    void addNode() {
        int data;
        cout << "������� �������� ��� ����������: ";
        cin >> data;
        insertNode(root, data);
    }

    void deleteNode() {
        int data;
        cout << "������� �������� ��� ��������: ";
        cin >> data;
        deleteNode(root, data);
    }

    void print() {
        cout << "������: " << endl;
        printTree(root);
        cout << endl;
    }

    void clear() {
        clearTree(root);
        root = NULL;
    }

    void countRight() {
        cout << "���������� ����� ������ ����� ������: ";
        cout << countRightNodes(root) << endl;
    }

    void mixedTraverse() {
        cout << "��������� ����� ������: ";
        mixedTraversal(root);
        cout << endl;
    }

    void descendingTraverse() {
        cout << "���������� ����� ������: ";
        descendingTraversal(root);
        cout << endl;
    }

    void checkBalance() {
        if (isBalanced(root)) {
            cout << "������ ��������������" << endl;
        }
        else {
            cout << "������ �� ��������������" << endl;
        }
    }
    };

int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree tree;
    int choice;
    do {
        cout << "�������� ��������: " << endl;
        cout << "1 - �������� ������\n";
        cout << "2 - ���������� ��������\n";
        cout << "3 - �������� ��������\n";
        cout << "4 - ����� ������\n";
        cout << "5 - ������� ������\n";
        cout << "6 - ���������� ����� ������ ����� ������\n";
        cout << "7 - ��������� ����� ������\n";
        cout << "8 - ���������� ����� ������\n";
        cout << "9 - �������� ������������������ ������\n";
        cout << "10 - �����\n";
        cout << "��� �����: ";
        cin >> choice;
        switch (choice) {
        case 1:
            tree.createTree();
            break;
        case 2:
            tree.addNode();
            break;
        case 3:
            tree.deleteNode();
            break;
        case 4:
            tree.print();
            break;
        case 5:
            tree.clear();
            break;
        case 6:
            tree.countRight();
            break;
        case 7:
            tree.mixedTraverse();
            break;
        case 8:
            tree.descendingTraverse();
            break;
        case 9:
            tree.checkBalance();
            break;
        case 10:
            cout << "�� ��������!" << endl;
            break;
        default:
            cout << "�������� �����, ���������� �����." << endl;
            break;
        }
    } while (choice != 10);

    return 0;
}