// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "Pawns/FortPawnTypes.h"
#include "FortPlayerDebugAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortPlayerDebugAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	EFortSynchedActionEndMovementMode SynchedActionEndMovementMode_Debug;

	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomMovement::Type> CustomMovementMode_Debug;

	UPROPERTY(Transient)
	TEnumAsByte<EMovementMode> MovementMode_Debug;

	UPROPERTY(Transient)
	uint8 bIsSynchedActionCompleted_Debug : 1;

	UPROPERTY(Transient)
	uint8 bIsOnGround_Debug : 1;

	UPROPERTY(Transient)
	uint8 bIsFalling_Debug : 1;

	UPROPERTY(Transient)
	FVector PawnPosition_Debug;

	UPROPERTY(Transient)
	FRotator PawnRotation_Debug;

	UPROPERTY(Transient)
	FRotator ControllerRotation_Debug;

	UPROPERTY(Transient)
	float YawRotationDelta_Debug;

	UPROPERTY(Transient)
	uint8 bRotationChangedSide_Debug : 1;

	UPROPERTY(Transient)
	TArray<FString> LinkedGraphComponent_Debug;

	UPROPERTY(Transient)
	bool bHasRootMotionSource;

};

