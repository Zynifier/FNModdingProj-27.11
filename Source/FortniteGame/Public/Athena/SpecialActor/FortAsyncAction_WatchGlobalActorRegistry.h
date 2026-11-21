// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_WatchGlobalActorRegistry.generated.h"

class AActor;
class UFortAsyncAction_WatchGlobalActorRegistry;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorRegisteryEventAsyncDelegate, AActor*, Actor);

UCLASS()
class UFortAsyncAction_WatchGlobalActorRegistry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_WatchGlobalActorRegistry* WatchGlobalActorRegistryWithTag(UObject* WorldContextObject, const FGameplayTag& TagToWatch, bool bOnlyWatchForFirstRegistration);

	UPROPERTY(BlueprintAssignable)
	FOnActorRegisteryEventAsyncDelegate OnActorRegistered;

	UPROPERTY(BlueprintAssignable)
	FOnActorRegisteryEventAsyncDelegate OnActorUnregistered;

private:
	UFUNCTION()
	void HandleActorRegisteredWithTag(const FGameplayTag& Tag, AActor* Actor);

	UFUNCTION()
	void HandleActorUnregisteredWithTag(const FGameplayTag& Tag, AActor* Actor);

};

