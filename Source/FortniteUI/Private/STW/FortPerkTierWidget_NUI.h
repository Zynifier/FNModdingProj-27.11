// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "STW/FortPerks.h"
#include "FortPerkTierWidget_NUI.generated.h"

class UFortPerkWidget_NUI;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPerkTierWidget_NUI : public UCommonUserWidget, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortPerkTierWidget")
	void OnGeneratePerk(FFortUIPerk Perk, UFortPerkWidget_NUI* PerkWidget);

	UFUNCTION(BlueprintCallable, Category="FortPerkTierWidget")
	void ProcessPerks();

	UPROPERTY(BlueprintReadWrite, Category="FortPerkTierWidget", meta=(ExposeOnSpawn="TRUE"))
	FFortUIPerkTier FortPerkTier;

};

