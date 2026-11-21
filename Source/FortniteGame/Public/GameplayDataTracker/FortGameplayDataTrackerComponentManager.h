// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "GameplayTagContainer.h"
#include "FortGameplayDataTrackerComponentManager.generated.h"

class AActor;
class UFortGameplayDataTrackerComponent;
class UFortGameplayDataTrackerComponentManager;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortDataTrackerComponentRegistered, UFortGameplayDataTrackerComponent*, RegisteredDataTracker);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortDataTrackerComponentUnRegistered, UFortGameplayDataTrackerComponent*, UnRegisteredDataTracker);

USTRUCT()
struct FFortGameplayDataTrackerRegisteredActorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag CurrentStateTag;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameplayDataTrackerComponentManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameplayDataTrackerComponentManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="FortGameplayDataTrackerComponent", meta=(DisplayName="Get Fort Gameplay Data Tracker Component Manager", WorldContext="WorldContextObject"))
	static UFortGameplayDataTrackerComponentManager* GetCurrent(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable)
	void GetRegisteredDataTrackerComponents(TArray<UFortGameplayDataTrackerComponent*>& OutDataTrackerComponents);

	UFUNCTION(BlueprintCallable)
	void RegisterTrackedStateActor(AActor* Actor, const FGameplayTag& InitialState);

	UFUNCTION(BlueprintCallable)
	void SetTrackedActorState(AActor* Actor, const FGameplayTag& CurrentState);

	UFUNCTION(BlueprintCallable)
	void UnRegisterTrackedStateActor(AActor* Actor);

protected:
	UFUNCTION()
	void OnTrackedActorDestroyed(AActor* DestroyedActor);

	UPROPERTY(BlueprintAssignable)
	FFortDataTrackerComponentRegistered OnDataTrackerComponentRegistered;

	UPROPERTY(BlueprintAssignable)
	FFortDataTrackerComponentUnRegistered OnDataTrackerComponentUnRegistered;

};

