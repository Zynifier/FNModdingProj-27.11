// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortLevelSaveComponent.h"
#include "CreativeContentBrowserItemInfo.generated.h"

class UFortItem;

UCLASS()
class FORTNITEUI_API UCreativeContentBrowserItemInfo : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowDescription(bool bShow);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateWithFortItem(const UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateWithLevel(const FLevelInstanceListElement& LevelInstanceElement);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateWithText(const FText& DisplayName, const FText& TypeName, const FText& Description);

};

