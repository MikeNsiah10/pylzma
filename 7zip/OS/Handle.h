// OS/Handle.h

#ifndef __OS_HANDLE_H
#define __OS_HANDLE_H

class CHandle
{
protected:
  HANDLE _handle;
public:
  operator HANDLE() { return _handle; }
  CHandle(): _handle(NULL) {}
  ~CHandle() { Close(); }
  bool Close()
  {
    if (_handle == NULL)
      return true;
    if (!::CloseHandle(_handle))
      return false;
    _handle = NULL;
    return true;
  }
  void Attach(HANDLE handle) 
    { _handle = handle; }
  HANDLE Detach() 
  { 
    HANDLE handle = _handle;
    _handle = NULL; 
    return handle;
  }
};

#endif