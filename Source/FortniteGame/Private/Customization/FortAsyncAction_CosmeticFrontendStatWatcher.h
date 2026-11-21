// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Stats/FortStatManagerTag.h"
#include "FortAsyncAction_CosmeticFrontendStatWatcher.generated.h"

class AActor;
class AFortPlayerController;
class UFortAsyncAction_CosmeticFrontendStatWatcher;
class UObject;

UCLASS()
class UFortAsyncAction_CosmeticFrontendStatWatcher : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWatchedStatChanged, FName, StatName, int32, StatValue);

public:
	UFUNCTION()
	void OnPawnEndPlay(AActor* Actor, EEndPlayReason::Type Reason);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="Owner", DisplayName="Watch Frontend Cosmetic Stat (DO NOT USE)", HidePin="Owner"))
	static UFortAsyncAction_CosmeticFrontendStatWatcher* WatchFrontendCosmeticStat(UObject* Owner, FFortStatManagerTag StatTag, bool bBroadcastInitialValue = true);

	UPROPERTY(BlueprintAssignable)
	FOnWatchedStatChanged OnStatChanged;

private:
	UFUNCTION()
	void BroadcastUpdate(const int32 ValueToBroadcast);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> OwningController;

};

