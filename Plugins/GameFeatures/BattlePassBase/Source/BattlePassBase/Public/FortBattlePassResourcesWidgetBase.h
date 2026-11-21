// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGlobalSeasonResourceWidget.h"
#include "FortBattlePassResourcesWidgetBase.generated.h"

class UDynamicEntryBox;
class UFortBattlePassResourceCounter;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassResourcesWidgetBase : public UFortGlobalSeasonResourceWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowMoreInfo(bool bShouldShowMoreInfo);

	UFUNCTION(BlueprintCallable)
	void ShowResourcesInfoModal();

	UPROPERTY(EditDefaultsOnly, Category="Resource Counter")
	TSubclassOf<UFortBattlePassResourceCounter> ResourceCounterClass;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourcesWidgetBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ResourceCounters;

};

