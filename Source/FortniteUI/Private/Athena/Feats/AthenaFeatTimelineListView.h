// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "AthenaFeatTimelineListView.generated.h"

UCLASS(meta=(EntryClass="AthenaFeatTimelineListEntryBase"))
class UAthenaFeatTimelineListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UAthenaFeatTimelineListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="List Entries")
	float EntrySpacing;

	UPROPERTY(EditAnywhere, Category="List Entries")
	float EndSpacing;

	UPROPERTY(EditAnywhere, Category="Completed Delay", meta=(ClampMin="0.000000"))
	float DelayBeforeStartCompleted;

	UPROPERTY(EditAnywhere, Category="Completed Delay", meta=(ClampMin="0.000000"))
	float DelayBetweenCompletedItems;

};

