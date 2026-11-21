// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortPlayerStartupController.generated.h"

class AFortPlayerControllerZone;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAllInCountdownInitiated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerStartupControllerCreated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerStartupControllerDestroyed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerStartupControllerRegistered);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerStartupControllerReset);

UCLASS(Config=Game, BlueprintType, Blueprintable)
class AFortPlayerStartupController : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Holding Area Info")
	void DropContainmentTimeToAllInCountdownTime();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Holding Area Info")
	float GetContainmentTimeRemaining();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Holding Area Info")
	int32 GetNumPlayersCurrentlyReady();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Holding Area Info")
	int32 GetNumPlayersExpected();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Holding Area Info")
	int32 GetNumPlayersStillWaitingFor();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void HandleAllInCountdownInitiated();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void HandlePlayerStartupControllerCreated();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void HandlePlayerStartupControllerDestroyed();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void HandlePlayerStartupControllerRegistered();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void HandlePlayerStartupControllerReset();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnAllPlayersLoadedIn_BP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnPlayerLoadedIn_BP(AFortPlayerControllerZone* NewPlayerPC);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Holding Area Info")
	bool UseIndividualHoldingAreas;

	UPROPERTY(BlueprintReadOnly, Config, Category="Holding Area Info")
	float DelayAfterFirstInTime;

	UPROPERTY(Transient, Replicated)
	float ContainmentTimer;

	UPROPERTY(BlueprintReadOnly, Config, Category="Holding Area Info")
	float AllInCountdownTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Holding Area Info", meta=(ClampMax="5.0", ClampMin="2.0"))
	float ErodeShieldTime;

	UPROPERTY(BlueprintReadOnly, Config, Category="Holding Area Info")
	float StopJoinabilityTime;

	UPROPERTY(BlueprintReadOnly, Config, Category="Holding Area Info")
	bool DestroyImmediately;

	UPROPERTY(BlueprintAssignable, Category="Holding Area Info")
	FPlayerStartupControllerCreated OnPlayerStartupControllerCreated;

	UPROPERTY(BlueprintAssignable, Category="Holding Area Info")
	FPlayerStartupControllerRegistered OnPlayerStartupControllerRegistered;

	UPROPERTY(BlueprintAssignable, Category="Holding Area Info")
	FAllInCountdownInitiated OnAllInCountdownInitiated;

	UPROPERTY(BlueprintAssignable, Category="Holding Area Info")
	FPlayerStartupControllerDestroyed OnPlayerStartupControllerDestroyed;

	UPROPERTY(BlueprintAssignable, Category="Holding Area Info")
	FPlayerStartupControllerDestroyed OnResetContainmentTimer;

};

