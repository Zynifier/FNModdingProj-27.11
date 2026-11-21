// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortSquadStatsWidgetBase.generated.h"

class UFortAttributeListItem_NUI;
class UFortAttributeList_NUI;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadStatsWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortSquadStatsWidgetBase")
	FUniqueNetIdRepl GetLocalPlayerId() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortSquadStatsWidgetBase", meta=(DisplayName="Handle Power Rating Changed"))
	void HandlePowerRatingChanged_BP(bool bHasTeamMebers);

	UFUNCTION(BlueprintCallable, Category="FortSquadStatsWidgetBase")
	void RequestShowPreviewStats();

	UFUNCTION(BlueprintCallable, Category="FortSquadStatsWidgetBase")
	void RequestStatsUpdate();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSquadSlottingPreviewStateChanged();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSquadStatsWidgetBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortAttributeListItem_NUI>> OverviewStats;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadStatsWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAttributeList_NUI> DetailedStats;

};

