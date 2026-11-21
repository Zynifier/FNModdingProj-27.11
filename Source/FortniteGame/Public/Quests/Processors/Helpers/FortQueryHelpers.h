// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "FortQueryHelpers.generated.h"

class UFortQuestItemDefinition;
class UObject;

USTRUCT()
struct FAdvancedClassFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AdvancedClassFilter", meta=(BaseStruct="/Script/FortniteGame.SoftClassFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> AdvancedClassFilters;

};

USTRUCT()
struct FAdvancedQuestDefinitionFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AdvancedQuestDefinitionFilter", meta=(BaseStruct="/Script/FortniteGame.SoftQuestDefinitionFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> AdvancedQuestFilters;

};

USTRUCT(meta=(Hidden))
struct FSoftClassFilterType
{
	GENERATED_BODY()

};

USTRUCT(meta=(DisplayName="All Expressions Match"))
struct FSoftClassFilterType_Expression_All : public FSoftClassFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftClassFilterType_Expression_All", meta=(BaseStruct="/Script/FortniteGame.SoftClassFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> Expressions;

};

USTRUCT(meta=(DisplayName="Any Expressions Match"))
struct FSoftClassFilterType_Expression_Any : public FSoftClassFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftClassFilterType_Expression_Any", meta=(BaseStruct="/Script/FortniteGame.SoftClassFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> Expressions;

};

USTRUCT(meta=(DisplayName="No Expressions Match"))
struct FSoftClassFilterType_Expression_None : public FSoftClassFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftClassFilterType_Expression_None", meta=(BaseStruct="/Script/FortniteGame.SoftClassFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> Expressions;

};

USTRUCT(meta=(DisplayName="Any Classes Match"))
struct FSoftClassFilterType_Rule_Any : public FSoftClassFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftClassFilterType_Rule_Any")
	TArray<TSoftClassPtr<UObject>> Classes;

};

USTRUCT(meta=(DisplayName="No Classes Match"))
struct FSoftClassFilterType_Rule_None : public FSoftClassFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftClassFilterType_Rule_None")
	TArray<TSoftClassPtr<UObject>> Classes;

};

USTRUCT(meta=(Hidden))
struct FSoftQuestDefinitionFilterType
{
	GENERATED_BODY()

};

USTRUCT(meta=(DisplayName="All Expressions Match"))
struct FSoftQuestDefinitionFilterType_Expression_All : public FSoftQuestDefinitionFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftQuestDefinitionFilterType_Expression_All", meta=(BaseStruct="/Script/FortniteGame.SoftQuestDefinitionFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> Expressions;

};

USTRUCT(meta=(DisplayName="Any Expressions Match"))
struct FSoftQuestDefinitionFilterType_Expression_Any : public FSoftQuestDefinitionFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftQuestDefinitionFilterType_Expression_Any", meta=(BaseStruct="/Script/FortniteGame.SoftQuestDefinitionFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> Expressions;

};

USTRUCT(meta=(DisplayName="No Expressions Match"))
struct FSoftQuestDefinitionFilterType_Expression_None : public FSoftQuestDefinitionFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftQuestDefinitionFilterType_Expression_None", meta=(BaseStruct="/Script/FortniteGame.SoftQuestDefinitionFilterType", ExcludeBaseStruct))
	TArray<FInstancedStruct> Expressions;

};

USTRUCT(meta=(DisplayName="Any Quests Match"))
struct FSoftQuestDefinitionFilterType_Rule_Any_QuestDefinition : public FSoftQuestDefinitionFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftQuestDefinitionFilterType_Rule_Any_QuestDefinition")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestItemDefinitions;

};

USTRUCT(meta=(DisplayName="No Quests Match"))
struct FSoftQuestDefinitionFilterType_Rule_None_QuestDefinition : public FSoftQuestDefinitionFilterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoftQuestDefinitionFilterType_Rule_None_QuestDefinition")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestItemDefinitions;

};

