// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationChoiceNode.h"
#include "GameplayTagContainer.h"
#include "FortConversationChoiceWithPreviewNode.generated.h"

UCLASS(meta=(DisplayName="Previewing Choice"))
class UFortConversationChoiceWithPreviewNode : public UConversationChoiceNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationChoiceWithPreviewNode")
	bool bShowPreviewOnlyIfChildTaskNodeValid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationChoiceWithPreviewNode", meta=(editCondition="!bShowPreviewOnlyIfChildTaskNodeValid"))
	bool bShowPreviewOnlyIfAnyChildTaskNodeValid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationChoiceWithPreviewNode", meta=(editCondition="bShowOnlyIfChildTaskNodeValid || bShowPreviewOnlyIfAnyChildTaskNodeValid"))
	FGameplayTag OptionalChildChoiceTagFilter;

};

