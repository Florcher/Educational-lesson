#ifndef __HEADER_H_
#define __HEADER_H_

#ifndef PROJECT_EXP
#define PROJECT_EXPORT __declspec(dllimport)
#else 
#define PROJECT_EXPORT __declspec(dllexport)
#endif

#endif __HEADER_H_