// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assets/AssetTypes.h"
#include "Net/UnrealNetwork.h"

void UVerseAssetPtr::OnRep_AssetPathName()
{
}

void UVerseAssetPtr::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseAssetPtr, AssetPathName);
}
