// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DownloadOnDemandStatusFeedLine.generated.h"

class UCommonTextBlock;

UCLASS()
class UDownloadOnDemandStatusFeedLine : public UUserWidget
{
	GENERATED_BODY()

public:
	UDownloadOnDemandStatusFeedLine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_DownloadStatus;

};

