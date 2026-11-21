// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortCombatTypes.h"
#include "FortAnimNotifyState_AbilityDecisionWindow.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Object"), AutoExpandCategories=("Ability"), meta=(DisplayName="Decision Window", ShowHiddenSelfPins))
class UFortAnimNotifyState_AbilityDecisionWindow : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability")
	FFortMontageInputAction PrimaryInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability")
	FFortMontageInputAction SecondaryInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability")
	FName DefaultNextSection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Melee")
	float PrimaryInputStrikeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Melee")
	float SecondaryInputStrikeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Melee")
	int32 ComboCounter;

};

