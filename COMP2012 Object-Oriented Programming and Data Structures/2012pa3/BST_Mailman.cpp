//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_Mailman.h"

// TODO: Constructors and Destructors
BST_Mailman::BST_Mailman()
{
    root = nullptr;
    
    
}

BST_Mailman_Node::BST_Mailman_Node(Mail *mail)
{
    this->streetName = mail->getStreetName();
    this->mailPtr[currentMailsStored] = mail;
    currentMailsStored ++;
    left = nullptr;
    right = nullptr;
    
}

BST_Mailman::~BST_Mailman()
{
    delete root;
    root = nullptr;
}

BST_Mailman_Node::~BST_Mailman_Node()
{
    for(int i=0;i<currentMailsStored;i++){
        delete mailPtr[i];
        mailPtr[i] = nullptr;
    }
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

// TODO: Getters
std::string BST_Mailman_Node::getStreetName() const
{
    return streetName;
}

BST_Mailman * BST_Mailman_Node::getRightBST() const
{
    return right;
}

BST_Mailman * BST_Mailman_Node::getLeftBST() const
{
    return left;
}


// TODO add mail to the array mailPtr[] - NOTE: WE WILL NEVER ASK YOU TO
//  PUT TOO MANY MAILS. (a max of MAX_NUM_MAILS add_mail calls)
void BST_Mailman::addMail(Mail *mail)
{   
    if(!root){
        root = new BST_Mailman_Node(mail);
        return;
    }
    if(root->streetName == mail->getStreetName()){
        root->addMail(mail); 
        return;
    }
    
    if(root->streetName>mail->getStreetName()){
        if(root->left){
            root->left->addMail(mail);
            return;
        }
        else{
            root->left = new BST_Mailman();
            root->left->addMail(mail);
            return;
        }
    }

    if(root->streetName<mail->getStreetName()){
        if(root->right){
            root->right->addMail(mail);
            return;
        }
        else{
            root->right = new BST_Mailman();
            root->right->addMail(mail);
            return;
        }
    }

}

void BST_Mailman_Node::addMail(Mail *mail)
{
    mailPtr[currentMailsStored] = mail;
    currentMailsStored++;

}

// TODO: Remove a mail, given its street name and ID
bool BST_Mailman::remove(int id, std::string streetName)
{
    if(root){
        if(!streetName.compare(this->root->getStreetName())){
            return(root->remove(id)); 
        }
        bool left = false;
        bool right = false;
        if(root->left && streetName<root->getStreetName()){
            left = root->left->remove(id,streetName);
        }
        if(root->right && streetName>root->getStreetName()){
            right = root->right->remove(id,streetName);
        }
        return (left||right);
    }
    return false;

}

bool BST_Mailman_Node::remove(int id)
{
    
    for(int i=0;i<currentMailsStored;i++){
        if (mailPtr[i] && mailPtr[i]->getId() == id){
            delete mailPtr[i];
            mailPtr[i] = nullptr;
            return true;
        }
    }
    return false; 
}

// TODO: Find a mail item, given its street name and ID
Mail * BST_Mailman::find(int id, std::string streetName)
{
    if(root){
        if(streetName == root->streetName){
            
            return(root->find(id)); 
        }
        Mail* left = nullptr;
        Mail* right = nullptr;
        if(root->left && streetName<root->streetName){
            left = root->left->find(id,streetName);
        }
        if(root->right && streetName>root->streetName){
            right = root->right->find(id,streetName);
        }
        if(left != nullptr){return left;}
        if(right != nullptr){return right;}
    }
    return nullptr;
}

Mail *BST_Mailman_Node::find(int id)
{
    for(int i=0;i<currentMailsStored;i++){
        if (mailPtr[i] && mailPtr[i]->getId() == id){
            return mailPtr[i];
        }
    }
    return nullptr; 
}


// TODO: Print functions. See example outputs for the necessary formats.
void BST_Mailman::printInOrder() const
{
    if(root){
        if(root->left){
            root->left->printInOrder();
        }
        
        root->print();
        
        if(root->right){
            root->right->printInOrder();
        }
    }
}

void BST_Mailman::printPostOrder() const
{
    if(root){
        if(root->left){
            root->left->printPostOrder();
        }
        
        if(root->right){
            root->right->printPostOrder();
        }
        if(root){root->print();}
    }
}

void BST_Mailman::printPreOrder() const
{
    if(root){
        if(root){root->print();}

        if(root->left){
            root->left->printPreOrder();
        }
        
        if(root->right){
            root->right->printPreOrder();
        }
    }
}

void BST_Mailman_Node::print() const
{
    std::cout << "BST Node for Street: " << streetName << std::endl;
    for (int i = 0; i < currentMailsStored; ++i) {
        if(mailPtr[i] != nullptr)
        {
            mailPtr[i]->printMail();
        }
    }
}
