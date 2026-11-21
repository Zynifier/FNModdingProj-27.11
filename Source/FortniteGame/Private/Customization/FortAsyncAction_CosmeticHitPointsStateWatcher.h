// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_CosmeticHitPointsStateWatcher.generated.h"

class AActor;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UFortAsyncAction_CosmeticHitPointsStateWatcher;

UCLASS()
class UFortAsyncAction_CosmeticHitPointsStateWatcher : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnWatchedHitPointsChanged, float, Health, float, MaxHealth, float, Shield, float, MaxShield);

public:
	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_CosmeticHitPointsStateWatcher* WatchPawnHealth(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_CosmeticHitPointsStateWatcher* WatchPlayerHealth(AFortPlayerStateAthena* PlayerState);

	UPROPERTY(BlueprintAssignable)
	FOnWatchedHitPointsChanged OnHitPointsChanged;

private:
	UFUNCTION()
	void OnPlayerStateEndPlay(AActor* Actor, EEndPlayReason::Type Reason);

	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> MyPlayerState;

};

