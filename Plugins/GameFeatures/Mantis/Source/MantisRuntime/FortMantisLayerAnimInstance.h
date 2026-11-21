// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortMantisTypes.h"
#include "FortMantisLayerAnimInstance.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortMantisLayerAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Mantis")
	MANTISRUNTIME_API void OnMantisTechniqueEnded(const int32 TechniqueIndex, const FName TechniqueName);

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis")
	MANTISRUNTIME_API void OnMantisTechniqueStarted(const int32 TechniqueIndex, const FName TechniqueName);

	UPROPERTY(BlueprintReadOnly, Category="Mantis")
	FFortMantisReplicatedAnimInstanceInfo MantisAnimInstanceInfo;

};

