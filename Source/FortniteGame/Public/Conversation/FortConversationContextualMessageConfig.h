// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationTypes.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortConversationContextualMessageConfig.generated.h"

class UFortControllerRequirement;

UENUM()
enum class EContextRequirementMatchPolicy : uint8
{
	RequireAll = 0,
	RequireAny = 1,
};

USTRUCT(BlueprintType)
struct FFortConversationContextRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationContextRequirement", meta=(Categories="Conversation.Participant"))
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="FortConversationContextRequirement")
	TObjectPtr<UFortControllerRequirement> Requirement;

};

USTRUCT(BlueprintType)
struct FContextualMessageCandidate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessageCandidate", meta=(MultiLine="true"))
	FText Message;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessageCandidate")
	EContextRequirementMatchPolicy RequirementMatchPolicy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessageCandidate")
	TArray<FFortConversationContextRequirement> ContextRequirements;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selection")
	FScalableFloat Priority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selection")
	FScalableFloat Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessageCandidate")
	TArray<FConversationNodeParameterPair> MetadataParameters;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContextualMessageCandidate")
	FGameplayTagContainer MetadataTags;

};

USTRUCT(BlueprintType)
struct FContextualMessageConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Messages", meta=(TitleProperty="Message"))
	TArray<FContextualMessageCandidate> ContextualMessages;

	UPROPERTY(EditAnywhere, Category="Messages", meta=(MultiLine="true"))
	FText DefaultMessage;

	UPROPERTY(EditAnywhere, Category="Messages")
	TArray<FConversationNodeParameterPair> DefaultMetadataParameters;

	UPROPERTY(EditAnywhere, Category="Messages")
	FGameplayTagContainer DefaultMetadataTags;

};

USTRUCT(BlueprintType)
struct FContextualMessageQueryResult
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Messages", meta=(MultiLine="true"))
	FText Message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Messages")
	TArray<FConversationNodeParameterPair> MetadataParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Messages")
	FGameplayTagContainer MetadataTags;

};

