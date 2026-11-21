// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMUEFNResolver.h"

const TSet<FString>& UFMUEFNResolver::GetFinishedDownloads() const
{
	static TSet<FString> Dummy;
	return Dummy;
}

const TSet<FString>& UFMUEFNResolver::GetInProgressDownloads() const
{
	static TSet<FString> Dummy;
	return Dummy;
}

void UFMUEFNResolver::HandleGameFeatureLoadComplete(bool bSuccess, const FString& LinkCode)
{
}

void UFMUEFNResolver::HandleResolveComplete(bool bSuccess, const FString& LinkCode, const TArray<FString>& PluginURLs)
{
}

bool UFMUEFNResolver::IsDownloadInProgress() const
{
	return false;
}

bool UFMUEFNResolver::ResolveAndLoadLinkCode(const FString& LinkCode, const AFortPlayerState* PlayerState)
{
	return false;
}
