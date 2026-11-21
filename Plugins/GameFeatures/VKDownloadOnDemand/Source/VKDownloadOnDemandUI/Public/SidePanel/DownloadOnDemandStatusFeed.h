// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DownloadOnDemandStatusFeed.generated.h"

class UFortDynamicEntryBox;

UCLASS()
class UDownloadOnDemandStatusFeed : public UUserWidget
{
	GENERATED_BODY()

public:
	UDownloadOnDemandStatusFeed(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="DownloadOnDemandStatusFeed")
	bool bOverrideOldStatusWithNewStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_DownloadStatusContainer;

};

