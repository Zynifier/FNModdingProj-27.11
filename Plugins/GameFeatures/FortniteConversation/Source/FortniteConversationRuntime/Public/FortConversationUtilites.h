// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationContext.h"
#include "ConversationTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "FortConversationUtilites.generated.h"

class UFortControllerRequirement;
class UFortConversationContextCondition;

USTRUCT(BlueprintType)
struct FFortConversationConditionalMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Message")
	TObjectPtr<UFortConversationContextCondition> Condition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Message")
	FText Message;

};

USTRUCT(BlueprintType, meta=(HideInConversationNode="true"))
struct FFortConversationNodeConditionalMessages
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Messages")
	TArray<FFortConversationConditionalMessage> Messages;

};

UCLASS(Abstract, EditInlineNew, BlueprintType)
class UFortConversationContextCondition : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Filtering")
	virtual bool DoesContextPass(const FConversationContext& Context) const;

};

UCLASS(Abstract, EditInlineNew, BlueprintType)
class UFortConversationContextConditionHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="Filtering")
	static bool GetMessageForContext(const FFortConversationNodeConditionalMessages& Messages, const FConversationContext& Context, FText& OutText);

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Participant Controller Meets Requirement"))
class UFortConversationContextCondition_ParticipantControllerMeetsRequirement : public UFortConversationContextCondition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, Instanced, Category="Filtering")
	TObjectPtr<UFortControllerRequirement> Requirement;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Participant Uses Character"))
class UFortConversationContextCondition_ParticipantHasCID : public UFortConversationContextCondition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.AthenaCharacterItemDefinition"))
	TArray<FSoftObjectPath> AllowedCIDs;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Participant Has Cosmetic MetaTag"))
class UFortConversationContextCondition_ParticipantHasMetaTag : public UFortConversationContextCondition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(Categories="Cosmetics.MetaTags"))
	FGameplayTag MetaTag;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Participant Has GameplayTag"))
class UFortConversationContextCondition_ParticipantHasOwnedTag : public UFortConversationContextCondition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag OwnedTag;

};

UCLASS(meta=(ScriptName="FortConversationParamLibrary"))
class UFortConversationParamLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool ExtractConversationParameterValue(const TArray<FConversationNodeParameterPair>& ConversationParameters, const FString& DesiredParameterName, FString& ParameterValueOut);

};

