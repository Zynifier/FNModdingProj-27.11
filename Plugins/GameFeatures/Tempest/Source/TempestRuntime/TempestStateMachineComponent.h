// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "ScalableFloat.h"
#include "TempestStateMachineComponent.generated.h"

enum class ETempestState : uint8;

UENUM(BlueprintType)
enum class ETempestState : uint8
{
	Unformed = 0,
	Forming = 1,
	Active = 2,
	Dissipating = 3,
	Complete = 4,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTempestStateInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="TempestStateInfo")
	ETempestState CurrentState;

	UPROPERTY(BlueprintReadOnly, Category="TempestStateInfo")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="TempestStateInfo")
	float EndTime;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTempestStateChangedSignature, const FTempestStateInfo, TempestStateInfo);

USTRUCT()
struct FTempestStateChangeTimerInfo
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Tempest"), meta=(BlueprintSpawnableComponent))
class TEMPESTRUNTIME_API UTempestStateMachineComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UTempestStateMachineComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ForceDissipate(const FString& InDissipationReason);

	UFUNCTION(BlueprintPure)
	ETempestState GetCurrentState() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentStateCompletionPercentage() const;

	UFUNCTION(BlueprintPure)
	FTempestStateInfo GetCurrentStateInfo() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="TempestStateMachineComponent")
	bool bDestroyOnCompletion;

	UPROPERTY(EditDefaultsOnly, Category="TempestStateMachineComponent")
	FScalableFloat FormationDuration;

	UPROPERTY(EditDefaultsOnly, Category="TempestStateMachineComponent")
	FScalableFloat ActiveDuration;

	UPROPERTY(EditDefaultsOnly, Category="TempestStateMachineComponent")
	FScalableFloat DissipationDuration;

private:
	UFUNCTION()
	void OnRep_CurrentStateInfo();

	UPROPERTY(ReplicatedUsing=OnRep_CurrentStateInfo)
	FTempestStateInfo CurrentStateInfo;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="true"))
	FOnTempestStateChangedSignature OnTempestStateChangedDelegate;

};

