// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "Subsystems/WorldSubsystem.h"
#include "Quests/Processors/EventObjectiveTypes.h"
#include "ObjectiveProcessorSubsystem.generated.h"

class UFilteredEventContextCollectorBase;
class UObject;
class UObjectiveProcessorBase;

UCLASS(MinimalAPI)
class UObjectiveProcessorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnBlueprintFilteredEventSuccessEvent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFilteredEventSuccessEvent);

public:
	UFUNCTION(BlueprintCallable, Category="Event Processor Subsystem", meta=(DefaultToSelf="EventManager", DisplayName="Start Listening To Filtered Event", WorldContext="WorldContextObject"))
	static FFilteredEventReceiverHandle BP_StartListeningToFilteredEvent(const UObject* WorldContextObject, const UObject* EventManager, const UObject* EventParticipant, const FInstancedStruct& VerbFilter, const bool bStopListeningOnSuccess, UPARAM(DisplayName="Event") FOnBlueprintFilteredEventSuccessEvent DelegateSignature);

	UFUNCTION(BlueprintCallable, Category="Event Processor Subsystem", meta=(DisplayName="Stop Listening To Filtered Event", WorldContext="WorldContextObject"))
	static void BP_StopListeningToFilteredEvent(const UObject* WorldContextObject, UPARAM(ref) FFilteredEventReceiverHandle& EventHandle);

private:
	UPROPERTY(Transient)
	TMap<UClass*, TObjectPtr<UObjectiveProcessorBase>> RegisteredProcessorsByType;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFilteredEventContextCollectorBase>> RegisteredCollectors;

};

