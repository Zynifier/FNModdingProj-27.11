// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationContext.h"
#include "ConversationRequirementNode.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_DataDrivenService.generated.h"

class UFortControllerEffect;
class UFortControllerRequirement;
class UServiceBriefConfigCollection;

UENUM()
enum class EDataDrivenEffectRecipient : uint8
{
	Player = 0,
	NPC = 1,
};

UENUM()
enum class ERequirementMatchPolicy : uint8
{
	RequireAll = 0,
	RequireAny = 1,
};

USTRUCT(BlueprintType)
struct FConversationParticipantRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ConversationParticipantRequirement", meta=(Categories="Conversation.Participant"))
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, Instanced, Category="ConversationParticipantRequirement")
	TObjectPtr<UFortControllerRequirement> Requirement;

	UPROPERTY(EditDefaultsOnly, Category="ConversationParticipantRequirement")
	EConversationRequirementResult FailureNodeBehaviour;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Choice Parameter Keys")
	FString CannotUseReasonParameter;

};

USTRUCT()
struct FDataDrivenServiceTaskMemory
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FEffectRecipientConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Choice Parameter Keys")
	EDataDrivenEffectRecipient Recipient;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Effects")
	TArray<TObjectPtr<UFortControllerEffect>> Effects;

};

UCLASS(Abstract)
class UFortConversationTaskNode_DataDrivenService : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Requirements")
	ERequirementMatchPolicy RequirementMatchPolicy;

	UPROPERTY(EditAnywhere, Category="Requirements")
	TArray<FConversationParticipantRequirement> Requirements;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TArray<FEffectRecipientConfig> EffectRecipientConfigs;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Events", meta=(Categories="Athena.Quests"))
	FGameplayTag ServiceGameplayTag;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Events")
	FString AnalyticsEventName;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Pricing")
	bool bPricingEnabled;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Pricing", meta=(EditCondition="bPricingEnabled", EditConditionHides))
	FName PricingKey;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Pricing", meta=(EditCondition="bPricingEnabled", EditConditionHides))
	int32 PricingColumn;

	UPROPERTY(EditDefaultsOnly, Category="Stock")
	FScalableFloat LimitedStockCount;

	UPROPERTY(EditAnywhere, Category="UI")
	TObjectPtr<UServiceBriefConfigCollection> ServiceBriefConfigCollection;

	UPROPERTY(EditAnywhere, Category="UI")
	FName ServiceBriefCollectionKeyOveride;

private:
	UFUNCTION(BlueprintPure)
	bool GetServicePrice(const FConversationContext& Context, float& PriceOut) const;

};

