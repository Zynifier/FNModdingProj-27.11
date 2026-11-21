// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/DisplayRequests/StoreToastRequest.h"

void UStoreToastRequest::BeginRequest()
{
}

void UStoreToastRequest::CompleteRequest()
{
}

FStoreCallout UStoreToastRequest::GetToast() const
{
	return FStoreCallout();
}

bool UStoreToastRequest::IsRequestReady()
{
	return false;
}

bool UStoreToastRequest::ShouldBeginRequest()
{
	return false;
}

void UStoreToastRequest::SkipRequest()
{
}
