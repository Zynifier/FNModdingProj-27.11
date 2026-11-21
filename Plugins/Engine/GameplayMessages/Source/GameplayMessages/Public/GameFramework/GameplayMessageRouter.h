// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "GameplayMessageRouter.generated.h"

class AActor;
class AGameplayMessageReplicator;
class UGameplayMessageRouter;

/** 
 * Entry information for a single registered receiver
 */
USTRUCT()
struct FGameplayMessageReceiverData
{
	GENERATED_BODY()

};

/**
 * An opaque handle that can be used to remove a previously registered message receiver
 * @see UGameplayMessageRouter::RegisterReceiver and UGameplayMessageRouter::UnregisterReceiver
 */
USTRUCT(BlueprintType)
struct GAMEPLAYMESSAGES_API FGameplayMessageReceiverHandle
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UGameplayMessageRouter> Subsystem;

	UPROPERTY(Transient)
	FEventMessageTag Channel;

	UPROPERTY(Transient)
	int32 ID;

};

/**
 * This system allows event raisers and receivers to register for messages without
 * having to know about each other directly, though they must agree on the format
 * of the message (as a USTRUCT() type).
 *
 * You can get to the message router from the game instance:
 *    UGameInstance::GetSubsystem<UGameplayMessageRouter>(GameInstance)
 * or directly from anything that has a route to a world:
 *    UGameplayMessageRouter::Get(WorldContextObject)
 *
 * Note that call order when there are multiple receivers for the same channel is
 * not guaranteed and can change over time!
 */// NOTE: The GameplayMessageRouter is deprecated, you should use the GameplayEventRouter instead

UCLASS()
class GAMEPLAYMESSAGES_API UGameplayMessageRouter : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * Clear the message saved to a channel if there is one
	 *
	 * @param Channel	The message channel to clear of its saved message
	 */
	UFUNCTION(BlueprintCallable, Category="Messaging")
	void ClearSavedMessage(FEventMessageTag Channel);

	/**
	 * Returns whether there is a valid saved message for the specified channel or not
	 *
	 * @param Channel	The message channel to check for a saved message
	 * 
	 * @return Whether or not there is a valid saved message for the specified channel
	 */
	UFUNCTION(BlueprintPure, Category="Messaging")
	bool HasValidSavedMessage(FEventMessageTag Channel) const;

protected:
	/**
	 * Broadcast a message on the specified channel
	 *
	 * @param Channel			The message channel to broadcast on
	 * @param Message			The message to send (must be the same type of UScriptStruct expected by the receivers for this channel, otherwise an error will be logged)
	 * @param bReplicate		Should this message be replicated from the server to the client
	 * @param bSaveToChannel	Should this message be saved to the channel so it can be queried in the future
	 * @param ActorContext		***Not functional yet*** Rather than broadcasting every message globally, you can optionally specify an actor context. Only message receivers that have registered with this actor's context will receive this message.
	 */
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Messaging", meta=(AllowAbstract="false", CustomStructureParam="Message", DisplayName="Broadcast Message"))
	void K2_BroadcastMessage(FEventMessageTag Channel, const int32& Message, bool bSaveToChannel = false, AActor* ActorContext = nullptr);
	DECLARE_FUNCTION(execK2_BroadcastMessage);

private:
	UPROPERTY(Transient)
	TObjectPtr<AGameplayMessageReplicator> MessageReplicator;

};

