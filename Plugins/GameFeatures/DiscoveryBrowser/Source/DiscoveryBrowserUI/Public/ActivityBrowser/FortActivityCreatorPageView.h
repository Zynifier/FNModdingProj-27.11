// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityCategoryPageView.h"
#include "FortActivityCreatorPageView.generated.h"

class UFortGameActivity;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortActivityCreatorPageView : public UFortActivityCategoryPageView
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCreatorActivitiesQueryFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNoContentFoundForCreator();

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> ActivityDetailsSelectedGameActivity;

	UPROPERTY(Transient)
	int32 AmountOfCreatorLinkEntriesQueried;

	UPROPERTY(Transient)
	int32 ProcessedCreatorLinkEntries;

	UPROPERTY(EditAnywhere, Config, Category="UI", meta=(DisplayName="Amount of creator activities queried when loading the Creator Page."))
	int32 AmountOfEntriesQueried;

};

