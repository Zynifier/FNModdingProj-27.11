// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DownloadOnDemandProjectDetailsSidePanel.generated.h"

class UCreativeContentBrowserItemInfo;
class UDownloadOnDemandProjectTile;

UCLASS()
class UDownloadOnDemandProjectDetailsSidePanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UDownloadOnDemandProjectDetailsSidePanel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDownloadOnDemandProjectTile> DownloadOnDemandProjectTile_CurrentProjectEntry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCreativeContentBrowserItemInfo> ContentBrowserItemInfo_ItemDetails;

};

