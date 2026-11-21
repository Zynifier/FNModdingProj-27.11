// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_DuelNPC.generated.h"

class UGameplayAbility;

UCLASS(Abstract, meta=(DisplayName="Duel NPC"))
class UFortConversationTaskNode_DuelNPC : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Abilities")
	TSoftClassPtr<UGameplayAbility> DuelObserverAbility;

	UPROPERTY(EditDefaultsOnly, Category="Knock Back")
	bool bEnableKnockBack;

};

