// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "AthenaChallengeListView.generated.h"

class UAthenaQuestEntryVisualData;

UCLASS(Abstract, meta=(EntryClass="AthenaChallengeListEntry_Challenge"))
class UAthenaChallengeListViewBase : public UListViewBase
{
	GENERATED_BODY()

public:
	UAthenaChallengeListViewBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Visual Data")
	TObjectPtr<UAthenaQuestEntryVisualData> VisualData;

private:
	UPROPERTY(EditAnywhere, Category="List Entries")
	float EntrySpacing;

};

