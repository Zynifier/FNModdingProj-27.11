// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortHUDElementWidget.h"
#include "RadialBacchusButtonBase.generated.h"

class AFortPawn;

UENUM(BlueprintType)
enum class ECooldownTrackingType : uint8
{
	Cue = 0,
	// Tracks a gameplay cue activate with magnitude duration

	AbilityCooldownTags = 1,
	// Tracks gameplay ability cooldown tags

	COUNT = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URadialBacchusButtonBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FGameplayTag GetListenedGameplayTag();

	UFUNCTION(BlueprintPure)
	float GetRemainingDuration() const;

	UFUNCTION(BlueprintPure)
	bool HasActiveCooldown() const;

	UFUNCTION(BlueprintCallable)
	void ReceiveRadialProgressEvent(FName EventName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UFUNCTION(BlueprintCallable)
	void SetListenedGameplayTag(FGameplayTag InListenedTag);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCooldownCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCooldownStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveRadialProgressEvent_Blueprint(FName EventName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UFUNCTION(BlueprintCallable)
	void StartUpdateCooldown();

	UFUNCTION(BlueprintCallable)
	void StopUpdateCooldown();

	UFUNCTION(BlueprintCallable)
	void UpdateCooldown();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDuration_Blueprint(float Remaining, float Duration);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RadialBacchusButtonBase")
	FGameplayTagContainer TrackedCooldownTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RadialBacchusButtonBase")
	ECooldownTrackingType TrackingType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadialBacchusButtonBase")
	float CooldownDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadialBacchusButtonBase")
	float CooldownStartTime;

private:
	UFUNCTION()
	void GameplayTagCallback(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION()
	void HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UFUNCTION()
	void OnPlayerPawnSet();

	UPROPERTY()
	TObjectPtr<AFortPawn> TrackedPawn;

};

