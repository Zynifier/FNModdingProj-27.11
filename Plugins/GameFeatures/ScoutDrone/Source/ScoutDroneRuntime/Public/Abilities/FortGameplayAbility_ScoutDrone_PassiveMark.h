// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Abilities/FortGameplayAbility_ScoutDrone_TargetingBase.h"
#include "Components/FortControllerComponent_IndicatedActorManagement.h"
#include "FortGameplayAbility_ScoutDrone_PassiveMark.generated.h"

class AActor;
class UScoutDronePassiveMarkPayload;

UENUM(BlueprintType)
enum class EFortScoutDroneTargetStatus : uint8
{
	None = 0,
	// No target

	TooFar = 1,
	// Out of range, but enough range for UI warning

	Pending = 2,
	// It's in range but we have to wait to confirm target

	Confirmed = 3,
};

USTRUCT(BlueprintType)
struct FScoutDroneStatusData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="ScoutDroneStatusData")
	EFortScoutDroneTargetStatus Status;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ScoutDroneStatusData")
	float ServerTimeStatusChanged;

};

UCLASS(MinimalAPI)
class UFortGameplayAbility_ScoutDrone_PassiveMark : public UFortGameplayAbility_ScoutDrone_TargetingBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, meta=(DisplayName="OnTargetStatusChanged"))
	void BP_OnTargetStatusChanged(AActor* ActiveTarget);

	UFUNCTION()
	void OnRep_CurrentTargetStatus();

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentTargetStatus, Category="FortGameplayAbility_ScoutDrone_PassiveMark")
	FScoutDroneStatusData CurrentTargetStatus;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Drone Indicators")
	FStenciledActorData StenciledActorData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Drone Indicators")
	FIndicatedActorData IndicatedActorData;

private:
	UFUNCTION()
	void OnActorIndicatorExpired(AActor* IndicatedActor);

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FScalableFloat ActorTargetingRange;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FScalableFloat TimeToConfirmTarget;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentTarget;

	UPROPERTY(Transient)
	FTimerHandle TargetConfirmationTimerHandle;

	UPROPERTY(Transient)
	TObjectPtr<UScoutDronePassiveMarkPayload> PayloadCache;

};

UCLASS(BlueprintType)
class SCOUTDRONERUNTIME_API UScoutDronePassiveMarkPayload : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ScoutDronePassiveMarkPayload")
	FScoutDroneStatusData TargetStatus;

};

