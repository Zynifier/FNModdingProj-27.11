// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "AsyncAction_RegisterGameplayMessageReceiver.generated.h"

class AActor;
class UAsyncAction_RegisterGameplayMessageReceiver;
class UObject;
enum class EGameplayMessageMatchType : uint8;

// Proxy object pin will be hidden in K2Node_GameplayMessageAsyncAction. Is used to get a reference to the object triggering the delegate for the follow up call of 'GetPayload'.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncGameplayMessageDelegate, UAsyncAction_RegisterGameplayMessageReceiver*, ProxyObject);

UCLASS(BlueprintType, meta=(ExposedAsyncProxy="AsyncTask", HasDedicatedAsyncNode))
class GAMEPLAYMESSAGES_API UAsyncAction_RegisterGameplayMessageReceiver : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	* Attempt to copy the payload received from the broadcasted gameplay message into the specified wildcard.
	* The wildcard's type must match the type from the received message.
	* 
	* @param OutPayload		The wildcard reference the payload should be copied into
	* @return				If the copy was a success
	*/
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Messaging", meta=(CustomStructureParam="OutPayload"))
	bool GetPayload(UPARAM(ref) int32& OutPayload);
	DECLARE_FUNCTION(execGetPayload);

	/**
	* Asynchronously waits for a gameplay message to be broadcasted on the specified channel.
	* 
	* @param Channel			The message channel to listen for
	* @param MatchType			The rule used for matching the receiver's channel with the broadcasted channel
	* @param bTriggerForSaved	If a message has previously been saved to this channel, immediately trigger a MessageReceived event with this message
	* @param ActorContext		***Not functional yet*** Rather than every message being sent globally, it is possible to broadcast a message with an optional actor context. Only message receivers that have registered with the same actor's context will receive that message.
	*/
	UFUNCTION(BlueprintCallable, Category="Messaging", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UAsyncAction_RegisterGameplayMessageReceiver* RegisterGameplayMessageReceiver(UObject* WorldContextObject, FEventMessageTag Channel, UObject* PayloadType, EGameplayMessageMatchType MatchType = EGameplayMessageMatchType::ExactMatch, AActor* ActorContext = nullptr);

	/**
	 * Unregister this handler as a message receiver and mark it ready for destruction.
	 */
	UFUNCTION(BlueprintCallable, Category="Messaging")
	void Unregister();

	/** Called when a message is broadcast on the specified channel. Use GetPayload() to request the message payload. */
	UPROPERTY(BlueprintAssignable)
	FAsyncGameplayMessageDelegate OnMessageReceived;

	/** This pin will execute during receiver registration if the specified channel has existing state saved to it. */
	UPROPERTY(BlueprintAssignable)
	FAsyncGameplayMessageDelegate HandleSavedState;

	/** Called when saved state is manually cleared from the specified channel */
	UPROPERTY(BlueprintAssignable)
	FAsyncGameplayMessageDelegate HandleStateCleared;

};

