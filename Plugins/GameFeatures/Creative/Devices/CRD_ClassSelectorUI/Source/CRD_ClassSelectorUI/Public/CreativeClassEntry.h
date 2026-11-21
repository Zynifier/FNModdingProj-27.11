// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UObject/NoExportTypes.h"
#include "CreativeClassSelectorButton.h"
#include "Minigame/FortMinigame.h"
#include "CreativeClassEntry.generated.h"

class UCreativeClassItemInfo;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativeClassEntry : public UCreativeClassSelectorButton, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBrowsingLoadout(const bool bBrowsingLoadout);

	UFUNCTION(BlueprintImplementableEvent)
	void OnClassEntryDataSet(const bool bIsCurrentClass, const bool bIsPendingClass);

protected:
	UPROPERTY(Transient)
	TObjectPtr<UCreativeClassItemInfo> ItemInfo;

};

UCLASS()
class UCreativeClassItemInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FMinigameClassSlot ClassSlot;

};

