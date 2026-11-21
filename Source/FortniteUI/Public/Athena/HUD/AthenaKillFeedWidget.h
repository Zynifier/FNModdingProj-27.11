// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaCommonPrioritizedWidget.h"
#include "AthenaKillFeedWidget.generated.h"

class UAthenaKillFeedEntryWidget;
class UPanelWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaKillFeedWidget : public UAthenaCommonPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UPanelWidget* EntriesContainer;

	UPROPERTY(EditAnywhere, Category="KillFeed")
	TSubclassOf<UAthenaKillFeedEntryWidget> KillfeedEntryClass;

	UPROPERTY(EditAnywhere, Category="KillFeed")
	float MaxDisplayTimeInSeconds;

	UPROPERTY(EditAnywhere, Category="KillFeed")
	int32 MaxKillFeedEntries;

};

