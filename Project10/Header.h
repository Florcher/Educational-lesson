
#ifndef __HEADER_H__
#define __HEADER_HH

#ifndef PROJECT_EXP
#define PROJECT_EXPORT __declspec(dllimport)
#else 
#define PROJECT_EXPORT __declspec(dllexport)

#endif

#endif __HEADER_H__