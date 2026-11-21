// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationContextualMessageConfig.h"
#include "FortConditionalBenefitsConfig.generated.h"

class UFortControllerRequirement;

USTRUCT(BlueprintType)
struct FFortParticipantRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortParticipantRequirement", meta=(Categories="Conversation.Participant"))
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="FortParticipantRequirement")
	UFortControllerRequirement* Requirement;

};

USTRUCT(BlueprintType)
struct FConditionalBenefitLevel
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ConditionalBenefitLevel")
	EContextRequirementMatchPolicy RequirementMatchPolicy;

	UPROPERTY(EditAnywhere, Category="ConditionalBenefitLevel")
	TArray<FFortParticipantRequirement> ParticipantRequirements;

	UPROPERTY(EditAnywhere, Category="ConditionalBenefitLevel")
	FGameplayTagContainer BenefitsGained;

	UPROPERTY(EditAnywhere, Category="ConditionalBenefitLevel")
	FGameplayTagContainer PreviousBenefitsRemoved;

};

USTRUCT(BlueprintType)
struct FConditionalBenefitsConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ConditionalBenefitsConfig")
	TArray<FConditionalBenefitLevel> LevelBasedConditionalBenefits;

	UPROPERTY(EditAnywhere, Category="ConditionalBenefitsConfig")
	TArray<FConditionalBenefitLevel> GeneralConditionalBenefits;

};

USTRUCT(BlueprintType)
struct FFortServiceDiscountBenefitSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortServiceDiscountBenefitSettings")
	FGameplayTag RequiredConditionalBenefitTag;

	UPROPERTY(EditDefaultsOnly, Category="FortServiceDiscountBenefitSettings")
	FScalableFloat ServiceCostMultiplier;

};

UCLASS()
class FORTNITEGAME_API UFortConditionalBenefitsConfigCollection : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortConditionalBenefitsConfigCollection")
	TMap<FGameplayTag, FConditionalBenefitsConfig> IDToConditionalBenefitsConfig;

};

