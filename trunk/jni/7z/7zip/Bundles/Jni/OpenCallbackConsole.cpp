// OpenCallbackConsole.cpp

#include "StdAfx.h"

#include "OpenCallbackConsole.h"

HRESULT COpenCallbackConsole::CheckBreak()
{
/*
  if (NConsoleClose::TestBreakSignal())
    return E_ABORT;
*/
  return S_OK;
}

HRESULT COpenCallbackConsole::SetTotal(const UInt64 *, const UInt64 *)
{
  return CheckBreak();
}

HRESULT COpenCallbackConsole::SetCompleted(const UInt64 *, const UInt64 *)
{
  return CheckBreak();
}
 
HRESULT COpenCallbackConsole::CryptoGetTextPassword(BSTR *password)
{
  RINOK(CheckBreak());
  if (!PasswordIsDefined)
  {
/*
    PasswordIsDefined = true;
    Password = GetPassword(OutStream);
*/
    return E_FAIL;
  }
  CMyComBSTR temp(Password);
  *password = temp.Detach();
  return S_OK;
}

HRESULT COpenCallbackConsole::GetPasswordIfAny(UString &password)
{
  if (PasswordIsDefined)
    password = Password;
  return S_OK;
}

  
