// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_PlayConversation.generated.h"

class AFortPawn;
class UFortAsyncAction_PlayConversation;
class UFortConversation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortConversationDelegate);

UCLASS()
class UFortAsyncAction_PlayConversation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Conversation", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_PlayConversation* PlayConversation(AFortPawn* Pawn, UFortConversation* ConversationToPlay);

	UPROPERTY(BlueprintAssignable)
	FFortConversationDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FFortConversationDelegate OnCanceled;

	UPROPERTY(BlueprintAssignable)
	FFortConversationDelegate OnFailure;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPawn> PawnWeak;

	UPROPERTY(Transient)
	TObjectPtr<UFortConversation> ConversationToPlay;

};

