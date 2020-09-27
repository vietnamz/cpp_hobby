#include <iostream>


/*
 *
 *
 *  proxy patterns:
 *      + a client.
 *      + a proxy object.
 *      + a real object.
 *
 *  smart pointer is a good example on this patterns.
 *  where we dont manipulate directly in the object but via a proxy.
 *  there are 3 types of projects:
 *      + virtual proxy: to create an expensive object on demand. image data creations for example.
 *      + remote proxy: to create a local object to represent a object in another address space. RPC is an example.
 *      + protected proxy: to create a wrapper object to protect the access into a real object. smart pointer is an example.
 *
 *
 *                                      subject
 *                                      request()
 *                                         |
 *                                         |
 *
 *              real object- - - - - - -  proxy
 *                                       request()
 *
 *
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}