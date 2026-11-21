// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "Types/SlateEnums.h"
#include "FortServerBrowserListView.generated.h"

class UFortCreativeServerInfoTile;
class UFortPlaylistSelectionActionTile;
class UFortServerActionTile;

UCLASS(meta=(EntryClass="FortServerTileBase"))
class UFortServerBrowserListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortServerBrowserListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="ListView")
	TEnumAsByte<EOrientation> Orientation;

	UPROPERTY(EditAnywhere, Category="ListEntries", meta=(ClampMin="0"))
	float EntrySpacing;

private:
	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortCreativeServerInfoTile> CreativeServerInfoTileEntryClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortServerActionTile> ServerActionTileEntryClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortServerActionTile> OwnServerActionTileEntryClass;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortPlaylistSelectionActionTile> PlaylistSelectionActionTileEntryClass;

};

