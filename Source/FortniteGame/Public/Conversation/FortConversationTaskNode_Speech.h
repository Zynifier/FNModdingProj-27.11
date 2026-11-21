// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationContext.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationContextualMessageConfig.h"
#include "Conversation/FortConversationTaskNode.h"
#include "FortConversationTaskNode_Speech.generated.h"

class UContextualMessageConfigCollection;

UCLASS(MinimalAPI, BlueprintType)
class UContextualMessageConfigCollection : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages")
	bool bUsePerNPC_ContextualMessageLookup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="bUsePerNPC_ContextualMessageLookup", EditConditionHides))
	bool bLookupViaServiceProviderTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="bUsePerNPC_ContextualMessageLookup", EditConditionHides))
	TMap<FGameplayTag, FContextualMessageConfig> SpeakerEntryTagToConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages")
	FContextualMessageConfig GeneralConfig;

};

UCLASS(Abstract, MinimalAPI)
class UFortConversationTaskNode_Speech : public UFortConversationTaskNode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool ResolveMessageForContext(const FGameplayTag& SpeakerParticipantTag, const FConversationContext& ConversationContext, FContextualMessageQueryResult& OutResult) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages")
	bool bUseInlineConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="bUseInlineConfig", EditConditionHides))
	bool bUsePerNPC_ContextualMessageLookup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="bUseInlineConfig && bUsePerNPC_ContextualMessageLookup", EditConditionHides))
	bool bLookupViaServiceProviderTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="!bUseInlineConfig", HideInConversationNode="true"))
	TObjectPtr<UContextualMessageConfigCollection> ExternalContextualMessageCollection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="bUseInlineConfig && bUsePerNPC_ContextualMessageLookup", EditConditionHides, HideInConversationNode="true"))
	TMap<FGameplayTag, FContextualMessageConfig> SpeakerEntryTagToConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessages", meta=(EditCondition="bUseInlineConfig", EditConditionHides, HideInConversationNode="true"))
	FContextualMessageConfig GeneralConfig;

};

