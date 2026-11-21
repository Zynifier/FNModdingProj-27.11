// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "FortConversationControllerRequirement.generated.h"

class AActor;
class AController;

USTRUCT(BlueprintType)
struct FControllerRequirementTestContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="ControllerRequirementTestContext")
	TObjectPtr<AActor> TestSubjectActor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ControllerRequirementTestContext")
	TObjectPtr<AController> TestSubjectController;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ControllerRequirementTestContext")
	TObjectPtr<AActor> OtherActor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ControllerRequirementTestContext")
	TObjectPtr<AController> OtherController;

};

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable)
class UFortControllerRequirement : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Filtering")
	bool IsRequirementMet(const FControllerRequirementTestContext& RequestContext) const;

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool IsRequirementMetInternal(const FControllerRequirementTestContext& RequestContext) const;

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bInverseCondition;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Account Item Threshold Check"))
class UFortControllerRequirement_AccountItemQuantityCheck : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FString ItemTemplateID;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig RequiredQuantityThresholdConfig;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Attribute Threshold Check"))
class UFortControllerRequirement_AttributeThresholdCheck : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayAttribute QueryAttribute;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig ThresholdTestConfig;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Uses Character"))
class UFortControllerRequirement_HasCID : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.AthenaCharacterItemDefinition"))
	TArray<FSoftObjectPath> AllowedCIDs;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Completed Num Quest Objectives"))
class UFortControllerRequirement_HasCompletedNumQuestObjectives : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.FortQuestItemDefinition", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	FSoftObjectPath QuestDefinition;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig RequiredCount;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Completed Quest"))
class UFortControllerRequirement_HasCompletedQuest : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.FortQuestItemDefinition", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	FSoftObjectPath QuestDefinition;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Completed Quest Objective"))
class UFortControllerRequirement_HasCompletedQuestObjective : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.FortQuestItemDefinition", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	FSoftObjectPath QuestDefinition;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(EditCondition="!bResolveQuestDetailsFromServiceProvider", GetOptions="Editor_GetValidObjectives"))
	FName ObjectiveBackendName;

private:
	UFUNCTION()
	TArray<FName> Editor_GetValidObjectives() const;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has GameplayTag"))
class UFortControllerRequirement_HasOwnedTag : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag OwnedTag;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Uses Variant"))
class UFortControllerRequirement_HasVariant : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_HasVariant")
	TArray<FVariantUID> AllowedVariants;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Is Quest Active"))
class UFortControllerRequirement_IsQuestActive : public UFortControllerRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.FortQuestItemDefinition", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	FSoftObjectPath QuestDefinition;

};

