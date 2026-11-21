// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortEventResponderComponent.generated.h"

enum class EEventResponderEventType : uint8;
enum class EMeshNetworkNodeType : uint8;

UENUM(BlueprintType)
enum class EEventResponderEventType : uint8
{
	// Event that is triggered in a "fire and forget" way

	OneShotEvent = 0,
	// Event that is triggered when a this event is previously active before this server or client has joined, active until "PersistentEventEnd" occurs

	PersistentEventJoinInProgress = 1,
	// Event that is triggered when starting a state that remains active until a "PersistentEventEnd" occurs

	PersistentEventStart = 2,
	// Event that is triggered when updating the parameters of a state that was made active by a "PersistentEventStart"

	PersistentEventChange = 3,
	// Event that is triggered when ending a state that was made active by a "PersistentEventStart"

	PersistentEventEnd = 4,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortEventResponderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FFortResponderHandleEventSignature, FGameplayTag, EventTag, bool, bPersistentOnOff, EEventResponderEventType, EventType, FString, EventParameters);

protected:
	UFUNCTION()
	FORTNITEGAME_API void OnMeshNetworkReady(EMeshNetworkNodeType NodeType);

	UPROPERTY(BlueprintAssignable)
	FFortResponderHandleEventSignature OnMeshNetEvent;

	UPROPERTY(EditAnywhere, Category="Mesh Network Event Responder | Data")
	TArray<FGameplayTag> MeshEventTags;

	UPROPERTY(EditAnywhere, Category="Mesh Network Event Responder | Data")
	FGameplayTagContainer FilteredEventTypes;

	UPROPERTY(EditDefaultsOnly, Category="Mesh Network Event Responder | Data")
	bool bServerRespondToEvents;

	UPROPERTY(EditDefaultsOnly, Category="Mesh Network Event Responder | Data")
	bool bClientRespondToEvents;

};

