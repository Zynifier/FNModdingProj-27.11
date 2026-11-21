// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayCueNotify_Looping.h"
#include "FortGameplayCueNotifyLoop_LowGravity.generated.h"

class AFortPawn;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Replication"), meta=(DisplayName="GCNL Low Gravity", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_LowGravity : public AFortGameplayCueNotify_Looping
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_LowGravity")
	float InterpDelta;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_LowGravity")
	float TargetDelta;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_LowGravity")
	TObjectPtr<AFortPawn> Pawn;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_LowGravity")
	float StartTime;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_LowGravity")
	float Duration;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_LowGravity")
	float ExpirationTellDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float TargetDelta_FallingRangeInput_Start;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float TargetDelta_FallingRangeInput_End;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float TargetDelta_FallingRangeOutput_Start;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float TargetDelta_FallingRangeOutput_End;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float InterpSpeedHigh;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float InterpSpeedLow;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float SoundMultiplier_RangeOutput_Start;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	float SoundMultiplier_RangeOutput_End;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	FName SoundParam_FallSpeed;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_LowGravity")
	FName SoundParam_FallSpeedInv;

};

