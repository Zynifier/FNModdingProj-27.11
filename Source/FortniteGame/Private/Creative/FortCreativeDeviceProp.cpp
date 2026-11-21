// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeDeviceProp.h"

bool AFortCreativeDeviceProp::BPCanInteractNativeHelper(const AFortPawn* InteractingPawn, const UFortActorOptionsComponent* ToyOptionsComponent, const UFortMinigameProgressComponent* MinigameProgressComponent)
{
	return false;
}

FOnlineLinkId AFortCreativeDeviceProp::CreateLinkId(const FString& LinkString)
{
	return FOnlineLinkId();
}

FOnlineLinkId AFortCreativeDeviceProp::CreateLinkIdWithVersion(const FString& LinkString, const int32 Version)
{
	return FOnlineLinkId();
}

const FString AFortCreativeDeviceProp::LinkIdToString(const FOnlineLinkId& LinkString)
{
	return FString();
}
