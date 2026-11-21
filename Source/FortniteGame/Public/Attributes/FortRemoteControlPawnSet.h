// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortRemoteControlPawnSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortRemoteControlPawnSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData FuseLength;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData MouseTurnCap;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData MouseTurnRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData MouseTurnRateMax;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData GyroTurnRateMax;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData KeyboardTurnRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData ControllerTurnRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData TouchTurnRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData MaxSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData MaxAcceleration;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData UseLaunchDelay;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData LaunchDelay;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData LaunchSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData OutOfHealthExplodeDelay;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="RemoteControlPawn", meta=(HideFromModifiers))
	FFortGameplayAttributeData PlayerCanDetonate;

};

