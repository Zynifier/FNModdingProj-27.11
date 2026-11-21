// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_HireNPC.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisplayName="Hire NPC"))
class UFortConversationTaskNode_HireNPC : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Selling")
	bool bHidePriceWhenFree;

	UPROPERTY(EditDefaultsOnly, Category="Hire")
	bool bAllowDismissAndHireWhenAtMax;

	UPROPERTY(EditDefaultsOnly, Category="Hire")
	bool bIsRehiringFree;

};

