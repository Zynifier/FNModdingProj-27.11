// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortMission.h"
#include "FortMission_HarvestingBase.generated.h"

class ABuildingActor;
class ABuildingDeco;
class UFortConversation;

USTRUCT(BlueprintType)
struct FFortReactiveQuestDialogue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortReactiveQuestDialogue")
	TObjectPtr<UFortConversation> Conversation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortReactiveQuestDialogue")
	int32 PlayOnObjectiveCount;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortMission_HarvestingBase : public AFortMission
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	TArray<TSubclassOf<ABuildingActor>> BuildingActorClassesValidForHarvestDrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	TArray<TSubclassOf<ABuildingDeco>> DecoActorClassesValidForHarvestDrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	float ItemDropChancePercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 ItemMinDropQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 ItemMaxDropQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	float MinDurationBetweenDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 MaxFailedDropsInARow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Conversation")
	bool bEnableConversations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Conversation")
	TArray<FFortReactiveQuestDialogue> Conversations;

};

