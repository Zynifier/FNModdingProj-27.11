// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationContext.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_ConversationHistory.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_ConversationHistory : public UFortControllerComponent
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortConversationHistoryLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Conversation")
	static void RecordConversationEventWithParticipant(const FConversationContext& Context, const FGameplayTag& EventType);

};

