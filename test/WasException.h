#ifndef __WASEXCEPTION_H_
#define __WASEXCEPTION_H_

#define was_exception(val) {try{val;} catch(std::exception& e) {std::cout << "was exeption" << std::endl;}};

#endif __WASEXCEPTION_H_
