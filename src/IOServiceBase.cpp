// Copyright (C) 2012-present ichenq@outlook.com All rights reserved.
// Distributed under the terms and conditions of the Apache License. 
// See accompanying files LICENSE.

#include "IOServiceBase.h"
#include "Common/Logging.h"
#include "Common/Error.h"
#include "OverlappedIOService.h"
#include "CompletionPortService.h"


IOServiceBase::IOServiceBase()
{
}

IOServiceBase::~IOServiceBase()
{
}


IOServiceBase* CreateIOService(IOServiceType type)
{
    switch(type)
    {
    case IOOverlapped:
        return new OverlappedIOService;

    case IOCompletionPort:
        return new CompletionPortService;

    default:
        LOG(ERROR) << "unsupported service type";
        return nullptr;
    }
}