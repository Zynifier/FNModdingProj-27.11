// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Movement/FortMovementComp_Character.h"
#include "FortMovementComp_CharacterAthena.generated.h"

USTRUCT(BlueprintType)
struct FAthenaJumpPenalty
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaJumpPenalty", meta=(ClampMin="0", UIMin="0"))
	float JumpScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaJumpPenalty", meta=(ClampMin="0", UIMin="0"))
	float MovementScalar;

};

UCLASS(MinimalAPI)
class UFortMovementComp_CharacterAthena : public UFortMovementComp_Character
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaJump")
	TArray<FAthenaJumpPenalty> JumpPenalties;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaJump")
	float JumpPenaltyResetTime;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	int32 NetworkSkipSkyDivingCollisionForPawnLOD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement (General Settings)", meta=(ClampMin="0", UIMin="0"))
	float MaxAccelerationFlying;

};

UCLASS()
class UFortMovementComp_CharacterAthena_Ostrich : public UFortMovementComp_CharacterAthena
{
	GENERATED_BODY()

};

