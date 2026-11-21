// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_TrackedData.generated.h"

USTRUCT(BlueprintType, meta=(Hidden))
struct FFortTrackedDataType
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortTrackedDataWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortTrackedDataWrapper", meta=(BaseStruct="/Script/FortniteGame.FortTrackedDataType", ExcludeBaseStruct))
	TArray<FInstancedStruct> TrackedData;

};

USTRUCT(BlueprintType, meta=(DisplayName="GUID"))
struct FFortTrackedData_GUID : public FFortTrackedDataType
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(DisplayName="Tags"))
struct FFortTrackedData_Tags : public FFortTrackedDataType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortTrackedData_Tags")
	FGameplayTagContainer Tags;

};

USTRUCT()
struct FObjectiveExtension_TrackedData : public FObjectiveExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveExtension_TrackedData")
	TMap<FName, FFortTrackedDataWrapper> SubjectToTrackedDataMapping;

};

UCLASS(BlueprintType, meta=(DisplayName="Tracked Data"))
class UFortQuestDefinitionComponent_TrackedData : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

};

