// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_RebootRally.generated.h"

UENUM()
enum class ERebootRallyQuestType : uint8
{
	Other = 0,
	QRQuest = 1,
	RewardQuest = 2,
};

USTRUCT()
struct FFortQuestEventDescription
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestEventDescription", meta=(MultiLine="true"))
	FText Description;

	UPROPERTY(EditAnywhere, Category="FortQuestEventDescription")
	FGameplayTagQuery TagQuery;

};

UCLASS(BlueprintType, meta=(DisplayName="Reboot Rally Component"))
class UFortQuestDefinitionComponent_RebootRally : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(DisplayAfter="Description"))
	TArray<FFortQuestEventDescription> EventDescriptions;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortQuestDefinitionComponent_RebootRally")
	ERebootRallyQuestType QuestType;
#endif

};

