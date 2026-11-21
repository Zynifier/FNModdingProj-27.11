// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "FortActivityBrowserListView.generated.h"

class UFortActivityBrowserRow;
class UFortHabaneroDisplayData;

UCLASS(meta=(DisableNativeTick, EntryClass="FortActivityBrowserRowList"))
class UFortActivityBrowserListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortActivityBrowserListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void NavigateToActivityInFirstRow(int32 ActivityItemIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(DisplayName="Directional Navigation Time Threshold"))
	float DirectionalNavigationTimeThreshold;

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void HandleVisibleEntriesChanged() const;

	UPROPERTY(EditAnywhere, Category="Habanero")
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

private:
	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortActivityBrowserRow> PromotedActivityClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortActivityBrowserRow> DiscoverItemRowClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortActivityBrowserRow> HomebarItemRowClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TMap<FName, TSubclassOf<UFortActivityBrowserRow>> RowTypes;

};

