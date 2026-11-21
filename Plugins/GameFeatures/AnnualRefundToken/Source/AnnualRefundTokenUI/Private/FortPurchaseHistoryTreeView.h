// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPurchaseHistoryListView.h"
#include "FortPurchaseHistoryTreeView.generated.h"

class UFortPurchaseHistoryBundleEntry;

UCLASS()
class UFortPurchaseHistoryTreeView : public UFortPurchaseHistoryListView
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ListEntries")
	TSubclassOf<UFortPurchaseHistoryBundleEntry> HeaderEntryWidgetClass;

};

