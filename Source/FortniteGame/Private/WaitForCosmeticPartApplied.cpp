// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaitForCosmeticPartApplied.h"

void UWaitForCosmeticPartApplied::PartApplied(AFortPlayerPawn* Pawn, const UCustomCharacterPart* Part, USkeletalMeshComponent* MeshPart, const EFortCustomPartType::Type PartType)
{
}

UWaitForCosmeticPartApplied* UWaitForCosmeticPartApplied::WaitForCosmeticPartApplied(const UObject* WorldContextObject, AFortPlayerPawn* FortPlayerPawn, bool bSkipNullMesh, const TArray<UObject*>& AnyObjects, const TArray<FString>& AnyStrings)
{
	return nullptr;
}

UWaitForCosmeticPartApplied* UWaitForCosmeticPartApplied::WaitForCosmeticSpecificPartApplied(const UObject* WorldContextObject, AFortPlayerPawn* FortPlayerPawn, bool bSkipNullMesh, EFortCustomPartType::Type PartType, const TArray<UObject*>& AnyObjects, const TArray<FString>& AnyStrings)
{
	return nullptr;
}
