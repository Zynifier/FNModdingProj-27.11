// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortStatsOverviewDetailsBase.generated.h"

class UFortAttributeListItem_NUI;
class UFortAttributeList_NUI;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortStatsOverviewDetailsBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortStatsOverviewDetailsBase")
	FUniqueNetIdRepl GetLocalPlayerId() const;

	UFUNCTION(BlueprintCallable, Category="FortStatsOverviewDetailsBase")
	void ListenForChanges(bool bListen);

	UFUNCTION(BlueprintCallable, Category="FortStatsOverviewDetailsBase")
	void RequestStatsUpdate();

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortStatsOverviewDetailsBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortAttributeListItem_NUI>> OverviewStats;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStatsOverviewDetailsBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortAttributeList_NUI> DetailedStats;

};

