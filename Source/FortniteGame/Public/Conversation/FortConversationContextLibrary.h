// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationContext.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortConversationContextLibrary.generated.h"

class AActor;
class AFortPlayerController;
class UConversationParticipantComponent;
class UConversationTaskNode;
class UFortControllerComponent_ConversationHistory;

UCLASS(MinimalAPI)
class UFortConversationContextLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UFortControllerComponent_ConversationHistory* GetConversationHistoryComponentPlayer(const FConversationContext& Context);

	UFUNCTION(BlueprintCallable)
	static AActor* GetParticipantActorNPC(const FConversationContext& Context);

	UFUNCTION(BlueprintCallable)
	static AActor* GetParticipantActorPlayer(const FConversationContext& Context);

	UFUNCTION(BlueprintCallable)
	static UConversationParticipantComponent* GetParticipantComponentNPC(const FConversationContext& Context);

	UFUNCTION(BlueprintCallable)
	static UConversationParticipantComponent* GetParticipantComponentPlayer(const FConversationContext& Context);

	UFUNCTION(BlueprintCallable)
	static AFortPlayerController* GetParticipantPlayerController(const FConversationContext& Context);

	UFUNCTION(BlueprintCallable)
	static const UConversationTaskNode* GetTaskBeingConsidered(const FConversationContext& Context);

};

