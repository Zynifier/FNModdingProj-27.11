// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Color.h"
#include "FortMissionTimerComponent.generated.h"

class AActor;
class UFortMissionTimerComponent;

UENUM(BlueprintType)
namespace ETimerOverrideSetting
{
	enum Type
	{
		DefaultBehavior = 0,
		ForceShow = 1,
		ForceHide = 2,
		ShowAtEnd = 3 UMETA(DisplayText="Do NOT set directly, use SetTimerVisibilityOverrideToShowAtEnd() to set"),
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMissionTimerComponentUpdated, UFortMissionTimerComponent*, TimerComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMissionTimerTimeAddedOrRemoved, UFortMissionTimerComponent*, TimerComponent, float, TimeAdded);

USTRUCT(BlueprintType)
struct FMissionTimeDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timer Display", meta=(ClampMin="1.0"))
	float LessThanTimeValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timer Display")
	bool bHideTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timer Display")
	FLinearColor BaseColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timer Display")
	FLinearColor PulseColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timer Display", meta=(ClampMin="0.0"))
	float ColorPulsesPerSecond;

};

USTRUCT()
struct FMissionTimerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bTimerIsPaused;

	UPROPERTY()
	float OriginalTimePeriod;

	UPROPERTY()
	float ReplicatedRemainingTime;

	UPROPERTY()
	float TimeAddedOrRemoved;

	UPROPERTY()
	float LastTimeAddedOrRemoved;

	UPROPERTY(NotReplicated)
	float ClientRemainingTime;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "Sockets", "Activation", "Component"), meta=(BlueprintSpawnableComponent))
class UFortMissionTimerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void AddOrRemoveTime(float TimeToAdd);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void ClearMissionTimer();

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	FMissionTimeDisplayData GetCorrectTimeDisplayData() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	float GetMissionTimerTimeElapsed() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	float GetMissionTimerTimeRemaining() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	float GetNormalizedTime() const;

	UFUNCTION(BlueprintPure, Category="Timer Component")
	FText GetTimerLabelText() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	FText GetTimeText() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	bool IsMissionTimerPaused() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	bool IsMissionTimerSet() const;

	UFUNCTION(BlueprintPure, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	bool IsTimerVisible() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void PauseMissionTimer();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void ResetMissionTimer();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void SetMissionTimeElapsedTimer();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void SetMissionTimer(const FString& FunctionName, float TimerLength, AActor* CallbackActor = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void SetTimerDisplayFormat(bool bNewDisplayInTimeFormat);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void SetTimerLabelText(FText NewLabelText);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void SetTimerVisibilityOverrideSetting(ETimerOverrideSetting::Type NewVisibilitySetting);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void SetTimerVisibilityOverrideToShowAtEnd(float ShowTime);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Timer Component", meta=(UnsafeDuringActorConstruction="true"))
	void UnpauseMissionTimer();

	UPROPERTY(EditDefaultsOnly, Category="Timer Display")
	uint8 bShowTimeElapsed : 1;

	UPROPERTY(EditDefaultsOnly, Category="Quests")
	uint8 bUpdateQuestsTimeElapsed : 1;

protected:
	UFUNCTION()
	void DummyTimer();

	UFUNCTION()
	void OnRep_TimerData();

	UFUNCTION()
	void OnRep_TimerVisibilityOverride();

	UPROPERTY(BlueprintAssignable, Category="MissionTimerComponent")
	FOnMissionTimerComponentUpdated OnMissionTimerComponentUpdated;

	UPROPERTY(BlueprintAssignable, Category="MissionTimerComponent")
	FOnMissionTimerTimeAddedOrRemoved OnMissionTimerTimeAddedOrRemoved;

	UPROPERTY(EditDefaultsOnly, Category="Timer Display")
	TArray<FMissionTimeDisplayData> DisplayData;

	UPROPERTY(ReplicatedUsing=OnRep_TimerData)
	FMissionTimerData TimerData;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Timer Display")
	FText TimerLabelText;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Timer Display")
	bool bDisplayInTimeFormat;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TimerVisibilityOverride, Category="Timer Display")
	TEnumAsByte<ETimerOverrideSetting::Type> TimerVisibilityOverrideSetting;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TimerVisibilityOverride, Category="Timer Display")
	float TimerVisibilityShowAtEndTime;

};

