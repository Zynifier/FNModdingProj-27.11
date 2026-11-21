// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbilityMod_Slope.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FSlopeModData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SlopeMod")
	TObjectPtr<UAnimMontage> MontageToPlay;

	UPROPERTY(EditAnywhere, Category="SlopeMod")
	FName MontageSectionName;

	UPROPERTY(EditAnywhere, Category="SlopeMod")
	float MinAngle;

	UPROPERTY(EditAnywhere, Category="SlopeMod")
	float MaxAngle;

};

UCLASS(BlueprintType)
class UFortGameplayAbilityMod_Slope : public UFortGameplayAbilityMod
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayAbilityMod_Slope")
	TArray<FSlopeModData> SlopeList;

};

