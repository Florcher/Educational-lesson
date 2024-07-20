#include "Vector2D.h"
#include "ContextIO.h"

vector2D ConcoleContext::getPoint() {
	return filer.readVector2D();
}

std::string ConcoleContext::getString() {
	return filer.readString();
}

int ConcoleContext::getInt() {
	return filer.readInt();
}

double ConcoleContext::getDouble() {
	return filer.readDouble();
}

uint64_t ConcoleContext::getUint64_t()
{
    return filer.readUint64_t();
}
