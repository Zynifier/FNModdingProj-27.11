// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortMatchXPDetails.generated.h"

class UAthenaAccoladeListWidget;
class UFortMatchStatsScreen;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMatchXPDetails : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PopulateAccoladeList();

	UFUNCTION(BlueprintCallable)
	void UpdateMatchStats();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchStatsScreen> Section_MatchStats;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaAccoladeListWidget> Section_MedalList;

};

