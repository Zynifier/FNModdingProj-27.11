// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "FortQuestToolListView.generated.h"

class UUserWidget;

UCLASS(meta=(EntryClass="QuestToolListViewBase"))
class UFortQuestToolListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortQuestToolListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	int32 GetNumListEntries() const;

	UFUNCTION(BlueprintPure)
	int32 GetQuestToolListItemIndex(UUserWidget* ListItemWidget) const;

	UFUNCTION(BlueprintCallable)
	bool RemoveQuestToolListEntry(UUserWidget* ListItemWidget);

};

