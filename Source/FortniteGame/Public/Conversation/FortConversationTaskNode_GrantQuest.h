// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_GrantQuest.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortConversationTaskNode_GrantQuest : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	bool bShouldOverrideSpeakerText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	bool bShouldDisplayQuestProviderImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	bool bSharedQuestLimitsEnforced;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	bool bReplacingQuest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	bool bAssignQuestOwner;

};

