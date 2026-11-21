// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortExternalRpcUtils.h"

UWorld* UFortExternalRpcUtils::FindGameWorld()
{
	return nullptr;
}

AFortPlayerController* UFortExternalRpcUtils::FindPlayerController()
{
	return nullptr;
}

bool UFortExternalRpcUtils::TryExecuteConsoleCommand(const FString& CommandString, FString& OutError)
{
	return false;
}
