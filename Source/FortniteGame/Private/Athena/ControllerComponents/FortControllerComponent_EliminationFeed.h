// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortControllerComponent_EliminationFeed.generated.h"

class AFortCreativeDeviceProp;
class AFortMinigame;
class AFortPlayerController;
class AFortPlayerState;
class APlayerState;
class UFortControllerComponent_EliminationFeed;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEliminationFeedMessageReceivedDelegate, const AFortCreativeDeviceProp*, EliminationFeedDevice, const AFortPlayerState*, PlayerState);

USTRUCT()
struct FEliminationFeedMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortCreativeDeviceProp> EliminationFeedDevice;

	UPROPERTY()
	TObjectPtr<AFortPlayerState> PlayerStateMessage;

};

USTRUCT()
struct FEliminationFeedMessageRepl : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MessageIndex;

	UPROPERTY()
	TObjectPtr<AFortCreativeDeviceProp> EliminationFeedDevice;

	UPROPERTY()
	TObjectPtr<AFortPlayerState> PlayerStateMessage;

};

USTRUCT()
struct FEliminationFeedMessageRingBuffer : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FEliminationFeedMessageRepl> Items;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortControllerComponent_EliminationFeed : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Elimination Feed")
	static UFortControllerComponent_EliminationFeed* GetEliminationFeedComponentFromPlayerController(AFortPlayerController* PC, bool bCreateIfNotFound);

	UFUNCTION(BlueprintPure, Category="Elimination Feed")
	static void GetMinigamePlayersForEliminationFeed(const AFortMinigame* FortMinigame, TArray<APlayerState*>& OutPlayers);

	UFUNCTION(BlueprintCallable, Category="Elimination Feed")
	void Reset();

	UPROPERTY(BlueprintAssignable)
	FEliminationFeedMessageReceivedDelegate OnEliminationFeedMessageRecieved;

protected:
	UFUNCTION(BlueprintCallable, Category="Elimination Feed")
	void AddMessageToQueue(const AFortCreativeDeviceProp* EliminationFeedDevice, const AFortPlayerState* PlayerStateMessage);

private:
	UFUNCTION()
	void OnRep_EliminationFeedMessageBatch();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EliminationFeedMessageBatch)
	FEliminationFeedMessageRingBuffer EliminationFeedMessageBatch;

};

