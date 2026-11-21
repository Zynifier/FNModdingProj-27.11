// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "Input/FortMiniMapInputComponent.h"
#include "AthenaFullScreenMapBase.generated.h"

class UAthenaMapLayerContainer;
class UFortMarkerDetailsTable;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFullScreenMapBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowMapLayerContainer(const bool bShowing);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMapLayerContainer> MapLayerContainer;

	UPROPERTY(EditAnywhere, Category="AthenaFullScreenMapBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleMapMarkerRowHandle;

	UPROPERTY(EditAnywhere, Category="AthenaFullScreenMapBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TeleportToMapMarkerRowHandle;

	UPROPERTY(EditAnywhere, Category="AthenaFullScreenMapBase", meta=(AssetBundles="MenuAthena"))
	TSoftObjectPtr<UFortMarkerDetailsTable> SoftMarkerDetailsTable;

	UPROPERTY(EditAnywhere, Category="AthenaFullScreenMapBase")
	FMinimapZoomBounds ZoomBounds;

	UPROPERTY(BlueprintReadOnly, Category="AthenaFullScreenMapBase", meta=(AllowPrivateAccess="true"))
	bool bMapLayerContainerEnabled;

};

