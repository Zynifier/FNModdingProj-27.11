// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortInitializationInterface.h"
#include "FortMissionState.generated.h"

class AFortMissionState;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMissionUIEvent, AFortMissionState*, MissionState, const FGameplayTagContainer&, EventTags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateUI, AFortMissionState*, MissionState);

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering"), meta=(ProhibitedInterfaces="UFortMissionInterface"))
class AFortMissionState : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnAllPlayersLoadedInWrapper();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions")
	void OnMatchStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions")
	void OnWorldReady();

	UFUNCTION(BlueprintCallable, Category="Mission")
	void SendMissionUIEvent(const FGameplayTagContainer& EventTags);

	UFUNCTION(BlueprintCallable, Category="Mission")
	virtual void UpdateUI();

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnUpdateUI OnUpdateUI;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnMissionUIEvent OnMissionUIEvent;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Mission")
	void OnAllPlayersLoadedIn();

	UFUNCTION(BlueprintCallable, Category="Mission")
	void SetTimerForOnAllPlayersLoadedIn(float Timer);

private:
	UPROPERTY(Transient)
	bool bAlreadySetTimerOnce;

	UPROPERTY(Transient)
	bool bAlreadyCalledOnAllPlayersLoadedIn;

	UPROPERTY(Transient)
	float TimerForOnAllPlayersLoadedIn;

};

