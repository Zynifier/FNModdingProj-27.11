// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoneMaskTypes.h"

void UBoneMaskFunctionLibrary::BP_BoneMask_GetBodyPartWeights(const FBoneMask& BoneMask, FName Name, float& LocalSpaceWeight, float& MeshSpaceWeight)
{
}

void UBoneMaskFunctionLibrary::BP_BoneMask_UpdateBodyPartLocalSpaceWeight(FBoneMask& BoneMask, FName Name, float LocalSpaceWeight)
{
}

void UBoneMaskFunctionLibrary::BP_BoneMask_UpdateBodyPartMeshSpaceWeight(FBoneMask& BoneMask, FName Name, float MeshSpaceWeight)
{
}

void UBoneMaskFunctionLibrary::BP_BoneMask_UpdateBodyPartWeights(FBoneMask& BoneMask, FName Name, float LocalSpaceWeight, float MeshSpaceWeight)
{
}

void UBoneMaskFunctionLibrary::BP_BoneMask_UpdateBodyPartWeightsMulti(FBoneMask& BoneMask, const TArray<FBoneMaskUpdateMultiParam>& Params)
{
}
