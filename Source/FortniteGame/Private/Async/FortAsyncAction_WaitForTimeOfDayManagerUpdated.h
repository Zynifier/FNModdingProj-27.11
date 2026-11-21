// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortTimeOfDayManagerInterface.h"
#include "FortAsyncAction_WaitForTimeOfDayManagerUpdated.generated.h"

class AActor;
class UFortAsyncAction_WaitForTimeOfDayManagerUpdated;
class UObject;
enum class EFortWaitForTimeOfDayManagerUpdatedBehavior : uint8;

UENUM()
enum class EFortWaitForTimeOfDayManagerUpdatedBehavior : uint8
{
	// Wait for local TODM if the OwningContextObject is a minigame or a gameplay volume, otherwise will wait for global TODM

	ContextAware = 0,
	// Waits for global TODM only

	GlobalOnly = 1,
	// Waits for local TODM only, but requires the OwningContextObject to be a minigame or a gameplay volume

	LocalOnly = 2,
};

UCLASS(BlueprintType, meta=(ExposedAsyncProxy="AsyncTask"))
class UFortAsyncAction_WaitForTimeOfDayManagerUpdated : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EndTask();

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningContextObject"))
	static UFortAsyncAction_WaitForTimeOfDayManagerUpdated* WaitForTimeOfDayManagerUpdated(UObject* OwningContextObject, EFortWaitForTimeOfDayManagerUpdatedBehavior Behavior = EFortWaitForTimeOfDayManagerUpdatedBehavior::ContextAware);

private:
	UFUNCTION()
	void HandleOwningActorDeath(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnTimeOfDayManagerUpdated OnUpdated;

};

