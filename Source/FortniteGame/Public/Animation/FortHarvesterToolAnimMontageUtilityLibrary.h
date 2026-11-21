// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortHarvesterToolAnimMontageUtilityLibrary.generated.h"

class UAnimMontage;
class UAnimSequence;

UCLASS(BlueprintType)
class UFortHarvesterSwingAnimMontageUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	static UAnimMontage* CreateHarvesterMontage(const UAnimSequence* SourceAnimation, const FString& Path, const FString& Name);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	static FString GetComboName(const UAnimSequence* AnimSequence);
#endif

};

