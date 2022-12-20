//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_PostOffice.h"

// TODO: Constructors and Destructors

//TIP: root will be nullptr at first, and we'll add a node once we try to add a mail object.
BST_PostOffice::BST_PostOffice()
{
    root = nullptr;
}

BST_PostOffice_Node::BST_PostOffice_Node(Mail *mail)
{
    this->district = mail->getDistrict();
    mailman[mail->getAddressHash()].addMail(mail);
    left = nullptr;
    right = nullptr;
}

BST_PostOffice::~BST_PostOffice()
{
    delete root;
    root = nullptr;
}

BST_PostOffice_Node::~BST_PostOffice_Node()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

// TODO: Accessor functions.
BST_PostOffice * BST_PostOffice_Node::getLeftBST() const
{
    return left;
}

BST_PostOffice * BST_PostOffice_Node::getRightBST() const
{
    return right;
}

District BST_PostOffice_Node::getDistrict() const
{
    return district;
}


//TODO: Given a district, id and street name, find the mail object.
Mail *BST_PostOffice::find(District dist, int id, std::string streetName)
{
    if(dist == root->district){
        return(root->find(id,streetName));
    }
    Mail* left = nullptr;
    Mail* right = nullptr;
    if(root->left && dist<root->district){
        left = root->left->find(dist,id,streetName);
    }
    if(root->right && dist>root->district){
        right = root->right->find(dist,id,streetName);
    }
    
    if(left){return left;}
    if(right){return right;}
    return nullptr;
    

    
}

Mail *BST_PostOffice_Node::find(int id, std::string streetName)
{
    for(int i=0;i<HASH_MODULO;i++){
        Mail* temp = mailman[i].find(id,streetName);
        
        if(temp){
            
            return temp;
        }
    }
    return nullptr;
}


// TODO: Given a district, id and street name, remove the mail object from the
// system.
bool BST_PostOffice::remove(District dist, int id, std::string streetName)
{
    if(dist == root->district){
        return(root->remove(id,streetName));
    }
    bool left = false;
    bool right = false;
    if(root->left && dist<root->district){
        left = root->left->remove(dist,id,streetName);
    }
    if(root->right && dist>root->district){
        right = root->right->remove(dist,id,streetName);
    }

    
    return left||right;
}

bool BST_PostOffice_Node::remove(int id, std::string streetName)
{
    for(int i=0;i<HASH_MODULO;i++){
        bool temp = mailman[i].remove(id,streetName);
        if(temp){
            return temp;
        }
    }
    return false;

}

// TODO: Add mail to the system
void BST_PostOffice::addMail(Mail *mail)
{
    if(!root){
        root = new BST_PostOffice_Node(mail);
        return;
    }
    if(root->district == mail->getDistrict()){
        root->addMail(mail); 
        return;
    }
    
    if(root->district > mail->getDistrict()){
        if(root->left){
            root->left->addMail(mail);
            return;
        }
        else{
            root->left = new BST_PostOffice;
            root->left->addMail(mail);
            return;
        }
        
    }

    if(root->district<mail->getDistrict()){
        if(root->right){
            root->right->addMail(mail);
            return;
        }
        else{
            root->right = new BST_PostOffice;
            root->right->addMail(mail);
            return;
        }
        
    }
}

void BST_PostOffice_Node::addMail(Mail *mail)
{
    mailman[mail->getAddressHash()].addMail(mail);
}

// TODO: Given a district, print all of the data in it.
// TIP: Print style depends on type.
void BST_PostOffice::printDistrict(District dist, printType type) const
{   
    if(root){
        if(dist == root->district){
            root->print(type);
        }
        if(root->left && dist<root->district){
            root->left->printDistrict(dist,type);
        }
        if(root->right && dist>root->district){
            root->right->printDistrict(dist,type);
        }
    }
}

void BST_PostOffice_Node::print(printType type) const
{
    std::cout<<"The District Mail Report for district"<<" "<<this->district<<std::endl;
    for(int i=0;i<HASH_MODULO;i++){
        std::cout<<"For Mailman"<<" "<<i<<std::endl;
        if(type == printType::inorder){
            mailman[i].printInOrder();
        }
        else if(type == printType::preorder){
            mailman[i].printPreOrder();
        }
        else{
             mailman[i].printPostOrder();
        }
        
    }
}

// TODO: Given a district and ID of the mailman, print all mail in it
// TIP: Print style depends on type - see the header file
void BST_PostOffice::printMailman(District district, int i, printType type) const
{
    if(root){
        if(district == root->district){
            root->printMailman(i,type);
        }
        
        if(root->left && district<root->district){
            root->left->printMailman(district,i,type);
        }
        if(root->right && district>root->district){
            root->right->printMailman(district,i,type);
        }
    }
}

void BST_PostOffice_Node::printMailman(int i, printType type) const
{
        if(type == printType::inorder){
            mailman[i].printInOrder();
        }
        else if(type == printType::preorder){
            mailman[i].printPreOrder();
        }
        else{
             mailman[i].printPostOrder();
        }
}

// TODO: Other print functions.
void BST_PostOffice::printInOrder() const
{
    if(root){
        if(root->left){
            root->left->printInOrder();
        }
        std::cout<<"BST Node for District:" << ' '<<root->district<<std::endl;
        for(int i=0;i<HASH_MODULO;i++){
            root->mailman[i].printInOrder();
        }
        if(root->right){
            root->right->printInOrder();
        }
    }
    
}

void BST_PostOffice::printPostOrder() const
{
    if(root){
        if(root->left){
            root->left->printPostOrder();
        }
        
        if(root->right){
            root->right->printPostOrder();
        }
        std::cout<<"BST Node for District:" << ' '<<root->district<<std::endl;
        for(int i=0;i<HASH_MODULO;i++){
            root->mailman[i].printPostOrder();
        }
    }
}

void BST_PostOffice::printPreOrder() const
{
    if(root){
        std::cout<<"BST Node for District:" << ' '<<root->district<<std::endl;
        for(int i=0;i<HASH_MODULO;i++){
            root->mailman[i].printPreOrder();
        }
        if(root->left){
            root->left->printPreOrder();
        }
        
        if(root->right){
            root->right->printPreOrder();
        }
    }
}