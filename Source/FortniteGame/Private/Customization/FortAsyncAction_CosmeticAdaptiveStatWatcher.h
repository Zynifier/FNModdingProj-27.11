// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Stats/FortStatManagerTag.h"
#include "FortAsyncAction_CosmeticAdaptiveStatWatcher.generated.h"

class AActor;
class AFortPlayerPawn;
class UFortAsyncAction_CosmeticAdaptiveStatWatcher;
class UObject;

UCLASS()
class UFortAsyncAction_CosmeticAdaptiveStatWatcher : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWatchedStatChanged, FName, StatName, int32, StatValue);

public:
	UFUNCTION()
	void OnPawnEndPlay(AActor* Actor, EEndPlayReason::Type Reason);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AdvancedDisplay="InitialValueBroadcastDelay,ChangeValueBroadcastDelay,bConsumeWaitingNotifications", BlueprintInternalUseOnly="true", DefaultToSelf="Owner", HidePin="Owner"))
	static UFortAsyncAction_CosmeticAdaptiveStatWatcher* WatchCosmeticStat(UObject* Owner, AFortPlayerPawn* Pawn, FFortStatManagerTag StatTag, int32 DefaultValue, bool bBroadcastInitialValue = true, float InitialValueBroadcastDelay = -1.000000f, float ChangeValueBroadcastDelay = -1.000000f, bool bConsumeWaitingNotifications = true);

	UPROPERTY(BlueprintAssignable)
	FOnWatchedStatChanged OnStatChanged;

private:
	UFUNCTION()
	void BroadcastUpdate(const int32 ValueToBroadcast);

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> MyPawn;

};

