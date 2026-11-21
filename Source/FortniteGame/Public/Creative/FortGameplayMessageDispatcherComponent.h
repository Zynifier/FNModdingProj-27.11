// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Building/SpatialGameplay/SpatialLoadingStateContext.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortGameplayMessageDispatcherComponent.generated.h"

class AController;
class UFortGameplayReceiverMessageComponent;
class UFortGameplayTriggerMessageComponent;

USTRUCT()
struct FFortGameplayMessageReceiverList
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortGameplayMessageTriggerList
{
	GENERATED_BODY()

public:
	UPROPERTY(Export)
	TArray<TWeakObjectPtr<UFortGameplayTriggerMessageComponent>> Triggers;

};

USTRUCT()
struct FFortMessageChannelInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortPendingReceiverReg
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer ChannelIds;

};

USTRUCT()
struct FFortTriggeredGameplayMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameplayTriggerMessageComponent> Sender;

	UPROPERTY()
	FGameplayTag ChannelId;

	UPROPERTY()
	TWeakObjectPtr<AController> TriggerInstigator;

};

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortGameplayMessageDispatcherComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnVolumeStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext);

	UPROPERTY()
	int32 NumBoundReceivers;

	UPROPERTY()
	TMap<FGameplayTag, FFortGameplayMessageReceiverList> ReceiverChannelList;

	UPROPERTY()
	int32 NumBoundTriggers;

	UPROPERTY()
	TMap<FGameplayTag, FFortGameplayMessageTriggerList> TriggersChannelList;

	UPROPERTY()
	TArray<FFortTriggeredGameplayMessage> EnqueuedMessages;

	UPROPERTY()
	FFortTriggeredGameplayMessage ActiveMessage;

	UPROPERTY()
	FFortGameplayMessageReceiverList ActiveMessageReceivers;

	UPROPERTY(Export)
	TSet<TWeakObjectPtr<UFortGameplayReceiverMessageComponent>> KnownReceivers;

};

