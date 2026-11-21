// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "FortPurchaseHistoryListView.generated.h"

UCLASS(meta=(EntryClass="FortPurchaseHistoryEntry"))
class UFortPurchaseHistoryListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortPurchaseHistoryListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

