// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EpicHardSurfaceQCRuntimeFunctions.generated.h"

UCLASS(meta=(ScriptName="EpicHardSurfaceQCRuntimeFunctions"))
class EPICHARDSURFACEQCRUNTIME_API UEpicHardSurfaceQCRuntimeFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="EpicHardSurfaceQCRuntimeFunctions")
	static bool SaveIndexToJson(const FString& WeaponName, const FString& WeaponIconSmall, TArray<FString> WeaponSkeletalMeshes, TArray<FString> WeaponAnimSequencesEquip, TArray<FString> WeaponAnimSequencesReload, TArray<FString> WeaponAnimSequencesFire, TArray<FString> WeaponAnimSequencesFireDownSights, const FString& CharacterName, const FString& CharacterIconSmall, TArray<FString> CharacterSkeletalMeshes, TArray<FString> CharacterAnimSequencesEquip, TArray<FString> CharacterAnimSequencesReload, TArray<FString> CharacterAnimSequencesFire, TArray<FString> CharacterAnimSequencesFireDownSights, const FString& Path);

};

