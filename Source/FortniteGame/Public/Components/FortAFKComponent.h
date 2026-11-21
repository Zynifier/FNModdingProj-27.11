// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "FortAFKComponent.generated.h"

USTRUCT()
struct FAFKCharacterMovementData
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortAFKComponent : public UPlayerStateComponent
{
	GENERATED_BODY()

public:
	UFortAFKComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION()
	void OnRep_bIsAFKWarningActive();

	UFUNCTION()
	void OnRep_bIsConfirmedAFK();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsAFKWarningActive)
	bool bIsAFKWarningActive;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsConfirmedAFK)
	bool bIsConfirmedAFK;

	UPROPERTY(Transient, Replicated)
	int32 NumTimesPlayerWentAFK;

};

