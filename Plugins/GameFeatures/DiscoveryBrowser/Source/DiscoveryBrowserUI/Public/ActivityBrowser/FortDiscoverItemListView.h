// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "Types/SlateEnums.h"
#include "FortDiscoverItemListView.generated.h"

class UFortActivityBrowserPlayWithFriendsTile;
class UFortActivityBrowserTileBase;

UCLASS(meta=(DisableNativeTick, EntryClass="FortActivityBrowserTileBase"))
class UFortDiscoverItemListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortDiscoverItemListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	const int32 GetInViewCount() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(DisplayName="Directional Navigation Time Threshold"))
	float DirectionalNavigationTimeThreshold;

protected:
	UPROPERTY(EditAnywhere, Category="PlayWithFriendsEntries")
	TSubclassOf<UFortActivityBrowserPlayWithFriendsTile> PlayWithFriendsEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortActivityBrowserTileBase> ActivityEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="ListView")
	TEnumAsByte<EOrientation> Orientation;

	UPROPERTY(EditAnywhere, Category="ListEntries", meta=(ClampMin="0"))
	float EntrySpacing;

private:
	UPROPERTY(EditAnywhere, Category="ListView")
	bool bCircularNavigationEnabled;

};

