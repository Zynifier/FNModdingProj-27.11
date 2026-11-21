// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationContextualMessageConfig.h"
#include "FortConversationGiftTypeDefinitions.generated.h"

class UFortControllerEffect;
class UFortControllerRequirement;
class UGiftUINotificationHandler;

USTRUCT(BlueprintType)
struct FConversationGiftTypeDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ConversationGiftTypeDefinition")
	EContextRequirementMatchPolicy ServiceProviderRequirementMatchPolicy;

	UPROPERTY(EditAnywhere, Instanced, Category="ConversationGiftTypeDefinition")
	TArray<TObjectPtr<UFortControllerRequirement>> ServiceProviderRequirements;

	UPROPERTY(EditAnywhere, Category="ConversationGiftTypeDefinition", meta=(DisplayName="Gift Recipient Requirement Match Policy"))
	EContextRequirementMatchPolicy RequirementMatchPolicy;

	UPROPERTY(EditAnywhere, Instanced, Category="ConversationGiftTypeDefinition", meta=(DisplayName="Gift Recipient Requirements"))
	TArray<TObjectPtr<UFortControllerRequirement>> Requirements;

	UPROPERTY(EditAnywhere, Instanced, Category="ConversationGiftTypeDefinition")
	TArray<TObjectPtr<UFortControllerEffect>> Effects;

	UPROPERTY(EditAnywhere, Instanced, Category="ConversationGiftTypeDefinition")
	TObjectPtr<UGiftUINotificationHandler> UINotificationType;

	UPROPERTY(EditAnywhere, Category="ConversationGiftTypeDefinition")
	FScalableFloat OptionalSelectionCooldown;

};

UCLASS()
class UFortConversationGiftTypeDefinitions : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortConversationGiftTypeDefinitions")
	TMap<FGameplayTag, FConversationGiftTypeDefinition> GiftDefinitionsByGiftTag;

};

