// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/HeadPartAnimInstance.h"
#include "CCP_AnimInstance_Head_GameplayFaceSystemStateMachine.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Head_GameplayFaceSystemStateMachine : public UHeadPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay Face System|Settings")
	float MaxWalkSpeed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System")
	float Player_YawDeltaSmoothed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System")
	bool bIsCurrentlyShooting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System")
	bool bIsUsingWeapon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System")
	bool bIsReloading;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System|Rule Flags")
	bool bIsNotTargetingAndIsNotCurrentlyShooting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System|Rule Flags")
	bool bIsSlidingOrIsSlopeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System|Rule Flags")
	bool bIsNeitherSlidingNorSlopeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System|Rule Flags")
	bool bFastAndNotInVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay Face System|Rule Flags")
	bool bNotFastAndNotInVehcile;

};

