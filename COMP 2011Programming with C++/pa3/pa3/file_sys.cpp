/** 
 * This file contains the file system functions that you need to implement.
 * You can define helper functions in this file.
 * 
 * Remember to remove the initial statements in the functions.
 * They are only used so that your semi-finished codes can compile.
*/

#include <iostream>
#include "file_sys.h"
#include "utils.h"
using namespace std;



bool legal_character(char s){
    if((int)s >= 65 &&  (int)s <= 90){
        return true;
    }
    if((int)s >= 97 &&  (int)s <= 122){
        return true;
    }
    if((int)s >= 48 && (int)s <= 57){
        return true;
    }
    if((int)s == 45 || (int)s == 46 || (int)s == 95){
        return true;
    }
    return false;
}


int delete_directory(Dir* dir, int level)
{
 
    /* deref head_ref to get the real head */
    
    File* current_file = dir->subfile;
    File* next_file = nullptr;
    while(current_file){
        next_file = current_file->next;
        delete current_file;
        current_file = next_file;
    }
    current_file = nullptr;
    next_file = nullptr;
    
    if(dir->subdir != nullptr){
        level = level+1;
        
        delete_directory(dir->subdir,level);
    }
    if(dir->next != nullptr && level != 0){
        delete_directory(dir->next,level);
    }
   
    delete dir;
    
    return 0;
    /* deref head_ref to affect the real head back
        in the caller. */
    
}


int createFile(Dir *dir, const char *name, unsigned int size, Tag tag)
{   
    if(dir == nullptr || name == nullptr){
        return 1;
    }
    if(strlen(name) == 0){
        return 2;
    }
    if(strlen(name) == 1){
        if(strcmp(name,".") == 0){
            return 2;
        }
    }
    if(strlen(name) == 2){
        if(strcmp(name,"..") == 0){
            return 2;
        }
    }

    for(int i=0;i<strlen(name);i++){
        if(i == 0 && (int) name[i] == 45){
            return 2;
        }
        if(!legal_character(name[i])){
            return 2;
        }
    }
    Dir* check_dir_name = nullptr;
    check_dir_name = dir->subdir;
    while(check_dir_name){
        if(strcmp(check_dir_name->name,name) == 0){
            check_dir_name = nullptr;
            return 3;
        }
        check_dir_name = check_dir_name->next;
    }
    File* check_file_name = nullptr;
    check_file_name = dir->subfile;
    while(check_file_name){
        if(strcmp(check_file_name->name,name)==0){
            check_file_name = nullptr;
            return 3;
        }
        check_file_name = check_file_name->next;
    }


    File* new_file = new File();
    strcpy(new_file->name,name);
    new_file->parent = dir;
    new_file->size = size;
    new_file->tag = tag;
    
    new_file->next = dir->subfile;
    dir->subfile = new_file;
    

    return 0;  // Remove this line after you finish.
}

int createDir(Dir *dir, const char *name)
{   
    if(dir == nullptr || name == nullptr){
        return 1;
    }
    if(strlen(name) == 0){
        return 2;
    }
    if(strlen(name) == 1){
        if(strcmp(name,".") == 0){
            return 2;
        }
    }
    if(strlen(name) == 2){
        if(strcmp(name,"..") == 0){
            return 2;
        }
    }

    for(int i=0;i<strlen(name);i++){
        if(i == 0 && (int) name[i] == 45){
            return 2;
        }
        if(!legal_character(name[i])){
            return 2;
        }
    }
    File* check_file_name = nullptr;
    check_file_name = dir->subfile;
    while(check_file_name){
        if(strcmp(check_file_name->name,name)==0){
            check_file_name = nullptr;
            return 3;
        }
        check_file_name = check_file_name->next;
    }
    Dir* subD = nullptr;
    subD = dir->subdir;
    while(subD){
        if(strcmp(subD->name,name) == 0){
            subD = nullptr;
            return 3;
        }
        subD = subD->next;
    }
   
    Dir* new_dir = new Dir();
    strcpy(new_dir->name,name);
    new_dir->parent = dir;
    new_dir->next = dir->subdir;
    dir->subdir = new_dir;
    
    return 0;
}

int deleteFile(Dir *dir, const char *name)
{
    if(dir == nullptr || name == nullptr){
        return 1;
    }
    File* subf = dir->subfile;
    
    
    if(strcmp(dir->subfile->name, name) == 0){
        dir->subfile = dir->subfile->next;
        delete subf;
        subf = nullptr;
        return 0;
    }
    File* prev = nullptr;
    while(subf){
        if(strcmp(subf->name, name) == 0){
            prev->next = subf->next;
            delete subf;
            prev = nullptr;
            subf = nullptr;
            return 0;
        }
        prev = subf;
        subf = subf->next;
    }
    prev = nullptr;
    subf = nullptr;

    return 2;  // Remove this line after you finish.
}

int deleteDir(Dir *dir, const char *name, bool recursive)
{
    if(dir == nullptr || name == NULL){
        return 1;
    }
    

    Dir* delete_dir;
    delete_dir = dir->subdir;
    

    if(strcmp(delete_dir->name, name) == 0){
        if(delete_dir->subdir == nullptr && delete_dir->subfile == nullptr){
                dir->subdir = dir->subdir->next;
                delete_directory(delete_dir,0);
                return 0;
            }
            else if (recursive == false){
                return 3;
            }
        dir->subdir = dir->subdir->next;
        delete_directory(delete_dir,0);
        return 0;
    }
    Dir* prev_dir = nullptr;
    while(delete_dir){
        if(strcmp(delete_dir->name, name) == 0){
            if(delete_dir->subdir == nullptr && delete_dir->subfile == nullptr){
                prev_dir->next = delete_dir->next;
                delete_directory(delete_dir,0);
                return 0;
            }
            else if (recursive == false){
                return 3;
            }
            prev_dir->next = delete_dir->next;
            delete_directory(delete_dir,0);
            
            return 0;
        }
        prev_dir = delete_dir;
        delete_dir = delete_dir->next;
        
    }
    
    return 2;  // Remove this line after you finish.
    
}

unsigned int real_getSize(const Dir *dir, int level){
    int sum = 0;
    if(dir->subdir != nullptr){
        level = level+1;
        sum+=real_getSize(dir->subdir,level);
    }
    if(dir->next != nullptr && level != 0){
        sum+=real_getSize(dir->next,level);
    }
    File* cur_file = nullptr;
    cur_file = dir->subfile;
    while(cur_file){
        sum += cur_file->size;
        cur_file = cur_file->next;
    }
    return sum;
}
unsigned int getSize(const Dir *dir)
{
    int sum = real_getSize(dir,0);
    return sum;   
}

int recursive_tag(const Dir* dir, Tag tag, unsigned int& length, const File** &tags){
    

    if(dir->next != nullptr){
        recursive_tag(dir->next,tag,length,tags);
    }
    if(dir->subdir != nullptr){
        recursive_tag(dir->subdir,tag,length,tags);
    }
    int sum = 0;
    const File* current_file = dir->subfile;
    while(current_file){
        if(current_file->tag == tag){
            sum++;
        }
        current_file = current_file->next;
    }
    const File** coming  = new const File*[length+sum]; 
    
    for(int i=0;i<length;++i){
                coming[i] = tags[i];
            }
    const File* current = dir->subfile;
    while(current){
        if(current->tag == tag){
            coming[length] = current;
            length++;
        }
        current = current->next;
    }
    
    delete [] tags;       
    tags = coming;
    coming = nullptr;
    delete [] coming;
    return 0;
}

const File **filesOfTag(const Dir *dir, Tag tag, unsigned int &length)
{
    length = 0;
    const File** tags = new const File*[length];
    recursive_tag(dir,tag,length,tags);
    if(length == 0){
        delete [] tags;
        return NULL;
    }
    return tags;                             
}

int moveFile(File *tgt, Dir *dest)
{
    if(tgt == nullptr || dest == nullptr){
        return 1;
    }
    if(tgt->parent == dest){
        return 2;
    }
    File* check_name = nullptr;
    check_name = dest->subfile;
    while(check_name){
        if(strcmp(check_name->name,tgt->name) == 0){
            return 3;
        }
        check_name = check_name->next;
    }

    Dir* subD = nullptr;
    subD = dest->subdir;
    while(subD){
        if(strcmp(subD->name,tgt->name) == 0){
            subD = nullptr;
            return 3;
        }
        subD = subD->next;
    }


    File* f = tgt->parent->subfile;
    if(f == tgt){
        tgt->parent->subfile = f->next;
        tgt->next = dest->subfile;
        dest->subfile = tgt;
        tgt->parent = dest;
        return 0; 
    }
    
    File* prev = nullptr;
    while(f){
        if(f == tgt){
            prev->next = f->next;
            tgt->next = dest->subfile;
            dest->subfile = tgt;
            tgt->parent = dest;
            return 0;
        }
        prev = f;
        f = f->next;
    }
    
    
    
    return -1;     // Remove this line after you finish. 
}

int moveDir(Dir *tgt, Dir *dest)
{   
    if(tgt == nullptr || dest == nullptr){
        return 1;
    }
    if(tgt->parent == dest){
        return 2;
    }
    if(tgt == dest){
        return 4;
    }
    Dir* check = nullptr;
    check = tgt->subdir;
    while(check){
        if(check == dest){
            return 4;
        }
        check = check->next;
    }
    check = dest->subdir;
    while(check){
        if(strcmp(check->name,tgt->name) == 0){
            return 3;
        }
        check = check->next;
    }
    check = nullptr;
    File* check_name = nullptr;
    check_name = dest->subfile;
    while(check_name){
        if(strcmp(check_name->name,tgt->name) == 0){
            return 3;
        }
        check_name = check_name->next;
    }



    Dir* cur = tgt->parent->subdir;
    if(cur == tgt){
        tgt->parent->subdir = tgt->parent->subdir->next;
        cur = nullptr;
    }
    else{
        Dir* prev = nullptr;
        while(cur){
            if(cur == tgt){
                prev->next = cur->next;
                prev = nullptr;
                cur = nullptr;
                break;
            }
        prev = cur;
        cur = cur->next;
        }
    }
    tgt->parent = dest;
    tgt->next = dest->subdir;
    dest->subdir = tgt;
    

    return 0;      // Remove this line after you finish.
}
