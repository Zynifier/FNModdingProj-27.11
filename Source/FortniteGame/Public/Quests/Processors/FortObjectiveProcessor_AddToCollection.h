// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_AddToCollection.generated.h"

USTRUCT(meta=(DisplayName="Add To Collection"))
struct FFortObjectiveFilter_AddToCollection : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AddToCollection")
	FObjectiveSubjectTags ItemDiscovered;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AddToCollection", meta=(Categories="Collections"))
	FObjectiveSubjectTags CollectionType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AddToCollection")
	uint8 bRequireNewlyFoundItem : 1;

};

UCLASS()
class UFortObjectiveProcessor_AddToCollection : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

